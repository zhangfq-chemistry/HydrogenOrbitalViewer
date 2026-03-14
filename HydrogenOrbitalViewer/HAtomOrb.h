#ifndef ATOMORBITAL_H
#define ATOMORBITAL_H

#include <cmath>
#include <iostream>
#include <fstream>
#include  <cstdlib>
#include <math.h>
#include <vector>
#include <string>
#include <QString>
#include "matrix3/vector3.h"
#include <QTreeWidget>
#include <QVector>
#include <QString>

#include <vtkSmartPointer.h>
#include <vtkMarchingCubes.h>
#include <vtkVoxelModeller.h>
#include <vtkSphereSource.h>
#include <vtkImageData.h>
#include <vtkDICOMImageReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkDoubleArray.h>
#include <vtkMarchingSquares.h>
#include <vtkFlyingEdges3D.h>
#include <vtkClipPolyData.h>
#include <vtkPlane.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTriangleFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkSliceCubes.h>
#include <vtkFloatArray.h>
#include <vtkVertexGlyphFilter.h>


class MainWindow;

#ifndef PI
  #define PI  3.14159265358979323846264338327950
#endif

#define Deg   0.0174532925199
#define Me    9.109389427e-31                      /* mass of electron, kg */
#define Mz    1.6726230e-27                         /* mass of proton, kg */
#define Mn    1.6749286e-27                         /* mass of neutron, kg */
#define Ma    1.6605402e-27                        /* atomic unit mass, kg */
//#define ao    0.529177249e-10              // radius of first Bohr orbit
//#define nFac  2*PI*a0*a0*a0
#define sqare(x)     ((x)*(x))


using namespace std;



class HAO
{
public:
    QString ObitalName;
    //MainWindow * m_parent;

    //quantum numbers: n, l, m,  Z=num protons
    int n, l, m, Z;
    int  lml; // = |m|

    vector3 pos;  //position
    double radius;
    double a0,  sqrt2, scale;

    QVector <double>  Nodes_R,Nodes_gR;
    QVector <double>  Nodes_T,Nodes_P;

    double Psi,Psi2;
    bool isXOYNode;
    bool hasNodesBuild;

public:
    HAO(){
        n=1;
        l=m=0;
        Z=1;
        scale=1.0;

        a0=1.0; //a0=0.529177;
        sqrt2=1.41421356237309504876;
        isXOYNode=false;
        ObitalName="none";
        hasNodesBuild=false;
    };

    HAO(int _Z, int _n, int _l, int _m)
    {
        n=_n;
        l=_l;
        m=_m; lml=abs(m);
        Z=_Z;

        scale=1.0;
        a0=1.0; //a0=0.529177;
        sqrt2=1.41421356237309504876;


        //check
        if (n<1)   n = 1;
        if (l > n || l<0)  l = 0;

        if (abs(m)>l)   m = 0;
        if (Z<1)        Z = 1;
        isXOYNode=false;
        hasNodesBuild=false;

        nlm2Name();
    }

    uint get_l() {return l;}
    uint get_m() {return m;}
    uint get_n() {return n;}


    void setPos(vector3 pos){ this->pos = pos;}
    vector3 Pos() {return pos;}

    void setScale(double s) {scale=s;}

    double x() {return pos[0];}
    double y() {return pos[1];}
    double z() {return pos[2];}
    uint getZ(){return Z;}

    //void setAngles(vector3 & angles)  { angles0 = angles; }
    void SetAtomObitalName (QString & name) {ObitalName=name;};
    void setQuantumNumber (int _n=1, int _l=0, int _m=0) { n=_n; l=_l; m=_m;  }


    void  Name2nlm(QString );  // orbital name to n/l/m
    void  nlm2Name ();         // n/l/m to orbital name
    QString getName () {return ObitalName;}



    //surface with psi=0
    void   buildNodes();
    void   buildRadialNodes();
    void   buildYlmNodes();

    double Coulomb_Sturmian_Psi (vector3);
    double Slater_Psi (vector3);
    double Hydrogen_Psi (vector3);

    double Hydrogen_Psi (double r, double theta, double phi);

    void   SphericalHarmonicY ();
    double SphericalHarmonicY (double phi, double theta);
    double SphericalHarmonicY (vector3 );
    double SphericalHarmonicY_byName(vector3 , QString );
    double SphericalHarmonicY_byName(vector3);

    double SphericalHarmonicY_byName(double theta, double phi, QString AOName);
    double SphericalHarmonicY_byName(double theta, double phi);

    double Hydrogen_R (double x, double y, double z);
    double Hydrogen_RDF (double );
    double Hydrogen_R   (double);


    double CoulombSturmian_RDF(double );
    double CoulombSturmian_R(double);
    double CoulombSturmian_R(double x, double y, double z);
    double CoulombSturmianR_byName(vector3 , QString );



    double HydrogenR_byName(vector3 , QString );
    double HydrogenPsi_byName(vector3 , QString);
    double HydrogenPsi_byName(vector3 );
    double calc_least_r(double eps=0.0001);
    double calc_least_rdf();
};






