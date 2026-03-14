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

#include "mainwindow.h"
#include "matrix3/vector3.h"
#include "orbitalProperty.h"

#include <vtkCamera.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkDataSetMapper.h>
#include <QVTKOpenGLWidget.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkDataSet.h>



MainWindow::MainWindow()  : mdiArea(new QMdiArea)
{
    ui.setupUi (this);
    ui.mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui.mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    QString ss(0X03A8);
    ui.label_psi->setText(ss);

   // setCentralWidget(ui.mdiArea);
  //  connect(ui.mdiArea, &QMdiArea::subWindowActivated,           this, &MainWindow::updateMenus);

   // createActions();
  //  createStatusBar();
  //  updateMenus();
   // readSettings();

   // setWindowTitle(tr("MDI"));
   // setUnifiedTitleAndToolBarOnMac(true);

    //ui.lineEdit_AX->setText("0.0");
    //ui.lineEdit_AY->setText("0.0");
    //ui.lineEdit_AZ->setText("0.0");


    ui.spinBox_n->setMaximum(6);
    ui.spinBox_l->setRange(0,5);
    ui.spinBox_m->setRange(-5,5);

    connect(ui.spinBox_n,SIGNAL(valueChanged(int )),this, SLOT (onChanged_n(int)) );
    connect(ui.spinBox_l,SIGNAL(valueChanged(int )),this, SLOT (onChanged_l(int)) );
    connect(ui.spinBox_m,SIGNAL(valueChanged(int )),this, SLOT (onChanged_m(int)) );


    n=1,l=0,m=0;
    ui.spinBox_n->setValue(n);
    ui.spinBox_l->setValue(l);
    ui.spinBox_l->setValue(m);



    connect(ui.comboBox_AOrbital,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onAOSeletedChanged()) );


    connect(ui.pushButton_addOrbital,SIGNAL(clicked()),
            this, SLOT(onAddOrbital()) );


    connect(ui.actionCascade, &QAction::triggered, ui.mdiArea, &QMdiArea::cascadeSubWindows);

    connect(ui.actionTitles, &QAction::triggered, ui.mdiArea, &QMdiArea::tileSubWindows);


    connect(ui.actionPsi3D_Active,  SIGNAL(triggered()),  this,SLOT(on3DViewActive()) );
    connect(ui.actionPsi3DProj_Active, SIGNAL(triggered()),  this,SLOT(on3DProjActive()) );
    connect(ui.actionRadial_Active, SIGNAL(triggered()),  this,SLOT(onRadialFuncActive()) );
    //connect(ui.actionOutput_Active, SIGNAL(triggered()),  this,SLOT(onInformActive()) );



    connect(ui.checkBox_OB_xoy,SIGNAL(clicked()),
            this,SLOT(onObtialXOY()) );

    connect(ui.checkBox_OB_xoz,SIGNAL(clicked()),
            this,SLOT(onObtialXOZ()) );

    connect(ui.checkBox_OB_yoz,SIGNAL(clicked()),
            this,SLOT(onObtialYOZ()) );


    connect(ui.checkBox_OB_corner,SIGNAL(clicked()),
            this,SLOT(onObtialCorner()) );

    connect(ui.checkBox_OB_quarter,SIGNAL(clicked()),
            this,SLOT(onObtialQuarter()) );

    connect(ui.checkBox_OB_widge,SIGNAL(clicked()),
            this,SLOT(onObtialWidge()) );

    connect(ui.checkBox_OB_smooth,SIGNAL(clicked()),
            this,SLOT(onObtialSmooth()) );

    connect(ui.checkBox_OB_mesh,SIGNAL(clicked()),
            this,SLOT(onObtialMesh()) );

    connect(ui.checkBox_NT_angular,SIGNAL(clicked()),
            this,SLOT(onShownObtialAngularNode()) );

    connect(ui.checkBox_NT_Radial,SIGNAL(clicked()),
            this,SLOT(onShownObtialRadialNode()) );

    connect(ui.checkBox_OB_positive,SIGNAL(clicked()),
            this,SLOT(onShownObtialPositiveLobe()) );
    connect(ui.checkBox_OB_negative,SIGNAL(clicked()),
            this,SLOT(onShownObtialNegativeLobe()) );


    connect(ui.actionbuild_Molecular_Orbital,SIGNAL(triggered()),
            this,SLOT(onBuildMO()) );


     //init FileTree
     ui.treeWidget->setColumnCount(1);
     ui.treeWidget->setHeaderLabel(tr("File"));
     ui.treeWidget->setHeaderHidden(true);
     QPalette p(ui.treeWidget->palette());
     p.setColor(QPalette::Base, QColor("#ced9e6"));
     ui.treeWidget->setPalette(p);
     ui.treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);


     //initial several views
     infoview = new TextEditor ();
     mesh3d = new Mesh3D(this);
     //calculator= new QCalculator(this);
     angularY3d=new Angular3D(this);
     view3d = new View3D(this);

     cloud3d= new Cloud3D(this);

     ui.RDFViewer->parent=this;
     ui.tabWidget->setCurrentWidget(ui.tab_mdi);


     //ui.mdiArea->addSubWindow(infoview);
     //infoview->show();
     //ui.mdiArea->addSubWindow(Rview);
    // Rview->show();



     ui.mdiArea->addSubWindow(mesh3d);
     mesh3d->show();

     ui.mdiArea->addSubWindow(angularY3d);
     mesh3d->show();

     ui.mdiArea->addSubWindow(cloud3d);
     cloud3d->show();


     ui.mdiArea->addSubWindow(view3d);
     view3d->show();

     ui.mdiArea->tileSubWindows();

     ui.checkBox_OB_mesh->setCheckState(Qt::Checked);
     ui.checkBox_OB_positive->setCheckState(Qt::Checked);
     ui.checkBox_OB_negative->setCheckState(Qt::Checked);

     ui.checkBox_R->setCheckState(Qt::Checked);
     ui.checkBox_R2->setCheckState(Qt::Checked);
     ui.checkBox_RDF->setCheckState(Qt::Checked);

     ui.spinBox_angle->setValue(10);

     ui.comboBox_OB_cossin->setEnabled(false);


     /*
     //bottom widget
     setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
     QDockWidget* bottomWidget = new QDockWidget(this);
     this->addDockWidget(Qt::BottomDockWidgetArea, bottomWidget, Qt::Horizontal);
     bottomWidget->setBaseSize(100,100);


     //!add tab widget
     QTabWidget *  tabWidget_1 =  new QTabWidget (this);
     tabWidget_1->setTabPosition (QTabWidget::South);
     bottomWidget->setWidget(tabWidget_1);
     bottomWidget->setMinimumHeight (100);
     tabWidget_1-> addTab(infoview,  QIcon( QPixmap(":images/console.png" )), tr("Message"));
     tabWidget_1->addTab(calculator,  QIcon( QPixmap(":images/console.png" )), tr("Calculator"));

     bottomWidget->setMinimumHeight (100);

     */
}




