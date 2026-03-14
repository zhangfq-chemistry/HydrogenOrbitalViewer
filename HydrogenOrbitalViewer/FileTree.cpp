/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QApplication>
#include <QRegExp>


#include "mainwindow.h"
#include "FileTree.h"

MainWindow * FileTree::getMainWindow()
{
    foreach (QWidget *w, qApp->topLevelWidgets())
        if (QMainWindow* mainWin = qobject_cast<QMainWindow*>(w))
            return (MainWindow *)mainWin;
    return nullptr;
}


void FileTree::sendMessage(QString  m_message)
{
    getMainWindow()->sendMessage(m_message);
}
void FileTree::appendMessage(QString  m_message)
{
    getMainWindow()->appendMessage(m_message);
}

FileTree::FileTree(QWidget *parent) : QTreeWidget(parent), autoRefresh(false)
{
    //setObjectName(QStringLiteral("treeWidget"));
    setGeometry(QRect(10, 1, 191, 691));

    QStringList labels;
    labels << tr("Setting") << tr("Type") << tr("Value");
    setHeaderLabels(labels);
    header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    header()->setSectionResizeMode(2, QHeaderView::Stretch);

    refreshTimer.setInterval(2000);

    groupIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirClosedIcon),
                        QIcon::Normal, QIcon::Off);
    groupIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),
                        QIcon::Normal, QIcon::On);
    keyIcon.addPixmap(style()->standardPixmap(QStyle::SP_FileIcon));

    //connect(&refreshTimer, &QTimer::timeout, this, &SettingsTree::maybeRefresh);
    Molecules.clear();
    NameLists.clear();
    AtomLabels.clear();
    orbital_type=FULL;
    isObtialMesh=true;

    visible_radial_node=false;
    visible_angular_node=false;


    connect(this, &QTreeWidget::itemClicked,   this, &FileTree::updateSelection);

    //setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,SIGNAL(customContextMenuRequested(const QPoint & )), this,SLOT(OnPopMenu(const QPoint &)));
}





FileTree::~FileTree()
{

}


