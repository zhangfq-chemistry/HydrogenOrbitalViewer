#include "View3D.h"
#include "matrix3/vector3.h"

#define USER_MATRIX


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




vector3 MakeGlColor(uint32_t dw)
{
   float v1,v2,v3;
   float &r = v1, &g = v2, &b = v3;
   r = (1.f/255.f)*((dw>>16)&0xff);
   g = (1.f/255.f)*((dw>>8)&0xff);
   b = (1.f/255.f)*((dw>>0)&0xff);

   vector3 v (r,g,b);

   return v;
}

void interP(vector3 p0, vector3 p1, uint num, QVector <vector3> & ColorMaps)
{
    vector3 step=(p1-p0)/num;
    uint i=0;
    while (i < num)
    {
        ColorMaps.push_front(p0+i*step);
        i++;
    }
}




View3D::View3D(QWidget *parent)
  : QVTKOpenGLNativeWidget(parent)
{
  this->setWindowTitle("Total Wave Function (Psi)");

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
  length_x=length_y=length_z=6.0;

   plane=nullptr;
   clipper_pos=nullptr;
   clipper_neg=nullptr;


   //LobeColor_pos,LobeColor_neg;
  // LobeColor_pos.Set(10.0,1.0,1.0);
 //  LobeColor_neg.Set(0.0,1.0,10.0);

   LobeColor_pos.Set(0.90,0.56,0.14);
   LobeColor_neg.Set(0.21,0.44,0.53);

   opacity_theta=opacity_phi=opacity_radial=0.5;
   opacity_pos=opacity_neg=1.0;

   orbitalLineWidth=1.0;
   nodeThickness=0.02;
}


void View3D::setRadialNodecolor (vector3 v)
{
    radialNodecolor=v;
}

void View3D::setAngularNodecolor_Theta (vector3 v )
{
    angularNodecolor_Theta=v;

}
void View3D::setAngularNodecolor_Phi (vector3 v )
{
    angularNodecolor_Phi=v;

}



void View3D::refreshView()
{
    GetRenderWindow()->Render();
}

void View3D::setRadialNodeOpicity (double o){
    opacity_radial=o;

}

void View3D::setAngularNodeOpicity_Theta (double o)
{
    opacity_theta=o;

}

void View3D::setAngularNodeOpicity_Phi (double o)
{
    opacity_phi=o;

}

void View3D::setOrbitalLineWidth(double l)
{
    orbitalLineWidth =l;

}

void View3D::setLobeColor_pos( vector3 c)
{
    LobeColor_pos=c;


}
void View3D::setLobeColor_neg( vector3 c)
{
    LobeColor_neg=c;

}


void View3D::setBackgroundColor( vector3 c)
{
    bkcolor=c;
    m_renderer->SetBackground(bkcolor.x(), bkcolor.y(), bkcolor.z());
    GetRenderWindow()->Render();
}

void View3D:: onViewXY()
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

void View3D:: onViewXZ()
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

void View3D:: onViewYZ()
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


void View3D:: onViewReset()
{
    onViewXY();
    /*
    camera->SetViewUp(0,1,0);
    camera->SetPosition(0,0,30);
    camera->SetFocalPoint(0,0,0);
    camera->ComputeViewPlaneNormal();

    GetRenderWindow()->Render();
*/
}

