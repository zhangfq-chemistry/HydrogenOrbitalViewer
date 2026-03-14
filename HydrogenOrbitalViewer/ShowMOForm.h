#ifndef SHOWMOFORM_H
#define SHOWMOFORM_H

#include <QDialog>
#include <QString>
#include <QTextStream>
#include <QAbstractButton>
#include <QCloseEvent>
#include <vector>
#include <QDoubleValidator>

#include "ui_MO.h"
#include "matrix3/vector3.h"
#include "matrix3/matrix3x3.h"

using namespace std;


class MainWindow;


class ShowMOForm : public QDialog
{
    Q_OBJECT
public:
    Ui::MOForm   ui;
    explicit ShowMOForm(QWidget *parent = nullptr);

    MainWindow * m_parent;

    vector <vector3 > xyz;
    vector <double > coeffs;
    vector <QString > symbols, orbitals;
    vector3 getXYZ();

    void rotate(string , float );
    void translate(vector3);
    void updateText();

signals:



public slots:
   void  onCentralize();
   void  onClear();
   void  onAddAtom();
   void  onRotate();
   void  onTranslate();
   void  onAddMolecule();
   void  onReset();
   void  onClose();


protected:
   void closeEvent(QCloseEvent *event); // override
   // QDoubleValidator * aQDoubleValidator;
private slots:
   void on_pushButton_import_clicked();
};

#endif // SHOWMOFORM_H