void FileTree::AddMolecularOrbitals(QString & s )
{
     sendMessage("Adding Molecular orbital ");

     //replace all the comma with whitespace
     s=s.replace(QRegExp(",")," ");

     QStringList Lines = s.trimmed().split("\n");
     QString single,fullName="MO";

     QStringList ls;

     uint projType=0;

     HMol * mol =  new HMol();

     bool isBegin=true;
     for (uint i=0; i < Lines.size(); i++)
     {
         single = Lines.at(i).trimmed();
         if ( single.contains(QRegExp("#") ) )  continue;
         ls = single.split(QRegExp("\\s+"));

         if (ls.size()<=1) continue;
         if ( ls[0].toLower().startsWith("name") )
         {
             // check existed or not, based on full name
             fullName=single.remove(0,5);
             if (fullName.trimmed().length()<1)
                 fullName="MO";

             if (NameLists.size()>0)
             for (QVector<QString>::iterator iter=NameLists.begin();iter!=NameLists.end();iter++)
             {
                  if ( *iter == fullName)
                  {
                      sendMessage("The " + fullName + " is existed! ");
                      QMessageBox::information(0, "Warning",fullName + " is existed! Please changed it!");
                      return;
                  }
             }
             NameLists.push_back(fullName) ;

             continue;
         }

         if ( ls[0].toLower().startsWith("proj") )
         {
             QString type= ls[1].toLower();

             projType=0;
             if ( type.contains("xoy") || type.contains("xy"))
                 projType=1;

             if ( type.contains("xoz") || type.contains("xz"))
                 projType=2;

             if ( type.contains("yoz") || type.contains("yz"))
                 projType=3;

             continue;
         }



         if ( (ls.size() != 6) && (ls.size() != 4) ) continue;

         QString AtomSymbol=ls[0];
         double x=ls[1].toDouble();
         double y=ls[2].toDouble();
         double z=ls[3].toDouble();

         QString AtomOrbital="None";

         double c=0.0;
         if ( ls.size() == 6) {
             c=ls[4].toDouble();
             AtomOrbital=ls[5];
         }

         //adding the orbital to this orbitals
         idx_mol=Molecules.size();
         vector3 pos(x,y,z);

         mol->addAtom(AtomSymbol,pos);
         mol->m_parent=getMainWindow();
         mol->setIdx(idx_mol);
         mol->setAtomLabel(fullName);

         if(ls.size() == 6) {
             if (isBegin) {
                 mol->addNewAO(AtomOrbital,AtomSymbol,pos, c,false);
                 isBegin=false;
             }
             else {
                 int idx= mol->getLastMOId();
                 mol->insertAO2MO(AtomOrbital,AtomSymbol, pos,c,idx,false);
             }
         }
     }

     if (mol->NAtoms()<1) {
         QMessageBox::information(0, "Warning","No atoms is existed!");
         NameLists.pop_back();
         delete mol;
         return;
     }


     idx_mo= mol->getLastMOId();

     //maybe atomic orbital
     if (mol->getObtial(idx_mo)->NumAOs()==1) {
         mol->getObtial(idx_mo)->setAtomicOrbitalTrue();
     }

     if (mol->getObtial(idx_mo)->NumAOs()>1) {
         mol->getObtial(idx_mo)->setHybridizedOrbitalTrue();
         if (mol->NAtoms()>1)
            mol->getObtial(idx_mo)->setMolecularOrbitalTrue();
     }


     mol->getObtial(idx_mo)->SetOrbitaName(fullName);
     mol->getObtial(idx_mo)->SetOrbitaType(orbital_type);
     mol->getObtial(idx_mo)->setActiveMolObitalMesh(isObtialMesh);
     mol->buildLatestMO();
     mol->buildBonds();


     mol->getObtial(idx_mo)->setProjType(projType);
     if (mol->getObtial(idx_mo)->NumAOs()>1)
        mol->buildMOProjectionData(idx_mo);

     mol->getObtial(idx_mo)->setVisible_radial_node(visible_radial_node);
     mol->getObtial(idx_mo)->setVisible_angular_node(visible_angular_node);

     // store in this FileTree class
     Molecules.push_back(mol);


     QTreeWidgetItem * itemMolecule = new QTreeWidgetItem(this,QStringList(fullName));
     itemMolecule->setText(1,QString ("%1").arg(mol->getIdx())); //store which molecule
     itemMolecule->setText(2,QString ("root")); //store which molecule

     itemMolecule->setBackgroundColor(0,QColor("#e5ebf4"));
     itemMolecule->setTextColor(0,Qt::blue);

     itemMolecule->setFlags(itemMolecule->flags() | Qt::ItemIsEditable);

     addViewsChildItems(itemMolecule, mol, fullName,true);


     this->expandAll();
     appendMessage("OK!");
}