void MainWindow::sendMessage(QString & m_message)
{
    if(!infoview) return;
    //m_message=">>"+m_message;
    infoview->displayMessage(m_message.toLatin1(),false, true);
    //TextEditor::display(const char *line,bool is_error,bool newline)
}

void MainWindow::appendMessage(QString & m_message)
{
    if(!infoview) return;
    infoview->displayMessage(m_message.toLatin1(),false, true);
    infoview->displaySpaceLine();
    //infoview->append(m_message);
    //TextEditor::display(const char *line,bool is_error,bool newline)
}



//parse atom orbital name to n/l/m
void MainWindow::onAOSeletedChanged()
{
    AOrbitalName=ui.comboBox_AOrbital->currentText();

    //sp,sp2,sp3,dsp2,dsp3,d2sp3
    if (AOrbitalName.startsWith("SP") || AOrbitalName.startsWith("DSP") || AOrbitalName.startsWith("D2SP3"))
    {
        ui.spinBox_n->setValue(1);
        ui.spinBox_l->setValue(0);
        ui.spinBox_m->setValue(0);
        return;
    }

    // 1S,2S,3S,4S,5S,6S
    // 2P,3P,4P,5P,6P
    // 3D,4D, 5D,6D
    // 4F,5F,6F
    // 5G, 6G

    QChar first=AOrbitalName[0],
          second=AOrbitalName[1];

    if (first.isDigit()) {
        n=AOrbitalName[0].digitValue();
    }

    second.toUpper();

    if (second=="S" )         l=0;
    else if (second=="P")     l=1;
    else if (second=="D")     l=2;
    else if (second=="F")     l=3;
    else if (second=="G")     l=4;
    else if (second=="H")     l=5;
    else l=0;


    QString name=AOrbitalName;
    name.remove(0,1);

    //S
    m=0;

    //P
    if (name.startsWith("Pz"))          m=0;
    else if (name.startsWith("Px"))     m=1;
    else if (name.startsWith("Py"))     m=-1;

    //D
    else if (name.startsWith("Dz2"))        m=0;
    else if (name.startsWith("Dxz"))        m=1;
    else if (name.startsWith("Dyz"))        m=-1;
    else if (name.startsWith("Dxy"))        m=2;
    else if (name.startsWith("Dx2-y2"))        m=-2;


    //F
    else if (name.startsWith("Fz3"))
        m=0;
    else if (name.startsWith("Fxz2"))
        m=1;
    else if (name.startsWith("Fyz2"))
        m=-1;
    else if (name.startsWith("Fz(x2-y2)") || name.startsWith("F(x2-y2)z"))
        m=2;
    else if (name.startsWith("Fzxy") || name.startsWith("Fxyz"))
        m=-2;
    else if (name.startsWith("Fx(x2-3y2)"))
        m=3;
    else if (name.startsWith("Fy(3x2-y2"))
        m=-3;




    //G
    else if (name.startsWith("Gz4"))
        m=0;

    else if (name.startsWith("Gz3x")  || name.startsWith("Gxz3"))
        m=1;

    else if (name.startsWith("Gz3y")  || name.startsWith("Gyz3"))
        m=-1;


    else if (name.startsWith("Gz2(x2-y2)") || name.startsWith("G(x2-y2)z2") )
        m=2;

    else if (name.startsWith("Gz2xy") || name.startsWith("Gxyz2"))
        m=-2;



    else if (name.startsWith("Gzx3") || name.startsWith("Gx3z"))
        m=3;

    else if (name.startsWith("Gzy3") || name.startsWith("Gy3z"))
        m=-3;

    else if (name.startsWith("Gxy(x2-y2)"))
        m=-4;

    else if (name.startsWith("G(x4+y4)"))
        m=4;







    ui.spinBox_n->setValue(n);
    ui.spinBox_l->setValue(l);
    ui.spinBox_m->setValue(m);


    ui.comboBox_OB_cossin->setCurrentIndex(0);
    if(m>0)  ui.comboBox_OB_cossin->setCurrentIndex(1);
    if(m<0) ui.comboBox_OB_cossin->setCurrentIndex(2);

}



