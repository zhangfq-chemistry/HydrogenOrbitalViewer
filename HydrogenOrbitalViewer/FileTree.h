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

#ifndef SETTINGSTREE_H
#define SETTINGSTREE_H

#include <QIcon>
#include <QTimer>
#include <QTreeWidget>
#include <QSharedPointer>
#include <QVector>
#include <QMenu>

#include "HAtomOrb.h"
#include "View3D.h"
#include "textEditor.h"
#include "FileTree.h"
#include "RadialFunViewer.h"
//#include "mainwindow.h"

QT_BEGIN_NAMESPACE
class QSettings;
QT_END_NAMESPACE




class MainWindow;

class FileTree : public QTreeWidget
{
    Q_OBJECT

public:
    typedef QSharedPointer<QSettings> SettingsPtr;


    FileTree(QWidget *parent = 0);
    ~FileTree() ;

    MainWindow * getMainWindow();


    void sendMessage(QString  );
    void appendMessage(QString  );


    void setSettingsObject(const SettingsPtr &settings);
    QSize sizeHint() const override;



public slots:
    void setAutoRefresh(bool autoRefresh);
    void setFallbacksEnabled(bool enabled);
    void maybeRefresh();
    void refresh();
    void AddMolecularOrbitals(QString & s);

    void NewAOObitals(QString AtomSymbol, QString ObName,vector3 pos);

    void NewHybridizedObitals(QString AtomSymbol, QString ObName,vector3 pos);
    void updateSetting(QTreeWidgetItem *);

    void updateSelection(QTreeWidgetItem *);


    void showActiveMolObitalRadialNodeType(bool );
    void showActiveMolObitalAngularNodeType(bool);

    void showActiveMolObtialNegativeLobe(bool );
    void showActiveMolObtialPositiveLobe(bool );


    void OnChangeName();
    void OnRemove();
    void OnRemoveAll();
    void OnPopMenu(const QPoint &);
    //void updateViewItems(QTreeWidgetItem *);
    //void removeOrbitals();


public:

    OrbitaType ObitalType (){return orbital_type;}
    void setObitalType (uint _t)
    {
        switch (_t){
        case 0: orbital_type=FULL;break;
        case 1: orbital_type=XOY;break;
        case 2: orbital_type=XOZ;break;
        case 3: orbital_type=YOZ;break;
        case 4: orbital_type=Wedge;break;
        case 5: orbital_type=Quarter;break;
        case 6: orbital_type=Corner;break;
        }
    }


    void setActiveMolObitalMesh(bool );


    HMol * getLastMol() {

        if (Molecules.size()<1)
            return nullptr;
        return Molecules[Molecules.size()-1];
    };


    HMol * getMol (int id)
    {
        if (Molecules.size()<1)       return nullptr;
        if (id > Molecules.size()-1 ) return nullptr;
        return Molecules[id];
    }

    HMol * getMol (QTreeWidgetItem * item)
    {
        return getMol(getMoleculeId(item));
    }

    HMO * getMO (int id_mol, int id_mo)
    {
         return getMol (id_mol)->getObtial(id_mo);
    }

    int getMoleculeId(QTreeWidgetItem *);
    int getMOId(QTreeWidgetItem *);
    void addViewsChildItems(QTreeWidgetItem * itemMolecule, HMol *  mol, QString ObName, bool addAtoms, uint idx);
    void addViewsChildItems(QTreeWidgetItem * itemMolecule, HMol *  mol, QString ObName, bool addAtoms);

    HMol *  getActivedMol();
    void setActiveMolObitalType(uint);

    bool hasMol(){if (Molecules.size()>0) return true;return false;};





private:
    void updateChildItems(QTreeWidgetItem *parent);
    QTreeWidgetItem *createItem(const QString &text, QTreeWidgetItem *parent,
                                int index);
    QTreeWidgetItem *childAt(QTreeWidgetItem *parent, int index);
    int childCount(QTreeWidgetItem *parent);
    int findChild(QTreeWidgetItem *parent, const QString &text, int startIndex);
    void moveItemForward(QTreeWidgetItem *parent, int oldIndex, int newIndex);

    void reMoveAllItems();
    void removeAllMolecules();



    bool visible_radial_node;
    bool visible_angular_node;

    OrbitaType  orbital_type;
    bool  isObtialMesh;
    SettingsPtr settings;
    QTimer refreshTimer;
    bool autoRefresh;

    QIcon groupIcon;
    QIcon keyIcon;

    QVector <HMol * > Molecules;
    QVector <QString > NameLists, AtomLabels;

    View3D  *  view3d;
    RadialFunViewer * Rview;
    TextEditor *  infoview;

    uint idx_mol,idx_mo;


};

#endif
