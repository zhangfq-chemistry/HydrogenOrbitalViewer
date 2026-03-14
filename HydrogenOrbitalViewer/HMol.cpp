#include "HMol.h"

double const CovalentRadii[119] = {0.0,   0.7181,   0.6047,   2.5322,
   1.7008,   1.5496,   1.4551,   1.4173,   1.3795,   1.3417,   1.3039,   2.9102,
   2.4566,   2.2299,   2.0976,   2.0031,   1.9275,   1.8708,   1.8330,   3.7039,
   3.2881,   2.7212,   2.5700,   2.3622,   2.4000,   2.6267,   2.3622,   2.3811,
   2.2866,   2.6078,   2.4755,   2.3811,   2.3055,   2.2488,   2.1921,   2.1543,
   2.0787,   3.9873,   3.6283,   3.0614,   2.7968,   2.5889,   2.7401,   2.9480,
   2.3811,   2.5511,   2.4755,   2.8913,   2.7968,   2.7212,   2.6645,   2.6078,
   2.5511,   2.5133,   2.4566,   4.2519,   3.7417,   3.1936,   3.4355,   3.4469,
   3.4280,   3.4658,   3.4091,   3.4091,   3.4091,   3.3505,   3.3656,   3.3297,
   3.3278,   3.3240,   3.3259,   3.0236,   2.8346,   2.6078,   2.7590,   3.0047,
   2.4188,   2.5889,   2.4188,   2.7212,   2.8157,   2.7968,   2.7779,   2.7590,
   2.8300,   2.9200,   2.7401,   5.4400,   4.7500,   3.7500,   3.3826,   3.0803,
   2.9480,   2.9291,   3.0047,   3.2692,   3.2881,   3.2125,   3.5149,   3.5149,
   3.2400,   3.1900,   3.1700,   3.2100,   3.2000,   3.2000,   3.2000,   3.2000,
   3.2000,   3.2000,   3.2000,   3.2000,   3.2000,   3.2000,   3.2000,   3.2000,
   3.2000,   3.2000,   3.2000
};

uint32_t ElementColors[110] = {0xdd00cc,
     0xFFFFFF,   0xD9FFFF,   0xCC80FF,  0xC2FF00,	 0xFFB5B5,
     0x909090,   0x3050F8,   0xFF0D0D,  0x90E050,    0xB3E3F5,
     0xAB5CF2,   0x8AFF00,   0xBFA6A6,   0xF0C8A0,   0xFF8000,
     0xFFFF30,	 0x1FF01F,	 0x80D1E3,	 0x8F40D4,	 0x3DFF00,
     0xE6E6E6,	 0xBFC2C7,	 0xA6A6AB,	 0x8A99C7,	 0x9C7AC7,
     0xE06633,	 0xF090A0,	 0x50D050,	 0xC88033,	 0x7D80B0,
     0xC28F8F,	 0x668F8F,	 0xBD80E3,	 0xFFA100,	 0xA62929,
     0x5CB8D1,	 0x702EB0,	 0x00FF00,	 0x94FFFF,	 0x94E0E0,
     0x73C2C9,	 0x54B5B5,	 0x3B9E9E,	 0x248F8F,	 0x0A7D8C,
     0x006985,	 0xC0C0C0,	 0xFFD98F,	 0xA67573,	 0x668080,
     0x9E63B5,	 0xD47A00,	 0x940094,	 0x429EB0,	 0x57178F,
     0x00C900,	 0x70D4FF,	 0xFFFFC7,	 0xD9FFC7,	 0xC7FFC7,
     0xA3FFC7,	 0x8FFFC7,	 0x61FFC7,	 0x45FFC7,	 0x30FFC7,
     0x1FFFC7,	 0x00FF9C,	 0x00E675,	 0x00D452,	 0x00BF38,
     0x00AB24,	 0x4DC2FF,	 0x4DA6FF,	 0x2194D6,	 0x267DAB,
     0x266696,	 0x175487,	 0xD0D0E0,	 0xFFD123,	 0xB8B8D0,
     0xA6544D,	 0x575961,	 0x9E4FB5,	 0xAB5C00,	 0x754F45,
     0x428296,	 0x420066,	 0x007D00,	 0x70ABFA,	 0x00BAFF,
     0x00A1FF,	 0x008FFF,	 0x0080FF,	 0x006BFF,	 0x545CF2,
     0x785CE3,	 0x8A4FE3,	 0xA136D4,	 0xB31FD4,	 0xB31FBA,
     0xB30DA6,	 0xBD0D87,	 0xC70066,	 0xCC0059,	 0xD1004F,
     0xD90045,	 0xE00038,   0xE6002E,	 0xEB0026
};

