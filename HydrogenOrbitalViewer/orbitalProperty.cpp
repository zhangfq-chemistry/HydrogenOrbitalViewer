#include "orbitalProperty.h"

#include <QMessageBox>
#include <iostream>
#include <QFileDialog>




#include "mainwindow.h"



OrbitalProperty::OrbitalProperty(QWidget *parent): QDialog(parent)
{
    m_parent=(MainWindow *)parent;

    view3d=m_parent->view3d;
    mesh3d=m_parent->mesh3d;
    angular3d=m_parent->angularY3d;


    ui.setupUi(this);

    initial();


}

//read from View3d
void OrbitalProperty::initial()
{

    QString s;

    //color
    backgroundcolor=255*view3d->getBackgroundColor();
    LobeColor_pos=255*view3d->positiveLobeColor();
    LobeColor_neg=255*view3d->negtiveLobeColor();


    ui.spinBox_OL_positive_red->setStyleSheet("backgroundcolor:red");
    ui.spinBox_OL_positive_green->setStyleSheet("backgroundcolor:green");
    ui.spinBox_OL_positive_blue->setStyleSheet("backgroundcolor:blue");

    ui.spinBox_OL_positive_red->setValue(LobeColor_pos.x());
    ui.spinBox_OL_positive_green->setValue(LobeColor_pos.y());
    ui.spinBox_OL_positive_blue->setValue(LobeColor_pos.z());

    ui.spinBox_OL_negative_red->setValue(LobeColor_neg.x());
    ui.spinBox_OL_negative_green->setValue(LobeColor_neg.y());
    ui.spinBox_OL_negative_blue->setValue(LobeColor_neg.z());

    s=tr("background-color: rgb(%1,%2,%3);").arg(LobeColor_pos.x()).arg(LobeColor_pos.y()).arg(LobeColor_pos.z());
    ui.pushButton_OL_positive->setStyleSheet(s);

    s=tr("background-color: rgb(%1,%2,%3);").arg(LobeColor_neg.x()).arg(LobeColor_neg.y()).arg(LobeColor_neg.z());
    ui.pushButton_OL_negative->setStyleSheet(s);


    radialNodecolor=255*view3d->getRadialNodecolor();
    angularNodecolor_Theta=255*view3d->getAngularNodecolor_Theta();
    angularNodecolor_Phi=255*view3d->getAngularNodecolor_Phi();

    ui.spinBox_ONR_red->setValue(radialNodecolor.x());
    ui.spinBox_ONR_green->setValue(radialNodecolor.y());
    ui.spinBox_ONR_blue->setValue(radialNodecolor.z());



    ui.spinBox_ONT_red->setValue(angularNodecolor_Theta.x());
    ui.spinBox_ONT_green->setValue(angularNodecolor_Theta.y());
    ui.spinBox_ONT_blue->setValue(angularNodecolor_Theta.z());


    ui.spinBox_ONP_red->setValue(angularNodecolor_Phi.x());
    ui.spinBox_ONP_green->setValue(angularNodecolor_Phi.y());
    ui.spinBox_ONP_blue->setValue(angularNodecolor_Phi.z());



    s=tr("background-color: rgb(%1,%2,%3);").arg(radialNodecolor.x()).arg(radialNodecolor.y()).arg(radialNodecolor.z());
    ui.pushButton_ON_R->setStyleSheet(s);


    s=tr("background-color: rgb(%1,%2,%3);").arg(angularNodecolor_Theta.x()).arg(angularNodecolor_Theta.y()).arg(angularNodecolor_Theta.z());
    ui.pushButton_ON_Theta->setStyleSheet(s);


    s=tr("background-color: rgb(%1,%2,%3);").arg(angularNodecolor_Phi.x()).arg(angularNodecolor_Phi.y()).arg(angularNodecolor_Phi.z());
    ui.pushButton_ON_Phi->setStyleSheet(s);


    //opacity
    R_Node_opacity=255*view3d->getRadialNodeOpacity();
    T_Node_opacity=255*view3d->getAngularNodeThetaOpacity();
    P_Node_opacity=255*view3d->getAngularNodePhiOpacity() ;

    ui.spinBox_ONR_opacity->setValue(R_Node_opacity);
    ui.spinBox_ONT_opacity->setValue(T_Node_opacity);
    ui.spinBox_ONP_opacity->setValue(P_Node_opacity);


    Lobe_opacity_pos=255*view3d->getPosLobeOpacity();
    Lobe_opacity_neg=255*view3d->getNegLobeOpacity();

    ui.spinBox_OL_positive_opacity->setValue(Lobe_opacity_pos);
    ui.spinBox_OL_negative_opacity->setValue(Lobe_opacity_neg);



    orbitalLineWidth=view3d->getOrbitalLineWidth();
    nodeThickness=view3d->getNodeThickness();



}