void MainWindow::onChanged_n(int _n)
{
    n=_n;
    if (n<1) return;

    ui.spinBox_l->setRange(0,n-1);
    onChanged_nlm();
}


void MainWindow::onChanged_l(int _l)
{
    l=_l;
    ui.spinBox_m->setRange(-l,l);
    onChanged_nlm();
}


void MainWindow::onChanged_m(int _m)
{
    m=_m;
    onChanged_nlm();
}


void MainWindow::onChanged_nlm()
{
    //QMessageBox::information(0, "Warning",AOName+" atom orbital!");

    //n=ui->spinBox_n->value();
    //l=ui->spinBox_l->value();
    //m=ui->spinBox_m->value();

    QString Name;

    if (l==0 )    Name="S";

    else if (l==1) //P
    {
           if (m==0) Name="Pz"; //0
           if (m>0)  Name="Px"; //1
           if (m<0)  Name="Py"; //-1
    }

    else if (l==2){ //D
           if       (m==0)   Name="Dz2"; //0

           else  if (m==1)   Name="Dxz"; //1
           else  if (m==-1)  Name="Dyz"; //-1

           else  if (m==2)   Name="Dxy"; //2
           else  if (m==-2)  Name="Dx2-y2"; //-2
    }

    else if (l==3){ //F
           if       (m==0)   Name="Fz3"; //0
           else  if (m==1)   Name="Fxz2"; //1
           else  if (m==-1)  Name="Fyz2"; //-1

           else  if (m==2)   Name="Fz(x2-y2)"; //2
           else  if (m==-2)  Name="Fzxy"; //-2

           else  if (m==3)   Name="Fx(x2-3y2)"; //3
           else  if (m==-3)  Name="Fy(3x2-y2)"; //-3
    }

    else if (l==4){ //G

        if       (m==0)    Name="Gz4"; //0

        else  if (m==1)    Name="Gxz3"; //1
        else  if (m==-1)   Name="Gyz3"; //-1

        else  if (m==2)    Name="G(x2-y2)z2"; //2
        else  if (m==-2)   Name="Gxyz2"; //2


        else  if (m==3)    Name="Gx3z"; //3
        else  if (m==-3)   Name="Gy3z"; //-3

        else  if (m==-4)   Name="Gxy(x2-y2)"; //-4
        else  if (m==4)    Name="G(x4+y4)"; //4
    }




    AOrbitalName.clear();
    AOrbitalName.setNum(n);
    AOrbitalName=AOrbitalName+Name;

    int idx=ui.comboBox_AOrbital->findText(AOrbitalName);

    if(idx> -1)
        ui.comboBox_AOrbital->setCurrentIndex(idx);
    else
    {
        ui.comboBox_AOrbital->insertItem(0,AOrbitalName);
        ui.comboBox_AOrbital->setCurrentIndex(0);
    }

    ui.comboBox_OB_cossin->setCurrentIndex(0);
    if(m>0)  ui.comboBox_OB_cossin->setCurrentIndex(1); //cos-type
    if(m<0) ui.comboBox_OB_cossin->setCurrentIndex(2);  //sin-type
}

void MainWindow::onBuildOrbital()
{
   // ui.glArea->mol.addAtom(a.at(0),  pos,  n,  l,  m,  scale, name);
   // ui.glArea->mol.isHybridizedOrb=false;

   // ui.glArea->mol.CalcBonds();
   // ui.glArea->buildIsosurface();
   // ui.glArea->update();
}

