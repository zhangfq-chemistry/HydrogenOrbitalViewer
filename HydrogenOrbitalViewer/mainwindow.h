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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MdiChild;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
QT_END_NAMESPACE

#include "HAtomOrb.h"

#include "View3D.h"
#include "RadialFunViewer.h"
#include "textEditor.h"
#include "FileTree.h"
#include "Mesh3D.h"
#include "Angular3D.h"
#include "Cloud3D.h"
#//include "muparser/qcalculator.h"

#include "ui_mainwindow.h"

#include "ShowMOForm.h"




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

 //   bool openFile(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
  //  void newFile();
 //   void open();
 //   void save();
  //  void saveAs();
  //  void updateRecentFileActions();
 //   void openRecentFile();
//#ifndef QT_NO_CLIPBOARD
//    void cut();
 //   void copy();
 //   void paste();
//#endif
  //  void about();
 //   void updateMenus();
 //   void updateWindowMenu();
  //  MdiChild *createMdiChild();
 //   void switchLayoutDirection();



    void on_pushButton_XY_clicked();
    void on_pushButton_XZ_clicked();
    void on_pushButton_YZ_clicked();
    void on_pushButton_restView_clicked();
    void on_pushButton_clockwise_clicked();
    void on_pushButton_counterclockwise_clicked();
    void on_pushButton_Up_clicked();
    void on_pushButton_Down_clicked();

    void on_actionNew_triggered();

    void on_actionFileOpen_triggered();



    void on_actionSave_PNG_triggered();


    void on_pushButton_OL_color_clicked();

    void on_pushButton_ON_color_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_left_clicked();

public:
    void newFile();
    void sendMessage(QString & );
    void appendMessage(QString & );
    void addMolecule(QString &);
    int  typeofActiveChild();
    void removeOrbitalfromMesh3D(HMol *  , uint );
    void removeOrbitalfromMesh3D(HMol *  );
    void clearAllViews();
    void loadFile(QString );
    void saveFile(QString );


public:
    int n,l,m;
    QString AOrbitalName;

    View3D  *  view3d;
    RadialFunViewer * Rview;
    TextEditor *  infoview;
    Mesh3D  * mesh3d;
    Angular3D * angularY3d;
    Cloud3D  * cloud3d;

    //QCalculator * calculator;

    //YView3D * viewY3D;
    //AOView2D * view2D;

   void initFileTree();

private:
    enum { MaxRecentFiles = 5 };
/*
    void createActions();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool loadFile(const QString &fileName);
    static bool hasRecentFiles();
    void prependToRecentFiles(const QString &fileName);
    void setRecentFilesVisible(bool visible);
    MdiChild *activeMdiChild() const;
    QMdiSubWindow *findMdiChild(const QString &fileName) const;

    */
    QMdiArea *mdiArea;
   // QMenu *windowMenu;
   // QAction *newAct;
  //  QAction *saveAct;
   // QAction *saveAsAct;
  //  QAction *recentFileActs[MaxRecentFiles];
  //  QAction *recentFileSeparator;
  //  QAction *recentFileSubMenuAct;



public slots:
  void onAddOrbital();
  void onBuildOrbital();
  void onAOSeletedChanged();

  void onChanged_n(int);
  void onChanged_l(int);
  void onChanged_m(int);
  void onChanged_nlm();
  void onCenterMol();

  void onRotate();
  void onTranslate();

  void refreshAllViews(HMol * );


  void actionShow3D();

  void onObtialXOY();
  void onObtialXOZ();
  void onObtialYOZ();
  void onObtialCorner();
  void onObtialQuarter();
  void onObtialWidge();
  void onObtialSmooth();
  void onObtialMesh();
  void setAllObtialUnchecked();

  void onShownObtialAngularNode();
  void onShownObtialRadialNode();

  void onShownObtialNegativeLobe();
  void onShownObtialPositiveLobe();

  void on3DViewActive();
  void on3DProjActive();
  void onRadialFuncActive();
  
  void onInformActive();



  void on_checkBox_R_stateChanged(int );
  void on_checkBox_R2_stateChanged(int );
  void on_checkBox_RDF_stateChanged(int );
  void onBuildMO();

  void refreshCurrentView();










/*

#ifndef QT_NO_CLIPBOARD
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
#endif
    QAction *closeAct;
    QAction *closeAllAct;
    QAction *tileAct;
    QAction *cascadeAct;
    QAction *nextAct;
    QAction *previousAct;
    QAction *windowMenuSeparatorAct;
    */
private:
  Ui::MainWindow ui;
};

#endif
