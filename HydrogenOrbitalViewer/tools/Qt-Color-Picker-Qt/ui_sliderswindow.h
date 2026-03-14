/********************************************************************************
** Form generated from reading UI file 'sliderswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDERSWINDOW_H
#define UI_SLIDERSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Widgets/Sliders/CMYK/cmykslider.h"
#include "Widgets/Sliders/HSV/hsvslider.h"
#include "Widgets/Sliders/RGB/rgbslider.h"

QT_BEGIN_NAMESPACE

class Ui_SlidersWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *pHSV;
    QVBoxLayout *verticalLayout_2;
    QWidget *pHue;
    QGridLayout *gridLayout;
    QLabel *lHue;
    HSVSlider *hSlider;
    QSpinBox *spHue;
    QWidget *pSaturation;
    QGridLayout *gridLayout_2;
    QLabel *lSaturation;
    HSVSlider *sSlider;
    QSpinBox *spSaturation;
    QWidget *pValue;
    QGridLayout *gridLayout_3;
    QLabel *lValue;
    HSVSlider *vSlider;
    QSpinBox *spValue;
    QSpacerItem *verticalSpacer;
    QWidget *pRGB;
    QVBoxLayout *verticalLayout;
    QWidget *pRed;
    QGridLayout *gridLayout_4;
    QLabel *lRed;
    RGBSlider *rSlider;
    QSpinBox *spRed;
    QWidget *pGreen;
    QGridLayout *gridLayout_6;
    RGBSlider *gSlider;
    QSpinBox *spGreen;
    QLabel *lGreen;
    QWidget *pBlue;
    QGridLayout *gridLayout_5;
    QSpinBox *spBlue;
    RGBSlider *bSlider;
    QLabel *lBlue;
    QSpacerItem *verticalSpacer_2;
    QWidget *pCMYK;
    QVBoxLayout *verticalLayout_3;
    QWidget *pRed_2;
    QGridLayout *gridLayout_7;
    QSpinBox *spCyan;
    CMYKSlider *cSlider;
    QLabel *lRed_2;
    QWidget *pGreen_2;
    QGridLayout *gridLayout_8;
    CMYKSlider *mSlider;
    QSpinBox *spMagenta;
    QLabel *lGreen_2;
    QWidget *pBlue_2;
    QGridLayout *gridLayout_9;
    QSpinBox *spYellow;
    QLabel *lBlue_2;
    CMYKSlider *ySlider;
    QWidget *pBlue_3;
    QGridLayout *gridLayout_10;
    QSpinBox *spBlack;
    QLabel *lBlue_3;
    CMYKSlider *kSlider;

    void setupUi(QMainWindow *SlidersWindow)
    {
        if (SlidersWindow->objectName().isEmpty())
            SlidersWindow->setObjectName(QString::fromUtf8("SlidersWindow"));
        SlidersWindow->resize(835, 254);
        SlidersWindow->setMinimumSize(QSize(0, 0));
        SlidersWindow->setMaximumSize(QSize(16777215, 254));
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
        SlidersWindow->setPalette(palette);
        centralwidget = new QWidget(SlidersWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        pHSV = new QWidget(centralwidget);
        pHSV->setObjectName(QString::fromUtf8("pHSV"));
        verticalLayout_2 = new QVBoxLayout(pHSV);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(8, 0, 8, 5);
        pHue = new QWidget(pHSV);
        pHue->setObjectName(QString::fromUtf8("pHue"));
        gridLayout = new QGridLayout(pHue);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lHue = new QLabel(pHue);
        lHue->setObjectName(QString::fromUtf8("lHue"));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        lHue->setFont(font);

        gridLayout->addWidget(lHue, 0, 0, 1, 1);

        hSlider = new HSVSlider(pHue);
        hSlider->setObjectName(QString::fromUtf8("hSlider"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hSlider->sizePolicy().hasHeightForWidth());
        hSlider->setSizePolicy(sizePolicy);
        hSlider->setMinimumSize(QSize(200, 36));
        hSlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout->addWidget(hSlider, 1, 0, 1, 1);

        spHue = new QSpinBox(pHue);
        spHue->setObjectName(QString::fromUtf8("spHue"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spHue->sizePolicy().hasHeightForWidth());
        spHue->setSizePolicy(sizePolicy1);
        spHue->setMinimumSize(QSize(53, 30));
        spHue->setMaximumSize(QSize(53, 16777215));
        spHue->setFont(font);
        spHue->setMaximum(360);

        gridLayout->addWidget(spHue, 1, 1, 1, 1);


        verticalLayout_2->addWidget(pHue);

        pSaturation = new QWidget(pHSV);
        pSaturation->setObjectName(QString::fromUtf8("pSaturation"));
        gridLayout_2 = new QGridLayout(pSaturation);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(2);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lSaturation = new QLabel(pSaturation);
        lSaturation->setObjectName(QString::fromUtf8("lSaturation"));
        lSaturation->setFont(font);

        gridLayout_2->addWidget(lSaturation, 0, 0, 1, 1);

        sSlider = new HSVSlider(pSaturation);
        sSlider->setObjectName(QString::fromUtf8("sSlider"));
        sizePolicy.setHeightForWidth(sSlider->sizePolicy().hasHeightForWidth());
        sSlider->setSizePolicy(sizePolicy);
        sSlider->setMinimumSize(QSize(200, 36));
        sSlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout_2->addWidget(sSlider, 1, 0, 1, 1);

        spSaturation = new QSpinBox(pSaturation);
        spSaturation->setObjectName(QString::fromUtf8("spSaturation"));
        sizePolicy1.setHeightForWidth(spSaturation->sizePolicy().hasHeightForWidth());
        spSaturation->setSizePolicy(sizePolicy1);
        spSaturation->setMinimumSize(QSize(53, 30));
        spSaturation->setMaximumSize(QSize(53, 16777215));
        spSaturation->setFont(font);
        spSaturation->setMaximum(255);
        spSaturation->setValue(255);

        gridLayout_2->addWidget(spSaturation, 1, 1, 1, 1);


        verticalLayout_2->addWidget(pSaturation);

        pValue = new QWidget(pHSV);
        pValue->setObjectName(QString::fromUtf8("pValue"));
        gridLayout_3 = new QGridLayout(pValue);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(2);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lValue = new QLabel(pValue);
        lValue->setObjectName(QString::fromUtf8("lValue"));
        lValue->setFont(font);

        gridLayout_3->addWidget(lValue, 0, 0, 1, 1);

        vSlider = new HSVSlider(pValue);
        vSlider->setObjectName(QString::fromUtf8("vSlider"));
        sizePolicy.setHeightForWidth(vSlider->sizePolicy().hasHeightForWidth());
        vSlider->setSizePolicy(sizePolicy);
        vSlider->setMinimumSize(QSize(200, 36));
        vSlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout_3->addWidget(vSlider, 1, 0, 1, 1);

        spValue = new QSpinBox(pValue);
        spValue->setObjectName(QString::fromUtf8("spValue"));
        sizePolicy1.setHeightForWidth(spValue->sizePolicy().hasHeightForWidth());
        spValue->setSizePolicy(sizePolicy1);
        spValue->setMinimumSize(QSize(53, 30));
        spValue->setMaximumSize(QSize(53, 16777215));
        spValue->setFont(font);
        spValue->setMaximum(255);
        spValue->setValue(255);

        gridLayout_3->addWidget(spValue, 1, 1, 1, 1);


        verticalLayout_2->addWidget(pValue);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(pHSV);

        pRGB = new QWidget(centralwidget);
        pRGB->setObjectName(QString::fromUtf8("pRGB"));
        verticalLayout = new QVBoxLayout(pRGB);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(8, 0, 8, 5);
        pRed = new QWidget(pRGB);
        pRed->setObjectName(QString::fromUtf8("pRed"));
        gridLayout_4 = new QGridLayout(pRed);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(5);
        gridLayout_4->setVerticalSpacing(2);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        lRed = new QLabel(pRed);
        lRed->setObjectName(QString::fromUtf8("lRed"));
        lRed->setFont(font);

        gridLayout_4->addWidget(lRed, 0, 0, 1, 1);

        rSlider = new RGBSlider(pRed);
        rSlider->setObjectName(QString::fromUtf8("rSlider"));
        sizePolicy.setHeightForWidth(rSlider->sizePolicy().hasHeightForWidth());
        rSlider->setSizePolicy(sizePolicy);
        rSlider->setMinimumSize(QSize(200, 36));
        rSlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout_4->addWidget(rSlider, 1, 0, 1, 1);

        spRed = new QSpinBox(pRed);
        spRed->setObjectName(QString::fromUtf8("spRed"));
        sizePolicy1.setHeightForWidth(spRed->sizePolicy().hasHeightForWidth());
        spRed->setSizePolicy(sizePolicy1);
        spRed->setMinimumSize(QSize(53, 30));
        spRed->setMaximumSize(QSize(53, 16777215));
        spRed->setFont(font);
        spRed->setMaximum(255);
        spRed->setValue(255);

        gridLayout_4->addWidget(spRed, 1, 1, 1, 1);


        verticalLayout->addWidget(pRed);

        pGreen = new QWidget(pRGB);
        pGreen->setObjectName(QString::fromUtf8("pGreen"));
        gridLayout_6 = new QGridLayout(pGreen);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setVerticalSpacing(2);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gSlider = new RGBSlider(pGreen);
        gSlider->setObjectName(QString::fromUtf8("gSlider"));
        sizePolicy.setHeightForWidth(gSlider->sizePolicy().hasHeightForWidth());
        gSlider->setSizePolicy(sizePolicy);
        gSlider->setMinimumSize(QSize(200, 36));
        gSlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout_6->addWidget(gSlider, 2, 0, 1, 1);

        spGreen = new QSpinBox(pGreen);
        spGreen->setObjectName(QString::fromUtf8("spGreen"));
        sizePolicy1.setHeightForWidth(spGreen->sizePolicy().hasHeightForWidth());
        spGreen->setSizePolicy(sizePolicy1);
        spGreen->setMinimumSize(QSize(53, 30));
        spGreen->setMaximumSize(QSize(53, 16777215));
        spGreen->setFont(font);
        spGreen->setMaximum(255);
        spGreen->setValue(0);

        gridLayout_6->addWidget(spGreen, 2, 1, 1, 1);

        lGreen = new QLabel(pGreen);
        lGreen->setObjectName(QString::fromUtf8("lGreen"));
        lGreen->setFont(font);

        gridLayout_6->addWidget(lGreen, 1, 0, 1, 1);


        verticalLayout->addWidget(pGreen);

        pBlue = new QWidget(pRGB);
        pBlue->setObjectName(QString::fromUtf8("pBlue"));
        gridLayout_5 = new QGridLayout(pBlue);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(2);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        spBlue = new QSpinBox(pBlue);
        spBlue->setObjectName(QString::fromUtf8("spBlue"));
        sizePolicy1.setHeightForWidth(spBlue->sizePolicy().hasHeightForWidth());
        spBlue->setSizePolicy(sizePolicy1);
        spBlue->setMinimumSize(QSize(53, 30));
        spBlue->setMaximumSize(QSize(53, 16777215));
        spBlue->setFont(font);
        spBlue->setMaximum(255);
        spBlue->setValue(0);

        gridLayout_5->addWidget(spBlue, 2, 1, 1, 1);

        bSlider = new RGBSlider(pBlue);
        bSlider->setObjectName(QString::fromUtf8("bSlider"));
        sizePolicy.setHeightForWidth(bSlider->sizePolicy().hasHeightForWidth());
        bSlider->setSizePolicy(sizePolicy);
        bSlider->setMinimumSize(QSize(200, 36));
        bSlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout_5->addWidget(bSlider, 2, 0, 1, 1);

        lBlue = new QLabel(pBlue);
        lBlue->setObjectName(QString::fromUtf8("lBlue"));
        lBlue->setFont(font);

        gridLayout_5->addWidget(lBlue, 1, 0, 1, 1);


        verticalLayout->addWidget(pBlue);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(pRGB);

        pCMYK = new QWidget(centralwidget);
        pCMYK->setObjectName(QString::fromUtf8("pCMYK"));
        verticalLayout_3 = new QVBoxLayout(pCMYK);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(8, 0, 8, 5);
        pRed_2 = new QWidget(pCMYK);
        pRed_2->setObjectName(QString::fromUtf8("pRed_2"));
        gridLayout_7 = new QGridLayout(pRed_2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(2);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        spCyan = new QSpinBox(pRed_2);
        spCyan->setObjectName(QString::fromUtf8("spCyan"));
        sizePolicy1.setHeightForWidth(spCyan->sizePolicy().hasHeightForWidth());
        spCyan->setSizePolicy(sizePolicy1);
        spCyan->setMinimumSize(QSize(53, 30));
        spCyan->setMaximumSize(QSize(53, 16777215));
        spCyan->setFont(font);
        spCyan->setMaximum(255);
        spCyan->setValue(255);

        gridLayout_7->addWidget(spCyan, 1, 1, 1, 1);

        cSlider = new CMYKSlider(pRed_2);
        cSlider->setObjectName(QString::fromUtf8("cSlider"));
        sizePolicy.setHeightForWidth(cSlider->sizePolicy().hasHeightForWidth());
        cSlider->setSizePolicy(sizePolicy);
        cSlider->setMinimumSize(QSize(200, 36));
        cSlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout_7->addWidget(cSlider, 1, 0, 1, 1);

        lRed_2 = new QLabel(pRed_2);
        lRed_2->setObjectName(QString::fromUtf8("lRed_2"));
        lRed_2->setFont(font);

        gridLayout_7->addWidget(lRed_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(pRed_2);

        pGreen_2 = new QWidget(pCMYK);
        pGreen_2->setObjectName(QString::fromUtf8("pGreen_2"));
        gridLayout_8 = new QGridLayout(pGreen_2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setVerticalSpacing(2);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        mSlider = new CMYKSlider(pGreen_2);
        mSlider->setObjectName(QString::fromUtf8("mSlider"));
        sizePolicy.setHeightForWidth(mSlider->sizePolicy().hasHeightForWidth());
        mSlider->setSizePolicy(sizePolicy);
        mSlider->setMinimumSize(QSize(200, 36));
        mSlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout_8->addWidget(mSlider, 2, 0, 1, 1);

        spMagenta = new QSpinBox(pGreen_2);
        spMagenta->setObjectName(QString::fromUtf8("spMagenta"));
        sizePolicy1.setHeightForWidth(spMagenta->sizePolicy().hasHeightForWidth());
        spMagenta->setSizePolicy(sizePolicy1);
        spMagenta->setMinimumSize(QSize(53, 30));
        spMagenta->setMaximumSize(QSize(53, 16777215));
        spMagenta->setFont(font);
        spMagenta->setMaximum(255);
        spMagenta->setValue(0);

        gridLayout_8->addWidget(spMagenta, 2, 1, 1, 1);

        lGreen_2 = new QLabel(pGreen_2);
        lGreen_2->setObjectName(QString::fromUtf8("lGreen_2"));
        lGreen_2->setFont(font);

        gridLayout_8->addWidget(lGreen_2, 1, 0, 1, 1);


        verticalLayout_3->addWidget(pGreen_2);

        pBlue_2 = new QWidget(pCMYK);
        pBlue_2->setObjectName(QString::fromUtf8("pBlue_2"));
        gridLayout_9 = new QGridLayout(pBlue_2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setVerticalSpacing(2);
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        spYellow = new QSpinBox(pBlue_2);
        spYellow->setObjectName(QString::fromUtf8("spYellow"));
        sizePolicy1.setHeightForWidth(spYellow->sizePolicy().hasHeightForWidth());
        spYellow->setSizePolicy(sizePolicy1);
        spYellow->setMinimumSize(QSize(53, 30));
        spYellow->setMaximumSize(QSize(53, 16777215));
        spYellow->setFont(font);
        spYellow->setMaximum(255);
        spYellow->setValue(0);

        gridLayout_9->addWidget(spYellow, 2, 1, 1, 1);

        lBlue_2 = new QLabel(pBlue_2);
        lBlue_2->setObjectName(QString::fromUtf8("lBlue_2"));
        lBlue_2->setFont(font);

        gridLayout_9->addWidget(lBlue_2, 1, 0, 1, 1);

        ySlider = new CMYKSlider(pBlue_2);
        ySlider->setObjectName(QString::fromUtf8("ySlider"));
        sizePolicy.setHeightForWidth(ySlider->sizePolicy().hasHeightForWidth());
        ySlider->setSizePolicy(sizePolicy);
        ySlider->setMinimumSize(QSize(200, 36));
        ySlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout_9->addWidget(ySlider, 2, 0, 1, 1);


        verticalLayout_3->addWidget(pBlue_2);

        pBlue_3 = new QWidget(pCMYK);
        pBlue_3->setObjectName(QString::fromUtf8("pBlue_3"));
        gridLayout_10 = new QGridLayout(pBlue_3);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setVerticalSpacing(2);
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        spBlack = new QSpinBox(pBlue_3);
        spBlack->setObjectName(QString::fromUtf8("spBlack"));
        sizePolicy1.setHeightForWidth(spBlack->sizePolicy().hasHeightForWidth());
        spBlack->setSizePolicy(sizePolicy1);
        spBlack->setMinimumSize(QSize(53, 30));
        spBlack->setMaximumSize(QSize(53, 16777215));
        spBlack->setFont(font);
        spBlack->setMaximum(255);
        spBlack->setValue(0);

        gridLayout_10->addWidget(spBlack, 2, 1, 1, 1);

        lBlue_3 = new QLabel(pBlue_3);
        lBlue_3->setObjectName(QString::fromUtf8("lBlue_3"));
        lBlue_3->setFont(font);

        gridLayout_10->addWidget(lBlue_3, 1, 0, 1, 1);

        kSlider = new CMYKSlider(pBlue_3);
        kSlider->setObjectName(QString::fromUtf8("kSlider"));
        sizePolicy.setHeightForWidth(kSlider->sizePolicy().hasHeightForWidth());
        kSlider->setSizePolicy(sizePolicy);
        kSlider->setMinimumSize(QSize(200, 36));
        kSlider->setStyleSheet(QString::fromUtf8("background:#3a3"));

        gridLayout_10->addWidget(kSlider, 2, 0, 1, 1);


        verticalLayout_3->addWidget(pBlue_3);


        horizontalLayout->addWidget(pCMYK);

        SlidersWindow->setCentralWidget(centralwidget);

        retranslateUi(SlidersWindow);

        QMetaObject::connectSlotsByName(SlidersWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SlidersWindow)
    {
        SlidersWindow->setWindowTitle(QApplication::translate("SlidersWindow", "Sliders", nullptr));
        lHue->setText(QApplication::translate("SlidersWindow", "Hue", nullptr));
        lSaturation->setText(QApplication::translate("SlidersWindow", "Saturation", nullptr));
        lValue->setText(QApplication::translate("SlidersWindow", "Value", nullptr));
        lRed->setText(QApplication::translate("SlidersWindow", "Red", nullptr));
        lGreen->setText(QApplication::translate("SlidersWindow", "Green", nullptr));
        lBlue->setText(QApplication::translate("SlidersWindow", "Blue", nullptr));
        lRed_2->setText(QApplication::translate("SlidersWindow", "Cyan", nullptr));
        lGreen_2->setText(QApplication::translate("SlidersWindow", "Magenta", nullptr));
        lBlue_2->setText(QApplication::translate("SlidersWindow", "Yellow", nullptr));
        lBlue_3->setText(QApplication::translate("SlidersWindow", "Black", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SlidersWindow: public Ui_SlidersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDERSWINDOW_H