void OrbitalProperty::getDataFromCurrentPanel()
{
    LobeColor_pos.SetX(ui.spinBox_OL_positive_red->value());
    LobeColor_pos.SetY(ui.spinBox_OL_positive_green->value());
    LobeColor_pos.SetZ(ui.spinBox_OL_positive_blue->value());


    LobeColor_neg.SetX(ui.spinBox_OL_negative_red->value());
    LobeColor_neg.SetY(ui.spinBox_OL_negative_green->value());
    LobeColor_neg.SetZ(ui.spinBox_OL_negative_blue->value());


    radialNodecolor.SetX(ui.spinBox_ONR_red->value());
    radialNodecolor.SetY(ui.spinBox_ONR_green->value());
    radialNodecolor.SetZ(ui.spinBox_ONR_blue->value());


    angularNodecolor_Theta.SetX(ui.spinBox_ONT_red->value());
    angularNodecolor_Theta.SetY(ui.spinBox_ONT_green->value());
    angularNodecolor_Theta.SetZ(ui.spinBox_ONT_blue->value());

    angularNodecolor_Phi.SetX(ui.spinBox_ONP_red->value());
    angularNodecolor_Phi.SetY(ui.spinBox_ONP_green->value());
    angularNodecolor_Phi.SetZ(ui.spinBox_ONP_blue->value());

    R_Node_opacity=ui.spinBox_ONR_opacity->value();
    T_Node_opacity=ui.spinBox_ONT_opacity->value();
    P_Node_opacity=ui.spinBox_ONP_opacity->value();

    Lobe_opacity_pos=ui.spinBox_OL_positive_opacity->value();
    Lobe_opacity_neg=ui.spinBox_OL_negative_opacity->value();
}


void OrbitalProperty::refreshView3d()
{
    getDataFromCurrentPanel();

    double a=255.0;

    //lobe color
    view3d->setLobeColor_pos(LobeColor_pos/a);
    view3d->setLobeColor_neg(LobeColor_neg/a);



    angular3d->setLobeColor_pos(LobeColor_pos/a);
    angular3d->setLobeColor_neg(LobeColor_neg/a);

    //lobe opacity
    angular3d->setPosLobeOpacity(Lobe_opacity_pos/a);
    angular3d->setNegLobeOpacity(Lobe_opacity_neg/a);

    view3d->setPosLobeOpacity(Lobe_opacity_pos/a);
    view3d->setNegLobeOpacity(Lobe_opacity_neg/a);


    //nodal color
    angular3d->setAngularNodecolor_Theta(angularNodecolor_Theta/a);
    angular3d->setAngularNodecolor_Phi(angularNodecolor_Phi/a);

    view3d->setRadialNodecolor(radialNodecolor/a);
    view3d->setAngularNodecolor_Theta(angularNodecolor_Theta/a);
    view3d->setAngularNodecolor_Phi(angularNodecolor_Phi/a);

    //nodal opacity
    view3d->setRadialNodeOpicity(R_Node_opacity/a);            //radial
    view3d->setAngularNodeOpicity_Theta(T_Node_opacity/a);     //theta
    view3d->setAngularNodeOpicity_Phi (P_Node_opacity/a);      //phi

    angular3d->setAngularNodeOpicity_Theta(T_Node_opacity/a);     //theta
    angular3d->setAngularNodeOpicity_Phi (P_Node_opacity/a);      //phi

    //re-draw
    m_parent->refreshCurrentView();
}


