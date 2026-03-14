#ifndef AO3DVIEW_H
#define AO3DVIEW_H

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

//smooth  actor->GetProperty()->SetInterpolationToGouraud();
//flat  actor->GetProperty()->SetInterpolationToFlat();

class View3D : public QVTKOpenGLNativeWidget
{
  Q_OBJECT

public:
  explicit View3D(QWidget *parent = 0);

  // Add a data set to the scene
  void addDataSet(vtkSmartPointer<vtkDataSet> dataSet);

  // Remove the data set from the scene
  void removeLastActor();
  void removeAllActors();
  void renderAxis(double l=3.0);

public:
  //int idx;
 // void setId(int id){idx=id;}
 // int getId(){return idx;}
  double length_x,length_y,length_z;
  bool   isAxisVisible;


  void setRadialNodecolor (vector3 v);
  void setAngularNodecolor_Theta (vector3 v );
  void setAngularNodecolor_Phi (vector3 v );


  vector3 getRadialNodecolor (){ return radialNodecolor;  }
  vector3 getAngularNodecolor_Theta (){ return angularNodecolor_Theta; }
  vector3 getAngularNodecolor_Phi (){ return angularNodecolor_Phi; }


  void setRadialNodeOpicity (double o);
  void setAngularNodeOpicity_Theta (double o);
  void setAngularNodeOpicity_Phi (double o);


  void setLobeColor_pos( vector3 );
  void setLobeColor_neg( vector3 );
  void setOrbitalLineWidth(double );
  double getOrbitalLineWidth() {return orbitalLineWidth;};
  void   refreshView();


public:
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkPlane> plane;
    vtkSmartPointer<vtkClipPolyData> clipper_pos,clipper_neg;

    void renderMol(HMol *  );
    void renderMolProj(HMol *  );
    void renderOrbital(HMol * );

    void renderOrbitallNodes(HMol *);
    void renderOrbitalRadialNodes(HMol *);
    void renderOrbitalAngularNodes(HMol *);

    void renderOrbitalAngularPhiNodes(HMol *);
    void renderOrbitalAngularThetaNodes(HMol *);
    void renderCones(double height, double cos2angle);

    void renderProjOrbital(HMol * );
    void renderLine(double p0[3],double p1[3],double color[3],float width,vtkTransform * transform);

    void  setBackgroundColor( vector3 );
    vector3 getBackgroundColor(){return bkcolor;}

    void  writePNG(QString );





    vtkSmartPointer<vtkCamera> camera;



public slots:
  //! Zoom to the extent of the data set in the scene
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

public:
  vector3 positiveLobeColor(){return LobeColor_pos;};
  vector3 negtiveLobeColor(){return LobeColor_neg;};

  void  setPosLobeOpacity(double c) {opacity_pos=c;}
  void  setNegLobeOpacity(double c) {opacity_neg=c;}

  double getPosLobeOpacity() {return opacity_pos;}
  double getNegLobeOpacity() {return opacity_neg;}
  double getAngularNodeThetaOpacity() {return opacity_theta;}
  double getAngularNodePhiOpacity() {return opacity_phi;}
  double getRadialNodeOpacity() {return opacity_radial;}

  double getNodeThickness (){return nodeThickness;}
  void   setNodeThickness (double t){nodeThickness=t;}



private:
  vtkSmartPointer<vtkRenderer> m_renderer;
  vector3 angularNodecolor_Theta,angularNodecolor_Phi,radialNodecolor;
  vector3 bkcolor,whiteColor;
  vector3 LobeColor_pos,LobeColor_neg;
  double  opacity_pos,opacity_neg;
  double  opacity_theta,opacity_phi,opacity_radial;
  double  orbitalLineWidth,nodeThickness;
};




#endif // AO3DVIEW_H
