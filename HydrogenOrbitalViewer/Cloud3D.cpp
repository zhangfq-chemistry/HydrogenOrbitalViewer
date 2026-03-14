#include "Cloud3D.h"
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
#include <vtkTubeFilter.h>
#include <vtkWindowToImageFilter.h>

#include <vtkOrientationMarkerWidget.h>

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
#include <vtkCleanPolyData.h>

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
#include <vtkContourFilter.h>
#include <vtkReverseSense.h>



#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkParametricFunctionSource.h>
#include <vtkParametricTorus.h>

#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkOrientationMarkerWidget.h>

#include <vtkSurfaceReconstructionFilter.h>
#include <vtkExtractSurface.h>


Cloud3D::Cloud3D(QWidget *parent)
  : QVTKOpenGLNativeWidget(parent)
{
  this->setWindowTitle("Cloud Wave Function");

  vtkNew<vtkGenericOpenGLRenderWindow> window;
  SetRenderWindow(window.Get());


  //background color
  bkcolor.Set(0.6,0.6,0.6);
  whiteColor.Set(1.0,1.0,1.0);

  angularNodecolor_Theta.Set(0.3,0.6,0.3);
  angularNodecolor_Phi.Set(0.3,0.6,0.3);
  radialNodecolor.Set(1.0,1.0,1.0);

  // Camera
  camera = vtkSmartPointer<vtkCamera>::New();
  camera->SetViewUp(0,1,0);
  camera->SetPosition(0,0,90);
  camera->SetFocalPoint(0,0,0);
  camera->SetParallelScale(0.0);
  //camera->ParallelProjectionOn();

  // Renderer
  m_renderer = vtkSmartPointer<vtkRenderer>::New();
  m_renderer->SetActiveCamera(camera);
  m_renderer->SetBackground(bkcolor.x(), bkcolor.y(), bkcolor.z());
  GetRenderWindow()->AddRenderer(m_renderer);


  isAxisVisible=true;


  LobeColor_pos.Set(0.90,0.56,0.14);
  LobeColor_neg.Set(0.21,0.44,0.53);


   opacity_theta=opacity_phi=opacity_radial=0.5;

   orbitalLineWidth=1.5;
   nodeThickness=0.02;
}



void Cloud3D::setLobeColor_pos( vector3 c)
{
    LobeColor_pos=c;


}
void Cloud3D::setLobeColor_neg( vector3 c)
{
    LobeColor_neg=c;

}


void Cloud3D::setBackgroundColor( vector3 c)
{
    bkcolor=c;
    m_renderer->SetBackground(bkcolor.x(), bkcolor.y(), bkcolor.z());
    GetRenderWindow()->Render();
}