//(1) HAOs include their coefficient themselves
//(2) the simplest MO includes only one AO
enum OrbitaType {FULL, XOY, XOZ, YOZ, Wedge, Quarter,Corner};
enum ExtIsoSurfAlgorithms {MarchingCube, FlyingEdge, MarchingTetrahedra, DualContouring,DiscretekdHierachy};

class HMO
{
public:
     MainWindow * m_parent;
     QString  OrbitalName;
     double   Psi, Psi2;
	 double MaxPsi=0.;
     enum     ProjOrbitaType {proj_NONE=0, proj_XOY=1, proj_XOZ=2, proj_YOZ=3};

     //run over all the AOs included
     double  calc_Psi  (vector3 );
     double  calc_Psi  (double x, double y, double z);


     void    calc_SphericalHarmonicY_SP (); //only calcuate s and p orbital
     void    calc_SphericalHarmonicY();
     void    calc_Ylm_phi(double theta, double phi, double phi1, double interval);
     void    calc_Ylm_theta(double phi, double theta, double theta1, double interval);
     void    calc_Ylm(double theta, double theta1, double interval_t,
                                  double phi,  double phi1, double interval_p);



     void calc_RadialThreeKindsData ();

     void build_AOProjectionData ();

     void setProjType(uint );
     void build_MOProjectionData();

     void buildCloudPoints(long int NP=10000);
     void buildYlmSurface();
     void buildYlmSurface_g(); //general case
     void buildYlmSurface_wedge(); //general case


     void ExtractIsosurface(vtkImageData * , vtkImageData *);
     void buildIsosurface();   // only for atomic orbital
     void buildMOIsosurface(); // for molecular orbital/hybridized orbital

     void buildWedgeIsosurface();
     void buildWedgeIsosurface1();


     //only angular parts: s, p, d, f etc.
     void buildSurfaceAngular_positive();
     void buildSurfaceAngular_negtive();
     void append_surfaceYlm_pos(double , double, double  );
     void append_surfaceYlm_neg(double , double , double  );
     void collect_All_Ylm();


     void buildCubeData();

     void addAO(HAO * ao) { AOs.push_back(ao); }

     HAO * getAO(int idx) {
         if (idx >= NumAOs())
             return nullptr;
          return AOs[idx];
     }

     HAO * getAO(QString obName) {
         if (idx >= NumAOs())
             return nullptr;
         for (int i=0;i<NumAOs();i++)
             if (AOs[i]->ObitalName==obName)
                 return AOs[i];
         return nullptr;
     }

     int NumAOs(){return AOs.size();};

     void clear();



     void    setBox(double _min, double _max)    { minBox=_min; maxBox=_max;}
     void    getBox(double & _min, double &_max) {_min=minBox; _max=maxBox;}
     void    setInterval (double _v) {interval=_v;}
     void    setNumPoints (int N) {NPoints=N;}

     double  MinBox () {return minBox;}
     double  MaxBox () {return maxBox;}
     int     NumPoints () {return NPoints;}
     double  Interval () {return interval; }

     void    setIsoValue (double v ) {isoValue =v;}
     double  IsoValue(){return isoValue;}

     void   SetOrbitaType(uint _t)
     {
         switch (_t){
         case 0: orbital_type=FULL;break;
         case 1: orbital_type=XOY;break;
         case 2: orbital_type=XOZ;break;
         case 3: orbital_type=YOZ;break;
         case 4: orbital_type=Wedge;break;
         case 5: orbital_type=Quarter;break;
         case 6: orbital_type=Corner;break;
         }
     }

     void  SetOrbitaType(OrbitaType te){
         orbital_type=te;
     }

     void setActiveMolObitalMesh(bool t){
         visible_pos_Lobe_Mesh=t;
         visible_neg_Lobe_Mesh=t;
     }
     bool isPosLobeMesh(){
         return visible_pos_Lobe_Mesh;
     }
     bool isNegLobeMesh(){
         return visible_neg_Lobe_Mesh;
     }

     void  SetOrbitaName(QString m){
         OrbitalName=m;
     }

     void setOpicity (float o){opacity=o;}
     float getOpicity (){ return opacity;}

     vector3 getPosLobeColor () {return color_pos;}
     vector3 getNegLobeColor () {return color_neg;}