string ElementNames[119] = {"X", "H", "He", "Li", "Be", "B", "C", "N",
   "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
   "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As",
   "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd",
   "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr",
   "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf",
   "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At",
   "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf",
   "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg",
   "Cn", "Uut", "Uuq", "Uup", "Uuh", "Uus", "Uuo"
};




uint Symbol2Z(QString symbol)
{
    int Z=1;

    if (symbol=="H")  Z=1;
    if (symbol=="Be") Z=4;
    if (symbol=="B")  Z=5;
    if (symbol=="C")  Z=6;
    if (symbol=="N")  Z=7;
    if (symbol=="O")  Z=8;
    if (symbol=="F")  Z=9;

    if (symbol=="Si")  Z=14;
    if (symbol=="P")   Z=15;
    if (symbol=="S")   Z=16;
    if (symbol=="Cl")  Z=17;

    if (symbol=="Ti")  Z=22;
    if (symbol=="V")   Z=23;
    if (symbol=="Cr")  Z=24;
    if (symbol=="Mn")  Z=25;
    if (symbol=="Fe")  Z=26;
    if (symbol=="Co")  Z=27;
    if (symbol=="Ni")  Z=28;
    if (symbol=="Cu")  Z=29;
    if (symbol=="Zn")  Z=30;
    if (symbol=="Ga")  Z=31;
    if (symbol=="Ge")  Z=32;
    if (symbol=="As")  Z=33;
    if (symbol=="Se")  Z=34;
    if (symbol=="Br")  Z=35;

    if (symbol=="Zr")  Z=40;
    if (symbol=="Nb")  Z=41;
    if (symbol=="Mo")  Z=42;

    if (symbol=="Ru")  Z=44;
    if (symbol=="Rh")  Z=45;
    if (symbol=="Pd")  Z=46;
    if (symbol=="Ag")  Z=47;
    if (symbol=="Cd")  Z=48;
    if (symbol=="In")  Z=49;
    if (symbol=="Sn")  Z=50;
    if (symbol=="Sb")  Z=51;
    if (symbol=="Te")  Z=52;
    if (symbol=="I")   Z=53;

    if (symbol=="Ta")  Z=73;
    if (symbol=="W")   Z=74;
    if (symbol=="Re")  Z=75;
    if (symbol=="Os")  Z=76;
    if (symbol=="Ir")  Z=77;
    if (symbol=="Pt")  Z=78;
    if (symbol=="Au")  Z=79;
    if (symbol=="Hg")  Z=80;

    return Z;
}


void HAtom::setColorRadius()
{
    Z=Symbol2Z(symbol);
    color=ElementColors[Z];
}

double HAtom::getRadius()
{
    radius=CovalentRadii[Z];
    return radius;
}




void HMol::clearAll()
{
    clearBonds();
    clearAtoms();
    clearObtials();
}


void HMol::clearBonds()
{
    uint size=bonds.size();
    if (size<0) return;

    while (size--) {
        delete bonds[size];
    }

    bonds.clear();
}




void HMol::clearAtoms()
{
    uint size=atoms.size();
    if (size<0) return;

    while (size--) {
        delete atoms[size];
    }

    atoms.clear();
    return;
}





void HMol::clearObtials()
{
    uint size=HMOs.size();

    if (size <1) return;


    while (size--){
        if (HMOs[size]!=nullptr)
            HMOs[size]->clear();
    }

    HMOs.clear();
}






void HMol::removeOrbital(uint idx)
{
    cout <<"Remove the "<<idx << " orbital "<< endl;
    if (idx >= HMOs.size()) return;
    HMOs[idx]->clear();

    uint id=0;
    cout << HMOs.size()<<endl;
    for(vector<HMO *>::iterator iter=HMOs.begin(); iter!=HMOs.end(); iter++)
    {
        if( id == idx)   {HMOs.erase(iter);break;}
        id++;
    }
    cout << HMOs.size()<<endl;
}