void FileTree::NewHybridizedObitals (QString AtomSymbol, QString ObName,vector3 pos)
{

    if ( ObName=="SP"  || ObName=="SP2" || ObName=="SP3")
        AtomSymbol="C";

    if ( ObName=="DSP2" || ObName=="DSP3" || ObName=="D2SP3" )
        AtomSymbol="C";


    sendMessage("Building hybridized orbital "+ ObName + " based on atom " + AtomSymbol);

    cout << "Building hybridized orbital ";
    cout << ObName.toStdString().c_str();
    cout << " based on atom ";
    cout << AtomSymbol.toStdString().c_str()<< "..."<<endl;


    // check existed or not, based on full name
    QString fullName=AtomSymbol+"-"+ObName;

    if (NameLists.size()>0)
    for (QVector<QString>::iterator iter=NameLists.begin();iter!=NameLists.end();iter++)
    {
         if ( *iter == fullName)
         {
             sendMessage("The " + fullName + " is existed! ");
             QMessageBox::information(0, "Warning",fullName + " is existed! ");
             return;
         }
    }
    NameLists.push_back(fullName) ;



    bool isAtomExisted=false;
    if (AtomLabels.size()>0)
    for (int i=0;i<AtomLabels.size();i++)
    {
        if (AtomSymbol==AtomLabels[i])
        {
            isAtomExisted=true;
            break;
        }
    }

    HMol *  mol = nullptr;

    if (isAtomExisted)
    {
        // get the index of this atom
        for (int j=0; j<Molecules.size();j++)
        {
            if (Molecules[j]->getAtomLabel() == AtomSymbol)
            {
                mol = Molecules[j];
                break;
            }
        }

        uint idx_begin_mo=mol->NOrbitals()-1;
        mol->addHybridOrbs(AtomSymbol,pos, ObName);

        //refresh orbital informations
        uint size=mol->NOrbitals();
        while (size--) {
            if (size==idx_begin_mo) break;
            mol->getObtial(size)->SetOrbitaType(orbital_type);
            mol->getObtial(size)->setActiveMolObitalMesh(isObtialMesh);
            mol->getObtial(size)->setVisible_radial_node(false);
            mol->getObtial(size)->setVisible_angular_node(false);
            mol->set_MO_Visible (size,true);
            mol->getObtial(size)->setHybridizedOrbitalTrue();
            mol->buildHybridizedMO(size);
        }
        mol->buildMOProjectionData(idx_begin_mo+1);


       //Refresh Items

       //find the item of the Atom
       QTreeWidgetItemIterator itemMolecule (this);
       while (*itemMolecule) {
                if ( (*itemMolecule)->text(0)==AtomSymbol) {
                    break;
                }
               ++itemMolecule;
        }


      size=mol->NOrbitals();
      for (uint k = idx_begin_mo+1; k<size; k++)
      {
          QString obName=mol->getObtial(k)->OrbitalName;
          addViewsChildItems(*itemMolecule, mol, obName,false,k);
      }

      this->expandAll();
      //connect(this, &QTreeWidget::itemClicked,              this, &FileTree::updateSelection);

      cout << " OK! "<<endl;

      appendMessage("OK!");
      return;
    }



    //if (!isAtomExisted)
    AtomLabels.push_back(AtomSymbol);

    //adding the orbital to this orbitals
    mol = new HMol();
    idx_mol=Molecules.size();
    mol->addAtom(AtomSymbol,pos);

    mol->m_parent=getMainWindow();
    mol->setIdx(idx_mol);
    mol->setAtomLabel(AtomSymbol);

    mol->addHybridOrbs(AtomSymbol,pos, ObName);

    //refresh orbital informations
    uint size=mol->NOrbitals();


    while (1) {
        size=size-1;
        mol->getObtial(size)->SetOrbitaType(orbital_type);
        mol->getObtial(size)->setActiveMolObitalMesh(isObtialMesh);
        mol->getObtial(size)->setVisible_radial_node(false);
        mol->getObtial(size)->setVisible_angular_node(false);

        mol->getObtial(size)->setHybridizedOrbitalTrue();
        mol->buildHybridizedMO(size);

        if (size<1) break;
    }
    mol->buildMOProjectionData(0);


    Molecules.push_back(mol);

    //RefreshItems
    QTreeWidgetItem * itemMolecule = new QTreeWidgetItem(this,QStringList(AtomSymbol));
    itemMolecule->setFlags(itemMolecule->flags() | Qt::ItemIsEditable);
    itemMolecule->setText(1,QString ("%1").arg(mol->getIdx())); //store which molecule
    itemMolecule->setText(2,QString ("root")); //store which molecule

    itemMolecule->setBackgroundColor(0,QColor("#e5ebf4"));
    itemMolecule->setTextColor(0,Qt::blue);

    size=mol->NOrbitals();
    for (uint k = 0; k<size; k++)
    {
        QString obName=mol->getObtial(k)->OrbitalName;
        if (k==0)
            addViewsChildItems(itemMolecule, mol, obName,true,k);
        else
            addViewsChildItems(itemMolecule, mol, obName,false,k);

    }


    this->expandAll();
    appendMessage("OK!");
    cout << " OK! "<<endl;
}

