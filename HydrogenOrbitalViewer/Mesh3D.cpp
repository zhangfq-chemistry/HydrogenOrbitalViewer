#include "Mesh3D.h"
#include <vtkObjectFactory.h>
#include <vtkWindowToImageFilter.h>
#include <vtkPNGWriter.h>
#include <QtWidgets/QVBoxLayout>
#include "mainwindow.h"

//vtkCxxMacro(MyActor, "$Revision: 1.45 $");
//vtkStandardNewMacro(MyActor);





void Mesh3D:: writePNG(QString name)
{
    //vector3 color=bkcolor,white(1.0,1.0,1.0);
    //setBKColor(white);

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



void Mesh3D::interP(vector3 p0, vector3 p1, uint num, QVector <vector3> & ColorMaps)
{
    vector3 step=(p1-p0)/num;
    uint i=0;
    while (i < num)
    {
        ColorMaps.push_back(p0+i*step);
        i++;
    }
}




Mesh3D::Mesh3D(QWidget *parent): QVTKOpenGLNativeWidget(parent)
{
  m_parent = (MainWindow *) parent;

  this->setWindowTitle("Wave-Function Projection");

  vtkNew<vtkGenericOpenGLRenderWindow> window;
  SetRenderWindow(window.Get());

  //background color
  bkcolor.Set(0.6,0.6,0.6);


  // Camera
  camera = vtkSmartPointer<vtkCamera>::New();
  camera->SetViewUp(0,1,0);
  camera->SetPosition(0,0,100);
  camera->SetFocalPoint(0,0,0);
  camera->SetParallelScale(0.0);
  //camera->ParallelProjectionOn();

  // Renderer
  m_renderer = vtkSmartPointer<vtkRenderer>::New();
  m_renderer->SetActiveCamera(camera);
  m_renderer->SetBackground(bkcolor.x(), bkcolor.y(), bkcolor.z());
  GetRenderWindow()->AddRenderer(m_renderer);


  lineWidth=2.0;

  scalarRange[0]=-1.0;
  scalarRange[1]=1.0;

  //LastMolId=0;
  buildColorTable();
}

void Mesh3D::setBKColor( vector3 color)
{
    bkcolor=color;
    m_renderer->SetBackground(bkcolor.x(), bkcolor.y(), bkcolor.z());
    GetRenderWindow()->Render();
}

void Mesh3D::sendMessage(QString  message)
{
    m_parent->sendMessage(message);
}

void Mesh3D::appendMessage(QString  message)
{
    m_parent->appendMessage(message);
}


void Mesh3D::buildColorTable()
{
    sendMessage("Building color table for projection orbital ... ");

    // Create the color map
    pColorTable=vtkLookupTable::New();
   // pColorTable->SetHueRange(0.63, 0.0);
    pColorTable->SetAlphaRange(1.0, 1.0);
    pColorTable->SetValueRange(1.0, 1.0);
    pColorTable->SetSaturationRange(1.0, 1.0);
    pColorTable->SetRange(scalarRange);

    vector3 red(255.,0.,0.);
    vector3 orange(255.,0,255.);
    vector3 white(255.,255.,255.);
    vector3 green(0.,255.,255.);
    vector3 blue(0.,0.,255.);

    QVector <vector3> ColorMaps;
    ColorMaps.clear();


    uint i=0;
    while (i<20){
        ColorMaps.push_back(red);
        i=i+1;
    }

    interP(red,orange,80,ColorMaps);
    interP(orange,white,25,ColorMaps);

    i=0;
    while (i<5) {
        i=i+1;
        ColorMaps.push_back(white);
    }


    interP(white,green,25,ColorMaps);
    interP(green,blue,80,ColorMaps);

    i=0;
    while (i<20){
        i=i+1;
        ColorMaps.push_back(blue);
    }

    //cout << "-------------------------------------"<<endl;
    //cout << "ColorMaps.size() "<<ColorMaps.size()<<endl;

    int size=ColorMaps.size();
    for (i=0;i<size;i++)
    {
        pColorTable->SetTableValue(i, ColorMaps[size-i].x()/255.0,
                                   ColorMaps[size-i].y()/255.0,
                                   ColorMaps[size-i].z()/255.0, 1);
        //cout << i<<": "<< ColorMaps[size-i].x() <<" "<<ColorMaps[size-i].y() <<" "<<ColorMaps[size-i].z() <<endl;
    }
//cout << "-------------------------------------"<<endl;
    pColorTable->SetNumberOfColors(size);
    pColorTable->SetNumberOfTableValues(size);
    pColorTable->Build();

    appendMessage("OK!");
}






void Mesh3D::renderLine(double p0[3],double p1[3],double color[3],float width, vtkTransform * transform,uint idmol,uint idmo)
{
    auto lineSource =  vtkSmartPointer<vtkLineSource>::New();
    lineSource->SetPoint1(p0);
    lineSource->SetPoint2(p1);
    lineSource->Update();

    auto lineActor = vtkActor::New();
    lineActor->setMolId(idmol);
    lineActor->setMOId(idmo);


    auto lineMapper = vtkPolyDataMapper::New();
    lineMapper->SetInputConnection(lineSource->GetOutputPort());


    lineActor->SetMapper(lineMapper);
    lineActor->GetProperty()->SetColor(color[0], color[1], color[2]);
    lineActor->GetProperty()->SetLineWidth(width);
    lineActor->SetUserTransform(transform);

    m_renderer->AddActor(lineActor);
    lineMapper->Delete();
}


void Mesh3D::renderMol(HMol * mol)
{
    removeAllActors();



    if (! mol || mol==nullptr)
    {
        cout << " mol is null " << endl;
        return;
    }

    //orbitals
    if (mol->NOrbitals()<1) return;


    vtkActorCollection* actorCollection = m_renderer->GetActors();
    int numActors = actorCollection->GetNumberOfItems();
    actorCollection->InitTraversal();


    //refresh visibility
    id_mol=mol->getIdx();


    sendMessage("Refresh visibility of each projection-orbital ...");
    for (uint k =0; k<mol->NOrbitals();k++)
    {
        HMO * mo=mol->getObtial(k);
        //if (mo->isHybridizedOrbital)   continue;
        //if (mo->isMolecularOrbital)   continue;

        if (mo->isVisible())
           sendMessage("Set " + mo->OrbitalName + " visible !");
        else
           sendMessage("Set " + mo->OrbitalName + " invisible !");
    }


    vector <int> invisibleMol;


    for (int i=0;i<numActors;++i)
    {
        vtkActor * actor = actorCollection->GetNextActor();

        if ( actor->MolId() == id_mol) {
            invisibleMol.push_back(actor->MolId());
            actor->SetVisibility(0);
            continue;
        }

        for (uint k =0; k<mol->NOrbitals();k++)
        {
            if (actor->MOId() != k) continue;

            HMO * mo=mol->getObtial(k);

            //if (mo->isHybridizedOrbital)   continue;
            //if (mo->isMolecularOrbital)   continue;

            if (mo->isVisible())
                actor->SetVisibility(1);
            else
               actor->SetVisibility(0);
        }
    }
    appendMessage("Done!");

    generateObital(mol);
    GetRenderWindow()->Render();
}





void Mesh3D::generateObital(HMol * mol)
{
    sendMessage("Generate the projection-orbitals ...");
    cout <<"Generate the projection-orbitals ..."<<endl;

    if (! mol || mol==nullptr)
    {
        cout << " mol is null " << endl;
        return;
    }

    //orbitals
    if (mol->NOrbitals()<1) return;


    double minBox, maxBox;
    uint scale=1;
    double color[3]={0.3,0.3,0.3};

    id_mol=mol->getIdx();

    for (uint k =0; k<mol->NOrbitals();k++) //each orbital
    {
        HMO * mo=mol->getObtial(k);

        cout << "generate orbital : " <<mo->dataXOY.size() +mo->dataYOZ.size() +mo->dataXOZ.size()<<endl;
        if ( mo->dataXOY.size() +mo->dataYOZ.size() +mo->dataXOZ.size() <1)
            continue;

        uint id_mo=k;
        scale=mo->get_projScale();

        //if (!mo->isAtomicOrbital)   continue;
        //cout << "generate orbital : " << k<<endl;

        //if (mo->isHybridizedOrbital)   continue;
        //if (mo->isMolecularOrbital)   continue;

        if (!mo->isVisible())   continue;

        double stepX=mo->Interval()/scale,
               stepY=mo->Interval()/scale,
               stepZ=mo->Interval()/scale;

        int countX=scale*mo->NumPoints(),
            countY=scale*mo->NumPoints(),
            countZ=scale*mo->NumPoints();


        mo->getBox(minBox,maxBox);
        maxBox-=stepX;


/*
        cout << "-----------------"<<endl;
        cout << " cout : " << countX<<endl;
        cout << " stepX : "<< stepX<<endl;
        cout << " minBox : "<< minBox<<endl;
        cout << " maxBox : "<< maxBox<<endl;
        cout << "-----------------"<<endl;
*/

        //render cube skeleton
        auto cubePoints =  vtkSmartPointer<vtkPoints>::New();
        auto polyLines =  vtkSmartPointer<vtkCellArray>::New();
        auto branchIdData = vtkSmartPointer<vtkIntArray>::New();

        double trans=maxBox*0.5;


        double  x0=minBox,
                y0=minBox,
                z0=minBox;

        auto points =  vtkSmartPointer<vtkPoints>::New();
        auto pointsSlice =  vtkSmartPointer<vtkPoints>::New();

        double x,y,z;

        double min=0.0, max=0.0;

        auto transform =  vtkSmartPointer<vtkTransform>::New();
        transform->PostMultiply();

        double p0[3] = { minBox, minBox, minBox-trans };
        double p1[3] = { minBox, maxBox, minBox-trans };
        double p2[3] = { maxBox, maxBox, minBox-trans };
        double p3[3] = { maxBox, minBox, minBox-trans };

        double p4[3] = { minBox, minBox, 0.0};
        double p5[3] = { minBox, maxBox, 0.0};
        double p6[3] = { maxBox, maxBox, 0.0};
        double p7[3] = { maxBox, minBox, 0.0};

        transform->Translate(0.0,0.0,(maxBox+trans)/2.0);

        renderLine(p0,p1,color,lineWidth,transform,id_mol,id_mo);
        renderLine(p1,p2,color,lineWidth,transform,id_mol,id_mo);
        renderLine(p2,p3,color,lineWidth,transform,id_mol,id_mo);
        renderLine(p0,p3,color,lineWidth,transform,id_mol,id_mo);

        renderLine(p4,p5,color,lineWidth,transform,id_mol,id_mo);
        renderLine(p5,p6,color,lineWidth,transform,id_mol,id_mo);
        renderLine(p6,p7,color,lineWidth,transform,id_mol,id_mo);
        renderLine(p4,p7,color,lineWidth,transform,id_mol,id_mo);

        renderLine(p0,p4,color,lineWidth,transform,id_mol,id_mo);
        renderLine(p1,p5,color,lineWidth,transform,id_mol,id_mo);
        renderLine(p2,p6,color,lineWidth,transform,id_mol,id_mo);
        renderLine(p3,p7,color,lineWidth,transform,id_mol,id_mo);

        //ProjOrbitaType {proj_XOY=1, proj_XOZ=2, proj_YOZ=3};
        if (mo->projType==1)
        {
            //#pragma omp parallel omp for
            if (mo->dataXOY.size()>0)
            for (int i = 0 ; i < countX; i++)
            {
                x = x0 + stepX*i;
                for (int j = 0; j < countY; j++)  {
                    y =  y0 + stepY*j;
                    z = mo->dataXOY[i][j];
                    points->InsertNextPoint(x, y, z);
                }
            }
        }

        if (mo->projType==3)
        {
            //dataYOZ[Ny][Nz]
            //#pragma omp parallel
            //#pragma omp for
            if (mo->dataYOZ.size()>0)
            for(int j=0; j < countY;  j++)
            {
                y = y0 + stepY*j;
                for(int k=0; k < countZ;  k++) {
                    z =  z0 + stepZ*k;
                    x = mo->dataYOZ[j][k];
                    points->InsertNextPoint(y, z, x);
                }
            }
        }

        if (mo->projType==2)
        {
            //#pragma omp parallel
            //#pragma omp for
            if (mo->dataXOZ.size()>0)
            for (int i = 0 ; i < countX; i++)
            {
                x = x0 + stepX*i;
                for (int k = 0; k < countZ; k++)  {
                    z =  z0 + stepZ*k;
                    y = mo->dataXOZ[i][k];
                    points->InsertNextPoint(x, z, y);
                }
            }
        }


        // Add the grid points to a polydata object
        auto inputPolyData =  vtkSmartPointer<vtkPolyData>::New();
        inputPolyData->SetPoints(points);


        // Triangulate the grid points
        auto delaunay =  vtkSmartPointer<vtkDelaunay2D>::New();
        delaunay->SetInputData(inputPolyData);
        delaunay->Update();


        //auto smoothFilter = vtkSmartPointer<vtkSmoothPolyDataFilter>::New();
        //smoothFilter->SetInputData(delaunay->GetOutput());
        //smoothFilter->SetNumberOfIterations(10);
        //smoothFilter->Update();


        auto outputPolyData = delaunay->GetOutput();

        double bounds[6];
        outputPolyData->GetBounds(bounds);

        min = bounds[4];
        max = bounds[5];

        //std::cout << "minz: " << minz << std::endl;
        //std::cout << "maxz: " << maxz << std::endl;

        auto scalars = vtkSmartPointer<vtkFloatArray>::New();
#pragma omp parallel for
        for(int i = 0; i < outputPolyData->GetNumberOfPoints(); i++)
        {
            double * p = outputPolyData->GetPoint(i);

            p[2]=p[2]*maxBox*0.9/max;  //correspond to red
            outputPolyData->GetPoints()->SetPoint(i,p);
            scalars->InsertTuple1(i, p[2]/maxBox);
        }

        outputPolyData->GetPointData()->SetScalars(scalars);

        auto actor = vtkActor::New();


        actor->setMolId(id_mol);
        actor->setMOId(id_mo);


        auto mapper = vtkPolyDataMapper::New();
        mapper->SetLookupTable(pColorTable);
        mapper->SetInputData(outputPolyData);
        mapper->SetScalarRange(scalarRange);
        mapper->ScalarVisibilityOn();


        actor->SetUserTransform(transform);
        actor->SetMapper(mapper);
        //actor->GetProperty()->SetOpacity(0.2);
        m_renderer->AddActor(actor);
        mapper->Delete();

        auto slicePolyData = vtkSmartPointer<vtkPolyData>::New();
        slicePolyData->DeepCopy(outputPolyData);

        #pragma omp parallel for
        for (int i=0;i<slicePolyData->GetNumberOfPoints();i++)
        {
            double * p = slicePolyData->GetPoint(i);
            p[2]=-trans+minBox;

            slicePolyData->GetPoints()->SetPoint(i,p);
        }
        slicePolyData->GetPointData()->SetScalars(scalars);

        auto actor1 = vtkActor::New();

        actor1->setMolId(id_mol);
        actor1->setMOId(id_mo);

        auto mapper1 = vtkPolyDataMapper::New();
        mapper1->SetLookupTable(pColorTable);
        mapper1->SetInputData(slicePolyData);
        mapper1->SetScalarRange(scalarRange);
        mapper1->ScalarVisibilityOn();

        actor1->SetUserTransform(transform);
        actor1->SetMapper(mapper1);
        //actor1->GetProperty()->SetOpacity(0.8);
        m_renderer->AddActor(actor1);
        mapper1->Delete();
    }

    appendMessage("Done!");
    GetRenderWindow()->Render();
}

void Mesh3D::removeOrbital(HMol * mol)
{
    uint id_mol=mol->getIdx();

    vtkActorCollection* actorCollection = m_renderer->GetActors();
    int numActors = actorCollection->GetNumberOfItems();
    actorCollection->InitTraversal();


    for (int i=0;i<numActors;++i)
    {
        vtkActor * actor = actorCollection->GetNextActor();
        if ( actor->MolId() != id_mol) continue;

        m_renderer->RemoveActor(actor);
    }
}





void Mesh3D::removeOrbital(HMol * mol,uint id_mo)
{
    uint id_mol=mol->getIdx();

    cout <<"remove orbital inside Mesh3D ... ...!"<<endl;

    vtkActorCollection* actorCollection = m_renderer->GetActors();
    int numActors = actorCollection->GetNumberOfItems();
    actorCollection->InitTraversal();


    for (int i=0;i<numActors;++i)
    {
        vtkActor * actor = actorCollection->GetNextActor();

        if ( actor->MolId() != id_mol) continue;
        if ( actor->MOId() != id_mo) continue;
        m_renderer->RemoveActor(actor);
    }

    cout <<"remove orbital inside Mesh3D done!"<<endl;
}



void Mesh3D::removeActors(HMol * mol)
{
   id_mol=mol->getIdx();

   vtkActorCollection* actorCollection = m_renderer->GetActors();
   int numActors = actorCollection->GetNumberOfItems();
   actorCollection->InitTraversal();

   for (int i=0;i<numActors;++i)
   {
       vtkActor * actor = actorCollection->GetNextActor();
       if ( actor->MolId() != id_mol) continue;
       m_renderer->RemoveActor(actor);
   }
}


void Mesh3D::removeAllActors()
{
    vtkActorCollection* actorCollection = m_renderer->GetActors();
    int numActors = actorCollection->GetNumberOfItems();
    actorCollection->InitTraversal();

    for (int i=0;i<numActors;++i)
    {
        vtkActor * actor = actorCollection->GetNextActor();
        m_renderer->RemoveActor(actor);
    }
}


void Mesh3D::removeLastActor()
{
  vtkActor * actor = m_renderer->GetActors()->GetLastActor();
  if (actor != nullptr) m_renderer->RemoveActor(actor);
}







void Mesh3D::zoomToExtent()
{
  // Zoom to extent of last added actor
  vtkSmartPointer<vtkActor> actor = m_renderer->GetActors()->GetLastActor();
  if (actor == nullptr) return;

  m_renderer->ResetCamera(actor->GetBounds());
}




void Mesh3D:: onViewXY()
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

void Mesh3D:: onViewXZ()
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

void Mesh3D:: onViewYZ()
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


void Mesh3D:: onViewReset()
{
    camera->SetViewUp(0,1,0);
    camera->SetPosition(0,0,30);
    camera->SetFocalPoint(0,0,0);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void Mesh3D:: onView_rotateClockwise(double degree)
{
    double angle= camera->GetRoll();
    camera->SetRoll(angle-degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();

}

void Mesh3D:: onView_rotateCounterClockwise(double degree)
{
    double angle= camera->GetRoll();
    camera->SetRoll(angle+degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void Mesh3D:: onView_rotateUp(double degree)
{
    //camera->Pitch(-5);
    camera->Elevation(-degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}
void Mesh3D:: onView_rotateDown(double degree)
{
    //camera->Pitch(5);
    camera->Elevation(degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void Mesh3D:: onView_rotateLeft(double degree)
{
    camera->Azimuth(degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

void Mesh3D:: onView_rotateRight(double degree)
{
    camera->Azimuth(-degree);
    camera->ComputeViewPlaneNormal();
    GetRenderWindow()->Render();
}