void MainWindow::newFile()
{
    /*
     infoview = new TextEditor ();
     //ui.mdiArea->addSubWindow(infoview);

     Rview = new RadialFunViewer(this);
     //ui.mdiArea->addSubWindow(Rview);

     view3d = new View3D(this);
     //ui.mdiArea->addSubWindow(view3d);
     */

    ui.treeWidget->OnRemoveAll();

}

void MainWindow::onAddOrbital()
{
    //QString symbol=ui.comboBox_Element->currentText();

    //QString x=ui.lineEdit_AX->text();
    //QString y=ui.lineEdit_AY->text();
    //QString z=ui.lineEdit_AZ->text();
    //vector3 pos(x.toDouble(),y.toDouble(),z.toDouble());

    QApplication::setOverrideCursor(Qt::WaitCursor);

    AOrbitalName=ui.comboBox_AOrbital->currentText();

    QString symbol="H";
    vector3 pos(0.0,0.0,0.0);


    if ( AOrbitalName=="SP"   || AOrbitalName=="SP2" || AOrbitalName=="SP3"  ||
         AOrbitalName=="DSP2" || AOrbitalName=="DSP3" || AOrbitalName=="D2SP3" )
    {
        ui.treeWidget -> NewHybridizedObitals (symbol, AOrbitalName, pos);
        mesh3d->generateObital(ui.treeWidget -> getLastMol());
    }
    else {
        ui.treeWidget -> NewAOObitals (symbol, AOrbitalName, pos);
        ui.RDFViewer->renderMol(ui.treeWidget -> getLastMol());
        ui.RDFViewer->update();
        mesh3d->generateObital(ui.treeWidget -> getLastMol());
    }


    view3d->renderMol(ui.treeWidget -> getLastMol());
    angularY3d->renderMol(ui.treeWidget -> getLastMol());
    cloud3d->renderMol(ui.treeWidget -> getLastMol());
    mesh3d->renderMol(ui.treeWidget -> getLastMol());

    QApplication::restoreOverrideCursor();
}


void MainWindow::actionShow3D()
{
    view3d->show();
    view3d->GetRenderWindow()->Render();
    view3d->setFocus();
}


//parse atom orbital name to n/l/m
void MainWindow::initFileTree()
{
    ui.treeWidget->setColumnCount(1);
    ui.treeWidget->setHeaderLabel(tr("File"));
    ui.treeWidget->setHeaderHidden(true);
    QPalette p(ui.treeWidget->palette());
    p.setColor(QPalette::Base, QColor("#ced9e6"));
    ui.treeWidget->setPalette(p);
}




void MainWindow::onRotate()
{
    /*
    float x,y,z, err=0.0000001;
    x=(ui.lineEdit_x->text()).toFloat();
    y=(ui.lineEdit_y->text()).toFloat();
    z=(ui.lineEdit_z->text()).toFloat();

    if ( abs(x) < err && abs(y) < err && abs(z) < err) {
        QMessageBox::information(0, "Warning","Please input rotation degree!");
        return;
    }

    if ( abs(x) > err && abs(y) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    if ( abs(y) > err && abs(z) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    if ( abs(x) > err && abs(z) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }


    vector3 v(0.0,0.0,0.0);

    if ( abs(x) > err) {
        v.SetX(1.0);
        //ui.glArea->mol.rotate(v,x);
    }

    if ( abs(y) > err) {
        v.SetY(1.0);
        //ui.glArea->mol.rotate(v,y);
    }

    if ( abs(z) > err) {
        v.SetZ(1.0);
       // ui.glArea->mol.rotate(v,z);
    }

  //  ui.glArea->update();
  */
}

void MainWindow::onTranslate()
{
    /*
    float x,y,z, err=0.0000001;
    x=(ui.lineEdit_x->text()).toFloat();
    y=(ui.lineEdit_y->text()).toFloat();
    z=(ui.lineEdit_z->text()).toFloat();

    if ( abs(x) < err && abs(y) < err && abs(z) < err) {
        QMessageBox::information(0, "Warning","Please input rotation degree!");
        return;
    }

    if ( abs(x) > err && abs(y) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    if ( abs(y) > err && abs(z) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    if ( abs(x) > err && abs(z) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    vector3 v(x,y,z);
    //ui.glArea->mol.translate(v);
    //ui.glArea->update();
    */
}

void MainWindow::onCenterMol()
{
   // ui.glArea->mol.centeralize();
    //ui.glArea->update();
}


void MainWindow::removeOrbitalfromMesh3D(HMol * mol, uint idx)
{
     mesh3d->removeOrbital(mol,idx);
}
void MainWindow::removeOrbitalfromMesh3D(HMol * mol)
{
     mesh3d->removeOrbital(mol);
}

void MainWindow::clearAllViews()
{
    view3d->removeAllActors();
    view3d->GetRenderWindow()->Render();

    mesh3d->removeAllActors();
    mesh3d->GetRenderWindow()->Render();

    angularY3d->removeAllActors();
    angularY3d->GetRenderWindow()->Render();

    cloud3d->removeAllActors();
    cloud3d->GetRenderWindow()->Render();

    ui.RDFViewer->removeSeries();
}

