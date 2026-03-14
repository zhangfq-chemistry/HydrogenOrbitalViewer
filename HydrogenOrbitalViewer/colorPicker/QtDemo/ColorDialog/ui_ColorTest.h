/********************************************************************************
** Form generated from reading UI file 'ColorTest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORTEST_H
#define UI_COLORTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorTest
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *ColorTest)
    {
        if (ColorTest->objectName().isEmpty())
            ColorTest->setObjectName(QString::fromUtf8("ColorTest"));
        ColorTest->resize(400, 300);
        pushButton = new QPushButton(ColorTest);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 110, 75, 23));

        retranslateUi(ColorTest);

        QMetaObject::connectSlotsByName(ColorTest);
    } // setupUi

    void retranslateUi(QWidget *ColorTest)
    {
        ColorTest->setWindowTitle(QApplication::translate("ColorTest", "ColorTest", nullptr));
        pushButton->setText(QApplication::translate("ColorTest", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorTest: public Ui_ColorTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORTEST_H