void FileTree::NewAOObitals (QString AtomSymbol, QString ObName,vector3 pos)
{
    // check existed or not, based on full name
    QString fullName=AtomSymbol+"-"+ObName;

    sendMessage("----------------------------");
    sendMessage("Building "+ fullName + " ...");

    if (NameLists.size()>0)
    for (QVector<QString>::iterator iter=NameLists.begin();iter!=NameLists.end();iter++)
    {
        cout <<(*iter).toStdString().c_str()<<endl;
         if ( *iter == fullName)
         {
             QMessageBox::information(0, "Warning",fullName + " is existed! ");
             return;
         }
    }
    NameLists.push_back(fullName) ;


    bool isAtomExisted=false;
    if (AtomLabels.size()>0)
    for (int i=0;i<AtomLabels.size();i++)
    {
        if (AtomSymbol==AtomLabels[i])
        {
            isAtomExisted=true;
            break;
        }
    }

    HMol *  mol = nullptr;


    if (isAtomExisted)
    {
        // get the index of this atom
        for (int j=0; j<Molecules.size();j++)
        {
            if (Molecules[j]->getAtomLabel() == AtomSymbol)
            {
                mol = Molecules[j];
                break;
            }
        }

        //cout << ObName.toStdString().c_str()<<endl;
        //cout << n << " " << l<< " " <<m<<endl;
        mol->addNewAO(ObName,AtomSymbol,pos, 1.0,true);
        int idx= mol->getLastMOId();
        mol->getObtial(idx)->SetOrbitaType(orbital_type);
        mol->getObtial(idx)->setActiveMolObitalMesh(isObtialMesh);

        mol->getObtial(idx_mo)->setAtomicOrbitalTrue();

        mol->buildLatestMO();


        mol->getObtial(idx)->setVisible_radial_node(visible_radial_node);
        mol->getObtial(idx)->setVisible_angular_node(visible_angular_node);



        //find the item of the Atom
        QTreeWidgetItemIterator itemMolecule (this);
        while (*itemMolecule) {
                if ( (*itemMolecule)->text(0)==AtomSymbol) {
                    //cout << "find it"<<endl;
                    break;
                }
               ++itemMolecule;
         }

        addViewsChildItems(*itemMolecule, mol, ObName,false);


        this->expandAll();
        appendMessage("OK!");

        return;
    }

    if (!isAtomExisted)
        AtomLabels.push_back(AtomSymbol);

    //adding the orbital to this orbitals
    mol = new HMol();
    mol->m_parent=getMainWindow();
    idx_mol=Molecules.size();

    mol->setIdx(idx_mol);
    mol->setAtomLabel(AtomSymbol);

    mol->addAtom(AtomSymbol,pos);
    mol->addNewAO(ObName,AtomSymbol,pos,1.0,true);

    idx_mo= mol->getLastMOId();
    mol->getObtial(idx_mo)->SetOrbitaType(orbital_type);
    mol->getObtial(idx_mo)->setActiveMolObitalMesh(isObtialMesh);
    mol->getObtial(idx_mo)->setAtomicOrbitalTrue();
    mol->buildLatestMO();

    mol->getObtial(idx_mo)->setVisible_radial_node(visible_radial_node);
    mol->getObtial(idx_mo)->setVisible_angular_node(visible_angular_node);


    // store in this FileTree class
    Molecules.push_back(mol);


    QTreeWidgetItem * itemMolecule = new QTreeWidgetItem(this,QStringList(AtomSymbol));
    itemMolecule->setText(1,QString ("%1").arg(mol->getIdx())); //store which molecule
    itemMolecule->setText(2,QString ("root")); //store which molecule

    itemMolecule->setBackgroundColor(0,QColor("#e5ebf4"));
    itemMolecule->setTextColor(0,Qt::blue);


    addViewsChildItems(itemMolecule, mol, ObName,true);

    this->expandAll();
    appendMessage("OK!");

}



void FileTree::addViewsChildItems(QTreeWidgetItem * itemMolecule, HMol *  mol, QString ObName, bool addAtoms)
{
    uint idx= mol->getLastMOId();
    addViewsChildItems(itemMolecule,mol,ObName,addAtoms,idx);
}

void FileTree::addViewsChildItems(QTreeWidgetItem * itemMolecule, HMol *  mol, QString ObName, bool addAtoms, uint idx)
{
    //the first time, Atoms should be added
    if (addAtoms) {
        QTreeWidgetItem *itemAoms = new QTreeWidgetItem(itemMolecule,QStringList(QString("Atoms")));
        itemMolecule->addChild(itemAoms);
        itemAoms->setForeground(0,QBrush(QColor("#546892")));
        itemAoms->setCheckState(0,Qt::Checked); //item1->setText(1,"true");
        itemAoms->setTextColor(0,Qt::blue);
        itemAoms->setText(1,QString ("%1").arg(mol->getIdx()));
        itemAoms->setText(2,QString ("Atoms"));
        itemAoms->setTextColor(0,Qt::blue);
    }


    QTreeWidgetItem * itemOB = new QTreeWidgetItem(itemMolecule,QStringList(ObName));
    itemOB->setFlags(itemOB->flags() | Qt::ItemIsEditable);
    itemOB->setBackgroundColor(0,QColor("#e5ebf4"));
    itemMolecule->addChild(itemOB);

    itemOB->setForeground(0,QBrush(QColor("#546892")));
    itemOB->setCheckState(0,Qt::Checked); //item1->setText(1,"true");
    itemOB->setTextColor(0,Qt::blue);

    //store the index of molecule and  this orbital
    itemOB->setText(1,QString ("%1").arg(mol->getIdx())); //store id of molecule
    itemOB->setText(2,QString ("%1").arg(idx)); //store id of orbitale
}