void MainWindow::refreshAllViews(HMol * mol)
{
    if (  mol ==nullptr || !mol)       return;


    view3d->renderMol(mol);
    //view3d->GetRenderWindow()->Render();

    mesh3d->renderMol(mol);
    //mesh3d->GetRenderWindow()->Render();

    angularY3d->renderMol(mol);
    //angularY3d->GetRenderWindow()->Render();

    cloud3d->renderMol(mol);
    //cloud3d->GetRenderWindow()->Render();

    ui.RDFViewer->renderMol(mol);
}

void MainWindow::refreshCurrentView()
{
    if (!ui.treeWidget->hasMol()) {
        setAllObtialUnchecked();
        return;
    }

    refreshAllViews(ui.treeWidget->getActivedMol());
}

void MainWindow::onObtialXOY()
{


    if (!ui.treeWidget->hasMol()) {
        setAllObtialUnchecked();
        return;
    }

    if  (!ui.checkBox_OB_xoy->checkState())
        ui.treeWidget->setActiveMolObitalType(0);
    else {
        ui.checkBox_OB_xoz->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_yoz->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_corner->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_quarter->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_widge->setCheckState(Qt::Unchecked);

        ui.treeWidget->setActiveMolObitalType(1);

    }

    refreshAllViews(ui.treeWidget->getActivedMol());
}

void MainWindow::onObtialXOZ()
{

    if (!ui.treeWidget->hasMol()) {
        setAllObtialUnchecked();
        return;
    }


    if  (!ui.checkBox_OB_xoz->checkState())
        ui.treeWidget->setActiveMolObitalType(0);
    else {
        ui.checkBox_OB_xoy->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_yoz->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_corner->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_quarter->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_widge->setCheckState(Qt::Unchecked);

        //ui.treeWidget->setActiveMolObitalType(2);
    }

    refreshAllViews(ui.treeWidget->getActivedMol());
}

void MainWindow::onObtialYOZ()
{
    if (!ui.treeWidget->hasMol()) {
        setAllObtialUnchecked();
        return;
    }

    if  (!ui.checkBox_OB_yoz->checkState())
        ui.treeWidget->setActiveMolObitalType(0);
    else {
        ui.checkBox_OB_xoy->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_xoz->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_corner->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_quarter->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_widge->setCheckState(Qt::Unchecked);

        ui.treeWidget->setActiveMolObitalType(3);

    }

    refreshAllViews(ui.treeWidget->getActivedMol());

}

void MainWindow::setAllObtialUnchecked()
{
    ui.checkBox_OB_xoy->setCheckState(Qt::Unchecked);
    ui.checkBox_OB_xoz->setCheckState(Qt::Unchecked);
    ui.checkBox_OB_yoz->setCheckState(Qt::Unchecked);
    ui.checkBox_OB_corner->setCheckState(Qt::Unchecked);
    ui.checkBox_OB_widge->setCheckState(Qt::Unchecked);
    ui.checkBox_OB_quarter->setCheckState(Qt::Unchecked);

    ui.checkBox_NT_angular->setCheckState(Qt::Unchecked);
    ui.checkBox_NT_Radial->setCheckState(Qt::Unchecked);

}
void MainWindow::onObtialWidge()
{
    if (!ui.treeWidget->hasMol()) {
        setAllObtialUnchecked();
        return;
    }

    if  (!ui.checkBox_OB_widge->checkState())
        ui.treeWidget->setActiveMolObitalType(0);
    else {
         ui.checkBox_OB_xoy->setCheckState(Qt::Unchecked);
         ui.checkBox_OB_xoz->setCheckState(Qt::Unchecked);
         ui.checkBox_OB_yoz->setCheckState(Qt::Unchecked);
         ui.checkBox_OB_corner->setCheckState(Qt::Unchecked);
         ui.checkBox_OB_quarter->setCheckState(Qt::Unchecked);

         ui.treeWidget->setActiveMolObitalType(4);

    }

    refreshAllViews(ui.treeWidget->getActivedMol());
}

/*
    case 0: orbital_type=FULL;break;
    case 1: orbital_type=XOY; break;
    case 2: orbital_type=XOZ;break;
    case 3: orbital_type=YOZ;break;
    case 4: orbital_type=Wedge;break;
    case 5: orbital_type=Quarter;break;
    case 6: orbital_type=Corner;break;
*/

void MainWindow::onObtialQuarter(){

    if (!ui.treeWidget->hasMol()) {
        setAllObtialUnchecked();
        return;
    }

    if  (!ui.checkBox_OB_quarter->checkState())
        ui.treeWidget->setActiveMolObitalType(0);
    else {
        ui.checkBox_OB_xoy->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_xoz->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_yoz->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_corner->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_widge->setCheckState(Qt::Unchecked);

        ui.treeWidget->setActiveMolObitalType(5);
    }

    refreshAllViews(ui.treeWidget->getActivedMol());
}