//set orbital-node-R color
void OrbitalProperty::on_pushButton_ON_R_clicked()
{
    QColor color(radialNodecolor.x(),
                      radialNodecolor.y(),
                      radialNodecolor.z(),
                      R_Node_opacity);

    color_widgets::ColorDialog dialog;
    dialog.setColor(color);
    dialog.exec();


    QColor c=dialog.color();
    radialNodecolor.Set(c.red(),c.green(),c.blue());
    R_Node_opacity=c.alpha();

    ui.spinBox_ONR_red->setValue(radialNodecolor.x());
    ui.spinBox_ONR_green->setValue(radialNodecolor.y());
    ui.spinBox_ONR_blue->setValue(radialNodecolor.z());
    ui.spinBox_ONR_opacity->setValue(R_Node_opacity);

    /*
    view3d->setRadialNodecolor(radialNodecolor/255);
    view3d->setRadialNodeOpicity(R_Node_opacity);
    view3d->refreshView();
    */
}



//set orbital-node-theta color
void OrbitalProperty::on_pushButton_ON_Theta_clicked()
{
    QColor color(angularNodecolor_Theta.x(),  angularNodecolor_Theta.y(),
                 angularNodecolor_Theta.z(),  T_Node_opacity);

    color_widgets::ColorDialog dialog;
    dialog.setColor(color);
    dialog.exec();


    QColor c=dialog.color();
    angularNodecolor_Theta.Set(c.red(),c.green(),c.blue());
    T_Node_opacity=c.alpha();

    ui.spinBox_ONT_red->setValue(angularNodecolor_Theta.x());
    ui.spinBox_ONT_green->setValue(angularNodecolor_Theta.y());
    ui.spinBox_ONT_blue->setValue(angularNodecolor_Theta.z());

    ui.spinBox_ONT_opacity->setValue(T_Node_opacity);


/*
    view3d->setAngularNodecolor_Theta(angularNodecolor_Theta/255);
    view3d->setAngularNodeOpicity_Theta(T_Node_opacity/255);
    view3d->refreshView();
    */
}

//set orbital-node-phi color
void OrbitalProperty::on_pushButton_ON_Phi_clicked()
{
    QColor color(angularNodecolor_Phi.x(),    angularNodecolor_Phi.y(),
                 angularNodecolor_Phi.z(),    P_Node_opacity);

    color_widgets::ColorDialog dialog;
    dialog.setColor(color);
    dialog.exec();


    QColor c=dialog.color();
    angularNodecolor_Phi.Set(c.red()*1.0,c.green()*1.0,c.blue()*1.0);
    T_Node_opacity=c.alpha();

    ui.spinBox_ONP_red->setValue(angularNodecolor_Phi.x());
    ui.spinBox_ONP_green->setValue(angularNodecolor_Phi.y());
    ui.spinBox_ONP_blue->setValue(angularNodecolor_Phi.z());
    ui.spinBox_ONP_opacity->setValue(P_Node_opacity);

/*
    view3d->setAngularNodecolor_Phi(angularNodecolor_Phi/255);
    view3d->setAngularNodeOpicity_Phi (P_Node_opacity/255);
    view3d->refreshView();
    */
}