void View3D:: onView_rotateClockwise(double degree)
{
    double angle= camera->GetRoll();
    camera->SetRoll(angle-degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();

}

void View3D:: onView_rotateCounterClockwise(double degree)
{
    double angle= camera->GetRoll();
    camera->SetRoll(angle+degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void View3D:: onView_rotateUp(double degree)
{
    //camera->Pitch(-5);
    camera->Elevation(-degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}
void View3D:: onView_rotateDown(double degree)
{
    //camera->Pitch(5);
    camera->Elevation(degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

/*
void View3D::renderAxis(double l)
{
    if (!isAxisVisible) return;

    auto axes = vtkSmartPointer<vtkAxesActor>::New();
    axes->SetPosition(0, 0, 0);
    axes->SetTotalLength(l, l, l);
    axes->SetShaftType(0);
    axes->SetCylinderRadius(0.03);
    axes->SetConeRadius(0.3);
    axes->SetConeResolution(50);
    axes->SetAxisLabels(true);
    //axes->AxisLabelsOn();

    m_renderer->AddActor(axes);
}

*/


void View3D:: renderAxis(double l)
{
    if (!isAxisVisible) return;
    auto axes =  vtkSmartPointer<vtkAxesActor>::New();

    auto widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
    widget->SetOutlineColor( 0.9300, 0.5700, 0.1300 );
    widget->SetOrientationMarker( axes );
    //widget->SetInteractor( renderWindowInteractor );
    widget->SetViewport( 0.0, 0.0, 0.4, 0.4 );
    widget->SetEnabled( 1 );
    widget->InteractiveOn();
}


void View3D::renderMol(HMol * mol)
{
    removeAllActors();

    double l=mol->getObtial(0)->MaxBox();
    if(l<1.0 || l>50.0) l=5.0;
    //renderAxis(l);

    if (! mol || mol==nullptr)
    {
        cout << " mol is null " << endl;
        return;
    }

    double x,y,z;
    vector3 color;

    double scale=0.3; //for display

    cout << "number of atoms : "<< mol->NAtoms()<<endl;

    if (mol->NAtoms()<0 ) return;

    cout << "render atoms! "<<endl;

    if ( mol->isAtomVisible())
    for (uint i=0;i<mol->NAtoms();i++)
    {
        x = mol->atoms[i]->x();
        y = mol->atoms[i]->y();
        z = mol->atoms[i]->z();

        auto sphere = vtkSphereSource::New();
        sphere->SetPhiResolution(20);
        sphere->SetThetaResolution(20);
        sphere->SetCenter(x,y,z);

        //cout << x << " "<< y << " "<< z << endl;

        sphere->SetRadius(scale*mol->atoms[i]->radius);
        sphere->Update();
        color = MakeGlColor(mol->atoms[i]->Color());

        auto actor = vtkActor::New();
        auto mapper = vtkPolyDataMapper::New();
        actor->GetProperty()->SetColor(color.x(),color.y(),color.z());
        actor->SetMapper(mapper);
        mapper->SetInputConnection(sphere->GetOutputPort());
        m_renderer->AddActor(actor);

        mapper->Delete();
        sphere->Delete();
    }

    cout << "render bonds! "<<endl;

    if ( mol->isAtomVisible())
    for (uint j=0;j<mol->NBonds();j++)
    {
        HBond * bond= mol->getBond(j);

        double scale=bond->getScale();

        vector3 p0=mol->getAtom(bond->atomIndex0())->Pos();
        vector3 p1=mol->getAtom(bond->atomIndex1())->Pos();

        vector3 p=(p0+p1)/2.0;
        //vector3 p=(p1+p0)*scale;

        auto line = vtkSmartPointer<vtkLineSource>::New();
        line->SetPoint1(p0[0], p0[1], p0[2]);
        line->SetPoint2(p[0], p[1], p[2]);

        auto tubeFilter = vtkSmartPointer<vtkTubeFilter>::New();
        tubeFilter->SetInputConnection(line->GetOutputPort());
        tubeFilter->SetRadius(0.1);
        tubeFilter->SetNumberOfSides(50);

        color = MakeGlColor(mol->getAtom(bond->atomIndex0())->Color());
        auto actor = vtkActor::New();
        auto mapper = vtkPolyDataMapper::New();
        actor->GetProperty()->SetColor(color.x(),color.y(),color.z());
        actor->SetMapper(mapper);
        mapper->SetInputConnection(tubeFilter->GetOutputPort());
        m_renderer->AddActor(actor);





        auto line1 = vtkSmartPointer<vtkLineSource>::New();
        line1->SetPoint1(p[0], p[1], p[2]);
        line1->SetPoint2(p1[0], p1[1], p1[2]);

        auto tubeFilter1 = vtkSmartPointer<vtkTubeFilter>::New();
        tubeFilter1->SetInputConnection(line1->GetOutputPort());
        tubeFilter1->SetRadius(0.1);
        tubeFilter1->SetNumberOfSides(50);

        auto actor1 = vtkActor::New();
        auto mapper1 = vtkPolyDataMapper::New();
        color = MakeGlColor(mol->getAtom(bond->atomIndex1())->Color());
        actor1->GetProperty()->SetColor(color.x(),color.y(),color.z());
        actor1->SetMapper(mapper1);
        mapper1->SetInputConnection(tubeFilter1->GetOutputPort());
        m_renderer->AddActor(actor1);

       // mapper->Delete();
       // line->Delete();
       // tubeFilter->Delete();
    }




    renderOrbital(mol);
    renderOrbitallNodes(mol);

    GetRenderWindow()->Render();
}


void View3D:: writePNG(QString name)
{
    //vector3 color=bkcolor;
    //setBKColor(whiteColor);


    auto windowToImageFilter =  vtkSmartPointer<vtkWindowToImageFilter>::New();
    windowToImageFilter->SetInput(GetRenderWindow());
    windowToImageFilter->SetScale(4);
    windowToImageFilter->SetInputBufferTypeToRGBA(); //also record the alpha (transparency) channel
    windowToImageFilter->ReadFrontBufferOff(); // read from the back buffer
    windowToImageFilter->Update();

    auto writer = vtkSmartPointer<vtkPNGWriter>::New();
    writer->SetFileName(name.toLatin1());
    writer->SetInputConnection(windowToImageFilter->GetOutputPort());
    writer->Write();

    //setBKColor(color);
  }



void View3D::renderOrbitallNodes(HMol * mol)
{
    if (! mol || mol==nullptr)
    {
        cout << " mol is null " << endl;
        return;
    }

    if (mol->NOrbitals()<1) return;

    renderOrbitalRadialNodes(mol);
    renderOrbitalAngularNodes(mol);
}


void View3D::renderOrbitalRadialNodes(HMol * mol)
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
void View3D::renderOrbitalAngularThetaNodes(HMol * mol)
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

             /*
             cout << k+1 <<": "<<cos2angle<<"---> ";
             double angle=acos(sqrt(cos2angle))/3.141592654*180.0;
             cout<<angle<<endl;
             */

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


void View3D::renderCones(double height, double cos2angle)
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

    //
    //mapper_torus->Delete();
    //mapper_torus1->Delete();
}




void View3D::renderOrbitalAngularNodes(HMol * mol)
{
    renderOrbitalAngularPhiNodes(mol);
    renderOrbitalAngularThetaNodes(mol);
}



//phi node around Z axis
void View3D::renderOrbitalAngularPhiNodes(HMol * mol)
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


void View3D::renderOrbital(HMol * mol)
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


    //orbitals
    if (mol->NOrbitals()<1) return;

    double lineWidth=orbitalLineWidth;

    uint NMOs=mol->NOrbitals();
    //cout << "render "<< NMOs << " orbital " <<endl;


    for (uint k =0; k<NMOs;k++) //each orbital
    {
        if (mol->getObtial(k)==nullptr)
             continue;

        if (! mol->getObtial(k)->isVisible())
            continue;

         auto actor_pos = vtkActor::New();
         auto mapper_pos = vtkPolyDataMapper::New();

         //cout << k+1<<":"<<endl;
         if (mol->getObtial(k)->isPosLobeVisible())
         {
             actor_pos->GetProperty()->SetColor(color1);
             actor_pos->GetProperty()->SetOpacity(opacity_pos);
             mapper_pos->ScalarVisibilityOff();


             if (mol->getObtial(k)->isPosLobeMesh()) {
                    actor_pos->GetProperty()->SetLineWidth(lineWidth);
                    actor_pos->GetProperty()->SetRepresentationToWireframe();
                    actor_pos->GetProperty()->ShadingOff();
                    //mapper_pos->ScalarVisibilityOff();
             }
             auto scalars = vtkSmartPointer<vtkFloatArray>::New();


#pragma omp parallel for
             for(int i = 0; i < mol->getObtial(k)->pData->GetNumberOfPoints(); i++)
             {
                    double * p = mol->getObtial(k)->pData->GetPoint(i);
                    scalars->InsertTuple1(i,-0.6);
             }
             mol->getObtial(k)->pData->GetPointData()->SetScalars(scalars);


/*
 * no improvement is observed
             auto reverse = vtkSmartPointer<vtkReverseSense>::New();
             reverse->SetInputData(mol->getObtial(k)->pData);
             reverse->ReverseCellsOn();
             reverse->ReverseNormalsOn();
             mapper_pos->SetInputConnection(reverse->GetOutputPort());
*/

             mapper_pos->SetInputData(mol->getObtial(k)->pData);
             actor_pos->SetMapper(mapper_pos);
             actor_pos->GetProperty()->SetInterpolationToGouraud();

             actor_pos->GetProperty()->SetDiffuse(0.9);
             actor_pos->GetProperty()->SetAmbient(0.3);
             actor_pos->GetProperty()->SetSpecular(0.2);
             actor_pos->GetProperty()->SetSpecularPower(10.0);


             m_renderer->AddActor(actor_pos);
             mapper_pos->Delete();
         }




        //negative lobe---------------------------------------------
        if (!mol->getObtial(k)->isNegLobeVisible()) continue;

        if (mol->getObtial(k)->pData1->GetNumberOfPoints()<10) continue;
        auto actor_neg = vtkActor::New();
        auto mapper_neg = vtkPolyDataMapper::New();


        actor_neg->GetProperty()->SetColor(color2);
        actor_neg->GetProperty()->SetOpacity(opacity_neg);
        mapper_neg->ScalarVisibilityOff();

        if (mol->getObtial(k)->isNegLobeMesh())
        {
                actor_neg->GetProperty()->ShadingOff();
                actor_neg->GetProperty()->SetLineWidth(lineWidth);
                actor_neg->GetProperty()->SetRepresentationToWireframe();
                mapper_neg->ScalarVisibilityOff();
        }


        auto scalars1 = vtkSmartPointer<vtkFloatArray>::New();
#pragma omp parallel for
        for(int i = 0; i < mol->getObtial(k)->pData1->GetNumberOfPoints(); i++)
        {
               double * p = mol->getObtial(k)->pData1->GetPoint(i);
               scalars1->InsertTuple1(i,0.8);
        }
        mol->getObtial(k)->pData1->GetPointData()->SetScalars(scalars1);

        mapper_neg->SetInputData(mol->getObtial(k)->pData1);
        actor_neg->SetMapper(mapper_neg);
        actor_neg->GetProperty()->SetInterpolationToGouraud();

        actor_neg->GetProperty()->SetDiffuse(0.9);
        actor_neg->GetProperty()->SetAmbient(0.3);
        actor_neg->GetProperty()->SetSpecular(0.2);
        actor_neg->GetProperty()->SetSpecularPower(10.0);

        m_renderer->AddActor(actor_neg);
        mapper_neg->Delete();

      }



     //plane->Delete();
     //clipper_neg->Delete();
     //clipper_pos->Delete();
     //renderAxis();
}

void View3D::renderLine(double p0[3],double p1[3],double color[3],float width, vtkTransform * transform)
{
    auto lineSource =  vtkSmartPointer<vtkLineSource>::New();
    lineSource->SetPoint1(p0);
    lineSource->SetPoint2(p1);
    lineSource->Update();

    auto lineActor = vtkActor::New();
    auto lineMapper = vtkPolyDataMapper::New();
    lineMapper->SetInputConnection(lineSource->GetOutputPort());


    lineActor->SetMapper(lineMapper);
    lineActor->GetProperty()->SetColor(color[0], color[1], color[2]);
    lineActor->GetProperty()->SetLineWidth(width);
    lineActor->SetUserTransform(transform);

    m_renderer->AddActor(lineActor);
}



void View3D::addDataSet(vtkSmartPointer<vtkDataSet> dataSet)
{
  // Actor
  auto actor = vtkSmartPointer<vtkActor>::New();

  // Mapper
  auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
  mapper->SetInputData(dataSet);
  actor->SetMapper(mapper);

  m_renderer->AddActor(actor);
 // m_renderer->ResetCamera(dataSet->GetBounds());
//  renderVTK();
}


void View3D::removeAllActors()
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


void View3D::removeLastActor()
{
    vtkActor * actor = m_renderer->GetActors()->GetLastActor();

    if (actor != nullptr)
        m_renderer->RemoveActor(actor);
}


void View3D::zoomToExtent()
{
    // Zoom to extent of last added actor
    vtkSmartPointer<vtkActor> actor = m_renderer->GetActors()->GetLastActor();
    if (actor != nullptr)
        m_renderer->ResetCamera(actor->GetBounds());

    //renderVTK();
}

void View3D:: onView_rotateLeft(double degree)
{
    camera->Azimuth(degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void View3D:: onView_rotateRight(double degree)
{
    camera->Azimuth(-degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}