void MainWindow::onObtialCorner()
{
    if (!ui.treeWidget->hasMol()) {
        setAllObtialUnchecked();
        return;
    }

    if  (!ui.checkBox_OB_corner->checkState())
        ui.treeWidget->setActiveMolObitalType(0);
    else {
        ui.checkBox_OB_xoy->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_xoz->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_yoz->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_quarter->setCheckState(Qt::Unchecked);
        ui.checkBox_OB_widge->setCheckState(Qt::Unchecked);

        ui.treeWidget->setActiveMolObitalType(6);
    }

    refreshAllViews(ui.treeWidget->getActivedMol());
}

void MainWindow::on3DViewActive()
{
    //QApplication::setOverrideCursor(Qt::WaitCursor);
    //view3d->renderMol(ui.treeWidget->getActivedMol());
    view3d->GetRenderWindow()->Render();
    view3d->setFocus();

    angularY3d->GetRenderWindow()->Render();
    //angularY3d->setFocus();

    //QApplication::restoreOverrideCursor();
}


void  MainWindow::on3DProjActive()
{
    mesh3d->GetRenderWindow()->Render();
    mesh3d->setFocus();
}

void  MainWindow::onRadialFuncActive()
{

}
void MainWindow::onInformActive()
{

}



void MainWindow::onShownObtialAngularNode()
{
    if (!ui.treeWidget->hasMol()) {
        setAllObtialUnchecked();
        return;
    }

    if  (ui.checkBox_NT_angular->checkState())
        ui.treeWidget->showActiveMolObitalAngularNodeType(true);
    else
        ui.treeWidget->showActiveMolObitalAngularNodeType(false);


    refreshAllViews(ui.treeWidget->getActivedMol());
}


void MainWindow::onShownObtialRadialNode()
{
    if (!ui.treeWidget->hasMol()) {
        setAllObtialUnchecked();
        return;
    }

    if  (ui.checkBox_NT_Radial->checkState())
        ui.treeWidget->showActiveMolObitalRadialNodeType(true);
    else
        ui.treeWidget->showActiveMolObitalRadialNodeType(false);

    refreshAllViews(ui.treeWidget->getActivedMol());
}



void MainWindow::onObtialSmooth()
{
    if  (ui.checkBox_OB_smooth->checkState()){
        ui.checkBox_OB_mesh->setCheckState(Qt::Unchecked);
        ui.treeWidget->setActiveMolObitalMesh(false);
    }
    else {
        ui.checkBox_OB_mesh->setCheckState(Qt::Checked);
        ui.treeWidget->setActiveMolObitalMesh(true);
    }

    view3d->renderMol(ui.treeWidget->getActivedMol());
    angularY3d->renderMol(ui.treeWidget->getActivedMol());
}

void MainWindow::onObtialMesh()
{
    if  (ui.checkBox_OB_mesh->checkState()){
        ui.checkBox_OB_smooth->setCheckState(Qt::Unchecked);
        ui.treeWidget->setActiveMolObitalMesh(true);
    }
    else {
         ui.checkBox_OB_smooth->setCheckState(Qt::Checked);
         ui.treeWidget->setActiveMolObitalMesh(false);
    }

    view3d->renderMol(ui.treeWidget->getActivedMol());
    angularY3d->renderMol(ui.treeWidget->getActivedMol());
}





void MainWindow::onShownObtialNegativeLobe()
{
    if  (ui.checkBox_OB_negative->checkState())
        ui.treeWidget->showActiveMolObtialNegativeLobe(true);
    else
        ui.treeWidget->showActiveMolObtialNegativeLobe(false);


    view3d->renderMol(ui.treeWidget->getActivedMol());
    angularY3d->renderMol(ui.treeWidget->getActivedMol());
    cloud3d->renderMol(ui.treeWidget->getActivedMol());
}


void MainWindow::onShownObtialPositiveLobe()
{
    if  (ui.checkBox_OB_positive->checkState())
        ui.treeWidget->showActiveMolObtialPositiveLobe(true);
    else
        ui.treeWidget->showActiveMolObtialPositiveLobe(false);

    view3d->renderMol(ui.treeWidget->getActivedMol());
    angularY3d->renderMol(ui.treeWidget->getActivedMol());
    cloud3d->renderMol(ui.treeWidget->getActivedMol());
}





void MainWindow::on_checkBox_R_stateChanged(int arg1)
{
    if (arg1)
        ui.RDFViewer->setRvisible(true);
    else
        ui.RDFViewer->setRvisible(false);

    ui.RDFViewer->renderMol(ui.treeWidget->getActivedMol());
}


void MainWindow::on_checkBox_R2_stateChanged(int arg1)
{
    if  (arg1)
        ui.RDFViewer->setR2visible(true);
    else
        ui.RDFViewer->setR2visible(false);

    ui.RDFViewer->renderMol(ui.treeWidget->getActivedMol());
}

