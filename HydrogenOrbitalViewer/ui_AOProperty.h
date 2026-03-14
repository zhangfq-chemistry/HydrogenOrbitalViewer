/********************************************************************************
** Form generated from reading UI file 'AOProperty.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AOPROPERTY_H
#define UI_AOPROPERTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_OrbitalProperty
{
public:
    QFormLayout *formLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBox_OL_negative_green;
    QSpinBox *spinBox_OL_positive_blue;
    QSpinBox *spinBox_OL_negative_red;
    QLabel *label_13;
    QPushButton *pushButton_OL_positive;
    QPushButton *pushButton_OL_negative;
    QSpinBox *spinBox_OL_positive_green;
    QSpinBox *spinBox_OL_negative_blue;
    QSpinBox *spinBox_OL_positive_opacity;
    QSpinBox *spinBox_OL_positive_red;
    QSpinBox *spinBox_OL_negative_opacity;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_flipPhase;
    QLabel *label_7;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_reGenerate;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_ONP_opacity;
    QPushButton *pushButton_ON_Theta;
    QLabel *label_11;
    QSpinBox *spinBox_ONR_opacity;
    QPushButton *pushButton_ON_Phi;
    QLabel *label_5;
    QPushButton *pushButton_ON_R;
    QSpinBox *spinBox_ONT_red;
    QSpinBox *spinBox_ONT_opacity;
    QLabel *label_12;
    QLabel *label_10;
    QLabel *label_8;
    QSpinBox *spinBox_ONP_red;
    QSpinBox *spinBox_ONR_red;
    QSpinBox *spinBox_ONR_green;
    QSpinBox *spinBox_ONR_blue;
    QSpinBox *spinBox_ONT_green;
    QSpinBox *spinBox_ONP_green;
    QSpinBox *spinBox_ONT_blue;
    QSpinBox *spinBox_ONP_blue;

    void setupUi(QDialog *OrbitalProperty)
    {
        if (OrbitalProperty->objectName().isEmpty())
            OrbitalProperty->setObjectName(QString::fromUtf8("OrbitalProperty"));
        OrbitalProperty->resize(370, 538);
        formLayout_2 = new QFormLayout(OrbitalProperty);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        groupBox = new QGroupBox(OrbitalProperty);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        spinBox_OL_negative_green = new QSpinBox(groupBox);
        spinBox_OL_negative_green->setObjectName(QString::fromUtf8("spinBox_OL_negative_green"));
        spinBox_OL_negative_green->setMaximum(255);

        gridLayout->addWidget(spinBox_OL_negative_green, 2, 2, 1, 1);

        spinBox_OL_positive_blue = new QSpinBox(groupBox);
        spinBox_OL_positive_blue->setObjectName(QString::fromUtf8("spinBox_OL_positive_blue"));
        spinBox_OL_positive_blue->setMaximum(255);

        gridLayout->addWidget(spinBox_OL_positive_blue, 3, 1, 1, 1);

        spinBox_OL_negative_red = new QSpinBox(groupBox);
        spinBox_OL_negative_red->setObjectName(QString::fromUtf8("spinBox_OL_negative_red"));
        spinBox_OL_negative_red->setMaximum(255);

        gridLayout->addWidget(spinBox_OL_negative_red, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_13, 6, 0, 1, 1);

        pushButton_OL_positive = new QPushButton(groupBox);
        pushButton_OL_positive->setObjectName(QString::fromUtf8("pushButton_OL_positive"));

        gridLayout->addWidget(pushButton_OL_positive, 0, 1, 1, 1);

        pushButton_OL_negative = new QPushButton(groupBox);
        pushButton_OL_negative->setObjectName(QString::fromUtf8("pushButton_OL_negative"));

        gridLayout->addWidget(pushButton_OL_negative, 0, 2, 1, 1);

        spinBox_OL_positive_green = new QSpinBox(groupBox);
        spinBox_OL_positive_green->setObjectName(QString::fromUtf8("spinBox_OL_positive_green"));
        spinBox_OL_positive_green->setMaximum(255);

        gridLayout->addWidget(spinBox_OL_positive_green, 2, 1, 1, 1);

        spinBox_OL_negative_blue = new QSpinBox(groupBox);
        spinBox_OL_negative_blue->setObjectName(QString::fromUtf8("spinBox_OL_negative_blue"));
        spinBox_OL_negative_blue->setMaximum(255);

        gridLayout->addWidget(spinBox_OL_negative_blue, 3, 2, 1, 1);

        spinBox_OL_positive_opacity = new QSpinBox(groupBox);
        spinBox_OL_positive_opacity->setObjectName(QString::fromUtf8("spinBox_OL_positive_opacity"));
        spinBox_OL_positive_opacity->setMaximum(255);

        gridLayout->addWidget(spinBox_OL_positive_opacity, 4, 1, 1, 1);

        spinBox_OL_positive_red = new QSpinBox(groupBox);
        spinBox_OL_positive_red->setObjectName(QString::fromUtf8("spinBox_OL_positive_red"));
        spinBox_OL_positive_red->setMaximum(255);

        gridLayout->addWidget(spinBox_OL_positive_red, 1, 1, 1, 1);

        spinBox_OL_negative_opacity = new QSpinBox(groupBox);
        spinBox_OL_negative_opacity->setObjectName(QString::fromUtf8("spinBox_OL_negative_opacity"));
        spinBox_OL_negative_opacity->setMaximum(255);

        gridLayout->addWidget(spinBox_OL_negative_opacity, 4, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 6, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        pushButton_ok = new QPushButton(groupBox);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        gridLayout->addWidget(pushButton_ok, 6, 3, 1, 1);

        pushButton_flipPhase = new QPushButton(groupBox);
        pushButton_flipPhase->setObjectName(QString::fromUtf8("pushButton_flipPhase"));

        gridLayout->addWidget(pushButton_flipPhase, 0, 3, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        pushButton_cancel = new QPushButton(groupBox);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        gridLayout->addWidget(pushButton_cancel, 4, 3, 1, 1);

        pushButton_reGenerate = new QPushButton(groupBox);
        pushButton_reGenerate->setObjectName(QString::fromUtf8("pushButton_reGenerate"));

        gridLayout->addWidget(pushButton_reGenerate, 6, 2, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout);


        formLayout_2->setWidget(2, QFormLayout::LabelRole, groupBox);

        groupBox_2 = new QGroupBox(OrbitalProperty);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        spinBox_ONP_opacity = new QSpinBox(groupBox_2);
        spinBox_ONP_opacity->setObjectName(QString::fromUtf8("spinBox_ONP_opacity"));
        spinBox_ONP_opacity->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONP_opacity, 4, 3, 1, 1);

        pushButton_ON_Theta = new QPushButton(groupBox_2);
        pushButton_ON_Theta->setObjectName(QString::fromUtf8("pushButton_ON_Theta"));

        gridLayout_2->addWidget(pushButton_ON_Theta, 0, 2, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        spinBox_ONR_opacity = new QSpinBox(groupBox_2);
        spinBox_ONR_opacity->setObjectName(QString::fromUtf8("spinBox_ONR_opacity"));
        spinBox_ONR_opacity->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONR_opacity, 4, 1, 1, 1);

        pushButton_ON_Phi = new QPushButton(groupBox_2);
        pushButton_ON_Phi->setObjectName(QString::fromUtf8("pushButton_ON_Phi"));

        gridLayout_2->addWidget(pushButton_ON_Phi, 0, 3, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        pushButton_ON_R = new QPushButton(groupBox_2);
        pushButton_ON_R->setObjectName(QString::fromUtf8("pushButton_ON_R"));

        gridLayout_2->addWidget(pushButton_ON_R, 0, 1, 1, 1);

        spinBox_ONT_red = new QSpinBox(groupBox_2);
        spinBox_ONT_red->setObjectName(QString::fromUtf8("spinBox_ONT_red"));
        spinBox_ONT_red->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONT_red, 1, 2, 1, 1);

        spinBox_ONT_opacity = new QSpinBox(groupBox_2);
        spinBox_ONT_opacity->setObjectName(QString::fromUtf8("spinBox_ONT_opacity"));
        spinBox_ONT_opacity->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONT_opacity, 4, 2, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 3, 0, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_8, 4, 0, 1, 1);

        spinBox_ONP_red = new QSpinBox(groupBox_2);
        spinBox_ONP_red->setObjectName(QString::fromUtf8("spinBox_ONP_red"));
        spinBox_ONP_red->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONP_red, 1, 3, 1, 1);

        spinBox_ONR_red = new QSpinBox(groupBox_2);
        spinBox_ONR_red->setObjectName(QString::fromUtf8("spinBox_ONR_red"));
        spinBox_ONR_red->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONR_red, 1, 1, 1, 1);

        spinBox_ONR_green = new QSpinBox(groupBox_2);
        spinBox_ONR_green->setObjectName(QString::fromUtf8("spinBox_ONR_green"));
        spinBox_ONR_green->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONR_green, 2, 1, 1, 1);

        spinBox_ONR_blue = new QSpinBox(groupBox_2);
        spinBox_ONR_blue->setObjectName(QString::fromUtf8("spinBox_ONR_blue"));
        spinBox_ONR_blue->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONR_blue, 3, 1, 1, 1);

        spinBox_ONT_green = new QSpinBox(groupBox_2);
        spinBox_ONT_green->setObjectName(QString::fromUtf8("spinBox_ONT_green"));
        spinBox_ONT_green->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONT_green, 2, 2, 1, 1);

        spinBox_ONP_green = new QSpinBox(groupBox_2);
        spinBox_ONP_green->setObjectName(QString::fromUtf8("spinBox_ONP_green"));
        spinBox_ONP_green->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONP_green, 2, 3, 1, 1);

        spinBox_ONT_blue = new QSpinBox(groupBox_2);
        spinBox_ONT_blue->setObjectName(QString::fromUtf8("spinBox_ONT_blue"));
        spinBox_ONT_blue->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONT_blue, 3, 2, 1, 1);

        spinBox_ONP_blue = new QSpinBox(groupBox_2);
        spinBox_ONP_blue->setObjectName(QString::fromUtf8("spinBox_ONP_blue"));
        spinBox_ONP_blue->setMaximum(255);

        gridLayout_2->addWidget(spinBox_ONP_blue, 3, 3, 1, 1);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, gridLayout_2);


        formLayout_2->setWidget(3, QFormLayout::LabelRole, groupBox_2);


        retranslateUi(OrbitalProperty);

        QMetaObject::connectSlotsByName(OrbitalProperty);
    } // setupUi

    void retranslateUi(QDialog *OrbitalProperty)
    {
        OrbitalProperty->setWindowTitle(QApplication::translate("OrbitalProperty", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("OrbitalProperty", "                              Orbital     Lobes      ", nullptr));
        label->setText(QApplication::translate("OrbitalProperty", "Red", nullptr));
        label_13->setText(QApplication::translate("OrbitalProperty", "IsoValue", nullptr));
        pushButton_OL_positive->setText(QApplication::translate("OrbitalProperty", "+", nullptr));
        pushButton_OL_negative->setText(QApplication::translate("OrbitalProperty", "\342\210\222", nullptr));
        label_3->setText(QApplication::translate("OrbitalProperty", "Blue", nullptr));
        label_2->setText(QApplication::translate("OrbitalProperty", "Green", nullptr));
        label_4->setText(QApplication::translate("OrbitalProperty", "Color", nullptr));
        pushButton_ok->setText(QApplication::translate("OrbitalProperty", "OK", nullptr));
        pushButton_flipPhase->setText(QApplication::translate("OrbitalProperty", "Flip Phase", nullptr));
        label_7->setText(QApplication::translate("OrbitalProperty", "Opacity", nullptr));
        pushButton_cancel->setText(QApplication::translate("OrbitalProperty", "Cancel", nullptr));
        pushButton_reGenerate->setText(QApplication::translate("OrbitalProperty", "reGenerate", nullptr));
        groupBox_2->setTitle(QApplication::translate("OrbitalProperty", "                                Orbital     Nodes  ", nullptr));
        pushButton_ON_Theta->setText(QApplication::translate("OrbitalProperty", "Theta", nullptr));
        label_11->setText(QApplication::translate("OrbitalProperty", "Green", nullptr));
        pushButton_ON_Phi->setText(QApplication::translate("OrbitalProperty", "Phi", nullptr));
        label_5->setText(QApplication::translate("OrbitalProperty", "Color", nullptr));
        pushButton_ON_R->setText(QApplication::translate("OrbitalProperty", "R", nullptr));
        label_12->setText(QApplication::translate("OrbitalProperty", "Blue", nullptr));
        label_10->setText(QApplication::translate("OrbitalProperty", "Red", nullptr));
        label_8->setText(QApplication::translate("OrbitalProperty", "Opacity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrbitalProperty: public Ui_OrbitalProperty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AOPROPERTY_H