void HMol:: addHybridOrbs(QString AtomSymbol, vector3  pos,  QString ObName)
{
    cout << "Adding hybridized orbital paramters ..."<<endl;

    double sqrt2=1.0/sqrt(2.0);
    double sqrt3=1.0/sqrt(3.0);
    double sqrt6=1.0/sqrt(6.0);
    double sqrt12=1.0/sqrt(12.0);
    double half=0.5;

     uint Z = Symbol2Z(AtomSymbol);

    if (ObName=="SP")
    {
        //the first one
        addNewAO("2S",AtomSymbol,pos,sqrt2,false);
        uint idx=HMOs.size()-1;
        insertAO2MO("2Px", AtomSymbol,  pos,  sqrt2,idx,false);
        HMOs[idx]->SetOrbitaName("SP-1");
        HMOs[idx]->setHybridizedOrbitalTrue();


        //the second one
        idx=idx+1;
        addNewAO("2S",AtomSymbol,pos,sqrt2,false);
        insertAO2MO("2Px", AtomSymbol,  pos, -sqrt2,idx,false);
        HMOs[idx]->SetOrbitaName("SP-2");
        HMOs[idx]->setHybridizedOrbitalTrue();
        cout << "Done!"<<endl;
        return;
    }


    //   trigonal
    //   sp2_1=s/sqrt3 - 2.0*px/sqrt6;
    //   sp2_2=s/sqrt3 + px/sqrt6 + py/sqrt2;
    //   sp2_3=s/sqrt3 + px/sqrt6 - py/sqrt2;

    if (ObName=="SP2")
    {
        //first
        addNewAO("2S",AtomSymbol, pos,sqrt3,false);
        uint idx=HMOs.size()-1;
        insertAO2MO("2Px", AtomSymbol,  pos,   -2.0*sqrt6,idx,false);
        HMOs[idx]->SetOrbitaName("SP2-1");
        HMOs[idx]->setHybridizedOrbitalTrue();


        //second
        idx=idx+1;
        addNewAO("2S",AtomSymbol, pos,sqrt3,false);
        insertAO2MO("2Px", AtomSymbol,  pos, sqrt6,idx,false);
        insertAO2MO("2Py", AtomSymbol,  pos, -sqrt2,idx,false);
        HMOs[idx]->SetOrbitaName("SP2-2");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //third
        idx=idx+1;
        addNewAO("2S",AtomSymbol, pos, sqrt3,false);
        insertAO2MO("2Px", AtomSymbol,  pos, sqrt6,idx,false);
        insertAO2MO("2Py", AtomSymbol,  pos, sqrt2,idx,false);
        HMOs[idx]->SetOrbitaName("SP2-3");
        HMOs[idx]->setHybridizedOrbitalTrue();


        cout << "Done!"<<endl;
        return;
    }

    //tetrahedral
    //sp3_1=(s + px + py + pz )/2.0;
    //sp3_2=(s + px - py - pz )/2.0;
    //sp3_3=(s - px - py + pz )/2.0;
    //sp3_4=(s - px + py - pz )/2.0;
    if (ObName=="SP3")
    {
        //first
        addNewAO("2S",AtomSymbol, pos, 0.5,false);
        uint idx=HMOs.size()-1;
        insertAO2MO("2Px", AtomSymbol,  pos,   0.5,idx,false);
        insertAO2MO("2Py", AtomSymbol,  pos,   0.5,idx,false);
        insertAO2MO("2Pz", AtomSymbol,  pos,   0.5,idx,false);
        HMOs[idx]->SetOrbitaName("SP3-1");
        HMOs[idx]->setHybridizedOrbitalTrue();


        //second
        idx=idx+1;
        addNewAO("2S",AtomSymbol, pos, 0.5,false);
        insertAO2MO("2Px", AtomSymbol,  pos,   0.5,idx,false);
        insertAO2MO("2Py", AtomSymbol,  pos,  -0.5,idx,false);
        insertAO2MO("2Pz", AtomSymbol,  pos,  -0.5,idx,false);
        HMOs[idx]->SetOrbitaName("SP3-2");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //third
        idx=idx+1;
        addNewAO("2S",AtomSymbol, pos, 0.5,false);
        insertAO2MO("2Px", AtomSymbol,  pos,   -0.5,idx,false);
        insertAO2MO("2Py", AtomSymbol,  pos,   -0.5,idx,false);
        insertAO2MO("2Pz", AtomSymbol,  pos,    0.5,idx,false);
        HMOs[idx]->SetOrbitaName("SP3-3");
        HMOs[idx]->setHybridizedOrbitalTrue();


        //forth
        idx=idx+1;
        addNewAO("2S",AtomSymbol, pos, 0.5,false);
        insertAO2MO("2Px", AtomSymbol,  pos,  -0.5,idx,false);
        insertAO2MO("2Py", AtomSymbol,  pos,   0.5,idx,false);
        insertAO2MO("2Pz", AtomSymbol,  pos,  -0.5,idx,false);
        HMOs[idx]->SetOrbitaName("SP3-4");
        HMOs[idx]->setHybridizedOrbitalTrue();

        cout << "Done!"<<endl;
        return;
    }


    //dsp2,square
    //dsp2_1 = (s + px + dx2y2 )/2.0;
    //dsp2_2 = (s - px + dx2y2 )/2.0;
   // dsp2_2 = (s + py - dx2y2 )/2.0;
    //dsp2_4 = (s - py - dx2y2 )/2.0;
    if (ObName=="DSP2")
    {
        //(1)
        addNewAO("4S",AtomSymbol, pos, 0.5,false);
        uint idx=HMOs.size()-1;
        insertAO2MO("4Px", AtomSymbol,  pos,   0.5,idx,false);
        insertAO2MO("3Dx2-y2", AtomSymbol,  pos,  0.5,idx,false);
        HMOs[idx]->SetOrbitaName("DSP2-1");
        HMOs[idx]->setHybridizedOrbitalTrue();
        //(2)
        idx=idx+1;
        addNewAO("4S",AtomSymbol, pos, 0.5,false);
        insertAO2MO("4Px", AtomSymbol,  pos,   -0.5,idx,false);
        insertAO2MO("3Dx2-y2", AtomSymbol,  pos,   0.5,idx,false);
        HMOs[idx]->SetOrbitaName("DSP2-2");
        HMOs[idx]->setHybridizedOrbitalTrue();


        //(3)
        idx=idx+1;
        addNewAO("4S",AtomSymbol, pos, 0.5,false);
        insertAO2MO("4Py", AtomSymbol,  pos,   0.5,idx,false);
        insertAO2MO("3Dx2-y2", AtomSymbol,  pos,   -0.5,idx,false);
        HMOs[idx]->SetOrbitaName("DSP2-3");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //(4)
        idx=idx+1;
        addNewAO("4S",AtomSymbol, pos, 0.5,false);
        insertAO2MO("4Py", AtomSymbol,  pos,   -0.5,idx,false);
        insertAO2MO("3Dx2-y2", AtomSymbol,  pos,   -0.5,idx,false);
        HMOs[idx]->SetOrbitaName("DSP2-4");
        HMOs[idx]->setHybridizedOrbitalTrue();

        cout << "Done!"<<endl;
        return;
    }


    //dsp3, trigonal bipyridal
    //dsp3_1= s/sqrt3 + px/sqrt6 + py/sqrt2;
    //dsp3_2= s/sqrt3 + px/sqrt6 - py/sqrt2;
    //dsp3_3= s/sqrt3 - sqrt(2.0/3.0)*px;
    //dsp3_4= s/sqrt2 + pz/sqrt2;
    //dsp3_5= s/sqrt2 - pz/sqrt2;

    if (ObName=="DSP3")
    {
        //(1)
        addNewAO("3S",AtomSymbol, pos,sqrt3,false);
        uint idx=HMOs.size()-1;
        insertAO2MO("3Px", AtomSymbol,  pos, sqrt6,idx,false);
        insertAO2MO("3Py", AtomSymbol,  pos, sqrt2,idx,false);
        HMOs[idx]->SetOrbitaName("DSP3-1");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //(2)
        idx=idx+1;
        addNewAO("3S",AtomSymbol, pos,sqrt3,false);
        insertAO2MO("3Px", AtomSymbol,  pos, sqrt6,idx,false);
        insertAO2MO("3Py", AtomSymbol,  pos,  -sqrt2,idx,false);
        HMOs[idx]->SetOrbitaName("DSP3-2");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //(3)
        idx=idx+1;
        addNewAO("3S",AtomSymbol, pos,sqrt3,false);
        insertAO2MO("3Px", AtomSymbol,  pos,   sqrt2/sqrt3,idx,false);
        HMOs[idx]->SetOrbitaName("DSP3-3");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //(4)
        idx=idx+1;
        addNewAO("3S",AtomSymbol, pos,sqrt2,false);
        insertAO2MO("3Pz", AtomSymbol,  pos, sqrt2,idx,false);
        HMOs[idx]->SetOrbitaName("DSP3-4");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //(5)
        idx=idx+1;
        addNewAO("3S",AtomSymbol, pos,sqrt2,false);
        insertAO2MO("3Pz", AtomSymbol,  pos,  -sqrt2,idx,false);
        HMOs[idx]->SetOrbitaName("DSP3-5");
        HMOs[idx]->setHybridizedOrbitalTrue();

        cout << "Done!"<<endl;
        return;
    }

    //octahedral
    //d2sp3_1 = s/sqrt6 - py/sqrt2 - dz2/sqrt12 + dx2y2/2.0;
    //d2sp3_2 = s/sqrt6 + py/sqrt2 - dz2/sqrt12 + dx2y2/2.0;
    //d2sp3_3 = s/sqrt6 - px/sqrt2 - dz2/sqrt12 - dx2y2/2.0;
    //d2sp3_4 = s/sqrt6 + px/sqrt2 - dz2/sqrt12 - dx2y2/2.0;
    //d2sp3_5 = s/sqrt6 - pz/sqrt2 + dz2/sqrt3;
    //d2sp3_6 = s/sqrt6 + pz/sqrt2 + dz2/sqrt3;

    if (ObName=="D2SP3")
    {

        //(1)
        addNewAO("4S",AtomSymbol, pos, sqrt6,false);
        uint idx=HMOs.size()-1;
        insertAO2MO("4Py", AtomSymbol,  pos, -sqrt2,idx,false);
        insertAO2MO("3Dz2", AtomSymbol,  pos,  -sqrt12,idx,false);
        insertAO2MO("3Dx2-y2", AtomSymbol,  pos, 0.5,idx,false);
        HMOs[idx]->SetOrbitaName("D2SP3-1");
        HMOs[idx]->setHybridizedOrbitalTrue();


        //(2)
        idx=idx+1;
        addNewAO("4S",AtomSymbol, pos,sqrt6,false);
        insertAO2MO("4Py", AtomSymbol,  pos,      sqrt2,idx,false);
        insertAO2MO("3Dz2", AtomSymbol,  pos,    -sqrt12,idx,false);
        insertAO2MO("3Dx2-y2", AtomSymbol,  pos,   0.5,idx,false);
        HMOs[idx]->SetOrbitaName("D2SP3-2");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //(3)
        idx=idx+1;
        addNewAO("4S",AtomSymbol, pos, sqrt6,false);
        insertAO2MO("4Px", AtomSymbol,  pos,     -sqrt2,idx,false);
        insertAO2MO("3Dz2", AtomSymbol,  pos,   -sqrt12,idx,false);
        insertAO2MO("3Dx2-y2", AtomSymbol,  pos,  -0.5,idx,false);
        HMOs[idx]->SetOrbitaName("D2SP3-3");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //(4)
        idx=idx+1;
        addNewAO("4S",AtomSymbol, pos,3, 0, 0, sqrt6,false);
        insertAO2MO("4Px", AtomSymbol,  pos,       sqrt2,idx,false);
        insertAO2MO("3Dz2", AtomSymbol,  pos,     -sqrt12,idx,false);
        insertAO2MO("3Dx2-y2", AtomSymbol,  pos,   -0.5,idx,false);
        HMOs[idx]->SetOrbitaName("D2SP3-4");
        HMOs[idx]->setHybridizedOrbitalTrue();

        //(5)     d2sp3_5 = s/sqrt6 + pz/sqrt2 + dz2/sqrt3;
        idx=idx+1;
        addNewAO("4S",AtomSymbol, pos, sqrt6,false);
        insertAO2MO("4Pz", AtomSymbol,  pos,     sqrt2,idx,false);
        insertAO2MO("3Dz2", AtomSymbol,  pos,   sqrt3,idx,false);
        HMOs[idx]->SetOrbitaName("D2SP3-5");
        HMOs[idx]->setHybridizedOrbitalTrue();


        //(6)     d2sp3_6 = s/sqrt6 1 pz/sqrt2 + dz2/sqrt3;
        idx=idx+1;
        addNewAO("4S",AtomSymbol, pos, sqrt6,false);
        insertAO2MO("4Pz", AtomSymbol,  pos,     -sqrt2,idx,false);
        insertAO2MO("3Dz2", AtomSymbol,  pos,     sqrt3,idx,false);
        HMOs[idx]->SetOrbitaName("D2SP3-6");
        HMOs[idx]->setHybridizedOrbitalTrue();

        cout << "Done!"<<endl;
    }
}



