#ifndef HMOL_H
#define HMOL_H


#include "HAtomOrb.h"

using namespace std;


class HAtom
{
public:
    HAtom() {
              symbol="H";
              Z=0;
              pos0=VZero;
              color=0xFFFFFF;
    };


    HAtom(QString sym, vector3 p)
    {
        symbol=sym;
        pos0=p;

        setColorRadius();
    }


   ~HAtom() {};

   void setPos(vector3 pos) {pos0=pos; }
   vector3 Pos (){return pos0;}
   void setSymbol ( QString s) {symbol=s;};

   void setColorRadius () ;


   double x(){return pos0.x();}
   double y(){return pos0.y();}
   double z(){return pos0.z();}
   uint32_t Color () {return color;}

   int getZ() ;
   double getRadius();


public:
    QString symbol;
    int Z;
    double coeff,radius;
    vector3 pos0;
    uint32_t color;
};


//display
class HBond
{
public:
     uint   atomId0, atomId1;
     double radius,scale;
     vector3 begin, end;

public:
      explicit HBond() {scale=1.0;};
     ~HBond(){}

     double getScale(){
         return scale;
     }
     void setScale(double _s) {
         scale=_s;
     }

     uint atomIndex0()
     {
         return  atomId0;
     }

     uint atomIndex1()
     {
         return  atomId1;
     }

     void setIndex(uint id1,uint id2)
     {
         atomId0=id1;
         atomId1=id2;
     }

     void setBegin(vector3 & b )
     {
         begin=b;
     }
     void setEnd(vector3 & e )
     {
         end=e;
     }
};




//molecule class
class HMol
{
public:
    MainWindow * m_parent;

    HMol() {
        atoms.clear();
        bonds.clear();
        HMOs.clear(); //orbitals
        atomsVisible=true;
        allInVisible=false;
        idx=0;
        AtomLabel="";
    };
   ~HMol() {};

    void addAtom(QString symbol="H", vector3 pos=VZero);
    //void addAtom(QString symbol, vector3  pos, int n, int l, int m, double scale, QString name);
    //void addAtom(QString symbol, vector3  pos, int n, int l, int m);

    int NAtoms() {return atoms.size();}
    int NBonds() {return bonds.size();}
    int NOrbitals() {if (HMOs.empty()) return 0;  return HMOs.size();}


    void Name2nlm(QString ,int & ,int & ,int &);

    void addNewAO(QString AOName, QString AtomSymbol,vector3  pos,  double scale, bool isbuildNode);
    void addNewAO(QString AOName, QString AtomSymbol,vector3  pos, int n, int l, int m, double scale, bool isbuildNode);

    void insertAO2MO(QString AOName, QString AtomSymbol,vector3  pos, int n, int l, int m,double scale, uint idx, bool isbuildNode);
    void insertAO2MO(QString AOName, QString AtomSymbol,vector3  pos, double scale, uint idx, bool isbuildNode);

    void addHybridOrbs(QString AtomSymbol, vector3  pos,  QString ObName);


    void buildMO (uint );
    void buildHybridizedMO(uint );
    void buildMOProjectionData(uint );


    void buildLatestMO (); //build the last one
    void buildMOsAfter (uint ); //build the new addeds ones

    void getCoordinates();

    void clearBonds();
    void clearAtoms();


    void clearObtials();
    void removeAll()
    {
        clearBonds();
        clearAtoms();
        clearObtials();
    }

    void clearAll();





    void centeralize();
    void rotate( vector3  , double  );
    void translate(vector3);


    void buildOrbitalRadialNodes();
    void buildOrbitalAngularNodes();

    void buildOrbitalRadialNodes(uint);
    void buildOrbitalAngularNodes(uint);

    void removeOrbital (uint);



    int  getLastMOId(){
        uint size =HMOs.size();
        if (size<1) return -1;
        return (size-1);
    }

    HMO * getObtial(int id){
        if (id> HMOs.size()-1)
            return nullptr;
        return HMOs[id];
    }

    HMO * getLastObital() {
        if (HMOs.size() < 0)
            return nullptr;
         return HMOs[HMOs.size()-1];
    }

    void set_MO_Visible (uint id, bool v)
    {
        //if (id> HMOs.size()-1)   return;
        HMOs[id]->setVisible(v);
    }

    bool is_MO_Visible (uint id) {
        if (id> HMOs.size()-1)   return false;
        return HMOs[id]->isVisible();
    }

    HAtom * getAtom(int id){
        if (id> atoms.size()-1)
            return nullptr;
        return atoms[id];
    }

    HBond * getBond(int id){
        if (id> bonds.size()-1)
            return nullptr;
        return bonds[id];
    }


    bool isAllInVisible() {return allInVisible;}
    void setAllInVisible(bool t) {allInVisible=t;}


    vector <HAtom *> atoms;
    vector <HBond *> bonds;
    vector < HMO *> HMOs;



    void setAtomLabel(QString l){
        AtomLabel=l;
    }
    QString getAtomLabel(){
        return AtomLabel;
    }

    string coord;
    uint getIdx () {return idx;}
    void setIdx (uint id){idx=id;}
    void setAtomsVisible(bool v){atomsVisible=v; }
    bool isAtomVisible() {return atomsVisible;}

    void buildBonds();

private:
    uint idx;
    bool atomsVisible,allInVisible;
     QString AtomLabel;
};


#endif // HMOL_H
