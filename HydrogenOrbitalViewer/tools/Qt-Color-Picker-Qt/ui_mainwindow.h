/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Widgets/ColorWidgets/colorsample.h"
#include "Widgets/ColorWidgets/hselector.h"
#include "Widgets/ColorWidgets/svselector.h"
#include "Widgets/colortext.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *topVSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *leftHSpacer;
    QWidget *pColorPicker;
    QGridLayout *gridLayout;
    ColorSample *colorSample;
    HSelector *hSelector;
    SVSelector *svSelector;
    QSpacerItem *vSpacer2;
    QSpacerItem *hSpacer2;
    QSpacerItem *innerHSpacer1;
    QVBoxLayout *loColorText;
    QWidget *pHSV;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *bHSV;
    ColorText *leHSV;
    QSpacerItem *verticalSpacer_5;
    QWidget *pRGB;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *bRGB;
    ColorText *leRGB;
    QSpacerItem *verticalSpacer_6;
    QWidget *pCMYK;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bCMYK;
    ColorText *leCMYK;
    QSpacerItem *verticalSpacer_4;
    QWidget *pHex;
    QGridLayout *gridLayout_2;
    ColorText *leHex;
    QPushButton *bPasteHex;
    QPushButton *bHex;
    QPushButton *bHexHash;
    QSpacerItem *verticalSpacer_7;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *vSpacer1;
    QSpacerItem *rightHSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *bottomVSpacer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(636, 414);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(636, 414));
        MainWindow->setMaximumSize(QSize(636, 414));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(219, 221, 219, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topVSpacer = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout->addItem(topVSpacer);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftHSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(leftHSpacer);

        pColorPicker = new QWidget(widget);
        pColorPicker->setObjectName(QString::fromUtf8("pColorPicker"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pColorPicker->sizePolicy().hasHeightForWidth());
        pColorPicker->setSizePolicy(sizePolicy1);
        pColorPicker->setMinimumSize(QSize(0, 365));
        pColorPicker->setMaximumSize(QSize(16777215, 365));
        pColorPicker->setAutoFillBackground(false);
        gridLayout = new QGridLayout(pColorPicker);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        colorSample = new ColorSample(pColorPicker);
        colorSample->setObjectName(QString::fromUtf8("colorSample"));
        sizePolicy1.setHeightForWidth(colorSample->sizePolicy().hasHeightForWidth());
        colorSample->setSizePolicy(sizePolicy1);
        colorSample->setMinimumSize(QSize(260, 80));
        colorSample->setStyleSheet(QString::fromUtf8("border:1px solid;"));

        gridLayout->addWidget(colorSample, 3, 0, 1, 1);

        hSelector = new HSelector(pColorPicker);
        hSelector->setObjectName(QString::fromUtf8("hSelector"));
        sizePolicy1.setHeightForWidth(hSelector->sizePolicy().hasHeightForWidth());
        hSelector->setSizePolicy(sizePolicy1);
        hSelector->setMinimumSize(QSize(54, 365));
        hSelector->setMaximumSize(QSize(54, 16777215));
        hSelector->setAutoFillBackground(false);
        hSelector->setStyleSheet(QString::fromUtf8("border:1px solid"));

        gridLayout->addWidget(hSelector, 0, 2, 4, 1, Qt::AlignTop);

        svSelector = new SVSelector(pColorPicker);
        svSelector->setObjectName(QString::fromUtf8("svSelector"));
        sizePolicy1.setHeightForWidth(svSelector->sizePolicy().hasHeightForWidth());
        svSelector->setSizePolicy(sizePolicy1);
        svSelector->setMinimumSize(QSize(260, 260));
        svSelector->setStyleSheet(QString::fromUtf8("border:1px solid;"));

        gridLayout->addWidget(svSelector, 0, 0, 1, 1, Qt::AlignTop);

        vSpacer2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(vSpacer2, 1, 0, 1, 1);

        hSpacer2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(hSpacer2, 0, 1, 2, 1);

        svSelector->raise();
        colorSample->raise();
        hSelector->raise();

        horizontalLayout->addWidget(pColorPicker);

        innerHSpacer1 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(innerHSpacer1);

        loColorText = new QVBoxLayout();
        loColorText->setSpacing(0);
        loColorText->setObjectName(QString::fromUtf8("loColorText"));
        loColorText->setContentsMargins(-1, -1, 0, -1);
        pHSV = new QWidget(widget);
        pHSV->setObjectName(QString::fromUtf8("pHSV"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pHSV->sizePolicy().hasHeightForWidth());
        pHSV->setSizePolicy(sizePolicy2);
        pHSV->setMinimumSize(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(pHSV);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        bHSV = new QPushButton(pHSV);
        bHSV->setObjectName(QString::fromUtf8("bHSV"));
        sizePolicy1.setHeightForWidth(bHSV->sizePolicy().hasHeightForWidth());
        bHSV->setSizePolicy(sizePolicy1);
        bHSV->setMinimumSize(QSize(110, 36));
        QFont font;
        font.setFamily(QString::fromUtf8("Trebuchet MS"));
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        bHSV->setFont(font);

        horizontalLayout_4->addWidget(bHSV);

        leHSV = new ColorText(pHSV);
        leHSV->setObjectName(QString::fromUtf8("leHSV"));
        sizePolicy1.setHeightForWidth(leHSV->sizePolicy().hasHeightForWidth());
        leHSV->setSizePolicy(sizePolicy1);
        leHSV->setMinimumSize(QSize(160, 36));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        leHSV->setFont(font1);
        leHSV->setStyleSheet(QString::fromUtf8(""));
        leHSV->setReadOnly(false);

        horizontalLayout_4->addWidget(leHSV, 0, Qt::AlignLeft);


        loColorText->addWidget(pHSV);

        verticalSpacer_5 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        loColorText->addItem(verticalSpacer_5);

        pRGB = new QWidget(widget);
        pRGB->setObjectName(QString::fromUtf8("pRGB"));
        sizePolicy2.setHeightForWidth(pRGB->sizePolicy().hasHeightForWidth());
        pRGB->setSizePolicy(sizePolicy2);
        pRGB->setMinimumSize(QSize(0, 0));
        horizontalLayout_3 = new QHBoxLayout(pRGB);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        bRGB = new QPushButton(pRGB);
        bRGB->setObjectName(QString::fromUtf8("bRGB"));
        sizePolicy1.setHeightForWidth(bRGB->sizePolicy().hasHeightForWidth());
        bRGB->setSizePolicy(sizePolicy1);
        bRGB->setMinimumSize(QSize(110, 36));
        bRGB->setFont(font);

        horizontalLayout_3->addWidget(bRGB);

        leRGB = new ColorText(pRGB);
        leRGB->setObjectName(QString::fromUtf8("leRGB"));
        sizePolicy1.setHeightForWidth(leRGB->sizePolicy().hasHeightForWidth());
        leRGB->setSizePolicy(sizePolicy1);
        leRGB->setMinimumSize(QSize(160, 36));
        leRGB->setFont(font1);
        leRGB->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(leRGB);


        loColorText->addWidget(pRGB);

        verticalSpacer_6 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        loColorText->addItem(verticalSpacer_6);

        pCMYK = new QWidget(widget);
        pCMYK->setObjectName(QString::fromUtf8("pCMYK"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pCMYK->sizePolicy().hasHeightForWidth());
        pCMYK->setSizePolicy(sizePolicy3);
        pCMYK->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(pCMYK);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        bCMYK = new QPushButton(pCMYK);
        bCMYK->setObjectName(QString::fromUtf8("bCMYK"));
        sizePolicy1.setHeightForWidth(bCMYK->sizePolicy().hasHeightForWidth());
        bCMYK->setSizePolicy(sizePolicy1);
        bCMYK->setMinimumSize(QSize(110, 36));
        bCMYK->setFont(font);

        horizontalLayout_2->addWidget(bCMYK);

        leCMYK = new ColorText(pCMYK);
        leCMYK->setObjectName(QString::fromUtf8("leCMYK"));
        sizePolicy1.setHeightForWidth(leCMYK->sizePolicy().hasHeightForWidth());
        leCMYK->setSizePolicy(sizePolicy1);
        leCMYK->setMinimumSize(QSize(160, 36));
        leCMYK->setFont(font1);
        leCMYK->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(leCMYK);


        loColorText->addWidget(pCMYK);

        verticalSpacer_4 = new QSpacerItem(30, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        loColorText->addItem(verticalSpacer_4);

        pHex = new QWidget(widget);
        pHex->setObjectName(QString::fromUtf8("pHex"));
        sizePolicy2.setHeightForWidth(pHex->sizePolicy().hasHeightForWidth());
        pHex->setSizePolicy(sizePolicy2);
        pHex->setMinimumSize(QSize(0, 0));
        gridLayout_2 = new QGridLayout(pHex);
        gridLayout_2->setSpacing(10);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        leHex = new ColorText(pHex);
        leHex->setObjectName(QString::fromUtf8("leHex"));
        sizePolicy1.setHeightForWidth(leHex->sizePolicy().hasHeightForWidth());
        leHex->setSizePolicy(sizePolicy1);
        leHex->setMinimumSize(QSize(160, 36));
        leHex->setFont(font1);
        leHex->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(leHex, 0, 1, 1, 1);

        bPasteHex = new QPushButton(pHex);
        bPasteHex->setObjectName(QString::fromUtf8("bPasteHex"));
        bPasteHex->setMinimumSize(QSize(0, 36));
        bPasteHex->setFont(font);

        gridLayout_2->addWidget(bPasteHex, 1, 1, 1, 1);

        bHex = new QPushButton(pHex);
        bHex->setObjectName(QString::fromUtf8("bHex"));
        sizePolicy1.setHeightForWidth(bHex->sizePolicy().hasHeightForWidth());
        bHex->setSizePolicy(sizePolicy1);
        bHex->setMinimumSize(QSize(110, 36));
        bHex->setFont(font);

        gridLayout_2->addWidget(bHex, 0, 0, 1, 1);

        bHexHash = new QPushButton(pHex);
        bHexHash->setObjectName(QString::fromUtf8("bHexHash"));
        sizePolicy1.setHeightForWidth(bHexHash->sizePolicy().hasHeightForWidth());
        bHexHash->setSizePolicy(sizePolicy1);
        bHexHash->setMinimumSize(QSize(110, 36));
        bHexHash->setFont(font);

        gridLayout_2->addWidget(bHexHash, 1, 0, 1, 1);


        loColorText->addWidget(pHex, 0, Qt::AlignTop);

        verticalSpacer_7 = new QSpacerItem(20, 32, QSizePolicy::Minimum, QSizePolicy::Expanding);

        loColorText->addItem(verticalSpacer_7);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy4);
        widget_2->setMinimumSize(QSize(0, 50));
        horizontalLayout_5 = new QHBoxLayout(widget_2);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);

        loColorText->addWidget(widget_2);

        vSpacer1 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        loColorText->addItem(vSpacer1);


        horizontalLayout->addLayout(loColorText);

        rightHSpacer = new QSpacerItem(10, 18, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(rightHSpacer);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        bottomVSpacer = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout->addItem(bottomVSpacer);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Lucida Sans Unicode"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        statusBar->setFont(font2);
        statusBar->setAutoFillBackground(false);
        statusBar->setStyleSheet(QString::fromUtf8("border-top:1px dotted #444;"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(bHSV, bRGB);
        QWidget::setTabOrder(bRGB, bCMYK);
        QWidget::setTabOrder(bCMYK, bHex);
        QWidget::setTabOrder(bHex, bHexHash);
        QWidget::setTabOrder(bHexHash, leHSV);
        QWidget::setTabOrder(leHSV, leRGB);
        QWidget::setTabOrder(leRGB, leCMYK);
        QWidget::setTabOrder(leCMYK, leHex);
        QWidget::setTabOrder(leHex, bPasteHex);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QtColorPicker v1.0.2", nullptr));
        bHSV->setText(QApplication::translate("MainWindow", "HSV", nullptr));
        leHSV->setText(QString());
        bRGB->setText(QApplication::translate("MainWindow", "RGB", nullptr));
        leRGB->setText(QString());
        bCMYK->setText(QApplication::translate("MainWindow", "CMYK", nullptr));
        leCMYK->setText(QString());
        leHex->setText(QString());
        bPasteHex->setText(QApplication::translate("MainWindow", "Paste Hex", nullptr));
        bHex->setText(QApplication::translate("MainWindow", "Hex", nullptr));
        bHexHash->setText(QApplication::translate("MainWindow", "Hex #", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