void Cloud3D:: onViewXY()
{
    camera->SetViewUp(0,1,0);

    double p[3];
    camera->GetPosition(p);
    vector3 v(p[0],p[1],p[2]);
    camera->SetPosition(0,0,v.length());

    camera->SetFocalPoint(0,0,0);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void Cloud3D:: onViewXZ()
{
    double p[3];
    camera->GetPosition(p);
    vector3 v(p[0],p[1],p[2]);

    onViewReset();
    camera->SetPosition(0,0,v.length());
    camera->Azimuth(90);
    camera->SetFocalPoint(0,0,0);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void Cloud3D:: onViewYZ()
{
    double p[3];
    camera->GetPosition(p);
    vector3 v(p[0],p[1],p[2]);

    onViewReset();
    camera->SetPosition(0,0,v.length());
    camera->Elevation(90);
    camera->SetFocalPoint(0,0,0);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}


void Cloud3D:: onViewReset()
{
    onViewXY();
}

void Cloud3D:: onView_rotateClockwise(double degree)
{
    double angle= camera->GetRoll();
    camera->SetRoll(angle-degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();

}

void Cloud3D:: onView_rotateCounterClockwise(double degree)
{
    double angle= camera->GetRoll();
    camera->SetRoll(angle+degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void Cloud3D:: onView_rotateUp(double degree)
{
    //camera->Pitch(-5);
    camera->Elevation(-degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void Cloud3D:: onView_rotateDown(double degree)
{
    //camera->Pitch(5);
    camera->Elevation(degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}
void Cloud3D:: onView_rotateLeft(double degree)
{
    camera->Azimuth(degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void Cloud3D:: onView_rotateRight(double degree)
{
    camera->Azimuth(-degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}



void Cloud3D::removeAllActors()
{
   while (1) {
      vtkActor * actor = m_renderer->GetActors()->GetLastActor();
      if (actor != nullptr)
      {
        m_renderer->RemoveActor(actor);
        continue;
      }
      break;
    }
}


void Cloud3D::removeLastActor()
{
    vtkActor * actor = m_renderer->GetActors()->GetLastActor();

    if (actor != nullptr)
        m_renderer->RemoveActor(actor);
}


void Cloud3D::zoomToExtent()
{
    // Zoom to extent of last added actor
    vtkSmartPointer<vtkActor> actor = m_renderer->GetActors()->GetLastActor();
    if (actor != nullptr)
        m_renderer->ResetCamera(actor->GetBounds());
}


void Cloud3D::renderMol(HMol * mol)
{
    removeAllActors();
    renderOrbital(mol);
    renderNodes(mol);
    GetRenderWindow()->Render();
}


void Cloud3D::renderNodes(HMol * mol)
{
    if (! mol || mol==nullptr)
    {
        cout << " mol is null " << endl;
        return;
    }

    if (mol->NOrbitals()<1) return;

    rendeRadialNodes(mol);
    renderPhiNodes(mol);
    renderThetaNodes(mol);
}


void Cloud3D::rendeRadialNodes(HMol * mol)
{
    double color[3];
    color[0]=radialNodecolor.x();
    color[1]=radialNodecolor.y();
    color[2]=radialNodecolor.z();

    for (uint i =0; i<mol->NOrbitals();i++) //each orbital
    {
         if (mol->getObtial(i)->isHybridizedOrbital) continue;
         if (mol->getObtial(i)->isMolecularOrbital) continue;
         if (!mol->getObtial(i)->isVisible()) continue;


         for (uint j =0; j<mol->getObtial(i)->NumAOs();j++)
         {
             if (!mol->getObtial(i)->isVisible_radial_node()) continue;

              for (int k=0;k<mol->getObtial(i)->getAO(j)->Nodes_R.size();k++)
              {
                  double r0=mol->getObtial(i)->getAO(j)->Nodes_R[k];
                  if (r0<0.1) continue;

                  auto sphere = vtkSphereSource::New();
                  sphere->SetPhiResolution(50);
                  sphere->SetThetaResolution(50);
                  sphere->SetRadius(r0);
                  sphere->Update();

                  auto actor = vtkActor::New();
                  auto mapper = vtkPolyDataMapper::New();
                  actor->GetProperty()->SetColor(color);
                  actor->SetMapper(mapper);
                  actor->GetProperty()->SetOpacity(0.6);

                  actor->GetProperty()->ShadingOff();
                  mapper->ScalarVisibilityOff();

                  mapper->SetInputConnection(sphere->GetOutputPort());
                  m_renderer->AddActor(actor);
                  mapper->Delete();


              }
         }
    }

}

//theta node
void Cloud3D::renderThetaNodes(HMol * mol)
{
    bool HorinzontalSquare=false;

    double height=4.0;
    double thickness=nodeThickness;
    double opacity=opacity_theta;

    double length=6.0;

    double color[3];

    color[0]=angularNodecolor_Theta.x();
    color[1]=angularNodecolor_Theta.y();
    color[2]=angularNodecolor_Theta.z();


    auto colors =  vtkSmartPointer<vtkNamedColors>::New();

    //upper
    auto coneSource0 =  vtkSmartPointer<vtkConeSource>::New();
    coneSource0->SetDirection(0.0,0.0,1.0);
    coneSource0->SetResolution(100);
    coneSource0->SetCenter(0.0, 0.0, 0.0);
    coneSource0->SetCapping(false);
    coneSource0->SetHeight(height);
    coneSource0->Update();


    //lower
    auto coneSource1 =  vtkSmartPointer<vtkConeSource>::New();
    coneSource1->SetDirection(0.0,0.0,-1.0);
    coneSource1->SetResolution(100);
    coneSource1->SetCenter(0.0, 0.0, 0.0);
    coneSource1->SetCapping(false);
    coneSource1->SetHeight(height);
    coneSource1->Update();

    auto cylinder =  vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetCenter(0.0, 0.0, 0.0);
    cylinder->SetRadius(length/2.0);
    cylinder->SetHeight(thickness);
    cylinder->SetResolution(100);
    cylinder->Update();




    //build one torus
    auto parametricObject = vtkSmartPointer<vtkParametricTorus>::New();
    auto parametricFunctionSource =	vtkSmartPointer<vtkParametricFunctionSource>::New();
    parametricFunctionSource->SetParametricFunction(parametricObject);
    parametricFunctionSource->Update();
    parametricObject->SetRingRadius(length/2.0);
    parametricObject->SetCrossSectionRadius(0.06);


    auto cube = vtkSmartPointer<vtkCubeSource>::New();
    cube->SetCenter(0.0, 0.0, 0.0);

    vtkSmartPointer<vtkTransform>  rotation;


    for (uint i =0; i<mol->NOrbitals();i++) //each orbital
    {
         if (!mol->getObtial(i)->isVisible()) continue;

         if (mol->getObtial(i)->isHybridizedOrbital) continue;
         if (mol->getObtial(i)->isMolecularOrbital) continue;

         //only one AO included
         uint j=0;
         if (!mol->getObtial(i)->isVisible_angular_node()) continue;

         for (int k=0;k<mol->getObtial(i)->getAO(j)->Nodes_T.size();k++)
         {
             double cos2angle=mol->getObtial(i)->getAO(j)->Nodes_T[k];


             //just the xoy plane
             if (abs(cos2angle)<0.001) //render disk orsquare
             {
                 length=mol->getObtial(i)->MaxBox();
                 thickness=length*0.005;
                 cube->SetXLength(length);
                 cube->SetYLength(length);
                 cube->SetZLength(thickness);
                 cube->Update();

                 auto mapper = vtkPolyDataMapper::New();
                 mapper->ScalarVisibilityOn();
                 auto actor = vtkActor::New();
                 actor->GetProperty()->SetColor(color);
                 actor->GetProperty()->SetOpacity(opacity);
                 actor->GetProperty()->ShadingOff();
                 actor->SetMapper(mapper);

                 if (HorinzontalSquare)
                     mapper->SetInputData(cube->GetOutput());
                 else
                 {
                    cylinder->SetRadius(length/2.0);
                    cylinder->SetHeight(thickness);
                    cylinder->Update();
                    mapper->SetInputData(cylinder->GetOutput());
                    rotation=  vtkSmartPointer<vtkTransform>::New();
                    rotation->PostMultiply();
                    rotation->RotateX(90.0);
                    actor->SetUserTransform(rotation);


                    //build one torus
                    parametricFunctionSource->Update();
                    parametricObject->SetRingRadius(length/2.0);
                    parametricObject->SetCrossSectionRadius(0.06);


                    auto mapper_torus =   vtkSmartPointer<vtkPolyDataMapper>::New();
                    mapper_torus->SetInputConnection(parametricFunctionSource->GetOutputPort());
                    mapper_torus->ScalarVisibilityOn();


                     auto actor_torus = vtkSmartPointer<vtkActor>::New();
                     actor_torus->SetMapper(mapper_torus);
                     actor_torus->GetProperty()->SetColor(color);
                     m_renderer->AddActor(actor_torus);

                     //crashed if added
                     //mapper_torus->Delete();
                 }

                 actor->GetProperty()->SetInterpolationToGouraud();
                 m_renderer->AddActor(actor);
                 mapper->Delete();
             }
             else{//cone
                 height=0.56*mol->getObtial(i)->MaxBox();
                 renderCones(height,  cos2angle);
             }
        }
    }
}


void Cloud3D::renderCones(double height, double cos2angle)
{
    //upper
    auto coneSource0 =  vtkSmartPointer<vtkConeSource>::New();
    coneSource0->SetDirection(0.0,0.0,1.0);
    coneSource0->SetResolution(100);
    coneSource0->SetCenter(0.0, 0.0, 0.0);
    coneSource0->SetCapping(false);
    coneSource0->SetHeight(height);
    coneSource0->Update();


    //lower
    auto coneSource1 =  vtkSmartPointer<vtkConeSource>::New();
    coneSource1->SetDirection(0.0,0.0,-1.0);
    coneSource1->SetResolution(100);
    coneSource1->SetCenter(0.0, 0.0, 0.0);
    coneSource1->SetCapping(false);
    coneSource1->SetHeight(height);
    coneSource1->Update();

    double thickness=nodeThickness;
    double opacity=opacity_theta;
    double length=6.0;

    double color[3];

    color[0]=angularNodecolor_Theta.x();
    color[1]=angularNodecolor_Theta.y();
    color[2]=angularNodecolor_Theta.z();

    //build one torus
    auto parametricObject = vtkSmartPointer<vtkParametricTorus>::New();
    auto parametricFunctionSource =	vtkSmartPointer<vtkParametricFunctionSource>::New();
    parametricFunctionSource->SetParametricFunction(parametricObject);
    parametricFunctionSource->Update();
    parametricObject->SetRingRadius(length/2.0);
    parametricObject->SetCrossSectionRadius(0.06);

    //the following code render double-cone node, based on theta
    auto actor = vtkActor::New();
    auto mapper = vtkPolyDataMapper::New();
    actor->GetProperty()->SetColor(color);
    actor->GetProperty()->SetOpacity(opacity);
    actor->GetProperty()->ShadingOff();



    auto transform =  vtkSmartPointer<vtkTransform>::New();
    transform->PostMultiply();
    transform->Translate(0.0,0.0,-height/2.0);
    actor->SetUserTransform(transform);
    mapper->ScalarVisibilityOn();

    coneSource0->SetHeight(height);
    double radius=height*sqrt(1.0/cos2angle-1.0);
    coneSource0->SetRadius(radius);
    coneSource0->Update();


    mapper->SetInputData(coneSource0->GetOutput());
    actor->SetMapper(mapper);
    actor->GetProperty()->SetInterpolationToGouraud();
    m_renderer->AddActor(actor);


    auto actor1 = vtkActor::New();
    auto mapper1 = vtkPolyDataMapper::New();
    actor1->GetProperty()->SetColor(color);
    actor1->SetMapper(mapper1);
    actor1->GetProperty()->SetOpacity(opacity);
    actor1->GetProperty()->ShadingOff();

    auto transform1 =  vtkSmartPointer<vtkTransform>::New();
    transform1->PostMultiply();
    transform1->Translate(0.0,0.0,height/2.0);
    actor1->SetUserTransform(transform1);

    mapper1->ScalarVisibilityOn();
    coneSource1->SetHeight(height);
    coneSource1->SetRadius(radius);

    mapper1->SetInputConnection(coneSource1->GetOutputPort());
    actor1->GetProperty()->SetInterpolationToGouraud();
    m_renderer->AddActor(actor1);
    mapper1->Delete();



    //building two torus
    parametricFunctionSource->Update();
    parametricObject->SetRingRadius(radius);
    parametricObject->SetCrossSectionRadius(0.08);


    auto transform_tours =  vtkSmartPointer<vtkTransform>::New();
    transform_tours->PostMultiply();
    transform_tours->Translate(0.0,0.0,-height);

    auto mapper_torus =   vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper_torus->SetInputConnection(parametricFunctionSource->GetOutputPort());
    mapper_torus->ScalarVisibilityOn();

    // Create an actor for the contours
    auto actor_torus = vtkSmartPointer<vtkActor>::New();
    actor_torus->SetMapper(mapper_torus);
    actor_torus->GetProperty()->SetColor(color);
    actor_torus->SetUserTransform(transform_tours);
    //actor_torus->GetProperty()->SetOpacity(0.9);
    m_renderer->AddActor(actor_torus);


    auto transform_tours1 =  vtkSmartPointer<vtkTransform>::New();
    transform_tours1->PostMultiply();
    transform_tours1->Translate(0.0,0.0,height);


    auto mapper_torus1 =   vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper_torus1->SetInputConnection(parametricFunctionSource->GetOutputPort());
    mapper_torus1->ScalarVisibilityOn();


    auto actor_torus1 = vtkSmartPointer<vtkActor>::New();
    actor_torus1->SetMapper(mapper_torus1);
    actor_torus1->GetProperty()->SetColor(color);
    actor_torus1->SetUserTransform(transform_tours1);
    //actor_torus1->GetProperty()->SetOpacity(0.9);
    m_renderer->AddActor(actor_torus1);
}


void Cloud3D::renderOrbital(HMol * mol)
{

    if (! mol || mol==nullptr)
    {
        cout << " mol is null " << endl;
        return;
    }

    double color1[3],color2[3];
    color1[0]=LobeColor_pos.x();
    color1[1]=LobeColor_pos.y();
    color1[2]=LobeColor_pos.z();

    color2[0]=LobeColor_neg.x();
    color2[1]=LobeColor_neg.y();
    color2[2]=LobeColor_neg.z();

    //Nodes_P
    for (uint i =0; i<mol->NOrbitals();i++) //each orbital
    {
         if (!mol->getObtial(i)->isVisible()) continue;
         if (mol->getObtial(i)->isHybridizedOrbital) continue;
         if (mol->getObtial(i)->isMolecularOrbital) continue;

         //positive
         //cout << mol->getObtial(i)->cloudPoints_pos.size()<<endl;
         //cout << mol->getObtial(i)->cloudPoints_neg.size()<<endl;

         if(mol->getObtial(i)->cloudPoints_pos.size()>10) {
             auto mapper=vtkSmartPointer<vtkPolyDataMapper>::New();
             mapper->SetInputData(mol->getObtial(i)->glyphFilter_pos->GetOutput());

             auto actor = vtkSmartPointer<vtkActor>::New();
             actor->SetMapper(mapper);
             actor->GetProperty()->SetColor(color1);
			 actor->GetProperty()->SetPointSize(2);
             m_renderer->AddActor(actor);
         }

         //negtive
         if(mol->getObtial(i)->cloudPoints_neg.size()>10)
         {
             auto mapper=vtkSmartPointer<vtkPolyDataMapper>::New();
             mapper->SetInputConnection(mol->getObtial(i)->glyphFilter_neg->GetOutputPort());

             auto actor = vtkSmartPointer<vtkActor>::New();
             actor->SetMapper(mapper);
             actor->GetProperty()->SetColor(color2);
			 actor->GetProperty()->SetPointSize(3);
             m_renderer->AddActor(actor);
         }

    }

}


//phi node around Z axis
void Cloud3D::renderPhiNodes(HMol * mol)
{
    double thikness=0.02;
    double length=6.0;
    double opacity=opacity_phi;

    double color[3];
    color[0]=angularNodecolor_Phi.x();
    color[1]=angularNodecolor_Phi.y();
    color[2]=angularNodecolor_Phi.z();

    auto cube = vtkSmartPointer<vtkCubeSource>::New();
    cube->SetCenter(0.0, 0.0, 0.0);

    auto cube1 = vtkSmartPointer<vtkCubeSource>::New();
    cube1->SetCenter(0.0, 0.0, 0.0);


    //Nodes_P
    for (uint i =0; i<mol->NOrbitals();i++) //each orbital
    {
         if (!mol->getObtial(i)->isVisible()) continue;
         if (mol->getObtial(i)->isHybridizedOrbital) continue;
         if (mol->getObtial(i)->isMolecularOrbital) continue;

           length=mol->getObtial(i)->MaxBox();
           thikness=length*0.005;
           cube->SetXLength(length);
           cube->SetYLength(thikness);
           cube->SetZLength(length);
           cube->Update();

           cube1->SetXLength(thikness);
           cube1->SetYLength(thikness);
           cube1->SetZLength(length);
           cube1->Update();



           // only one AO inside each MO
           int j=0;

           if (!mol->getObtial(i)->isVisible_angular_node()) continue;
           if (mol->getObtial(i)->getAO(j)->Nodes_P.size()<1) continue;

           uint nNodes=mol->getObtial(i)->getAO(j)->Nodes_P.size();


           for (int k=0; k<nNodes; k++)
           {
               double angle=mol->getObtial(i)->getAO(j)->Nodes_P[k];


               auto actor = vtkActor::New();
               auto mapper = vtkPolyDataMapper::New();
               actor->GetProperty()->SetColor(color);
               actor->SetMapper(mapper);
               actor->GetProperty()->SetOpacity(opacity);
               actor->GetProperty()->ShadingOn();

               auto rotation=  vtkSmartPointer<vtkTransform>::New();
               rotation->PostMultiply();
               rotation->RotateZ(angle);
               actor->SetUserTransform(rotation);

               mapper->ScalarVisibilityOn();
               mapper->SetInputConnection(cube->GetOutputPort());
               actor->GetProperty()->SetInterpolationToGouraud();
               m_renderer->AddActor(actor);

               mapper->Delete();


               if(! mol->getObtial(i)->getAO(j)->isXOYNode )
                   continue;


               auto cube2 = vtkSmartPointer<vtkCubeSource>::New();
               cube2->SetCenter(0.0, 0.0, 0.0);
               cube2->SetXLength(length);
               cube2->SetYLength(thikness);
               cube2->SetZLength(thikness);
               cube2->Update();

               //render one line along the cross
               auto actor2 = vtkActor::New();
               auto mapper2 = vtkPolyDataMapper::New();
               actor2->GetProperty()->SetColor(0.0,0.0,0.0);
               actor2->SetMapper(mapper2);
               actor2->GetProperty()->SetOpacity(1.0);
               actor2->GetProperty()->ShadingOff();
               actor2->SetUserTransform(rotation);
               actor2->GetProperty()->SetInterpolationToGouraud();

               mapper2->ScalarVisibilityOff();

               mapper2->SetInputConnection(cube2->GetOutputPort());

               m_renderer->AddActor(actor2);
               mapper2->Delete();
           }



           if ( nNodes <2) continue;

           //render one line along the cross
           auto actor = vtkActor::New();
           auto mapper = vtkPolyDataMapper::New();
           actor->GetProperty()->SetColor(0.0,0.0,0.0);
           actor->SetMapper(mapper);
           actor->GetProperty()->SetOpacity(1.0);
           actor->GetProperty()->ShadingOff();
           actor->GetProperty()->SetInterpolationToGouraud();

           //rotation=  vtkSmartPointer<vtkTransform>::New();
           //rotation->PostMultiply();
           //rotation->RotateZ(angle);
           //actor->SetUserTransform(rotation);

           mapper->ScalarVisibilityOn();

           mapper->SetInputConnection(cube1->GetOutputPort());
           m_renderer->AddActor(actor);

           mapper->Delete();

    }
}