// new MO and new AO
void HMol::addNewAO(QString AOName, QString AtomSymbol,vector3  pos,  double scale, bool isbuildNode)
{
    int n,l,m;
    Name2nlm ( AOName, n, l,  m);
    addNewAO(AOName,  AtomSymbol,  pos,  n,  l,  m,  scale,  isbuildNode);
}


void HMol::addNewAO(QString AOName, QString AtomSymbol,vector3  pos, int n, int l, int m, double scale, bool isbuildNode)
{
    int nn,ll,mm;
    Name2nlm ( AOName, nn, ll,  mm);
    if ( nn!=n || ll!=l || mm!=m )
    {
        cout << "Input Name: "<< AOName.toStdString().c_str()<<endl;
        cout << "compuated quantum number: " << nn << " "<< ll << " "<< mm<<endl;
        cout << " Input quantum number: " << n << " "<< l << " "<< m<<endl;
    }


    uint Z = Symbol2Z(AtomSymbol);
    HAO * ao= new HAO(Z,n,l,m); //prepare

    ao->SetAtomObitalName(AOName); //just provide a name
    ao->setPos(pos);
    ao->setScale(scale);

    if (isbuildNode)
        ao->buildNodes();

    HMO * mo = new  HMO();
    if (m_parent)
        mo->m_parent=m_parent;

    mo->OrbitalName=AOName;
    mo->visible =true;
    mo->idx=NOrbitals()-1;
    mo->addAO(ao);
    HMOs.push_back(mo);
}


