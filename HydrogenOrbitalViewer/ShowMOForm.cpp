#include "ShowMOForm.h"
#include <QMessageBox>
#include <iostream>
#include <QFileDialog>
#include "mainwindow.h"

ShowMOForm::ShowMOForm(QWidget *parent): QDialog(parent)
{
    m_parent=(MainWindow *)parent;

    ui.setupUi(this);
    ui.MO_textEdit->setLineWrapMode(QTextEdit::NoWrap);

    connect(ui.pushButton_centralize,SIGNAL(clicked()),this, SLOT(onCentralize()));
    //connect(ui.pushButton_clear,SIGNAL(clicked()),this, SLOT(onClear()));
    //connect(ui.pushButton_rotate,SIGNAL(clicked()),this, SLOT(onRotate()));
    //connect(ui.pushButton_translate,SIGNAL(clicked()),this, SLOT(onTranslate()));
    connect(ui.pushButton_addAtom,SIGNAL(clicked()),this, SLOT(onAddAtom()));

    connect(ui.pushButton_addMolecule,SIGNAL(clicked()),this, SLOT(onAddMolecule()));

    connect(ui.pushButton_reset,SIGNAL(clicked()),this, SLOT(onReset()));
    connect(ui.pushButton_close,SIGNAL(clicked()),this, SLOT(onClose()));



    onReset();
    ui.lineEdit_x->setText("0.0");
    ui.lineEdit_y->setText("0.0");
    ui.lineEdit_z->setText("0.0");
    ui.lineEdit_coeff->setText("1.0");


    auto aQDoubleValidator = new QDoubleValidator;
    aQDoubleValidator->setRange(-10.0,10.0,3);
    ui.lineEdit_x->setValidator(aQDoubleValidator);
    ui.lineEdit_y->setValidator(aQDoubleValidator);
    ui.lineEdit_z->setValidator(aQDoubleValidator);
    ui.lineEdit_coeff->setValidator(aQDoubleValidator);
}


void ShowMOForm::onReset()
{
    onClear();
    ui.MO_textEdit->clear();
    ui.MO_textEdit->append("Name MO-1" );
    ui.MO_textEdit->append("#  atom      x         y        z    orbital-coefficient  orbital" );
    ui.comboBox_orb->setCurrentIndex(1);
}


void ShowMOForm::onClear()
{
    xyz.clear();
    symbols.clear();
    orbitals.clear();

    ui.lineEdit_x->setText("0.0");
    ui.lineEdit_y->setText("0.0");
    ui.lineEdit_z->setText("0.0");
    ui.lineEdit_coeff->setText("1.0");
}

void ShowMOForm::onAddAtom()
{
    xyz.clear();
    coeffs.clear();
    symbols.clear();
    orbitals.clear();

    vector3 v=getXYZ();
    QString symbol=ui.comboBox->currentText();
    QString ao=ui.comboBox_orb->currentText();

    double c=1.0;
    if(ui.lineEdit_coeff->text().size()>0)
        c=ui.lineEdit_coeff->text().toFloat();


    //check it
    bool isExisted=false;
    QString single,fullName;
    QStringList ls;

    QString s=ui.MO_textEdit->toPlainText();
    s=s.replace(QRegExp(",")," ");
    QStringList Lines = s.trimmed().split("\n");

    bool isBegin=true;


    for (uint i=0; i < Lines.size(); i++)
    {
        single = Lines.at(i).trimmed();
        if ( single.contains(QRegExp("#") ) )  continue;
        ls = single.split(QRegExp("\\s+"));

        if (ls.size()<=1) continue;
        if ( ls[0].toLower().startsWith("name") )
        {
            // check existed or not, based on full name
            fullName=single.remove(0,5);
            if (fullName.trimmed().length()<1)
                fullName="MO";
            continue;
        }

        if ( ls[0].toLower().startsWith("proj") )
        {
            continue;
        }


        if ( (ls.size() != 6) && (ls.size() != 4) ) continue;

        QString AtomSymbol=ls[0];
        double x=ls[1].toDouble();
        double y=ls[2].toDouble();
        double z=ls[3].toDouble();

        QString AtomOrbital="None";

        double coeff=0.0;
        if ( ls.size() == 6) {
            coeff=ls[4].toDouble();
            AtomOrbital=ls[5];
        }

        vector3 pos(x,y,z);

        xyz.push_back(pos);
        coeffs.push_back(coeff);
        symbols.push_back( AtomSymbol);
        orbitals.push_back(AtomOrbital);
    }

    if (symbols.size() >0)
    for (uint j=0;j<symbols.size();j++)
    {
        if ((xyz[j]-v).length()>0.6) continue;

        if( symbol==symbols[j] && ao==orbitals[j])
        {
            isExisted=true;
            QMessageBox::information(0, "Warning", QString("This atom/orbital %1 is existed !").arg(j+1));
            return;
        }

        if ( ((xyz[j]-v).length()<0.6)  && (symbol != symbols[j])  )
        {
            QMessageBox::information(0, "Warning", QString("The distance between this atom and %1 is too short!").arg(j+1));
            return;
        }
    }

    QString strX = QString::number(v.x(),'f',2);
    QString strY = QString::number(v.y(),'f',2);
    QString strZ = QString::number(v.z(),'f',2);
    QString strCoeff = QString::number(c,'f',4);

    if (ao.toLower()=="none")
        ui.MO_textEdit->append("      "+symbol+ "      "+ strX+ "      " +strY+ "      "+strZ);
    else
        ui.MO_textEdit->append("      "+symbol+ "      "+ strX+ "      " +strY+ "      "+strZ+ "     "+ strCoeff+ "      "+ao);


    xyz.push_back(v);
    coeffs.push_back(c);
    symbols.push_back( symbol);
    orbitals.push_back(ao);
}