int FileTree::getMoleculeId(QTreeWidgetItem *item)
{
        //QTreeWidgetItem * ancestor=nullptr;
        int idx=-1;

        QString key = item->text(0);

        if (key == "Atoms")
            return (item->text(1).toInt());


        if (item->text(2)=="root")
            return item->text(1).toInt();

        return idx;
}

int FileTree::getMOId(QTreeWidgetItem *item)
{
    //QTreeWidgetItem * ancestor=nullptr;
    int idx=-1;

    QString key = item->text(0);
    if (key == "Atoms"){
         return -1;
    }

    if (item->text(2)=="root")
         return -1;

    return item->text(2).toInt();
}


HMol * FileTree::getActivedMol()
{
    return getMol (idx_mol);
}

void FileTree::showActiveMolObtialNegativeLobe(bool t)
{
    HMol * mol = getActivedMol();

    for (int i=0;i<mol->NOrbitals();i++)
    {
        if (!mol->getObtial(i)->isVisible()) continue;
         mol->getObtial(i)->setNegLobeVisible(t);
    }
}





void FileTree::showActiveMolObtialPositiveLobe(bool t)
{
    HMol * mol = getActivedMol();

    for (int i=0;i<mol->NOrbitals();i++)
    {
        if (!mol->getObtial(i)->isVisible()) continue;
         mol->getObtial(i)->setPosLobeVisible(t);
    }
}

void FileTree::setActiveMolObitalType(uint t)
{
    switch (t){
        case 0: orbital_type=FULL;break;
        case 1: orbital_type=XOY; break;
        case 2: orbital_type=XOZ;break;
        case 3: orbital_type=YOZ;break;
        case 4: orbital_type=Wedge;break;
        case 5: orbital_type=Quarter;break;
        case 6: orbital_type=Corner;break;
    }


    HMol * mol = getActivedMol();

    for (int i=0;i<mol->NOrbitals();i++)
    {
        if (!mol->getObtial(i)->isVisible()) continue;

         mol->getObtial(i)->SetOrbitaType(t);

         if (mol->getObtial(i)->isHybridizedOrbital || mol->getObtial(i)->isMolecularOrbital)
            mol->getObtial(i)->buildMOIsosurface();
         else {
            mol->getObtial(i)->buildIsosurface();
            //mol->getObtial(i)->buildYlmSurfaceData();
         }

    }
}


void FileTree::setActiveMolObitalMesh(bool isMesh)
{
    HMol * mol = getActivedMol();
    isObtialMesh=isMesh;

    for (int i=0;i<mol->NOrbitals();i++)
    {
        if (!mol->getObtial(i)->isVisible()) continue;

         mol->getObtial(i)->setActiveMolObitalMesh(isMesh);
    }
}


void FileTree::showActiveMolObitalRadialNodeType(bool t)
{
    HMol * mol = getActivedMol();

    //if( mol->isAllInVisible() ) return;
    if (mol==nullptr) return;

    for (int i=0;i<mol->NOrbitals();i++)
    {
        if (!mol->getObtial(i)->isVisible())continue;

         mol->getObtial(i)->setVisible_radial_node(t);

    }
    visible_radial_node=t;
}

void FileTree::showActiveMolObitalAngularNodeType(bool t)
{
    HMol * mol = getActivedMol();

    if (mol==nullptr) return;
    //if( mol->isAllInVisible() ) return;

    for (int i=0;i<mol->NOrbitals();i++)
    {
        if (!mol->getObtial(i)->isVisible())continue;

         mol->getObtial(i)->setVisible_angular_node(t);
    }

    visible_angular_node=t;
}