void HMol::insertAO2MO(QString AOName, QString AtomSymbol,vector3  pos,  double scale,  uint idx, bool isbuildNode)
{
    int n,l,m;
    Name2nlm ( AOName, n, l,  m);
    insertAO2MO(AOName,  AtomSymbol,  pos,  n,  l,  m,  scale, idx,  isbuildNode);
}

void HMol::insertAO2MO(QString AOName, QString AtomSymbol,vector3  pos, int n, int l, int m, double scale, uint idx,bool isbuildNode)
{
    int nn,ll,mm;
    Name2nlm ( AOName, nn, ll,  mm);
    if ( nn!=n || ll!=l || mm!=m )
    {
        cout << "Input Name: "<< AOName.toStdString().c_str()<<endl;
        cout << "compuated quantum number: " << nn << " "<< ll << " "<< mm<<endl;
        cout << " Input quantum number: " << n << " "<< l << " "<< m<<endl;
        return;
    }


    int size=NOrbitals();
    //cout << "idx: "<< idx<< endl; cout << "number of MO: "<< size<< endl;

    if (idx>size-1) {
        cout << "Wrong! Only "<< size << " moleculear orbitals existed!"<<endl;
        return;
    }

    uint Z = Symbol2Z(AtomSymbol);
    HAO * ao= new HAO(Z,n,l,m); //prepare

    ao->SetAtomObitalName(AOName); //just provide a name
    ao->setPos(pos);
    ao->setScale(scale);

    if (isbuildNode)
        ao->buildNodes();

    HMOs[idx]->addAO(ao);
}