void ShowMOForm::onAddMolecule()
{
    //read from ui.MO_textEdit
    QString s=ui.MO_textEdit->toPlainText();

    for (uint i=0;i<symbols.size();i++)
    {
        vector3 v=xyz[i];
        QString symbol=symbols[i];
        QString ao=orbitals[i];

        for (uint j=i+1;j<symbols.size();j++)
        {
            if ((xyz[j]-v).length()>0.6) continue;

            if( symbol==symbols[j] && ao==orbitals[j])
            {
                QMessageBox::information(0, "Warning", QString("This atom/orbital %1 is existed !").arg(j+1));
                return;
            }


            if ( ((xyz[j]-v).length()<0.6)  && (symbol != symbols[j])  )
            {
                QMessageBox::information(0, "Warning", QString("The distance between this atom and %1 is too short!").arg(j+1));
                return;
            }
        }
    }


    m_parent->addMolecule(s);
    close();
}


vector3 ShowMOForm::getXYZ()
{
    float x=0.0,y=0.0,z=0.0, err=0.0000001;

    if(ui.lineEdit_x->text().size()>0)
        x=(ui.lineEdit_x->text()).toFloat();

    if(ui.lineEdit_y->text().size()>0)
        y=(ui.lineEdit_y->text()).toFloat();

    if(ui.lineEdit_z->text().size()>0)
        z=(ui.lineEdit_z->text()).toFloat();

    vector3 v(x,y,z);
    return v;
}


void ShowMOForm::rotate(string axis, float angle)
{

    if(xyz.size()<1) return;
    for (uint i=0;i<xyz.size();i++)
    {
        xyz[i]= rotateVector(xyz[i], angle,axis);
    }
    updateText();
}




void ShowMOForm::translate(vector3 v )
{
    if(xyz.size()<1) return;
    for (uint i=0;i<xyz.size();i++)
    {
        xyz[i]=xyz[i]+v;
    }

    updateText();
}

void ShowMOForm::onRotate()
{
    float x=0.0,y=0.0,z=0.0, err=0.0000001;
    if(ui.lineEdit_x->text().size()>0)
        x=(ui.lineEdit_x->text()).toFloat();

    if(ui.lineEdit_y->text().size()>0)
        y=(ui.lineEdit_y->text()).toFloat();

    if(ui.lineEdit_z->text().size()>0)
        z=(ui.lineEdit_z->text()).toFloat();

    if ( abs(x) < err && abs(y) < err && abs(z) < err) {
        QMessageBox::information(0, "Warning","Please input rotation degree!");
        return;
    }

    if ( abs(x) > err && abs(y) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    if ( abs(y) > err && abs(z) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    if ( abs(x) > err && abs(z) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }


    if ( abs(x) > err) {
        rotate("x", x);  return;
    }

    if ( abs(y) > err) {
        rotate("x", y);return;
    }

    if ( abs(z) > err) {
        rotate("z", z);return;
    }
}

void ShowMOForm::onTranslate()
{
    float x=0.0,y=0.0,z=0.0, err=0.0000001;

    if(ui.lineEdit_x->text().size()>0)
        x=(ui.lineEdit_x->text()).toFloat();

    if(ui.lineEdit_y->text().size()>0)
        y=(ui.lineEdit_y->text()).toFloat();

    if(ui.lineEdit_z->text().size()>0)
        z=(ui.lineEdit_z->text()).toFloat();

    if ( abs(x) < err && abs(y) < err && abs(z) < err) {
        QMessageBox::information(0, "Warning","Please input rotation degree!");
        return;
    }

    if ( abs(x) > err && abs(y) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    if ( abs(y) > err && abs(z) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    if ( abs(x) > err && abs(z) > err) {
        QMessageBox::information(0, "Warning","Only one axis can be defined!");
        return;
    }

    vector3 v(x,y,z);
    translate(v);

}

void ShowMOForm::onCentralize()
{
    if(xyz.size()<1) return;

    vector3 center(0.,0.,0.);
    for (uint i=0;i<xyz.size();i++)
    {
        center+=xyz[i];
    }
    center/=xyz.size();

    for (uint i=0;i<xyz.size();i++)
    {
        xyz[i]=xyz[i]-center;
    }

    updateText();
}

void ShowMOForm::updateText()
{
    ui.MO_textEdit->clear();
    ui.MO_textEdit->append("Name MO-1" );
    ui.MO_textEdit->append("# atom      x         y        z    orbital-coefficient  orbital" );

    for (uint i=0;i<symbols.size();i++)
    {
        QString strX = QString::number(xyz[i].x(),'f',2);
        QString strY = QString::number(xyz[i].y(),'f',2);
        QString strZ = QString::number(xyz[i].z(),'f',2);
        QString strCoeff = QString::number(coeffs[i],'f',4);

        ui.MO_textEdit->append("      "+symbols[i]+ "      "+ strX+ "      " +strY+ "      "+strZ+ "     "+ strCoeff+ "      "+orbitals[i]);
    }
}



void ShowMOForm::onClose()
{
    close();
}

void ShowMOForm::closeEvent(QCloseEvent *event)
{
   return QDialog::closeEvent(event);
}


void ShowMOForm::on_pushButton_import_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this, "Select Orbital File",
       "", "Molecular Orbital (*.orb);;All Files (*.*)");

    if (FileName.isEmpty()) return;


    QFile file(FileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString s="";
    while (!in.atEnd()) {
        QString line = in.readLine();
        s+=line+"\n";
    }
    ui.MO_textEdit->clear();
    ui.MO_textEdit->append(s);
}