void MainWindow::on_checkBox_RDF_stateChanged(int arg1)
{
    if (arg1)
        ui.RDFViewer->setRDFvisible(true);
    else
        ui.RDFViewer->setRDFvisible(false);

    ui.RDFViewer->renderMol(ui.treeWidget->getActivedMol());
}


void MainWindow::onBuildMO()
{
    ShowMOForm * moForm = new ShowMOForm (this);
    if (moForm!=nullptr) {
        moForm->setAttribute( Qt::WA_DeleteOnClose, true );
        moForm->exec();
    }
}




void MainWindow::closeEvent(QCloseEvent *event)
{/*
    mdiArea->closeAllSubWindows();
    if (mdiArea->currentSubWindow()) {
        event->ignore();
    } else {
        writeSettings();
        event->accept();
    }
    */
}

void MainWindow::addMolecule(QString & s)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui.treeWidget->AddMolecularOrbitals(s);
    QApplication::restoreOverrideCursor();

    refreshAllViews(ui.treeWidget->getActivedMol());
}


int MainWindow::typeofActiveChild()
{
    int type = -1;

    QMdiSubWindow * activeSubWindow = ui.mdiArea->activeSubWindow();
    if (!activeSubWindow) return type;


    QObject * obj = activeSubWindow->widget();
    if (!activeSubWindow)    return type;
    QString classname=obj->metaObject()->className();

    cout << classname.toStdString().c_str()<<endl;

    if (classname.contains("View3D"))  type = 0;
    if (classname.contains("Mesh3D"))  type = 1;
    if (classname.contains("Angular3D"))  type = 2;
    if (classname.contains("Cloud3D"))  type = 4;


    return type;
}


void MainWindow::on_pushButton_XY_clicked()
{
    /*
    if (typeofActiveChild()==0)
        view3d->onViewXY();

    if (typeofActiveChild()==1)
        mesh3d->onViewXY();

    if (typeofActiveChild()==2)
        angularY3d->onViewXY();
*/

        view3d->onViewXY();
        mesh3d->onViewXY();
        angularY3d->onViewXY();
        //cloud3d->onViewXY();

}

void MainWindow::on_pushButton_XZ_clicked()
{
    /*
    if (typeofActiveChild()==0)
        view3d->onViewXZ();

    if (typeofActiveChild()==1)
        mesh3d->onViewXZ();

    if (typeofActiveChild()==2)
        angularY3d->onViewXZ();
*/

        view3d->onViewXZ();
        mesh3d->onViewXZ();
        angularY3d->onViewXZ();
        cloud3d->onViewXZ();
}

void MainWindow::on_pushButton_YZ_clicked()
{
    /*
    if (typeofActiveChild()==0)
        view3d->onViewYZ();

    if (typeofActiveChild()==1)
        mesh3d->onViewYZ();

    if (typeofActiveChild()==2)
        angularY3d->onViewYZ();
    */

        view3d->onViewYZ();
        mesh3d->onViewYZ();
        angularY3d->onViewYZ();
        cloud3d->onViewYZ();
}

void MainWindow::on_pushButton_restView_clicked()
{
    /*
    if (typeofActiveChild()==0)
        view3d->onViewReset();

    if (typeofActiveChild()==1)
        mesh3d->onViewReset();

    if (typeofActiveChild()==2)
        angularY3d->onViewReset();
    */

        view3d->onViewReset();
        mesh3d->onViewReset();
        angularY3d->onViewReset();
        cloud3d->onViewReset();
}

void MainWindow::on_pushButton_clockwise_clicked()
{
    /*
    if (typeofActiveChild()==0)
        view3d->onView_rotateClockwise(ui.spinBox_angle->value());

    if (typeofActiveChild()==1)
        mesh3d->onView_rotateClockwise(ui.spinBox_angle->value());

    if (typeofActiveChild()==2)
        angularY3d->onView_rotateClockwise(ui.spinBox_angle->value());
*/

        view3d->onView_rotateClockwise(ui.spinBox_angle->value());
        mesh3d->onView_rotateClockwise(ui.spinBox_angle->value());
        angularY3d->onView_rotateClockwise(ui.spinBox_angle->value());
        cloud3d->onView_rotateClockwise(ui.spinBox_angle->value());

}

void MainWindow::on_pushButton_counterclockwise_clicked()
{
    /*
    if (typeofActiveChild()==0)
        view3d->onView_rotateCounterClockwise(ui.spinBox_angle->value());

    if (typeofActiveChild()==1)
        mesh3d->onView_rotateCounterClockwise(ui.spinBox_angle->value());

    if (typeofActiveChild()==2)
        angularY3d->onView_rotateCounterClockwise(ui.spinBox_angle->value());
    */

        view3d->onView_rotateCounterClockwise(ui.spinBox_angle->value());
        mesh3d->onView_rotateCounterClockwise(ui.spinBox_angle->value());
        angularY3d->onView_rotateCounterClockwise(ui.spinBox_angle->value());
        cloud3d->onView_rotateCounterClockwise(ui.spinBox_angle->value());
}