void HMol::addAtom(QString symbol, vector3 pos)
{
    HAtom * a = new HAtom(symbol,pos);
    atoms.push_back(a);
}


void HMol::Name2nlm (QString AOName, int & nn, int & ll, int & mm)
{
    QString ObitalName=AOName;

    // 1S,2S,3S,4S,5S,6S,7S
    // 2P,3P,4P,5P,6P,7P
    // 3D,4D, 5D,6D,7D
    // 4F,5F,6F,7F
    // 5G, 6G, 7G

    QChar first=AOName[0],
          second = AOName[1];

    nn=1;
    if (first.isDigit()) {
        nn=AOName[0].digitValue();
    }


    second.toUpper();
    if (second=="S" )         ll=0;
    else if (second=="P")     ll=1;
    else if (second=="D")     ll=2;
    else if (second=="F")     ll=3;
    else if (second=="G")     ll=4;
    else if (second=="H")     ll=5;
    else ll=0;

    QString name=AOName;
    name.remove(0,1);
    if (name.startsWith("Pz"))          mm=0;
    else if (name.startsWith("Px"))     mm=1;
    else if (name.startsWith("Py"))     mm=-1;


    else if (name.startsWith("Dz2"))     mm=0;
    else if (name.startsWith("Dxz"))     mm=1;
    else if (name.startsWith("Dyz"))     mm=-1;
    else if (name.startsWith("Dxy") )    mm=2;
    else if (name.startsWith("Dx2-y2"))  mm=-2;

    else if (name.startsWith("Fz3"))        mm=0;

    else if (name.startsWith("Fxz2"))       mm=1;
    else if (name.startsWith("Fyz2"))       mm=-1;

    else if (name.startsWith("Fz(x2-y2)"))  mm=2;
    else if (name.startsWith("Fzxy"))       mm=-2;

    else if (name.startsWith("Fx(x2-3y2)")) mm=3;
    else if (name.startsWith("Fy(3x2-y2"))  mm=-3;

    //waiting for check
    else if (name.startsWith("Gz4"))        mm=0;
    else if (name.startsWith("Gz3x"))       mm=1;
    else if (name.startsWith("Gz3y"))       mm=-1;

    else if (name.startsWith("Gz2xy"))      mm=2;
    else if (name.startsWith("Gz2(x2-y2)")) mm=-2;

    else if (name.startsWith("Gzx3"))       mm=3;
    else if (name.startsWith("Gzy3"))       mm=-3;

    else if (name.startsWith("Gxy(x2-y2)")) mm=4;
    else if (name.startsWith("G(x4+y4)"))   mm=-4;
    else mm=0;
}