void FileTree::updateSelection(QTreeWidgetItem *item)
{
    //the root of molecule
    bool modified=false;
    if (! item->parent())
    {
        //set blue itself
        item->setTextColor(0,Qt::blue); //set this root blue
        idx_mol=item->text(1).toInt();

        //set brother black
        QTreeWidgetItemIterator it (this);
        while (*it)
        {
            if ( (*it)->text(2) == "root")
            if ( (*it)->text(1).toInt()!=idx_mol  )
            {
                    (*it)->setTextColor(0,Qt::black);
                     modified=true;
            }
            ++it;
         }

        //if (!modified) return;
        HMol * mol = getMol (idx_mol);

        getMainWindow()->refreshAllViews(mol); //refresh all views
        return;
    }



    //only dispose the first branch
    HMol * mol = nullptr;
    HMO *  mo  = nullptr;


    //The first branch
    if (! item->parent()->parent() )
    {
        if ( item->text(0) == "Atoms")
        {
            bool visible_Atom=false;
            item->parent()->setTextColor(0,Qt::blue);

            if (item->checkState(0)){
                 item->setCheckState(0,Qt::Unchecked);
                 item->setTextColor(0,Qt::black);
                 visible_Atom=false;
            }

            else {
                 item->setCheckState(0,Qt::Checked);
                 item->setTextColor(0,Qt::blue);
                 visible_Atom=true;
            }

            idx_mol=item->text(1).toInt();
            mol = getMol (idx_mol);
            mol->setAtomsVisible(visible_Atom);



            if (visible_Atom)
            {
                item->parent()->setTextColor(0,Qt::blue);
            }
/*            else {
                bool isAllInvisible=true;
                for  (int i = 0; i < item->parent()->childCount(); ++i)
                {
                       if (item->parent()->child(i)->checkState(0)==Qt::Checked){
                           isAllInvisible=false;
                           break;
                       }
                }
                if (isAllInvisible) {
                   item->parent()->setTextColor(0,Qt::black);
                   mol->setAllInVisible(true);
                }
                else {
                    mol->setAllInVisible(false);
                    item->parent()->setTextColor(0,Qt::blue);
                }
            }
*/
            getMainWindow()->refreshAllViews(mol); //refresh atom
            return;
        }

        else {

            bool visible_MO=false;
            item->parent()->setTextColor(0,Qt::blue);

            if (item->checkState(0)){
                 item->setCheckState(0,Qt::Unchecked);
                 item->setTextColor(0,Qt::black);
                 visible_MO=false;

            }
            else {
                 item->setCheckState(0,Qt::Checked);
                 item->setTextColor(0,Qt::blue);
                 visible_MO=true;
            }

            idx_mol=item->text(1).toInt();
            idx_mo=item->text(2).toInt();
            mol = getMol (idx_mol);
            mo = getMO(idx_mol,idx_mo);


            if (visible_MO)
            {
                item->parent()->setTextColor(0,Qt::blue);
                mo->setVisible(true);
            }
            else {
                mo->setVisible(false);
                bool isAllInvisible=true;
                for  (int i = 0; i < item->parent()->childCount(); ++i)
                {
                    //cout << item->parent()->child(i)->text(0).toStdString().c_str()<<endl;
                       if (item->parent()->child(i)->checkState(0)==Qt::Checked){
                           isAllInvisible=false;
                           break;
                       }
                }
                if (isAllInvisible) {
                   item->parent()->setTextColor(0,Qt::black);
                   mol->setAllInVisible(true);
                }
                else {
                    mol->setAllInVisible(false);
                    item->parent()->setTextColor(0,Qt::blue);
                }
            }

            getMainWindow()->refreshAllViews(mol);
        }
    }

}



void FileTree::setSettingsObject(const SettingsPtr &newSettings)
{
    settings = newSettings;
    clear();

    if (settings.isNull()) {
        refreshTimer.stop();
    } else {
        refresh();
        if (autoRefresh)
            refreshTimer.start();
    }
}

QSize FileTree::sizeHint() const
{
    const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
    return QSize(availableGeometry.width() * 2 / 3, availableGeometry.height() * 2 / 3);
}

void FileTree::setAutoRefresh(bool autoRefresh)
{
    this->autoRefresh = autoRefresh;
    if (!settings.isNull()) {
        if (autoRefresh) {
            maybeRefresh();
            refreshTimer.start();
        } else {
            refreshTimer.stop();
        }
    }
}

void FileTree::setFallbacksEnabled(bool enabled)
{
    if (!settings.isNull()) {
        settings->setFallbacksEnabled(enabled);
        refresh();
    }
}

void FileTree::maybeRefresh()
{
    if (state() != EditingState)
        refresh();
}


void FileTree::refresh()
{
    if (settings.isNull())
        return;

    disconnect(this, &QTreeWidget::itemChanged,
               this, &FileTree::updateSetting);

    settings->sync();
    updateChildItems(0);

    connect(this, &QTreeWidget::itemChanged,
            this, &FileTree::updateSetting);
}

/*
bool FileTree::event(QEvent *event)
{
    if (event->type() == QEvent::WindowActivate) {
        if (isActiveWindow() && autoRefresh)
            maybeRefresh();
    }
    return QTreeWidget::event(event);
}
*/




