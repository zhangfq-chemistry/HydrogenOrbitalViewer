#ifndef MESH3D_H
#define MESH3D_H

#include <QObject>
#include <QWidget>
#include <QString>


//#include <QtDataVisualization/Q3DSurface>
//#include <QtDataVisualization/QSurfaceDataProxy>
//#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
//#include <QtDataVisualization/QSurface3DSeries>

#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>
#include <QtCore/QPropertyAnimation>

#include <vtkCamera.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkDataSetMapper.h>

#include <QVTKOpenGLWidget.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkDataSet.h>

#include <vtkActor.h>
#include <vtkCommand.h>
#include <vtkConeSource.h>
#include <vtkEventQtSlotConnect.h>
#include <vtkInteractorStyle.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkTDxInteractorStyleCamera.h>
#include <vtkTDxInteractorStyleSettings.h>

#include <QVTKInteractor.h>

#include <vtkSmartPointer.h>
#include <vtkVolumeProperty.h>

#include <vtkPolyData.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>

#include <vtkCubeSource.h>
#include <vtkSphereSource.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataNormals.h>
#include <vtkAxesActor.h>
#include <vtkTransform.h>
#include <vtkCommand.h>
#include <vtkReflectionFilter.h>
#include <vtkNamedColors.h>
#include <vtkImplicitPolyDataDistance.h>
#include <vtkVolumeProperty.h>
#include <vtkAppendPolyData.h>
#include <vtkCleanPolyData.h>
#include <vtkPNGWriter.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkObjectFactory.h>
#include <vtkRenderingCoreModule.h>
#include <vtkProperty.h>
#include <vtkTexture.h>
#include <QVTKOpenGLNativeWidget.h>

#include "HAtomOrb.h"
#include "HMol.h"
#include "View3D.h"
#include <QHash>

class MainWindow;

class Mesh3D :  public QVTKOpenGLNativeWidget
{
    enum renderType {Line, Orbital};
    Q_OBJECT

public:
   MainWindow * m_parent;

  explicit Mesh3D(QWidget *parent = 0);
    ~Mesh3D() {
        if (pColorTable) pColorTable->Delete();
         removeAllActors();
    }


  // Remove the data set from the scene
  void removeActors(HMol * );
  void removeLastActor();
  void removeAllActors();
  void renderAxis();
  void removeOrbital(HMol * , uint );
  void removeOrbital(HMol *  );

  double scalarRange[2];

public:
    uint id_mol;
    vtkSmartPointer<vtkRenderer> renderer;


    void renderMol(HMol * );
    void generateObital(HMol * );

    void renderLine(double p0[3],double p1[3],double color[3],float width,vtkTransform * transform,
                uint idmol,uint idmo);

    void interP(vector3 , vector3 , uint , QVector <vector3> & );
    void buildColorTable();


    void sendMessage(QString);
    void appendMessage(QString);

    void setBKColor( vector3 );
    void writePNG(QString );


    vtkSmartPointer <vtkCamera> camera;

    vtkSmartPointer <vtkLookupTable> pColorTable;

    float  lineWidth;


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

private:

  vtkSmartPointer<vtkRenderer> m_renderer;
  vector3 bkcolor;
};


#endif // MESH3D_H