void HMol::centeralize()
{
    vector3 center(0.0,0.0,0.0),a;

   // cout << "intital center: " << center.X()<< " "<< center.Y()<< " "<< center.Z()<< " "<<endl;

    for (uint i=0;i<atoms.size();i++)
        center=center+atoms[i]->Pos();
        //center=center+Atoms[i]->Pos()*Atoms[i]->Mass();
    center=center/atoms.size();

   // cout << "calculated center: " << center.X()<< " "<< center.Y()<< " "<< center.Z()<< " "<<endl;


    for (uint i=0;i<atoms.size();i++){
        a=atoms[i]->Pos();
        atoms[i]->setPos(a-center);
    }
}



void HMol::getCoordinates()
{
    if (NAtoms()<1)
        return;

    coord.clear();
    char ss[256];

    for (uint i=0;i<atoms.size();i++)  {

         std::sprintf (ss,"%s %10.6f  %10.6f  %10.6f\n",(atoms[i]->symbol.toStdString()).c_str(),
                       atoms[i]->x(),atoms[i]->y(),atoms[i]->z());
         coord+=ss;
    }
}



void HMol::rotate( vector3  v, double angle )
{
    double  ele[3][3];

    double ang = angle*3.14159265359/180.0;

    double c = cos(ang), t=1-c,  s = sin(ang);


    vector3 vec = v;
    v.normalize();

    double   x = vec[0],
             y = vec[1],
             z = vec[2];

      ele[0][0] = x*x*t+c ;
      ele[0][1] = x*y*t-z*s;
      ele[0][2] = x*z*t+y*s;

      ele[1][0] = x*y*t+z*s;
      ele[1][1] = y*y*t+c;
      ele[1][2] = y*z*t-x*s;

      ele[2][0] = x*z*t-y*s;
      ele[2][1] = y*z*t+x*s;
      ele[2][2] = z*z*t+c;

     vector3  a,b;
      for (uint i=0;i<atoms.size();i++)
      {
          a=atoms[i]->Pos();

          b.SetX(  a.x()*ele[0][0] + a.y()*ele[0][1] + a.z()*ele[0][2] );
          b.SetY(  a.x()*ele[1][0] + a.y()*ele[1][1] + a.z()*ele[1][2] );
          b.SetZ(  a.x()*ele[2][0] + a.y()*ele[2][1] + a.z()*ele[2][2]);

          atoms[i]->setPos(b);
      }
}


void  HMol::translate(vector3 p)
{

    for (uint i=0;i<atoms.size();i++){
        atoms[i]->setPos(atoms[i]->Pos()+p);
    }
}




void HMol::buildOrbitalRadialNodes(uint idx)
{

     HMO * mo=HMOs[idx];

     int numAOs=mo->NumAOs();

     if (numAOs==1)
     for (uint j =0; j<numAOs;j++)
          mo->getAO(j)->buildRadialNodes();
}