//set orbital positive-lobe color
void OrbitalProperty::on_pushButton_OL_positive_clicked()
{
    QColor color(LobeColor_pos.x(), LobeColor_pos.y(),
                 LobeColor_pos.z(), Lobe_opacity_pos);

    color_widgets::ColorDialog dialog;
    dialog.setColor(color);
    dialog.exec();


    QColor c=dialog.color();
    LobeColor_pos.Set(c.red(),c.green(),c.blue());
    Lobe_opacity_pos=c.alpha();


    ui.spinBox_OL_positive_red->setValue(LobeColor_pos.x());
    ui.spinBox_OL_positive_green->setValue(LobeColor_pos.y());
    ui.spinBox_OL_positive_blue->setValue(LobeColor_pos.z());
    ui.spinBox_OL_positive_opacity->setValue(Lobe_opacity_pos);

}

//set orbital negtive-lobe color
void OrbitalProperty::on_pushButton_OL_negative_clicked()
{
    QColor color(LobeColor_neg.x(),
                 LobeColor_neg.y(),
                 LobeColor_neg.z(),
                 Lobe_opacity_neg);


    color_widgets::ColorDialog dialog;
    dialog.setColor(color);
    dialog.exec();


    QColor c=dialog.color();
    LobeColor_neg.Set(c.red(),c.green(),c.blue());
    Lobe_opacity_neg=c.alpha();


    ui.spinBox_OL_negative_red->setValue(LobeColor_neg.x());
    ui.spinBox_OL_negative_green->setValue(LobeColor_neg.y());
    ui.spinBox_OL_negative_blue->setValue(LobeColor_neg.z());
    ui.spinBox_OL_negative_opacity->setValue(Lobe_opacity_neg);
}

void OrbitalProperty::on_spinBox_ONR_opacity_valueChanged(int arg1)
{
    R_Node_opacity=arg1;

}

void OrbitalProperty::on_spinBox_ONT_opacity_valueChanged(int arg1)
{
    T_Node_opacity=arg1;
}

void OrbitalProperty::on_spinBox_ONP_opacity_valueChanged(int arg1)
{  
    P_Node_opacity=arg1;
}

void OrbitalProperty::on_spinBox_OL_positive_opacity_valueChanged(int arg1)
{

    Lobe_opacity_pos=arg1;
}

void OrbitalProperty::on_spinBox_OL_negative_opacity_valueChanged(int arg1)
{
    Lobe_opacity_neg=arg1;
}


void OrbitalProperty::on_pushButton_flipPhase_clicked()
{
    //store
    int opacity=Lobe_opacity_neg;
    int red=LobeColor_neg.x();
    int blue=LobeColor_neg.y();
    int green=LobeColor_neg.z();

    Lobe_opacity_neg=Lobe_opacity_pos;
    LobeColor_neg.Set(LobeColor_pos.x(),LobeColor_pos.y(),LobeColor_pos.z());
    LobeColor_pos.Set(red,blue,green);
    Lobe_opacity_neg=opacity;


    ui.spinBox_OL_negative_red->setValue(LobeColor_neg.x());
    ui.spinBox_OL_negative_green->setValue(LobeColor_neg.y());
    ui.spinBox_OL_negative_blue->setValue(LobeColor_neg.z());
    ui.spinBox_OL_negative_opacity->setValue(Lobe_opacity_neg);


    ui.spinBox_OL_positive_red->setValue(LobeColor_pos.x());
    ui.spinBox_OL_positive_green->setValue(LobeColor_pos.y());
    ui.spinBox_OL_positive_blue->setValue(LobeColor_pos.z());
    ui.spinBox_OL_positive_opacity->setValue(Lobe_opacity_pos);

    QString s;
    s=tr("background-color: rgb(%1,%2,%3);").arg(LobeColor_pos.x()).arg(LobeColor_pos.y()).arg(LobeColor_pos.z());
    ui.pushButton_OL_positive->setStyleSheet(s);

    s=tr("background-color: rgb(%1,%2,%3);").arg(LobeColor_neg.x()).arg(LobeColor_neg.y()).arg(LobeColor_neg.z());
    ui.pushButton_OL_negative->setStyleSheet(s);


    //refreshView3d();
}



void OrbitalProperty::on_pushButton_reGenerate_clicked()
{

}

void OrbitalProperty::on_pushButton_cancel_clicked()
{
    initial();
    close();
}

