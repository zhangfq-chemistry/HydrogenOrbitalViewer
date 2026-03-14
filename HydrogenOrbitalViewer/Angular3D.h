#ifndef ANGULAR3D_H
#define ANGULAR3D_H





#include <QWidget>
#include <QColor>

#include <QVTKOpenGLWidget.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkDataSet.h>
#include <vtkClipPolyData.h>
#include <vtkPlane.h>

#include <vtkImplicitPlaneWidget2.h>
#include <vtkImplicitPlaneRepresentation.h>


#include <vtkOutlineFilter.h>
#include <vtkStripper.h>
#include <vtkSmoothPolyDataFilter.h>
#include <vtkImplicitBoolean.h>

#include <vtkCutter.h>
#include <vtkFillHolesFilter.h>
#include <vtkStripper.h>
#include <vtkFeatureEdges.h>
#include <vtkRegularPolygonSource.h>
#include <QVTKOpenGLWidget.h>
#include <QVTKOpenGLWindow.h>
#include <vtkDelaunay2D.h>
#include <vtkLookupTable.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPointData.h>
#include <vtkWindowedSincPolyDataFilter.h>
#include <vtkPolyLine.h>
#include <vtkLineSource.h>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkPNGWriter.h>

#include "HAtomOrb.h"
#include "HMol.h"


class Angular3D: public QVTKOpenGLNativeWidget
{
  Q_OBJECT
public:
  explicit Angular3D(QWidget *parent = 0);

  // Add a data set to the scene
  void addDataSet(vtkSmartPointer<vtkDataSet> dataSet);


  // Remove the data set from the scene
  void removeLastActor();
  void removeAllActors();
  void renderAxis(double l=3.0);

public:
  double length_x,length_y,length_z;
  bool   isAxisVisible;


  void setAngularNodecolor_Theta (vector3 v );
  void setAngularNodecolor_Phi (vector3 v );


  vector3 getAngularNodecolor_Theta (){ return angularNodecolor_Theta; }
  vector3 getAngularNodecolor_Phi (){ return angularNodecolor_Phi; }


  void setAngularNodeOpicity_Theta (double o);
  void setAngularNodeOpicity_Phi (double o);


  void setLobeColor_pos( vector3 );
  void setLobeColor_neg( vector3 );
  void setOrbitalLineWidth(double );
  double getOrbitalLineWidth() {return orbitalLineWidth;};
  void refreshView();


public:
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkPlane> plane;
    vtkSmartPointer<vtkClipPolyData> clipper_pos,clipper_neg;

    void renderMol(HMol *  );

    void renderOrbital(HMol * );
    void renderAllNodes(HMol *);
    void renderPhiNodes(HMol *);
    void renderThetaNodes(HMol *);
    void renderCones(double height, double cos2angle);

    void renderLine(double p0[3],double p1[3],double color[3],float width,vtkTransform * transform);

    void  setBackgroundColor( vector3 );
    vector3 getBackgroundColor(){return bkcolor;}

    void  writePNG(QString );



    vtkSmartPointer<vtkCamera> camera;


    vector3 positiveLobeColor(){return LobeColor_pos;};
    vector3 negtiveLobeColor(){return LobeColor_neg;};

    void  setPosLobeOpacity(double c) {opacity_pos=c;}
    void  setNegLobeOpacity(double c) {opacity_neg=c;}

    double getPosLobeOpacity() {return opacity_pos;}
    double getNegLobeOpacity() {return opacity_neg;}
    double getAngularNodeThetaOpacity() {return opacity_theta;}
    double getAngularNodePhiOpacity() {return opacity_phi;}

    double getNodeThickness (){return nodeThickness;}
    void   setNodeThickness (double t){nodeThickness=t;}



public slots:

  void zoomToExtent();

  void onViewXY();
  void onViewXZ();
  void onViewYZ();
  void onViewReset();

  void onView_rotateClockwise(double degree);
  void onView_rotateCounterClockwise(double degree);
  void onView_rotateUp(double degree);
  void onView_rotateDown(double degree);

  void onView_rotateRight(double );
  void onView_rotateLeft(double );





private:
  vtkSmartPointer<vtkRenderer> m_renderer;
  vector3 angularNodecolor_Theta,angularNodecolor_Phi;
  vector3 bkcolor;
  vector3 LobeColor_pos,LobeColor_neg;
  double  opacity_pos,opacity_neg;
  double  opacity_theta,opacity_phi;
  double  orbitalLineWidth,nodeThickness;
};

#endif // ANGULAR3D_H