void MainWindow::on_pushButton_Up_clicked()
{
    /*
    if (typeofActiveChild()==0)
        view3d->onView_rotateUp(ui.spinBox_angle->value());

    if (typeofActiveChild()==1)
        mesh3d->onView_rotateUp(ui.spinBox_angle->value());

    if (typeofActiveChild()==2)
        angularY3d->onView_rotateUp(ui.spinBox_angle->value());
    */

    view3d->onView_rotateUp(ui.spinBox_angle->value());
    mesh3d->onView_rotateUp(ui.spinBox_angle->value());
    angularY3d->onView_rotateUp(ui.spinBox_angle->value());
    cloud3d->onView_rotateUp(ui.spinBox_angle->value());
}


void MainWindow::on_pushButton_Down_clicked()
{
    /*
    if (typeofActiveChild()==0)
        view3d->onView_rotateDown(ui.spinBox_angle->value());

    if (typeofActiveChild()==1)
        mesh3d->onView_rotateDown(ui.spinBox_angle->value());

    if (typeofActiveChild()==2)
        angularY3d->onView_rotateDown(ui.spinBox_angle->value());

    */

    view3d->onView_rotateDown(ui.spinBox_angle->value());
    mesh3d->onView_rotateDown(ui.spinBox_angle->value());
    angularY3d->onView_rotateDown(ui.spinBox_angle->value());
    cloud3d->onView_rotateDown(ui.spinBox_angle->value());
}


void MainWindow::on_pushButton_right_clicked()
{
    view3d->onView_rotateRight(ui.spinBox_angle->value());
    mesh3d->onView_rotateRight(ui.spinBox_angle->value());
    angularY3d->onView_rotateRight(ui.spinBox_angle->value());
    cloud3d->onView_rotateRight(ui.spinBox_angle->value());
}

void MainWindow::on_pushButton_left_clicked()
{
    view3d->onView_rotateLeft(ui.spinBox_angle->value());
    mesh3d->onView_rotateLeft(ui.spinBox_angle->value());
    angularY3d->onView_rotateLeft(ui.spinBox_angle->value());
	cloud3d->onView_rotateLeft(ui.spinBox_angle->value());
}


void MainWindow::on_actionNew_triggered()
{
     ui.treeWidget->OnRemoveAll();
}

void MainWindow::on_actionFileOpen_triggered()
{
    QStringList filters;
    filters << tr("Atomic Orbital Input") + "(*.orb)"
            << tr("Cube ")+ "(*.cub)"
            << tr("All files") + "(* *.*)";

    QString FileNames = QFileDialog::getOpenFileName( this,
                                                      tr( "Open File" ), QDir::currentPath(), filters.join(";;"));
    if (FileNames.isEmpty()) return;

   loadFile(FileNames);
}

void MainWindow::loadFile(QString filename)
{
    if (filename.isEmpty()) return;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


    if( filename.endsWith("orb") )
    {
        QTextStream in(&file);
        QString s="";
        while (!in.atEnd()) {
            QString line = in.readLine();
            s+=line+"\n";
        }

        addMolecule(s);
    }
}



void MainWindow::saveFile(QString filename)
{

}

void MainWindow::on_actionSave_PNG_triggered()
{
    uint type=-1;
    if (typeofActiveChild()==0) type=0;
    if (typeofActiveChild()==1) type=1;
    if (typeofActiveChild()==2) type=2;

    if(type<0) {
       QMessageBox::information(0, "Warning","No Actived Orbital!");
    }


    QStringList filters;
    filters << tr("Atomic Orbital Input") + "(*.orb)"
            << tr("png")+ "(*.png)"
            << tr("All files") + "(* *.*)";

    QString FileNames = QFileDialog::getSaveFileName(this,
                           tr( "Save File" ), QDir::currentPath(), filters.join(";;"));

    if (FileNames.isEmpty()) return;

    if( FileNames.endsWith("png") ) {
        if (type==0)    view3d-> writePNG(FileNames);
        if (type==1)    mesh3d->writePNG(FileNames);
        if (type==2)    angularY3d->writePNG(FileNames);
    }
}




void MainWindow::on_pushButton_OL_color_clicked()
{
    OrbitalProperty * moForm = new OrbitalProperty (this);
    if (moForm!=nullptr) {
        moForm->setAttribute( Qt::WA_DeleteOnClose, true );
        moForm->exec();
    }
}

void MainWindow::on_pushButton_ON_color_clicked()
{
    OrbitalProperty * moForm = new OrbitalProperty (this);
    if (moForm!=nullptr) {
        moForm->setAttribute( Qt::WA_DeleteOnClose, true );
        moForm->exec();
    }
}


