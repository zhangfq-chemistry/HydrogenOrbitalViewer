/********************************************************************************
** Form generated from reading UI file 'MO.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MO_H
#define UI_MO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_MOForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_z;
    QPushButton *pushButton_close;
    QTextEdit *MO_textEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_y;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_x;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox;
    QComboBox *comboBox_orb;
    QPushButton *pushButton_addAtom;
    QPushButton *pushButton_import;
    QPushButton *pushButton_centralize;
    QPushButton *pushButton_reset;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_coeff;
    QPushButton *pushButton_addMolecule;

    void setupUi(QDialog *MOForm)
    {
        if (MOForm->objectName().isEmpty())
            MOForm->setObjectName(QString::fromUtf8("MOForm"));
        MOForm->resize(385, 603);
        gridLayout = new QGridLayout(MOForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(MOForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_z = new QLineEdit(MOForm);
        lineEdit_z->setObjectName(QString::fromUtf8("lineEdit_z"));

        horizontalLayout_3->addWidget(lineEdit_z);


        gridLayout->addLayout(horizontalLayout_3, 11, 0, 1, 1);

        pushButton_close = new QPushButton(MOForm);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));

        gridLayout->addWidget(pushButton_close, 11, 1, 1, 1);

        MO_textEdit = new QTextEdit(MOForm);
        MO_textEdit->setObjectName(QString::fromUtf8("MO_textEdit"));
        MO_textEdit->setTabChangesFocus(true);
        MO_textEdit->setAcceptRichText(false);

        gridLayout->addWidget(MO_textEdit, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(MOForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_y = new QLineEdit(MOForm);
        lineEdit_y->setObjectName(QString::fromUtf8("lineEdit_y"));

        horizontalLayout_2->addWidget(lineEdit_y);


        gridLayout->addLayout(horizontalLayout_2, 8, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MOForm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_x = new QLineEdit(MOForm);
        lineEdit_x->setObjectName(QString::fromUtf8("lineEdit_x"));

        horizontalLayout->addWidget(lineEdit_x);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox = new QComboBox(MOForm);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_5->addWidget(comboBox);

        comboBox_orb = new QComboBox(MOForm);
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->addItem(QString());
        comboBox_orb->setObjectName(QString::fromUtf8("comboBox_orb"));

        horizontalLayout_5->addWidget(comboBox_orb);

        pushButton_addAtom = new QPushButton(MOForm);
        pushButton_addAtom->setObjectName(QString::fromUtf8("pushButton_addAtom"));

        horizontalLayout_5->addWidget(pushButton_addAtom);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        pushButton_import = new QPushButton(MOForm);
        pushButton_import->setObjectName(QString::fromUtf8("pushButton_import"));

        gridLayout->addWidget(pushButton_import, 2, 1, 1, 1);

        pushButton_centralize = new QPushButton(MOForm);
        pushButton_centralize->setObjectName(QString::fromUtf8("pushButton_centralize"));

        gridLayout->addWidget(pushButton_centralize, 3, 1, 1, 1);

        pushButton_reset = new QPushButton(MOForm);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));

        gridLayout->addWidget(pushButton_reset, 5, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(MOForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_coeff = new QLineEdit(MOForm);
        lineEdit_coeff->setObjectName(QString::fromUtf8("lineEdit_coeff"));

        horizontalLayout_4->addWidget(lineEdit_coeff);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        pushButton_addMolecule = new QPushButton(MOForm);
        pushButton_addMolecule->setObjectName(QString::fromUtf8("pushButton_addMolecule"));

        gridLayout->addWidget(pushButton_addMolecule, 8, 1, 1, 1);


        retranslateUi(MOForm);

        QMetaObject::connectSlotsByName(MOForm);
    } // setupUi

    void retranslateUi(QDialog *MOForm)
    {
        MOForm->setWindowTitle(QApplication::translate("MOForm", "Molecule Orbital", nullptr));
        label_3->setText(QApplication::translate("MOForm", "z", nullptr));
        pushButton_close->setText(QApplication::translate("MOForm", "Close", nullptr));
        label_2->setText(QApplication::translate("MOForm", "y", nullptr));
        label->setText(QApplication::translate("MOForm", "x", nullptr));
        comboBox->setItemText(0, QApplication::translate("MOForm", "H", nullptr));
        comboBox->setItemText(1, QApplication::translate("MOForm", "He", nullptr));
        comboBox->setItemText(2, QApplication::translate("MOForm", "Li", nullptr));
        comboBox->setItemText(3, QApplication::translate("MOForm", "Be", nullptr));
        comboBox->setItemText(4, QApplication::translate("MOForm", "B", nullptr));
        comboBox->setItemText(5, QApplication::translate("MOForm", "C", nullptr));
        comboBox->setItemText(6, QApplication::translate("MOForm", "N", nullptr));

        comboBox_orb->setItemText(0, QApplication::translate("MOForm", "None", nullptr));
        comboBox_orb->setItemText(1, QApplication::translate("MOForm", "1S", nullptr));
        comboBox_orb->setItemText(2, QApplication::translate("MOForm", "2S", nullptr));
        comboBox_orb->setItemText(3, QApplication::translate("MOForm", "2Px", nullptr));
        comboBox_orb->setItemText(4, QApplication::translate("MOForm", "2Py", nullptr));
        comboBox_orb->setItemText(5, QApplication::translate("MOForm", "2Pz", nullptr));
        comboBox_orb->setItemText(6, QApplication::translate("MOForm", "3S", nullptr));
        comboBox_orb->setItemText(7, QApplication::translate("MOForm", "3Px", nullptr));
        comboBox_orb->setItemText(8, QApplication::translate("MOForm", "3Py", nullptr));
        comboBox_orb->setItemText(9, QApplication::translate("MOForm", "3Pz", nullptr));
        comboBox_orb->setItemText(10, QApplication::translate("MOForm", "3Dxy", nullptr));
        comboBox_orb->setItemText(11, QApplication::translate("MOForm", "3Dxz", nullptr));
        comboBox_orb->setItemText(12, QApplication::translate("MOForm", "3Dyz", nullptr));
        comboBox_orb->setItemText(13, QApplication::translate("MOForm", "3Dx2-y2", nullptr));
        comboBox_orb->setItemText(14, QApplication::translate("MOForm", "3Dz2", nullptr));
        comboBox_orb->setItemText(15, QApplication::translate("MOForm", "4S", nullptr));
        comboBox_orb->setItemText(16, QApplication::translate("MOForm", "4Px", nullptr));
        comboBox_orb->setItemText(17, QApplication::translate("MOForm", "4Py", nullptr));
        comboBox_orb->setItemText(18, QApplication::translate("MOForm", "4Pz", nullptr));
        comboBox_orb->setItemText(19, QApplication::translate("MOForm", "4Dxy", nullptr));
        comboBox_orb->setItemText(20, QApplication::translate("MOForm", "4Dxz", nullptr));
        comboBox_orb->setItemText(21, QApplication::translate("MOForm", "4Dyz", nullptr));
        comboBox_orb->setItemText(22, QApplication::translate("MOForm", "4Dxy", nullptr));
        comboBox_orb->setItemText(23, QApplication::translate("MOForm", "4Dxz", nullptr));
        comboBox_orb->setItemText(24, QApplication::translate("MOForm", "4Dyz", nullptr));
        comboBox_orb->setItemText(25, QApplication::translate("MOForm", "4Dx2-y2", nullptr));
        comboBox_orb->setItemText(26, QApplication::translate("MOForm", "4Dz2", nullptr));

        pushButton_addAtom->setText(QApplication::translate("MOForm", "Add Atom", nullptr));
        pushButton_import->setText(QApplication::translate("MOForm", "Import", nullptr));
        pushButton_centralize->setText(QApplication::translate("MOForm", "Centeralize", nullptr));
        pushButton_reset->setText(QApplication::translate("MOForm", "Reset", nullptr));
        label_4->setText(QApplication::translate("MOForm", "Orbital Coefficient", nullptr));
        pushButton_addMolecule->setText(QApplication::translate("MOForm", "Add Molecule", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MOForm: public Ui_MOForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MO_H
