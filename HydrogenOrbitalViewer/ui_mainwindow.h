/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "FileTree.h"
#include "RadialFunViewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_as;
    QAction *actionAlignView_Xy;
    QAction *actionAlignView_Xz;
    QAction *actionAlignView_Yz;
    QAction *actionAbout;
    QAction *actionSave_Png;
    QAction *actionSave_Gif;
    QAction *actionPsi3D_Active;
    QAction *actionPsi3DProj_Active;
    QAction *actionRadial_Active;
    QAction *actionYlm;
    QAction *actionCascade;
    QAction *actionTitles;
    QAction *actionFileOpen;
    QAction *actionFileClose;
    QAction *actionFileTreeViewShow;
    QAction *actionBuilderShow;
    QAction *actionbuild_Molecular_Orbital;
    QAction *actionNew;
    QAction *actionSave_PNG;
    QAction *actionChangeColor;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_mdi;
    QGridLayout *gridLayout_2;
    QMdiArea *mdiArea;
    QWidget *tab_rf;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_RDF;
    QCheckBox *checkBox_R;
    QCheckBox *checkBox_R2;
    RadialFunViewer *RDFViewer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuwindows;
    QMenu *menuToosBar;
    QDockWidget *dockWidget_right;
    QWidget *dockWidgetContents_5;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_6;
    QSpinBox *spinBox_l;
    QLabel *label_39;
    QLabel *label_36;
    QSpinBox *spinBox_n;
    QLabel *label_40;
    QCheckBox *checkBox_quadMesh;
    QSpinBox *spinBox_m;
    QPushButton *pushButton_addOrbital;
    QComboBox *comboBox_OB_cossin;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    QLabel *label_psi;
    QComboBox *comboBox_typeR;
    QLabel *label_5;
    QComboBox *comboBox_AOrbital;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_10;
    QCheckBox *checkBox_OB_xoy;
    QCheckBox *checkBox_OB_positive;
    QCheckBox *checkBox_OB_xoz;
    QCheckBox *checkBox_OB_negative;
    QCheckBox *checkBox_OB_corner;
    QCheckBox *checkBox_OB_yoz;
    QCheckBox *checkBox_OB_smooth;
    QCheckBox *checkBox_OB_mesh;
    QCheckBox *checkBox_OB_quarter;
    QCheckBox *checkBox_OB_widge;
    QPushButton *pushButton_OL_color;
    QPushButton *pushButton_ON_color;
    QGroupBox *groupBox_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_NT_Radial;
    QCheckBox *checkBox_NT_angular;
    QDockWidget *dockWidget_left;
    QWidget *dockWidgetContents;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_clockwise;
    QLabel *label_3;
    QPushButton *pushButton_YZ;
    QPushButton *pushButton_counterclockwise;
    QPushButton *pushButton_XY;
    QPushButton *pushButton_Down;
    QPushButton *pushButton_XZ;
    QLabel *label_4;
    QPushButton *pushButton_Up;
    QSpinBox *spinBox_angle;
    QPushButton *pushButton_restView;
    QPushButton *pushButton_right;
    QPushButton *pushButton_left;
    FileTree *treeWidget;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1142, 748);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        QIcon icon;
        icon.addFile(QStringLiteral("../images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon);
        actionAlignView_Xy = new QAction(MainWindow);
        actionAlignView_Xy->setObjectName(QStringLiteral("actionAlignView_Xy"));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(13);
        actionAlignView_Xy->setFont(font);
        actionAlignView_Xz = new QAction(MainWindow);
        actionAlignView_Xz->setObjectName(QStringLiteral("actionAlignView_Xz"));
        actionAlignView_Xz->setFont(font);
        actionAlignView_Yz = new QAction(MainWindow);
        actionAlignView_Yz->setObjectName(QStringLiteral("actionAlignView_Yz"));
        actionAlignView_Yz->setFont(font);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout->setFont(font);
        actionSave_Png = new QAction(MainWindow);
        actionSave_Png->setObjectName(QStringLiteral("actionSave_Png"));
        actionSave_Gif = new QAction(MainWindow);
        actionSave_Gif->setObjectName(QStringLiteral("actionSave_Gif"));
        actionPsi3D_Active = new QAction(MainWindow);
        actionPsi3D_Active->setObjectName(QStringLiteral("actionPsi3D_Active"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../images/Isosurface.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPsi3D_Active->setIcon(icon1);
        actionPsi3DProj_Active = new QAction(MainWindow);
        actionPsi3DProj_Active->setObjectName(QStringLiteral("actionPsi3DProj_Active"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../images/mesh2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPsi3DProj_Active->setIcon(icon2);
        actionRadial_Active = new QAction(MainWindow);
        actionRadial_Active->setObjectName(QStringLiteral("actionRadial_Active"));
        actionYlm = new QAction(MainWindow);
        actionYlm->setObjectName(QStringLiteral("actionYlm"));
        actionCascade = new QAction(MainWindow);
        actionCascade->setObjectName(QStringLiteral("actionCascade"));
        actionTitles = new QAction(MainWindow);
        actionTitles->setObjectName(QStringLiteral("actionTitles"));
        actionFileOpen = new QAction(MainWindow);
        actionFileOpen->setObjectName(QStringLiteral("actionFileOpen"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileOpen->setIcon(icon3);
        actionFileClose = new QAction(MainWindow);
        actionFileClose->setObjectName(QStringLiteral("actionFileClose"));
        actionFileTreeViewShow = new QAction(MainWindow);
        actionFileTreeViewShow->setObjectName(QStringLiteral("actionFileTreeViewShow"));
        actionBuilderShow = new QAction(MainWindow);
        actionBuilderShow->setObjectName(QStringLiteral("actionBuilderShow"));
        actionbuild_Molecular_Orbital = new QAction(MainWindow);
        actionbuild_Molecular_Orbital->setObjectName(QStringLiteral("actionbuild_Molecular_Orbital"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon4);
        actionSave_PNG = new QAction(MainWindow);
        actionSave_PNG->setObjectName(QStringLiteral("actionSave_PNG"));
        actionChangeColor = new QAction(MainWindow);
        actionChangeColor->setObjectName(QStringLiteral("actionChangeColor"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_mdi = new QWidget();
        tab_mdi->setObjectName(QStringLiteral("tab_mdi"));
        gridLayout_2 = new QGridLayout(tab_mdi);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        mdiArea = new QMdiArea(tab_mdi);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        gridLayout_2->addWidget(mdiArea, 0, 0, 1, 1);

        tabWidget->addTab(tab_mdi, QString());
        tab_rf = new QWidget();
        tab_rf->setObjectName(QStringLiteral("tab_rf"));
        gridLayout_4 = new QGridLayout(tab_rf);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        checkBox_RDF = new QCheckBox(tab_rf);
        checkBox_RDF->setObjectName(QStringLiteral("checkBox_RDF"));

        gridLayout_3->addWidget(checkBox_RDF, 1, 2, 1, 1);

        checkBox_R = new QCheckBox(tab_rf);
        checkBox_R->setObjectName(QStringLiteral("checkBox_R"));

        gridLayout_3->addWidget(checkBox_R, 1, 1, 1, 1);

        checkBox_R2 = new QCheckBox(tab_rf);
        checkBox_R2->setObjectName(QStringLiteral("checkBox_R2"));

        gridLayout_3->addWidget(checkBox_R2, 1, 3, 1, 1);

        RDFViewer = new RadialFunViewer(tab_rf);
        RDFViewer->setObjectName(QStringLiteral("RDFViewer"));

        gridLayout_3->addWidget(RDFViewer, 2, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_rf, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1142, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuwindows = new QMenu(menuBar);
        menuwindows->setObjectName(QStringLiteral("menuwindows"));
        menuToosBar = new QMenu(menuBar);
        menuToosBar->setObjectName(QStringLiteral("menuToosBar"));
        MainWindow->setMenuBar(menuBar);
        dockWidget_right = new QDockWidget(MainWindow);
        dockWidget_right->setObjectName(QStringLiteral("dockWidget_right"));
        dockWidget_right->setMinimumSize(QSize(200, 217));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        groupBox_2 = new QGroupBox(dockWidgetContents_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 191, 211));
        gridLayoutWidget_4 = new QWidget(groupBox_2);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 100, 171, 101));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        spinBox_l = new QSpinBox(gridLayoutWidget_4);
        spinBox_l->setObjectName(QStringLiteral("spinBox_l"));

        gridLayout_6->addWidget(spinBox_l, 1, 1, 1, 1);

        label_39 = new QLabel(gridLayoutWidget_4);
        label_39->setObjectName(QStringLiteral("label_39"));
        QFont font1;
        font1.setPointSize(14);
        label_39->setFont(font1);

        gridLayout_6->addWidget(label_39, 1, 0, 1, 1);

        label_36 = new QLabel(gridLayoutWidget_4);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setFont(font1);

        gridLayout_6->addWidget(label_36, 0, 0, 1, 1);

        spinBox_n = new QSpinBox(gridLayoutWidget_4);
        spinBox_n->setObjectName(QStringLiteral("spinBox_n"));

        gridLayout_6->addWidget(spinBox_n, 0, 1, 1, 1);

        label_40 = new QLabel(gridLayoutWidget_4);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setFont(font1);

        gridLayout_6->addWidget(label_40, 2, 0, 1, 1);

        checkBox_quadMesh = new QCheckBox(gridLayoutWidget_4);
        checkBox_quadMesh->setObjectName(QStringLiteral("checkBox_quadMesh"));

        gridLayout_6->addWidget(checkBox_quadMesh, 1, 2, 1, 1);

        spinBox_m = new QSpinBox(gridLayoutWidget_4);
        spinBox_m->setObjectName(QStringLiteral("spinBox_m"));

        gridLayout_6->addWidget(spinBox_m, 2, 1, 1, 1);

        pushButton_addOrbital = new QPushButton(gridLayoutWidget_4);
        pushButton_addOrbital->setObjectName(QStringLiteral("pushButton_addOrbital"));
        QFont font2;
        font2.setFamily(QStringLiteral("Cantarell"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        pushButton_addOrbital->setFont(font2);

        gridLayout_6->addWidget(pushButton_addOrbital, 0, 2, 1, 1);

        comboBox_OB_cossin = new QComboBox(gridLayoutWidget_4);
        comboBox_OB_cossin->addItem(QString());
        comboBox_OB_cossin->addItem(QString());
        comboBox_OB_cossin->addItem(QString());
        comboBox_OB_cossin->setObjectName(QStringLiteral("comboBox_OB_cossin"));

        gridLayout_6->addWidget(comboBox_OB_cossin, 2, 2, 1, 1);

        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 181, 64));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_psi = new QLabel(layoutWidget);
        label_psi->setObjectName(QStringLiteral("label_psi"));

        gridLayout_7->addWidget(label_psi, 0, 0, 1, 1);

        comboBox_typeR = new QComboBox(layoutWidget);
        comboBox_typeR->addItem(QString());
        comboBox_typeR->addItem(QString());
        comboBox_typeR->setObjectName(QStringLiteral("comboBox_typeR"));

        gridLayout_7->addWidget(comboBox_typeR, 0, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_7->addWidget(label_5, 1, 0, 1, 1);

        comboBox_AOrbital = new QComboBox(layoutWidget);
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->addItem(QString());
        comboBox_AOrbital->setObjectName(QStringLiteral("comboBox_AOrbital"));

        gridLayout_7->addWidget(comboBox_AOrbital, 1, 1, 1, 1);

        groupBox = new QGroupBox(dockWidgetContents_5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 220, 191, 231));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(8, 30, 181, 190));
        gridLayout_10 = new QGridLayout(layoutWidget1);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        checkBox_OB_xoy = new QCheckBox(layoutWidget1);
        checkBox_OB_xoy->setObjectName(QStringLiteral("checkBox_OB_xoy"));
        checkBox_OB_xoy->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout_10->addWidget(checkBox_OB_xoy, 3, 2, 1, 1);

        checkBox_OB_positive = new QCheckBox(layoutWidget1);
        checkBox_OB_positive->setObjectName(QStringLiteral("checkBox_OB_positive"));

        gridLayout_10->addWidget(checkBox_OB_positive, 1, 1, 1, 1);

        checkBox_OB_xoz = new QCheckBox(layoutWidget1);
        checkBox_OB_xoz->setObjectName(QStringLiteral("checkBox_OB_xoz"));

        gridLayout_10->addWidget(checkBox_OB_xoz, 4, 2, 1, 1);

        checkBox_OB_negative = new QCheckBox(layoutWidget1);
        checkBox_OB_negative->setObjectName(QStringLiteral("checkBox_OB_negative"));

        gridLayout_10->addWidget(checkBox_OB_negative, 1, 2, 1, 1);

        checkBox_OB_corner = new QCheckBox(layoutWidget1);
        checkBox_OB_corner->setObjectName(QStringLiteral("checkBox_OB_corner"));

        gridLayout_10->addWidget(checkBox_OB_corner, 5, 2, 1, 1);

        checkBox_OB_yoz = new QCheckBox(layoutWidget1);
        checkBox_OB_yoz->setObjectName(QStringLiteral("checkBox_OB_yoz"));

        gridLayout_10->addWidget(checkBox_OB_yoz, 4, 1, 1, 1);

        checkBox_OB_smooth = new QCheckBox(layoutWidget1);
        checkBox_OB_smooth->setObjectName(QStringLiteral("checkBox_OB_smooth"));

        gridLayout_10->addWidget(checkBox_OB_smooth, 2, 2, 1, 1);

        checkBox_OB_mesh = new QCheckBox(layoutWidget1);
        checkBox_OB_mesh->setObjectName(QStringLiteral("checkBox_OB_mesh"));

        gridLayout_10->addWidget(checkBox_OB_mesh, 2, 1, 1, 1);

        checkBox_OB_quarter = new QCheckBox(layoutWidget1);
        checkBox_OB_quarter->setObjectName(QStringLiteral("checkBox_OB_quarter"));

        gridLayout_10->addWidget(checkBox_OB_quarter, 5, 1, 1, 1);

        checkBox_OB_widge = new QCheckBox(layoutWidget1);
        checkBox_OB_widge->setObjectName(QStringLiteral("checkBox_OB_widge"));

        gridLayout_10->addWidget(checkBox_OB_widge, 3, 1, 1, 1);

        pushButton_OL_color = new QPushButton(layoutWidget1);
        pushButton_OL_color->setObjectName(QStringLiteral("pushButton_OL_color"));

        gridLayout_10->addWidget(pushButton_OL_color, 6, 1, 1, 1);

        pushButton_ON_color = new QPushButton(layoutWidget1);
        pushButton_ON_color->setObjectName(QStringLiteral("pushButton_ON_color"));

        gridLayout_10->addWidget(pushButton_ON_color, 6, 2, 1, 1);

        groupBox_3 = new QGroupBox(dockWidgetContents_5);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 450, 191, 141));
        horizontalLayoutWidget = new QWidget(groupBox_3);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 30, 181, 28));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_NT_Radial = new QCheckBox(horizontalLayoutWidget);
        checkBox_NT_Radial->setObjectName(QStringLiteral("checkBox_NT_Radial"));

        horizontalLayout_2->addWidget(checkBox_NT_Radial);

        checkBox_NT_angular = new QCheckBox(horizontalLayoutWidget);
        checkBox_NT_angular->setObjectName(QStringLiteral("checkBox_NT_angular"));

        horizontalLayout_2->addWidget(checkBox_NT_angular);

        dockWidget_right->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_right);
        dockWidget_left = new QDockWidget(MainWindow);
        dockWidget_left->setObjectName(QStringLiteral("dockWidget_left"));
        dockWidget_left->setMinimumSize(QSize(200, 159));
        dockWidget_left->setMaximumSize(QSize(220, 524287));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        layoutWidget2 = new QWidget(dockWidgetContents);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 181, 681));
        gridLayout_8 = new QGridLayout(layoutWidget2);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton_clockwise = new QPushButton(layoutWidget2);
        pushButton_clockwise->setObjectName(QStringLiteral("pushButton_clockwise"));

        gridLayout_5->addWidget(pushButton_clockwise, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        pushButton_YZ = new QPushButton(layoutWidget2);
        pushButton_YZ->setObjectName(QStringLiteral("pushButton_YZ"));

        gridLayout_5->addWidget(pushButton_YZ, 1, 1, 1, 1);

        pushButton_counterclockwise = new QPushButton(layoutWidget2);
        pushButton_counterclockwise->setObjectName(QStringLiteral("pushButton_counterclockwise"));

        gridLayout_5->addWidget(pushButton_counterclockwise, 2, 2, 1, 1);

        pushButton_XY = new QPushButton(layoutWidget2);
        pushButton_XY->setObjectName(QStringLiteral("pushButton_XY"));

        gridLayout_5->addWidget(pushButton_XY, 0, 1, 1, 1);

        pushButton_Down = new QPushButton(layoutWidget2);
        pushButton_Down->setObjectName(QStringLiteral("pushButton_Down"));

        gridLayout_5->addWidget(pushButton_Down, 4, 2, 1, 1);

        pushButton_XZ = new QPushButton(layoutWidget2);
        pushButton_XZ->setObjectName(QStringLiteral("pushButton_XZ"));

        gridLayout_5->addWidget(pushButton_XZ, 0, 2, 1, 1);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 2, 0, 1, 1);

        pushButton_Up = new QPushButton(layoutWidget2);
        pushButton_Up->setObjectName(QStringLiteral("pushButton_Up"));

        gridLayout_5->addWidget(pushButton_Up, 4, 1, 1, 1);

        spinBox_angle = new QSpinBox(layoutWidget2);
        spinBox_angle->setObjectName(QStringLiteral("spinBox_angle"));
        spinBox_angle->setMinimum(1);

        gridLayout_5->addWidget(spinBox_angle, 4, 0, 1, 1);

        pushButton_restView = new QPushButton(layoutWidget2);
        pushButton_restView->setObjectName(QStringLiteral("pushButton_restView"));

        gridLayout_5->addWidget(pushButton_restView, 1, 2, 1, 1);

        pushButton_right = new QPushButton(layoutWidget2);
        pushButton_right->setObjectName(QStringLiteral("pushButton_right"));

        gridLayout_5->addWidget(pushButton_right, 3, 1, 1, 1);

        pushButton_left = new QPushButton(layoutWidget2);
        pushButton_left->setObjectName(QStringLiteral("pushButton_left"));

        gridLayout_5->addWidget(pushButton_left, 3, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_5, 2, 0, 1, 1);

        treeWidget = new FileTree(layoutWidget2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setMinimumSize(QSize(100, 200));
        treeWidget->setMaximumSize(QSize(200, 1000));
        treeWidget->setMouseTracking(true);
        treeWidget->setTabletTracking(true);
        treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        treeWidget->setFrameShadow(QFrame::Raised);
        treeWidget->setDragEnabled(true);

        gridLayout_8->addWidget(treeWidget, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer, 1, 0, 1, 1);

        dockWidget_left->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_left);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuToosBar->menuAction());
        menuBar->addAction(menuwindows->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionFileOpen);
        menuFile->addAction(actionFileClose);
        menuFile->addAction(actionSave_PNG);
        menuView->addAction(actionPsi3D_Active);
        menuView->addAction(actionPsi3DProj_Active);
        menuView->addAction(actionRadial_Active);
        menuView->addSeparator();
        menuView->addAction(actionChangeColor);
        menuwindows->addAction(actionCascade);
        menuwindows->addAction(actionTitles);
        menuToosBar->addAction(actionbuild_Molecular_Orbital);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AtomOrbital", nullptr));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", nullptr));
        actionAlignView_Xy->setText(QApplication::translate("MainWindow", "Align to x/y", nullptr));
        actionAlignView_Xz->setText(QApplication::translate("MainWindow", "Align to x/z", nullptr));
        actionAlignView_Yz->setText(QApplication::translate("MainWindow", "Align to y/z", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", nullptr));
        actionSave_Png->setText(QApplication::translate("MainWindow", "Save Png", nullptr));
        actionSave_Gif->setText(QApplication::translate("MainWindow", "Save Gif", nullptr));
        actionPsi3D_Active->setText(QApplication::translate("MainWindow", "3D", nullptr));
        actionPsi3DProj_Active->setText(QApplication::translate("MainWindow", "3D-Projection", nullptr));
        actionRadial_Active->setText(QApplication::translate("MainWindow", "Radial Functions", nullptr));
        actionYlm->setText(QApplication::translate("MainWindow", "Ylm", nullptr));
        actionCascade->setText(QApplication::translate("MainWindow", "Cascade", nullptr));
        actionTitles->setText(QApplication::translate("MainWindow", "Titles", nullptr));
        actionFileOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionFileClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
        actionFileTreeViewShow->setText(QApplication::translate("MainWindow", "FileView", nullptr));
        actionBuilderShow->setText(QApplication::translate("MainWindow", "Builder", nullptr));
        actionbuild_Molecular_Orbital->setText(QApplication::translate("MainWindow", "Molecular Orbital", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
        actionSave_PNG->setText(QApplication::translate("MainWindow", "Save PNG", nullptr));
        actionChangeColor->setText(QApplication::translate("MainWindow", "ChangeColor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_mdi), QApplication::translate("MainWindow", "Orbital", nullptr));
        checkBox_RDF->setText(QApplication::translate("MainWindow", "RDF", nullptr));
        checkBox_R->setText(QApplication::translate("MainWindow", "R", nullptr));
        checkBox_R2->setText(QApplication::translate("MainWindow", "R2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_rf), QApplication::translate("MainWindow", "Radial Function", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuwindows->setTitle(QApplication::translate("MainWindow", "Windows", nullptr));
        menuToosBar->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "           Atomic Orbital ", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "l", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "n", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "m", nullptr));
        checkBox_quadMesh->setText(QApplication::translate("MainWindow", "quadMesh", nullptr));
        pushButton_addOrbital->setText(QApplication::translate("MainWindow", "Add", nullptr));
        comboBox_OB_cossin->setItemText(0, QApplication::translate("MainWindow", "none", nullptr));
        comboBox_OB_cossin->setItemText(1, QApplication::translate("MainWindow", "   cos", nullptr));
        comboBox_OB_cossin->setItemText(2, QApplication::translate("MainWindow", "   sin", nullptr));

        label_psi->setText(QApplication::translate("MainWindow", "Psi", nullptr));
        comboBox_typeR->setItemText(0, QApplication::translate("MainWindow", "Hydrogenoid", nullptr));
        comboBox_typeR->setItemText(1, QApplication::translate("MainWindow", "Coulomb-Sturmian", nullptr));

        label_5->setText(QApplication::translate("MainWindow", "AO", nullptr));
        comboBox_AOrbital->setItemText(0, QApplication::translate("MainWindow", "1S", nullptr));
        comboBox_AOrbital->setItemText(1, QApplication::translate("MainWindow", "2S", nullptr));
        comboBox_AOrbital->setItemText(2, QApplication::translate("MainWindow", "2Px", nullptr));
        comboBox_AOrbital->setItemText(3, QApplication::translate("MainWindow", "2Py", nullptr));
        comboBox_AOrbital->setItemText(4, QApplication::translate("MainWindow", "2Pz", nullptr));
        comboBox_AOrbital->setItemText(5, QApplication::translate("MainWindow", "3S", nullptr));
        comboBox_AOrbital->setItemText(6, QApplication::translate("MainWindow", "3Px", nullptr));
        comboBox_AOrbital->setItemText(7, QApplication::translate("MainWindow", "3Py", nullptr));
        comboBox_AOrbital->setItemText(8, QApplication::translate("MainWindow", "3Pz", nullptr));
        comboBox_AOrbital->setItemText(9, QApplication::translate("MainWindow", "3Dxy", nullptr));
        comboBox_AOrbital->setItemText(10, QApplication::translate("MainWindow", "3Dyz", nullptr));
        comboBox_AOrbital->setItemText(11, QApplication::translate("MainWindow", "3Dxz", nullptr));
        comboBox_AOrbital->setItemText(12, QApplication::translate("MainWindow", "3Dx2-y2", nullptr));
        comboBox_AOrbital->setItemText(13, QApplication::translate("MainWindow", "3Dz2", nullptr));
        comboBox_AOrbital->setItemText(14, QApplication::translate("MainWindow", "4S", nullptr));
        comboBox_AOrbital->setItemText(15, QApplication::translate("MainWindow", "4Px", nullptr));
        comboBox_AOrbital->setItemText(16, QApplication::translate("MainWindow", "4Py", nullptr));
        comboBox_AOrbital->setItemText(17, QApplication::translate("MainWindow", "4Pz", nullptr));
        comboBox_AOrbital->setItemText(18, QApplication::translate("MainWindow", "4Dxy", nullptr));
        comboBox_AOrbital->setItemText(19, QApplication::translate("MainWindow", "4Dyz", nullptr));
        comboBox_AOrbital->setItemText(20, QApplication::translate("MainWindow", "4Dxz", nullptr));
        comboBox_AOrbital->setItemText(21, QApplication::translate("MainWindow", "4Dx2-y2", nullptr));
        comboBox_AOrbital->setItemText(22, QApplication::translate("MainWindow", "4Dz2", nullptr));
        comboBox_AOrbital->setItemText(23, QApplication::translate("MainWindow", "4Fz3", nullptr));
        comboBox_AOrbital->setItemText(24, QApplication::translate("MainWindow", "4Fxz2", nullptr));
        comboBox_AOrbital->setItemText(25, QApplication::translate("MainWindow", "4Fyz2", nullptr));
        comboBox_AOrbital->setItemText(26, QApplication::translate("MainWindow", "4Fz(x2-y2)", nullptr));
        comboBox_AOrbital->setItemText(27, QApplication::translate("MainWindow", "4Fxyz", nullptr));
        comboBox_AOrbital->setItemText(28, QApplication::translate("MainWindow", "4Fx(x2-3y2)", nullptr));
        comboBox_AOrbital->setItemText(29, QApplication::translate("MainWindow", "4Fy(3x2-y2)", nullptr));
        comboBox_AOrbital->setItemText(30, QApplication::translate("MainWindow", "5S", nullptr));
        comboBox_AOrbital->setItemText(31, QApplication::translate("MainWindow", "5Px", nullptr));
        comboBox_AOrbital->setItemText(32, QApplication::translate("MainWindow", "5Py", nullptr));
        comboBox_AOrbital->setItemText(33, QApplication::translate("MainWindow", "5Pz", nullptr));
        comboBox_AOrbital->setItemText(34, QApplication::translate("MainWindow", "5Dxy", nullptr));
        comboBox_AOrbital->setItemText(35, QApplication::translate("MainWindow", "5Dyz", nullptr));
        comboBox_AOrbital->setItemText(36, QApplication::translate("MainWindow", "5Dxz", nullptr));
        comboBox_AOrbital->setItemText(37, QApplication::translate("MainWindow", "5Dx2-y2", nullptr));
        comboBox_AOrbital->setItemText(38, QApplication::translate("MainWindow", "5Dz2", nullptr));
        comboBox_AOrbital->setItemText(39, QApplication::translate("MainWindow", "5Fz3", nullptr));
        comboBox_AOrbital->setItemText(40, QApplication::translate("MainWindow", "5Fxz2", nullptr));
        comboBox_AOrbital->setItemText(41, QApplication::translate("MainWindow", "5Fyz2", nullptr));
        comboBox_AOrbital->setItemText(42, QApplication::translate("MainWindow", "5Fz(x2-y2)", nullptr));
        comboBox_AOrbital->setItemText(43, QApplication::translate("MainWindow", "5Fxyz", nullptr));
        comboBox_AOrbital->setItemText(44, QApplication::translate("MainWindow", "5Fx(x2-3y2)", nullptr));
        comboBox_AOrbital->setItemText(45, QApplication::translate("MainWindow", "5Fy(3x2-y2)", nullptr));
        comboBox_AOrbital->setItemText(46, QApplication::translate("MainWindow", "5Gz4", nullptr));
        comboBox_AOrbital->setItemText(47, QApplication::translate("MainWindow", "5Gxz3", nullptr));
        comboBox_AOrbital->setItemText(48, QApplication::translate("MainWindow", "5Gyz3", nullptr));
        comboBox_AOrbital->setItemText(49, QApplication::translate("MainWindow", "5Gx3z", nullptr));
        comboBox_AOrbital->setItemText(50, QApplication::translate("MainWindow", "5Gy3z", nullptr));
        comboBox_AOrbital->setItemText(51, QApplication::translate("MainWindow", "5Gxyz2", nullptr));
        comboBox_AOrbital->setItemText(52, QApplication::translate("MainWindow", "5G(x2-y2)z2", nullptr));
        comboBox_AOrbital->setItemText(53, QApplication::translate("MainWindow", "5Gxy(x2-y2)", nullptr));
        comboBox_AOrbital->setItemText(54, QApplication::translate("MainWindow", "5G(x4+y4)", nullptr));
        comboBox_AOrbital->setItemText(55, QApplication::translate("MainWindow", "6S", nullptr));
        comboBox_AOrbital->setItemText(56, QApplication::translate("MainWindow", "6Px", nullptr));
        comboBox_AOrbital->setItemText(57, QApplication::translate("MainWindow", "6Py", nullptr));
        comboBox_AOrbital->setItemText(58, QApplication::translate("MainWindow", "6Pz", nullptr));
        comboBox_AOrbital->setItemText(59, QApplication::translate("MainWindow", "6Dxy", nullptr));
        comboBox_AOrbital->setItemText(60, QApplication::translate("MainWindow", "6Dxz", nullptr));
        comboBox_AOrbital->setItemText(61, QApplication::translate("MainWindow", "6Dxz", nullptr));
        comboBox_AOrbital->setItemText(62, QApplication::translate("MainWindow", "6Dx2-y2", nullptr));
        comboBox_AOrbital->setItemText(63, QApplication::translate("MainWindow", "6Dz2", nullptr));
        comboBox_AOrbital->setItemText(64, QApplication::translate("MainWindow", "6Fz3", nullptr));
        comboBox_AOrbital->setItemText(65, QApplication::translate("MainWindow", "6Fxz2", nullptr));
        comboBox_AOrbital->setItemText(66, QApplication::translate("MainWindow", "6Fyz2", nullptr));
        comboBox_AOrbital->setItemText(67, QApplication::translate("MainWindow", "6Fz(x2-y2)", nullptr));
        comboBox_AOrbital->setItemText(68, QApplication::translate("MainWindow", "6Fxyz", nullptr));
        comboBox_AOrbital->setItemText(69, QApplication::translate("MainWindow", "6Fx(x2-3y2)", nullptr));
        comboBox_AOrbital->setItemText(70, QApplication::translate("MainWindow", "6Fy(3x2-y2)", nullptr));
        comboBox_AOrbital->setItemText(71, QApplication::translate("MainWindow", "6Gz4", nullptr));
        comboBox_AOrbital->setItemText(72, QApplication::translate("MainWindow", "6Gxz3", nullptr));
        comboBox_AOrbital->setItemText(73, QApplication::translate("MainWindow", "6Gyz3", nullptr));
        comboBox_AOrbital->setItemText(74, QApplication::translate("MainWindow", "6Gx3z", nullptr));
        comboBox_AOrbital->setItemText(75, QApplication::translate("MainWindow", "6Gy3z", nullptr));
        comboBox_AOrbital->setItemText(76, QApplication::translate("MainWindow", "6G(x2-y2)z2", nullptr));
        comboBox_AOrbital->setItemText(77, QApplication::translate("MainWindow", "6Gxy(x2-y2)", nullptr));
        comboBox_AOrbital->setItemText(78, QApplication::translate("MainWindow", "6G(x4+y4)", nullptr));
        comboBox_AOrbital->setItemText(79, QApplication::translate("MainWindow", "6Gxyz2", nullptr));
        comboBox_AOrbital->setItemText(80, QApplication::translate("MainWindow", "SP", nullptr));
        comboBox_AOrbital->setItemText(81, QApplication::translate("MainWindow", "SP2", nullptr));
        comboBox_AOrbital->setItemText(82, QApplication::translate("MainWindow", "SP3", nullptr));
        comboBox_AOrbital->setItemText(83, QApplication::translate("MainWindow", "DSP2", nullptr));
        comboBox_AOrbital->setItemText(84, QApplication::translate("MainWindow", "DSP3", nullptr));
        comboBox_AOrbital->setItemText(85, QApplication::translate("MainWindow", "D2SP3", nullptr));

        groupBox->setTitle(QApplication::translate("MainWindow", "            Orbital Type  ", nullptr));
        checkBox_OB_xoy->setText(QApplication::translate("MainWindow", "xoy", nullptr));
        checkBox_OB_positive->setText(QApplication::translate("MainWindow", "positive", nullptr));
        checkBox_OB_xoz->setText(QApplication::translate("MainWindow", "xoz", nullptr));
        checkBox_OB_negative->setText(QApplication::translate("MainWindow", "negative", nullptr));
        checkBox_OB_corner->setText(QApplication::translate("MainWindow", "corner", nullptr));
        checkBox_OB_yoz->setText(QApplication::translate("MainWindow", "yoz", nullptr));
        checkBox_OB_smooth->setText(QApplication::translate("MainWindow", "smooth", nullptr));
        checkBox_OB_mesh->setText(QApplication::translate("MainWindow", "mesh", nullptr));
        checkBox_OB_quarter->setText(QApplication::translate("MainWindow", "quarter", nullptr));
        checkBox_OB_widge->setText(QApplication::translate("MainWindow", "wedge", nullptr));
        pushButton_OL_color->setText(QApplication::translate("MainWindow", "color-Lobe", nullptr));
        pushButton_ON_color->setText(QApplication::translate("MainWindow", "color-Node", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "            Node  Type", nullptr));
        checkBox_NT_Radial->setText(QApplication::translate("MainWindow", "radial", nullptr));
        checkBox_NT_angular->setText(QApplication::translate("MainWindow", "angular", nullptr));
        pushButton_clockwise->setText(QApplication::translate("MainWindow", "Clock", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Align", nullptr));
        pushButton_YZ->setText(QApplication::translate("MainWindow", "YOZ", nullptr));
        pushButton_counterclockwise->setText(QApplication::translate("MainWindow", "Aclock", nullptr));
        pushButton_XY->setText(QApplication::translate("MainWindow", "XOY", nullptr));
        pushButton_Down->setText(QApplication::translate("MainWindow", "Down", nullptr));
        pushButton_XZ->setText(QApplication::translate("MainWindow", "XOZ", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Rotate", nullptr));
        pushButton_Up->setText(QApplication::translate("MainWindow", "Up", nullptr));
        pushButton_restView->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        pushButton_right->setText(QApplication::translate("MainWindow", "-->", nullptr));
        pushButton_left->setText(QApplication::translate("MainWindow", "<--", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
