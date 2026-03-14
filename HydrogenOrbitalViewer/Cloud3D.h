#ifndef CLOUD3D_H
#define CLOUD3D_H


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


class Cloud3D : public QVTKOpenGLNativeWidget
{
  Q_OBJECT

public:
   MainWindow * m_parent;

public:
  explicit Cloud3D(QWidget *parent = 0);

  // Add a data set to the scene
  void addDataSet(vtkSmartPointer<vtkDataSet> dataSet);

  // Remove the data set from the scene
  void removeLastActor();
  void removeAllActors();
  void renderAxis(double l=3.0);


  void  setBackgroundColor( vector3 );
  vector3 getBackgroundColor(){return bkcolor;}

  void  writePNG(QString );


  void setLobeColor_pos( vector3 c);
  void setLobeColor_neg( vector3 c);

  vtkSmartPointer<vtkCamera> camera;


  void renderMol(HMol * );

  void renderOrbital(HMol * );

  void renderCones(double , double );
  void renderThetaNodes(HMol * );
  void renderPhiNodes(HMol * );
  void rendeRadialNodes(HMol * );
  void renderNodes(HMol * );




  double getNodeThickness (){return nodeThickness;}
  void   setNodeThickness (double t){nodeThickness=t;}

  vector3 positiveLobeColor(){return LobeColor_pos;};
  vector3 negtiveLobeColor(){return LobeColor_neg;};

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
  vector3 angularNodecolor_Theta,angularNodecolor_Phi,radialNodecolor;
  vector3 bkcolor,whiteColor;
  vector3 LobeColor_pos,LobeColor_neg;
  double opacity_theta,opacity_phi,opacity_radial;
  double  orbitalLineWidth,nodeThickness;
  bool   isAxisVisible;
};

#endif // CLOUD3D_H