void FileTree::updateSetting(QTreeWidgetItem *item)
{
    QString key = item->text(0);

    QTreeWidgetItem *ancestor = item->parent();
    while (ancestor) {
        key.prepend(ancestor->text(0) + QLatin1Char('/'));
        ancestor = ancestor->parent();
    }

    settings->setValue(key, item->data(2, Qt::UserRole));
    if (autoRefresh)
        refresh();

}


void FileTree::updateChildItems(QTreeWidgetItem *parent)
{
    int dividerIndex = 0;

    foreach (QString group, settings->childGroups()) {
        QTreeWidgetItem *child;
        int childIndex = findChild(parent, group, dividerIndex);
        if (childIndex != -1) {
            child = childAt(parent, childIndex);
            child->setText(1, QString());
            child->setText(2, QString());
            child->setData(2, Qt::UserRole, QVariant());
            moveItemForward(parent, childIndex, dividerIndex);
        } else {
            child = createItem(group, parent, dividerIndex);
        }
        child->setIcon(0, groupIcon);
        ++dividerIndex;

        settings->beginGroup(group);
        updateChildItems(child);
        settings->endGroup();
    }

    foreach (const QString &key, settings->childKeys()) {
        QTreeWidgetItem *child;
        int childIndex = findChild(parent, key, 0);

        if (childIndex == -1 || childIndex >= dividerIndex) {
            if (childIndex != -1) {
                child = childAt(parent, childIndex);
                for (int i = 0; i < child->childCount(); ++i)
                    delete childAt(child, i);
                moveItemForward(parent, childIndex, dividerIndex);
            } else {
                child = createItem(key, parent, dividerIndex);
            }
            child->setIcon(0, keyIcon);
            ++dividerIndex;
        } else {
            child = childAt(parent, childIndex);
        }

        QVariant value = settings->value(key);
        if (value.type() == QVariant::Invalid) {
            child->setText(1, "Invalid");
        } else {
            child->setText(1, value.typeName());
        }
        //child->setText(2, VariantDelegate::displayText(value));
        child->setData(2, Qt::UserRole, value);
    }

    while (dividerIndex < childCount(parent))
        delete childAt(parent, dividerIndex);
}


QTreeWidgetItem *FileTree::createItem(const QString &text,
                                          QTreeWidgetItem *parent, int index)
{
    QTreeWidgetItem *after = 0;
    if (index != 0)
        after = childAt(parent, index - 1);

    QTreeWidgetItem *item;
    if (parent)
        item = new QTreeWidgetItem(parent, after);
    else
        item = new QTreeWidgetItem(this, after);

    //

    item->setText(0, text);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    return item;
}

QTreeWidgetItem *FileTree::childAt(QTreeWidgetItem *parent, int index)
{
    if (parent)
        return parent->child(index);
    else
        return topLevelItem(index);
}


int FileTree::childCount(QTreeWidgetItem *parent)
{
    if (parent)
        return parent->childCount();
    else
        return topLevelItemCount();
}

int FileTree::findChild(QTreeWidgetItem *parent, const QString &text,
                            int startIndex)
{
    for (int i = startIndex; i < childCount(parent); ++i) {
        if (childAt(parent, i)->text(0) == text)
            return i;
    }
    return -1;
}

void FileTree::moveItemForward(QTreeWidgetItem *parent, int oldIndex,
                                   int newIndex)
{
    for (int i = 0; i < oldIndex - newIndex; ++i)
        delete childAt(parent, newIndex);
}


void FileTree::reMoveAllItems()
{
    //find the item of the Atom
    QTreeWidgetItemIterator itemFirstBranches (this);
    while (*itemFirstBranches)
    {
       if ( (*itemFirstBranches)->text(1)=="root") {

           for (int i = 0; i < (*itemFirstBranches)->childCount(); ++i) {
               if  ((*itemFirstBranches)->child(i)->text(1)=="Atoms") {
                   delete (*itemFirstBranches)->child(i);
                   continue;
               }

               for (int j = 0; j < (*itemFirstBranches)->child(i)->childCount(); ++j)
                   delete (*itemFirstBranches)->child(i)->child(j);

           }
        }
        ++itemFirstBranches;
     }
}


void FileTree::removeAllMolecules()
{
    uint size = Molecules.size();
    if (size<1) return;

    while (size--)
    {
        if (Molecules[size]!=nullptr) {
            Molecules[size]->clearAll();
        }
    }
}