     void setPosLobeColor (vector3 v) {color_pos=v;}
     void setNegLobeColor (vector3 v) {color_neg=v;}


public:
     explicit HMO()
     {
         NPoints=200;
         minBox=-20.0;
         maxBox=20.0;
         isoValue=0.001;

         CubeData=nullptr;
         CubeDataXOY=nullptr;
         CubeDataXOZ=nullptr;
         CubeDataYOZ=nullptr;
         CubeDataWedge=nullptr;
         CubeDataQuarter=nullptr;
         CubeDataCorner=nullptr;

         CubeDataQuarter1=nullptr;
         CubeDataQuarter2=nullptr;


         visible=true;

         visible_pos_Lobe_Mesh=true;
         visible_neg_Lobe_Mesh=true;

         visible_pos_Lobe=true;
         visible_neg_Lobe=true;

         visible_radial_node=false;
         visible_angular_node=false;

         orbital_type=OrbitaType::FULL;
         projType=proj_XOY;
         extractIsoSurfMethod = ExtIsoSurfAlgorithms::MarchingCube;

         isHybridizedOrbital=false;
         isMolecularOrbital=false;
         isAtomicOrbital=true;

         color_pos.Set(0.3,0.6,0.3);
         color_neg.Set(0.6,0.3,0.6);

         surfaceAngular_positive.clear();
         surfaceAngular_negative.clear();

         opacity=1.0;
         Ylm_neg_existed=false;
         Ylm_pos_existed=false;

         isCubeDataOK=false;
         isSphericalHarmonicYOK=false;

         lengthYlm=1.6;
         heigthYlm=1.6;



         cloudPoints_pos.clear();
         cloudPoints_neg.clear();



     };

     double lengthYlm,heigthYlm;
     double getLengthYlm(){return 2.0*lengthYlm;}
     double getHeightYlm(){return heigthYlm;}

     ~HMO(){};
     uint idx;

    vtkSmartPointer <vtkMarchingCubes> surfaceMC0,surfaceMC1,Surface_MC_Zero;
    vtkSmartPointer <vtkFlyingEdges3D> surfaceFE0,surfaceFE1,Surface_FE_Zero;

    vtkSmartPointer <vtkPolyData>  surfaceYlm_pos,surfaceYlm_neg;
    vtkPolyData * pData,  * pData1; //Psi
    vtkPolyData * yData,  * yData1; //Ylm

    vtkPolyData  * ylmData,  * ylmData1; //Ylm

    vtkSmartPointer <vtkVertexGlyphFilter> glyphFilter_pos,glyphFilter_neg;

    bool Ylm_neg_existed, Ylm_pos_existed;


    vector<vector<double> > dataXOY,dataYOZ,dataXOZ;
    vector <vector3> cloudPoints_pos,cloudPoints_neg;

    ProjOrbitaType projType;

    bool isNegYlmExisted() {return Ylm_neg_existed;}
    bool isPosYlmExisted() {return Ylm_pos_existed;}

    bool isPosLobeVisible() {return visible_pos_Lobe;}
    bool isNegLobeVisible() {return visible_neg_Lobe;}

    bool isPosLobeInvisible() {if (visible_pos_Lobe) return false; return true;}
    bool isNegLobeInvisible() {if (visible_neg_Lobe) return false; return true;}


    void setPosLobeVisible(bool t) {visible_pos_Lobe=t;}
    void setNegLobeVisible(bool t) {visible_neg_Lobe=t;}


    void setVisible_radial_node(bool t) {visible_radial_node=t;}
    void setVisible_angular_node(bool t) {visible_angular_node=t;}
    bool isVisible_radial_node(){return visible_radial_node;}
    bool isVisible_angular_node(){return visible_angular_node;}

    void setVisible (bool t){visible=t;}
    bool isVisible() {return visible;}

    uint get_projScale(){return proj_scale;}

    void sendMessage(QString  );
    void appendMessage(QString  );


    void setHybridizedOrbitalTrue()
    {
        isHybridizedOrbital=true;
        isMolecularOrbital=false;
        isAtomicOrbital=false;
    }

    void setMolecularOrbitalTrue()
    {
        isMolecularOrbital=true;
        isHybridizedOrbital=false;
        isAtomicOrbital=false;
    }

    void setAtomicOrbitalTrue()
    {
        isMolecularOrbital=false;
        isHybridizedOrbital=false;
        isAtomicOrbital=true;
        isCoulombSturmianOrbital=false;
    }




private:
    uint proj_scale;
    OrbitaType orbital_type;

    ExtIsoSurfAlgorithms extractIsoSurfMethod;

     vector <HAO *> AOs;
     int    NPoints;
     double minBox,maxBox;
     double interval;
     double isoValue;

     //cutting Psi
     bool isCubeDataOK;
     double * CubeData;
     double * CubeDataXOY;
     double * CubeDataXOZ;
     double * CubeDataYOZ;
     double * CubeDataWedge;
     double * CubeDataQuarter, * CubeDataQuarter1, * CubeDataQuarter2;
     double * CubeDataCorner;

     //cutting Ylm
     bool isSphericalHarmonicYOK;

     vector3 color_pos,color_neg;
     float opacity;



public:
     bool visible_pos_Lobe_Mesh;
     bool visible_neg_Lobe_Mesh;

     bool visible_pos_Lobe;
     bool visible_neg_Lobe;

     bool visible;



     QList<QPointF> RData, R2Data,RDFData;

     std::vector <vector3> surfaceAngular_positive,surfaceAngular_negative;
     std::vector <vector <vector3> > pos_Ylm, neg_Ylm;


     bool visible_radial_node;
     bool visible_angular_node;
     bool isHybridizedOrbital,isMolecularOrbital,isAtomicOrbital;
     bool isCoulombSturmianOrbital;
};



#endif // ATOMORBITAL_H