void OrbitalProperty::on_pushButton_ok_clicked()
{
    refreshView3d();
    close();
}


void OrbitalProperty::on_spinBox_ONR_red_valueChanged(int arg1)
{
    int r=ui.spinBox_ONR_red->value(),
        g=ui.spinBox_ONR_green->value(),
        b=ui.spinBox_ONR_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_ON_R->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_ONR_green_valueChanged(int arg1)
{

    int r=ui.spinBox_ONR_red->value(),
        g=ui.spinBox_ONR_green->value(),
        b=ui.spinBox_ONR_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_ON_R->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_ONR_blue_valueChanged(int arg1)
{
    int r=ui.spinBox_ONR_red->value(),
        g=ui.spinBox_ONR_green->value(),
        b=ui.spinBox_ONR_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_ON_R->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_ONT_red_valueChanged(int arg1)
{
    int r=ui.spinBox_ONT_red->value(),
        g=ui.spinBox_ONT_green->value(),
        b=ui.spinBox_ONT_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_ON_Theta->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_ONT_green_valueChanged(int arg1)
{
    int r=ui.spinBox_ONT_red->value(),
        g=ui.spinBox_ONT_green->value(),
        b=ui.spinBox_ONT_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_ON_Theta->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_ONT_blue_valueChanged(int arg1)
{
    int r=ui.spinBox_ONT_red->value(),
        g=ui.spinBox_ONT_green->value(),
        b=ui.spinBox_ONT_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_ON_Theta->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_ONP_red_valueChanged(int arg1)
{
    int r=ui.spinBox_ONP_red->value(),
        g=ui.spinBox_ONP_green->value(),
        b=ui.spinBox_ONP_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_ON_Phi->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_ONP_green_valueChanged(const QString &arg1)
{
    int r=ui.spinBox_ONP_red->value(),
        g=ui.spinBox_ONP_green->value(),
        b=ui.spinBox_ONP_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_ON_Phi->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_ONP_blue_valueChanged(const QString &arg1)
{
    int r=ui.spinBox_ONP_red->value(),
        g=ui.spinBox_ONP_green->value(),
        b=ui.spinBox_ONP_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_ON_Phi->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_OL_positive_red_valueChanged(int arg1)
{
    int r=ui.spinBox_OL_positive_red->value(),
        g=ui.spinBox_OL_positive_green->value(),
        b=ui.spinBox_OL_positive_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_OL_positive->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_OL_positive_green_valueChanged(int arg1)
{
    int r=ui.spinBox_OL_positive_red->value(),
        g=ui.spinBox_OL_positive_green->value(),
        b=ui.spinBox_OL_positive_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_OL_positive->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_OL_positive_blue_valueChanged(int arg1)
{
    int r=ui.spinBox_OL_positive_red->value(),
        g=ui.spinBox_OL_positive_green->value(),
        b=ui.spinBox_OL_positive_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_OL_positive->setStyleSheet(s);
}


void OrbitalProperty::on_spinBox_OL_negative_red_valueChanged(int arg1)
{
    int r=ui.spinBox_OL_negative_red->value(),
        g=ui.spinBox_OL_negative_green->value(),
        b=ui.spinBox_OL_negative_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_OL_negative->setStyleSheet(s);

}

void OrbitalProperty::on_spinBox_OL_negative_green_valueChanged(int arg1)
{
    int r=ui.spinBox_OL_negative_red->value(),
        g=ui.spinBox_OL_negative_green->value(),
        b=ui.spinBox_OL_negative_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_OL_negative->setStyleSheet(s);
}

void OrbitalProperty::on_spinBox_OL_negative_blue_valueChanged(int arg1)
{
    int r=ui.spinBox_OL_negative_red->value(),
        g=ui.spinBox_OL_negative_green->value(),
        b=ui.spinBox_OL_negative_blue->value();

    QString s=tr("background-color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    ui.pushButton_OL_negative->setStyleSheet(s);
}