void HMol::buildOrbitalAngularNodes(uint idx)
{
    HMO * mo=HMOs[idx];
    int numAOs=mo->NumAOs();


     if (numAOs==1)
     for (uint j =0; j<numAOs;j++)
          mo->getAO(j)->buildYlmNodes();
}

void HMol::buildOrbitalRadialNodes()
{
   HMO * mo=nullptr;

   for (uint i =0; i<NOrbitals();i++)
   {
     mo=getObtial(i);
     int numAOs=mo->NumAOs();
     for (uint j =0; j<numAOs;j++)
          mo->getAO(j)->buildRadialNodes();
   }
}


void HMol::buildOrbitalAngularNodes()
{
   HMO * mo=nullptr;

   for (uint i =0; i<NOrbitals();i++)
   {
       mo=getObtial(i);

       int numAOs=mo->NumAOs();
       if (numAOs==1)
           for (uint j =0; j<numAOs;j++)
               mo->getAO(j)->buildYlmNodes();
   }

}

void HMol::buildHybridizedMO(uint idx)
{
    uint id=NOrbitals()-1;
    if (idx > id){
        cout << "wrong inside HMol::buildMO"<<endl;
        return;
    }

    HMOs[idx]->buildMOIsosurface();

}

void HMol::buildMOProjectionData(uint idx)
{
    uint id=NOrbitals()-1;
    if (idx > id){
        cout << "wrong inside HMol::buildMO"<<endl;
        return;
    }

   HMOs[idx]->build_MOProjectionData();
}


void HMol::buildMO (uint idx)
{
    uint id=NOrbitals()-1;
    if (idx > id){
        cout << "wrong inside HMol::buildMO"<<endl;
        return;
    }

    //normalize MO coefficient
    uint NAOs=HMOs[idx]->NumAOs();
    if  (NAOs==1) {
        HMOs[idx]->getAO(0)->scale=1.0;
    }
    else {
        double sum2=0.0;
        for (uint i=0;i<NAOs;i++)
        {
            double c=HMOs[idx]->getAO(i)->scale;
            sum2=sum2+c*c;
        }
        for (uint i=0;i<NAOs;i++)
        {
            double c=HMOs[idx]->getAO(i)->scale;
            HMOs[idx]->getAO(i)->scale=c/sum2;
        }
    }


     HMOs[idx]->buildIsosurface();

    if (HMOs[idx]->isAtomicOrbital )  {
        buildOrbitalRadialNodes(idx);
        buildOrbitalAngularNodes(idx);
        HMOs[idx]->calc_RadialThreeKindsData();
        HMOs[idx]->build_AOProjectionData();
    }
    //else  HMOs[idx]->build_MOProjectionData();
}

void HMol::buildLatestMO ()
{
    if (NOrbitals()<1)
    {
        cout << "wrong inside HMol::buildMO"<<endl;
        return;
    }
    uint idx=NOrbitals()-1;
    buildMO (idx);
}

void HMol:: buildMOsAfter (uint index)
{
   uint size=NOrbitals();
   while (size--){
       if (size==index) break;
       buildMO(size);
   }
}



void HMol::buildBonds()
{
    cout << "Building bonds based on "<<NAtoms() << " atoms "<<endl;
    uint natoms=NAtoms();

    if (natoms<=1) return;

    vector3 p1,p2;
    double r,dist;

    for(uint i=0; i < natoms;i++)
    {
        for(uint j=i+1; j < natoms;j++)
        {
            dist=(atoms[i]->Pos()-atoms[j]->Pos()).length();

            if (dist<0.5){
                cout << "The distance between " <<i+1 << "  and "<< j+1 << ": "<< dist << " is too short!"<<endl;
                continue;
            }

            r=1.1*(atoms[j]->getRadius()+atoms[i]->getRadius())*0.529177;


            if (dist > r ) continue;

            //cout << "radius: "<< atoms[i]->getRadius() << " "<<atoms[j]->getRadius()<<endl;
            //cout << "dist "<< dist << " "<< i+1 << " "<< j+1<<endl;


            HBond * bond = new HBond();
            bond->atomId0=i;
            bond->atomId1=j;


            double r1=atoms[i]->getRadius();
            double r2=atoms[j]->getRadius();

            bond->setScale(sqrt(r1/r2)/2.0);

            //cout << "scale is "<<sqrt(r1/r2)/2.0<<endl;
            bonds.push_back(bond);
        }
    }

    cout << "find "<<bonds.size() << " bonds"<<endl;
    cout << "Building bonds done!"<<endl<<endl;
}


