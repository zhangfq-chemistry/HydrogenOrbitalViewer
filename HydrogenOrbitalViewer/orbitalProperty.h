#ifndef ORBITALPROPERTY_H
#define ORBITALPROPERTY_H

#include <QWidget>
#include <QtColorWidgets/color_2d_slider.hpp>
#include <QtColorWidgets/color_delegate.hpp>
#include <QtColorWidgets/color_dialog.hpp>
#include <QtColorWidgets/color_line_edit.hpp>
#include <QtColorWidgets/color_list_widget.hpp>
#include <QtColorWidgets/color_palette_widget.hpp>
#include <QtColorWidgets/color_preview.hpp>
#include <QtColorWidgets/color_wheel.hpp>
#include <QtColorWidgets/hue_slider.hpp>
#include <QColorDialog>
#include "matrix3/vector3.h"

#include "ui_AOProperty.h"

using namespace std;

class MainWindow;
class View3D;
class Mesh3D;
class Angular3D;


class OrbitalProperty : public QDialog
{
    Q_OBJECT
public:
    Ui::OrbitalProperty   ui;
    explicit OrbitalProperty(QWidget *parent = nullptr);

    MainWindow * m_parent;

    View3D * view3d;
    Mesh3D * mesh3d;
    Angular3D * angular3d;


    void initial();
    void refreshView3d();







signals:


private slots:
    void on_pushButton_flipPhase_clicked();
    void on_pushButton_reGenerate_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_ON_R_clicked();
    void on_pushButton_ON_Theta_clicked();
    void on_pushButton_ON_Phi_clicked();
    void on_pushButton_OL_positive_clicked();
    void on_pushButton_OL_negative_clicked();
    void on_spinBox_ONR_opacity_valueChanged(int arg1);
    void on_spinBox_ONT_opacity_valueChanged(int arg1);
    void on_spinBox_ONP_opacity_valueChanged(int arg1);
    void on_spinBox_OL_positive_opacity_valueChanged(int arg1);
    void on_spinBox_OL_negative_opacity_valueChanged(int arg1);

    void getDataFromCurrentPanel();

    void on_spinBox_ONR_red_valueChanged(int arg1);

    void on_spinBox_ONR_green_valueChanged(int arg1);

    void on_spinBox_ONR_blue_valueChanged(int arg1);

    void on_spinBox_ONT_red_valueChanged(int arg1);

    void on_spinBox_ONT_green_valueChanged(int arg1);

    void on_spinBox_ONT_blue_valueChanged(int arg1);

    void on_spinBox_ONP_red_valueChanged(int arg1);

    void on_spinBox_ONP_green_valueChanged(const QString &arg1);

    void on_spinBox_ONP_blue_valueChanged(const QString &arg1);

    void on_spinBox_OL_positive_red_valueChanged(int arg1);

    void on_spinBox_OL_positive_green_valueChanged(int arg1);

    void on_spinBox_OL_positive_blue_valueChanged(int arg1);

    void on_spinBox_OL_negative_red_valueChanged(int arg1);

    void on_spinBox_OL_negative_green_valueChanged(int arg1);

    void on_spinBox_OL_negative_blue_valueChanged(int arg1);






private:
    vector3 LobeColor_pos,LobeColor_neg;
    vector3 angularNodecolor_Theta,angularNodecolor_Phi,radialNodecolor;

    int  R_Node_opacity,T_Node_opacity,P_Node_opacity;
    int  Lobe_opacity_pos, Lobe_opacity_neg;

    vector3 backgroundcolor;

    double  orbitalLineWidth,nodeThickness;


};

#endif // ORBITALPROPERTY_H