void FileTree::OnPopMenu(const QPoint & pos)
{
    QTreeWidgetItem * curItem=currentItem();
    if(curItem==nullptr)return;

    QString itemName = curItem->text(0);


    //the first branch
    if ( curItem->text(0) == "Atoms")
            return;


    //the first branch
    if (curItem->parent()==nullptr ) return;

    if( curItem->parent()->parent()==nullptr )
    {
        //QAction changeNameAction(QString::fromLocal8Bit("ChangeName"),this);
        QAction removeSelectedAction(QString::fromLocal8Bit("Remove"),this);
        //QAction removeAllAction (QString::fromLocal8Bit("RemoveAll"),this);

        //connect(&changeNameAction, SIGNAL(triggered()), this, SLOT(OnChangeName()));
        //connect(&removeAllAction, SIGNAL(triggered()), this, SLOT(OnRemoveAll()));
        connect(&removeSelectedAction,SIGNAL(triggered()),this,SLOT(OnRemove()));

        QMenu menu(this);
        //menu.addAction(&changeNameAction);
        menu.addAction(&removeSelectedAction);
        //menu.addAction(&removeAllAction);
        menu.exec(QCursor::pos());
    }
}

void FileTree::OnChangeName()
{
    //item->setText();
}


void FileTree::OnRemove()
{
    QTreeWidgetItem * item=currentItem();
    if(item==nullptr) return;

    QString itemName = item->text(0);


    //the first branch
    if (item->parent())
    {
        uint icount=item->parent()->childCount();
        uint idx = item->parent()->indexOfChild(item);

        idx_mol=item->text(1).toInt();
        idx_mo=item->text(2).toInt();

        HMol * mol = getMol (idx_mol);
        HMO *  mo  = getMO(idx_mol,idx_mo);

        if (mol==nullptr || mo==nullptr) return;

        // only one orbital of this root

        cout << icount << " inside OnRemove()"<<endl;

        if (icount==2) //remove all of this root
        {
            QString name=item->parent()->text(0)+"-"+item->text(0);
            //cout <<name.toStdString().c_str()<<endl;

            if (NameLists.size()==1)   NameLists.clear();
            else
                for (int k = 0; k < NameLists.size(); k++)
                {
                    if (NameLists[k] == name) {
                        NameLists.erase(NameLists.begin()+k);
                    }
                }


            if (AtomLabels.size()==1)   AtomLabels.clear();
            else
                for (int k = 0; k < AtomLabels.size(); k++)
                {
                    if (AtomLabels[k] == item->parent()->text(0)) {
                        AtomLabels.erase(AtomLabels.begin()+k);
                    }
                }


            int childIndex=indexOfTopLevelItem(item);
            if(childIndex==-1)
                 childIndex = item->parent()->indexOfChild(item);
            int parentIndex=indexOfTopLevelItem(item->parent());

            delete item->parent()->takeChild(childIndex);
            takeTopLevelItem(parentIndex);


            getMainWindow()->removeOrbitalfromMesh3D(mol);

            mol->clearAll();
            for (int i = 0; i < Molecules.size(); i++)
            {
                if (i!=idx_mol) continue;
                Molecules.erase(Molecules.begin()+i);
            }


            mol=getLastMol();
            if (mol!=nullptr)
                getMainWindow()->refreshAllViews(mol);
            else
                getMainWindow()->clearAllViews();

            return;
        }



        //more than one orbital
        if (icount>2) //remove this orbital/item
        {
            QString name=item->parent()->text(0)+"-"+item->text(0);

            if (NameLists.size()==1)   NameLists.clear();
            else
                for (int k = 0; k < NameLists.size(); k++)
                {
                    if (NameLists[k] == name) {
                        NameLists.erase(NameLists.begin()+k);
                        //NameLists.resize(NameLists.size()-1);
                    }
                }


            delete item->parent()->takeChild(idx);
            mol->removeOrbital(idx_mo);

            getMainWindow()->removeOrbitalfromMesh3D(mol,idx_mo);
            getMainWindow()->refreshAllViews(mol);

        }
    }

}



void FileTree::OnRemoveAll()
{
    if (NameLists.size()<1) return;
    NameLists.clear();
    removeAllMolecules();
    AtomLabels.clear();
    this->clear();
    Molecules.clear();

    getMainWindow()->clearAllViews();
}

