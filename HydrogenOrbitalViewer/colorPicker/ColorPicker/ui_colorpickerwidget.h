/********************************************************************************
** Form generated from reading UI file 'colorpickerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORPICKERWIDGET_H
#define UI_COLORPICKERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myqlabel.h"

QT_BEGIN_NAMESPACE

class Ui_ColorPickerWidget
{
public:
    QGroupBox *groupBox;
    MyQLabel *previewlabel;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_19;
    QLineEdit *decLineEdit;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_20;
    QLineEdit *hexLineEdit;
    QHBoxLayout *horizontalLayout_19;
    QLabel *locationLabel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_7;
    QLineEdit *redLineEdit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_8;
    QLineEdit *greenLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *blueLineEdit;
    QLabel *colorLabel;

    void setupUi(QWidget *ColorPickerWidget)
    {
        if (ColorPickerWidget->objectName().isEmpty())
            ColorPickerWidget->setObjectName(QString::fromUtf8("ColorPickerWidget"));
        ColorPickerWidget->resize(686, 551);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ColorPickerWidget->setWindowIcon(icon);
        groupBox = new QGroupBox(ColorPickerWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(390, 170, 301, 381));
        groupBox->setMouseTracking(true);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 103, 155);\n"
""));
        previewlabel = new MyQLabel(groupBox);
        previewlabel->setObjectName(QString::fromUtf8("previewlabel"));
        previewlabel->setGeometry(QRect(1, 1, 299, 265));
        previewlabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-left:1px solid #999999;\n"
"border-top:1px solid #999999;\n"
"border-right:1px solid #999999;\n"
""));
        previewlabel->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 270, 281, 31));
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 300, 121, 74));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_17->addWidget(label_19);

        decLineEdit = new QLineEdit(layoutWidget);
        decLineEdit->setObjectName(QString::fromUtf8("decLineEdit"));
        decLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        decLineEdit->setReadOnly(true);

        horizontalLayout_17->addWidget(decLineEdit);


        verticalLayout_6->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_18->addWidget(label_20);

        hexLineEdit = new QLineEdit(layoutWidget);
        hexLineEdit->setObjectName(QString::fromUtf8("hexLineEdit"));
        hexLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        hexLineEdit->setReadOnly(true);

        horizontalLayout_18->addWidget(hexLineEdit);


        verticalLayout_6->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        locationLabel = new QLabel(layoutWidget);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));
        locationLabel->setMinimumSize(QSize(0, 20));
        locationLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(locationLabel);


        verticalLayout_6->addLayout(horizontalLayout_19);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 300, 81, 74));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_13->addWidget(label_7);

        redLineEdit = new QLineEdit(layoutWidget1);
        redLineEdit->setObjectName(QString::fromUtf8("redLineEdit"));
        redLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        redLineEdit->setReadOnly(true);

        horizontalLayout_13->addWidget(redLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_14->addWidget(label_8);

        greenLineEdit = new QLineEdit(layoutWidget1);
        greenLineEdit->setObjectName(QString::fromUtf8("greenLineEdit"));
        greenLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        greenLineEdit->setReadOnly(true);

        horizontalLayout_14->addWidget(greenLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        blueLineEdit = new QLineEdit(layoutWidget1);
        blueLineEdit->setObjectName(QString::fromUtf8("blueLineEdit"));
        blueLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        blueLineEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(blueLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        colorLabel = new QLabel(groupBox);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));
        colorLabel->setGeometry(QRect(10, 300, 61, 61));
        colorLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(ColorPickerWidget);

        QMetaObject::connectSlotsByName(ColorPickerWidget);
    } // setupUi

    void retranslateUi(QWidget *ColorPickerWidget)
    {
        ColorPickerWidget->setWindowTitle(QApplication::translate("ColorPickerWidget", "\345\217\226\350\211\262\345\231\250", nullptr));
        groupBox->setTitle(QString());
        previewlabel->setText(QString());
        label_2->setText(QApplication::translate("ColorPickerWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\215\225\345\207\273\351\274\240\346\240\207\351\200\211\346\213\251\351\242\234\350\211\262,\346\214\211Esc\351\200\200\345\207\272\345\217\226\350\211\262,\346\214\211\346\226\271\345\220\221\351\224\256\345\256\232\344\275\215\351\242\234\350\211\262</span></p></body></html>", nullptr));
        label_19->setText(QApplication::translate("ColorPickerWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\215\201\350\277\233\345\210\266:&nbsp;</span></p></body></html>", nullptr));
        label_20->setText(QApplication::translate("ColorPickerWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\215\201\345\205\255\350\277\233\345\210\266:</span></p></body></html>", nullptr));
        locationLabel->setText(QApplication::translate("ColorPickerWidget", "<html><head/><body><p><span style=\" font-size:10pt; color:rgb(255,232,86);\">X=0 , Y=0</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("ColorPickerWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\272\242:</span></p></body></html>", nullptr));
        label_8->setText(QApplication::translate("ColorPickerWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\273\277:</span></p></body></html>", nullptr));
        label_9->setText(QApplication::translate("ColorPickerWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\223\235:</span></p></body></html>", nullptr));
        colorLabel->setText(QApplication::translate("ColorPickerWidget", "\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorPickerWidget: public Ui_ColorPickerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORPICKERWIDGET_H
