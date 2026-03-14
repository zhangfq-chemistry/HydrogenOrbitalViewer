/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpinBox *red_spinbox;
    QSlider *red_slider;
    QSlider *green_slider;
    QLabel *green_label;
    QSpinBox *green_spinbox;
    QLabel *red_label;
    QLabel *blue_label;
    QSlider *blue_slider;
    QSpinBox *blue_spinbox;
    QWidget *colorDisplay;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(564, 400);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        red_spinbox = new QSpinBox(Widget);
        red_spinbox->setObjectName(QString::fromUtf8("red_spinbox"));
        red_spinbox->setMaximum(255);

        gridLayout->addWidget(red_spinbox, 0, 2, 1, 1);

        red_slider = new QSlider(Widget);
        red_slider->setObjectName(QString::fromUtf8("red_slider"));
        red_slider->setMaximum(255);
        red_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(red_slider, 0, 1, 1, 1);

        green_slider = new QSlider(Widget);
        green_slider->setObjectName(QString::fromUtf8("green_slider"));
        green_slider->setMaximum(255);
        green_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(green_slider, 1, 1, 1, 1);

        green_label = new QLabel(Widget);
        green_label->setObjectName(QString::fromUtf8("green_label"));

        gridLayout->addWidget(green_label, 1, 0, 1, 1);

        green_spinbox = new QSpinBox(Widget);
        green_spinbox->setObjectName(QString::fromUtf8("green_spinbox"));
        green_spinbox->setMaximum(255);

        gridLayout->addWidget(green_spinbox, 1, 2, 1, 1);

        red_label = new QLabel(Widget);
        red_label->setObjectName(QString::fromUtf8("red_label"));

        gridLayout->addWidget(red_label, 0, 0, 1, 1);

        blue_label = new QLabel(Widget);
        blue_label->setObjectName(QString::fromUtf8("blue_label"));

        gridLayout->addWidget(blue_label, 2, 0, 1, 1);

        blue_slider = new QSlider(Widget);
        blue_slider->setObjectName(QString::fromUtf8("blue_slider"));
        blue_slider->setMaximum(255);
        blue_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(blue_slider, 2, 1, 1, 1);

        blue_spinbox = new QSpinBox(Widget);
        blue_spinbox->setObjectName(QString::fromUtf8("blue_spinbox"));
        blue_spinbox->setMaximum(255);

        gridLayout->addWidget(blue_spinbox, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        colorDisplay = new QWidget(Widget);
        colorDisplay->setObjectName(QString::fromUtf8("colorDisplay"));
        colorDisplay->setAutoFillBackground(true);

        verticalLayout->addWidget(colorDisplay);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);
        QObject::connect(red_slider, SIGNAL(valueChanged(int)), red_spinbox, SLOT(setValue(int)));
        QObject::connect(red_spinbox, SIGNAL(valueChanged(int)), red_slider, SLOT(setValue(int)));
        QObject::connect(green_slider, SIGNAL(valueChanged(int)), green_spinbox, SLOT(setValue(int)));
        QObject::connect(green_spinbox, SIGNAL(valueChanged(int)), green_slider, SLOT(setValue(int)));
        QObject::connect(blue_slider, SIGNAL(valueChanged(int)), blue_spinbox, SLOT(setValue(int)));
        QObject::connect(blue_spinbox, SIGNAL(valueChanged(int)), blue_slider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Pick a color, man!", nullptr));
        green_label->setText(QApplication::translate("Widget", "Green", nullptr));
        red_label->setText(QApplication::translate("Widget", "Red", nullptr));
        blue_label->setText(QApplication::translate("Widget", "Blue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
