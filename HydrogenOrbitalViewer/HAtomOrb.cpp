#include "HAtomOrb.h"
#include <QString>
#include <QMessageBox>
#include <vtkSmartVolumeMapper.h>
#include <vtkColorTransferFunction.h>
#include <vtkVolumeProperty.h>
#include <vtkAppendPolyData.h>
#include <vtkCleanPolyData.h>
#include <vtkDelaunay2D.h>
#include <vtkVoronoi2D.h>
#include <vtkSurfaceReconstructionFilter.h>
#include <vtkContourFilter.h>
#include <vtkMergePoints.h>
#include <vtkQuantizePolyDataPoints.h>
#include <vtkReverseSense.h>
#include <vtkClipClosedSurface.h>
#include <vtkPlaneCollection.h>
#include <vtkVertexGlyphFilter.h>
#include <algorithm>
#include <random>
#include "mainwindow.h"
#include "SolveEquation.h"
#include <ctime>


double ElementMasses[27] = {0, 1.00794, 4.002602, 6.941,
   9.012182, 10.811, 12.0107, 14.0067, 15.9994, 18.9984032, 20.1797,
   22.98976928, 24.3050, 26.9815386, 28.0855, 30.973762, 32.065, 35.453, 39.948,
   39.0983, 40.078, 44.955912, 47.867, 50.9415, 51.9961, 54.938045, 55.845
};


double m_random(uint type) {
 /*   std::random_device rd;
    std::mt19937 mt(rd());
    if(type<1) {
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        return distribution(mt);
    }
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);
    return distribution(mt);*/
	
}

/*
 * #include <math.h>
 * #include <stdlib.h>
 *
  const double pi = 3.141592653589793;

  static double laguerrel(const double n, const double k, const double x)
  {
      int i;
      double L0, L1 = 0.0;
      double LaguerreL = 1.0;
      for (i = 0; i < n; i++)
      {
             L0 = L1;
             L1 = LaguerreL;
             LaguerreL = ((2 * i + 1 + k - x) * L1 - (i + k) * L0) / (i + 1);
      }
      return LaguerreL;
  }

   static double Rnl(const int n, const int l, const double r)
   {
      // radial wave function
      int i;
      double rho, a;
      rho = 2.0 * r / n;
      a = 4.0;
      for (i = n - l; i <= n + l; i++)
      {
         a /= i;
      }
      a = sqrt(a);
      a /= n * n;

      return a * exp(-0.5 * rho) * pow(rho, l) * laguerrel(n-l-1, 2*l+1, rho);

    }


    static double legendrepn(const int l, int m, const double x)
    {
      // renormalized associated legendre polynomials
      // = polar angle part of spherical harmonics
      int i, j;
      double fac, fac1, pn, a, b, c;
      m = abs(m);
      a = 1.0;

      if (m > 0)
      {
         fac = 1.0;
         c = (1.0 + x) * (1.0 - x);
         for (i = 1; i <= m; i++)
         {
           a *= c * fac / (fac + 1.0);
           fac += 2.0;
         }
      }
     a = sqrt((2 * m + 1) * a / (4.0 * pi));

     if (m & 1)
        a = -a;

     if (l == m)
        return a;
     else
     {
         b = a * x * sqrt(2.0 * m + 3.0);
         if (l == m + 1)   return b;
         else  {
           fac1 = sqrt(2.0 * m + 3.0);
           for (j = m + 2; j <= l; j++)
           {
              fac = sqrt((4.0 * j * j - 1.0) / (j * j - m * m));
              pn = fac * (b * x - a / fac1);
              fac1 = fac;
              a = b;
              b = pn;
           }
           return pn;
         }
       }
 }

// https://commons.wikimedia.org/wiki/User:Geek3/hydrogen#Code
void Psi(const int n, const int l, const int m, const double x, const double y, const double z,
        double *pabs, double *pphase)
{
        double r, rxy, p0;
        // absolute value of Psi without phi dependency
         r = sqrt(x * x + y * y + z * z);
         if (r == 0.0)
            *pabs = Rnl(n, l, r) * legendrepn(l, m, 0.0);
         else
            *pabs = Rnl(n, l, r) * legendrepn(l, m, z / r);
                         
        // phase of Psi
        p0 = (n + l + m + 1) * pi;
        if (*pabs < 0.0)
        {
          *pabs = -*pabs;
           p0 += pi;
        }

        if (m != 0)
        {
            rxy = sqrt(x * x + y * y);
            if (rxy != 0.0)
               p0 += m * atan2(y, x);
         }
         *pphase = fmod(p0, 2.0 * pi);
 }

 */

double Factorial(int n) {
    if (n==0) return 1.0;
    if(n == 1)     return 1.0;
    else    return n * Factorial(n - 1);
}

// Associated Laguerre polynomial with unity norm
double AssociatedLaguerre (int n, int lambda, double x) {
    int i;
    double l=0, l1, l2;
    double c, c2;

    // starting values
    l2 = 1.0/sqrt(Factorial(lambda));
    if (n == 0) return l2;
    c2 = sqrt(lambda+1);
    l1 = -(x-lambda-1)*l2/c2;
    if (n == 1)
        return l1;

    // recurrence
    for (i=2; i<=n; ++i) {
        c = sqrt(i*(lambda+i));
        l = -l1*(x-lambda-2*i+1)/c - l2*c2/c;
        l2 = l1;
        l1 = l;
        c2 = c;
    }
    return l;
}


// Associated Legendre polynomial with unity norm
double AssociatedLegendre (int l, int m, float x)
{
    double tmp;
    double p=0, p1, p2;
    double c, c2;
    int i;

    // compute starting values for recurrence
    tmp = 1.0;
    for (i=2; i<=2*m; i+=2)
        tmp *= (1-x*x)*(i+1.0)/i;

    p2 = sqrt(tmp/2);
    if (l == m)
        return p2;

    p1 = sqrt(2*m+3)*x*p2;
    if (l == m+1)
        return p1;

    // recurrence
    c2 = sqrt((4.0*m*m+8.0*m+3)/(2*m+1.0));
    for (i=m+2; i<=l; ++i) {
        c = sqrt((4.0*i*i-1.0)/(1.0*i*i-1.0*m*m));
        p = p1*x*c - p2*c/c2;
        p2 = p1;
        p1 = p;
        c2 = c;
    }
    return p;
}





int rnd(int a, int b) {
    return rand() % (b-a+1)+ a;
}


double sgnd(double x)
{
    if (x>0.0) return(1.0);
    if (x<0.0) return(-1.0);
    return(1.0);
}

double powl(double val, int p)
{
   if (p ==0) return 1.0;
   if (p < 0) return pow(val,p);

  double ret;
  if (!p)  return(val!=0);
  ret = 1.0;
  while (p) {
    if (p&1)  ret *= val;
    val *= val;  p >>= 1;
  }

  return ret;
}








// Wavefunction of the electron in a hydrogen atom
double HAO::Hydrogen_Psi (double r, double theta, double phi)
{
    if (r<0.001)
        r=0.001;

    double cos_theta=cos(theta);

    double alpha = 2.0*Z/n/a0;
    double p=alpha*r;

    // radial part
    double R=pow(p,l)*exp(-p/2.0)*AssociatedLaguerre(n-l-1,2*l+1,p);
    double factor=sqrt(alpha*alpha*alpha/2.0/n);
    R=R*factor;


    // angular parts
    double Y=1.0,Theta=1.0,Phi=1.0;

    if(l>4) { //h...
        Theta = AssociatedLegendre(l,abs(m),cos_theta);

        Phi=1.0/sqrt(2.0*3.141592654); //m=0

        if (m > 0)
            Phi=cos(m*phi)/sqrt(3.141592654); //m>0

        if (m < 0)
            Phi=sin(m*phi)/sqrt(3.141592654); //m<0

        Y=Theta*Phi;
    }
    else //s,p,d,f,g
        Y=SphericalHarmonicY_byName(theta,phi);


    return R*Y*scale;
}


double HAO::Hydrogen_Psi (vector3 pos1)
{
    double R, Theta, Phi;

    vector3 pos0 = pos1 - pos;

    double  x=pos0[0],
            y=pos0[1],
            z=pos0[2];

    double x2=x*x,y2=y*y,z2=z*z;
    double r = pos0.length();

    if (r<0.001)
        r=0.001;

    if (abs(x)<0.001)
        x=sgnd(x)*0.001;

    double phi = atan2(y, x);
    double theta = acos(z/r);
    double cos_theta=z/r;

    double alpha = 2.0*Z/n/a0;
    double p=alpha*r;

    // radial part
    R=pow(p,l)*exp(-p/2.0)*AssociatedLaguerre(n-l-1,2*l+1,p);
    double factor=sqrt(alpha*alpha*alpha/2.0/n);
    R=R*factor;



    // angular parts
    double Y=1.0;
    if(l>4) { //h...
        Theta = AssociatedLegendre(l,abs(m),cos_theta);

        Phi=1.0/sqrt(2.0*3.141592654); //m=0
        if (m > 0)
            Phi=cos(m*phi)/sqrt(3.141592654); //m>0

        if (m < 0)
            Phi=sin(m*phi)/sqrt(3.141592654); //m<0
        Y=Theta*Phi;
    }
    else //s,p,d,f,g
        Y=SphericalHarmonicY_byName(theta,phi);

    return R*Y*scale;
}


double HAO::Coulomb_Sturmian_Psi(vector3 pos1)
{
    double R, Theta, Phi;

    vector3 pos0 = pos1 - pos;

    double  x=pos0[0],
            y=pos0[1],
            z=pos0[2];

    double x2=x*x,y2=y*y,z2=z*z;
    double r = pos0.length();

    if (r<0.001)
        r=0.001;

    if (abs(x)<0.001)
        x=sgnd(x)*0.001;

    double phi = atan2(y, x);
    double theta = acos(z/r);
    double cos_theta=z/r;

    double alpha = 2.0*Z/n/a0;
    double p=alpha*r;

    // radial part,using Coulomb_Sturmian function
    double ksi=1.0*Z;
    R=pow(r,n-1)*exp(-ksi*r);
    double factor=powl(2*ksi,n)*sqrt(2*ksi/Factorial(2*n));
    R=R*factor;

    // angular parts
    double Y=1.0;
    if(l>4) { //h...
        Theta = AssociatedLegendre(l,abs(m),cos_theta);

        Phi=1.0/sqrt(2.0*3.141592654); //m=0
        if (m > 0)
            Phi=cos(m*phi)/sqrt(3.141592654); //m>0

        if (m < 0)
            Phi=sin(m*phi)/sqrt(3.141592654); //m<0
        Y=Theta*Phi;
    }
    else //s,p,d,f,g
        Y=SphericalHarmonicY_byName(theta,phi);

    return R*Y*scale;
}

double HAO::Slater_Psi (vector3 pos1)
{
    double R, Theta, Phi;

    vector3 pos0 = pos1 - pos;

    double  x=pos0[0],
            y=pos0[1],
            z=pos0[2];

    double x2=x*x,y2=y*y,z2=z*z;
    double r = pos0.length();

    if (r<0.001)
        r=0.001;

    if (abs(x)<0.001)
        x=sgnd(x)*0.001;

    double phi = atan2(y, x);
    double theta = acos(z/r);
    double cos_theta=z/r;

    double alpha = 2.0*Z/n/a0;
    double p=alpha*r;

    // radial part
    double ksi=1.0*Z;
    R=pow(r,n-1)*exp(-ksi*r);
    double factor=powl(2*ksi,n)*sqrt(2*ksi/Factorial(2*n));
    R=R*factor;


    // angular parts
    double Y=1.0;
    if(l>4) { //h...
        Theta = AssociatedLegendre(l,abs(m),cos_theta);

        Phi=1.0/sqrt(2.0*3.141592654); //m=0
        if (m > 0)
            Phi=cos(m*phi)/sqrt(3.141592654); //m>0

        if (m < 0)
            Phi=sin(m*phi)/sqrt(3.141592654); //m<0
        Y=Theta*Phi;
    }
    else //s,p,d,f,g
        Y=SphericalHarmonicY_byName(theta,phi);



    return R*Y*scale;
}




double HAO::CoulombSturmian_RDF(double r)
{
    double  RDF=1.0;
    return RDF;
}
double HAO::CoulombSturmian_R(double x, double y, double z)
{
    double  R=1.0;
    return R;
}
double HAO::CoulombSturmianR_byName(vector3 v, QString name)
{
    double  R=1.0;
    return R;
}



double HAO::Hydrogen_RDF (double r)
{
    double  R, RDF;

    if (r<0.000001)
        r=0.0000001;

    double alpha=2.0*Z/n/a0;
    double p=alpha*r;

    R = pow(p,l)*exp(-p/2.0)*AssociatedLaguerre(n-l-1,2*l+1,p);
    double factor=sqrt(alpha*alpha*alpha/2.0/n);
    R=R*factor;

    RDF=r*r*R*R;

    return RDF;
}


double HAO::Hydrogen_R(double x, double y, double z)
{
    double x2=x*x,y2=y*y,z2=z*z;
    double r = sqrt(x2+y2+z2);

    if (r<0.001)        r=0.001;

    double alpha=2.0*Z/n/a0;
    double p=alpha*r;

    // radial part
    double R=pow(p,l)*exp(-p/2.0)*AssociatedLaguerre(n-l-1,2*l+1,p);

    double factor=sqrt(alpha*alpha*alpha/2.0/n);
    R=R*factor;

    return R;
}



double HAO::Hydrogen_R (double r)
{
    if (r<0.001)
        r=0.001;

    double alpha=2.0*Z/n/a0;
    double p=alpha*r;

    // radial part
    double R=pow(p,l)*exp(-p/2.0)*AssociatedLaguerre(n-l-1,2*l+1,p);

    double factor=sqrt(alpha*alpha*alpha/2.0/n);
    R=R*factor;

    return R;
}


double HAO::SphericalHarmonicY (double phi, double theta)
{
    double cos_theta=cos(theta*3.141592654/180.0);

    double  Theta, Phi ,Y;
    Theta = AssociatedLegendre(l,abs(m),cos_theta);


    double sin_mphi=sin(m*phi*3.141592654/180.0);
    double cos_mphi=cos(m*phi*3.141592654/180.0);


    Phi=1.0/sqrt(2.0*3.141592654); //m=0
    if (m > 0)    Phi=cos_mphi/sqrt(3.141592654); //m>0,cos-type
    if (m < 0)    Phi=sin_mphi/sqrt(3.141592654); //m<0,sin-type

    Y=Theta*Phi;
    return Y;
}



double HAO::SphericalHarmonicY (vector3 pos1)
{
    vector3 pos0 = pos1 - pos;

    double  x=pos0[0],
            y=pos0[1],
            z=pos0[2];

    double x2=x*x,y2=y*y,z2=z*z;
    double r = sqrt(x*x+y*y+z*z);

    if (r<0.000001)
        r=0.0000001;

    if (abs(x)<0.000001)
        x=sgnd(x)*0.000001;

    double phi = atan2(y, x);
    double theta = acos(z/r);
    double cos_theta=z/r;

    double sin_mphi=sin(m*phi);
    double cos_mphi=cos(m*phi);

    double  Theta, Phi ,Y;
    Theta = AssociatedLegendre(l,abs(m),cos_theta);

    Phi=1.0/sqrt(2.0*3.141592654); //m=0
    if (m > 0)    Phi=cos_mphi/sqrt(3.141592654); //m>0
    if (m < 0)    Phi=sin_mphi/sqrt(3.141592654); //m<0

    Y=Theta*Phi;
    return Y;
}





void HAO::nlm2Name()
{
    QString name;

    if (l==0 )
        name="S";

    else if (l==1) //P
    {
           name="Pz";           //0
           if (m>0)  name="Px"; //1
           if (m<0)  name="Py"; //-1
    }

    else if (l==2){ //D

           name="Dz2"; //0

           if       (m==1)   name="Dxz";    //1
           else  if (m==-1)  name="Dyz";    //-1

           else  if (m==-2)   name="Dxy";   //-2
           else  if (m==2)    name="Dx2-y2"; //2
    }

    else if (l==3){ //F
         
           name="Fz3"; //0

           if       (m==1)   name="Fxz2"; //1
           else  if (m==-1)  name="Fyz2"; //-1

           else  if (m==2)   name="Fz(x2-y2)"; //2
           //else  if (m==-2)  name="Fzxy"; //-2
           else  if (m==-2)  name="Fxyz"; //-2

           else  if (m==3)   name="Fx(x2-3y2)"; //3
           else  if (m==-3)  name="Fy(3x2-y2)"; //-3
    }


    else if (l==4){ //G

        name="Gz4"; //0

        if       (m==1)   name="Gz3x"; //1
        else  if (m==-1)  name="Gz3y"; //-1

        else  if (m==2)   name="Gz2(x2-y2)"; //2
        else  if (m==-2)  name="Gz2xy"; //-2


        else  if (m==3)   name="Gzx3"; //3
        else  if (m==-3)  name="Gzy3"; //-3

        else  if (m==4)   name="Gxy(x2-y2)"; //3
        else  if (m==-4)  name="G(x4+y4)"; //-3
    }

    ObitalName.clear();
    ObitalName.setNum(n);
    ObitalName=ObitalName+name;
}




void HAO::Name2nlm(QString AOName)
{
    ObitalName=AOName;

    // 1S,2S,3S,4S,5S,6S,7S
    // 2P,3P,4P,5P,6P,7P
    // 3D,4D, 5D,6D,7D
    // 4F,5F,6F,7F
    // 5G, 6G, 7G

    QChar first=AOName[0],
          second = AOName[1];

    if (first.isDigit()) {
        n=AOName[0].digitValue();
    }


    second.toUpper();
    l=0;
    if (second=="S" )         l=0;
    else if (second=="P")     l=1;
    else if (second=="D")     l=2;
    else if (second=="F")     l=3;
    else if (second=="G")     l=4;
    else if (second=="H")     l=5;
    else if (second=="I")     l=6;
    else if (second=="J")     l=7;


    QString name=AOName;
    name.remove(0,1);

    //cos=positive, sin=negative
    m=0;
    if (name.startsWith("Pz"))          m=0;
    else if (name.startsWith("Px"))     m=1;
    else if (name.startsWith("Py"))     m=-1;


    else if (name.startsWith("Dz2"))     m=0;
    else if (name.startsWith("Dxz"))     m=1;
    else if (name.startsWith("Dyz"))     m=-1;
    else if (name.startsWith("Dx2-y2"))  m=2;
    else if (name.startsWith("Dxy") )    m=-2;

    else if (name.startsWith("Fz3"))        m=0;
    else if (name.startsWith("Fxz2"))       m=1;
    else if (name.startsWith("Fyz2"))       m=-1;
    else if (name.startsWith("Fz(x2-y2)"))  m=2;
    else if (name.startsWith("Fzxy"))       m=-2;
    else if (name.startsWith("Fxyz"))       m=-2;
    else if (name.startsWith("Fx(x2-3y2)")) m=3;
    else if (name.startsWith("Fy(3x2-y2"))  m=-3;



    //need check
    else if (name.startsWith("Gz4"))        m=0;
    else if (name.startsWith("Gz3x") || name.startsWith("Gxz3"))
        m=1;
    else if (name.startsWith("Gz3y") || name.startsWith("Gyz3") )
        m=-1;
    else if (name.startsWith("Gz2(x2-y2)") || name.startsWith("G(x2-y2)z2"))
        m=2;
    else if (name.startsWith("Gz2xy") || name.startsWith("Gxyz2"))
        m=-2;
    else if (name.startsWith("Gzx3")|| name.startsWith("Gx3z"))
        m=3;
    else if (name.startsWith("Gzy3") || name.startsWith("Gy3z"))
        m=-3;
    else if (name.startsWith("Gxy(x2-y2)"))
        m=-4;
    else if (name.startsWith("G(x4+y4)"))
        m=4;

}




double HAO::HydrogenPsi_byName(vector3 pos, QString AOName)
{
    double R = HydrogenR_byName(pos,AOName),
           Y = SphericalHarmonicY_byName(pos,AOName);

    return R*Y;
}

double  HAO::HydrogenPsi_byName(vector3 pos)
{
    if (ObitalName=="none")
        nlm2Name();

    return HydrogenPsi_byName(pos,ObitalName);
}



double HAO::HydrogenR_byName(vector3 pos1, QString AOName)
{
    vector3 pos0 = pos1 - pos;

    double  x=pos0.x(),
            y=pos0.y(),
            z=pos0.z();

    double r=sqrt(x*x+y*y+z*z);

    if (r<0.001) r=0.001;
    if (abs(x)<0.001)  x=sgnd(x)*0.001;

    double p=1.0,p2,p3,p4,p5, p6;

    double  Z3=Z*Z*Z;
    double  Zeff=Z/a0;

    double  x2=x*x;
    double  y2=y*y;
    double  z2=z*z;

    double  x4=x2*x2,
            y4=y2*y2,
            z4=z2*z2;

    double  r2=r*r;
    double  r3=r2*r;
    double  r4=r3*r;

    double  Zeff32 = pow(Zeff,1.5);

    double NS=1/sqrt(4*PI);
    double Ys = NS;

    /*
     // NR=sqrt (2^3*(n-l-1)! / (2*n * (n+l)!* (n+l)! * (n+l)! )
     R1s = 2 * Zeff32 * exp(-p/2);
     R2s = 1/(2*sqrt(2) ) * ( 2 - p ) * Zeff32 * exp(-p/2);
     R3s = 1/(9*sqrt(3) ) * ( 6 - 6*p + p2 ) * Zeff32 * exp(-p/2);
     R4s = 1/96 * ( 24 - 36*p + 12*p2 - p3 ) * Zeff32 * exp(-p/2);
     R5s = 1/(300*sqrt(5) )  * ( 120 - 240*p + 120*p2 - 20*p3 + p4 ) * Zeff32 * exp(-p/2);
     R6s = 1/(2160*sqrt(6) ) * ( 720 - 1800*p + 1200*p2 - 300*p3 + 30*p4 - p5 ) * Zeff32 * exp(-p/2);
     //R7s = 1                *(5040 - 15120*ρ + 12600*ρ2 - 4200*ρ3 + 630*ρ4 - 42*ρ5 + ρ6)  * Zeff32 * exp(-p/2);
 */
    double R=1.0;
    double alpha=1.0;



    if (AOName.startsWith("1S") )
    {
        n=1; l=0;
        p = 2.0 * Z * r/a0;
        R = 2.0 * Zeff32 * exp(-p/2.0);
        return R;
    }

    else if (AOName.startsWith("2S"))
    {
        n=2; l=0;

        alpha=2.0 * Z/(n*a0);
        p = alpha * r;

        R = 1.0/(2.0*sqrt(2.0) ) * ( 2.0 - p) * Zeff32 * exp(-p/2.0);
        return R;
    }


    else if (AOName.startsWith("3S"))
    {
        n=3; l=0;

        alpha=2.0 * Z/(n*a0);
        p = alpha * r;
        p2=p*p;

        R = 1/(9.0*sqrt(3.0) ) * ( 6.0 - 6.0*p + p2 ) * Zeff32 * exp(-p/2.0);
        return R;
    }

    else if (AOName.startsWith("4S"))
    {
        n=4; l=0;
        alpha=2.0 * Z/(n*a0);
        p = alpha * r;
        p2=p*p;p3=p2*p;
        R = 1/96. * ( 24. - 36.0*p + 12*p2 - p3 ) * Zeff32 * exp(-p/2);
        return R;
    }

    else if (AOName.startsWith("5S"))
    {
        n=5;l=0;
        p = 2.0 * Z * r / (n*a0);p2=p*p;p3=p2*p;p4=p2*p2;
        R = 1/(300.*sqrt(5.0) )  * ( 120. - 240.*p + 120.*p2 - 20.*p3 + p4 ) * Zeff32 * exp(-p/2.0);
        return R;
    }

    else if (AOName.startsWith("6S"))
    {

        n=6;l=0;
        p = 2.0 * Z * r / (n*a0);
        p2=p*p;
        p3=p2*p;
        p4=p2*p2;
        p5=p2*p3;
        R = 1/(2160.*sqrt(6.0) ) *
                ( 720. - 1800.*p + 1200.*p2 - 300.*p3 + 30.*p4 - p5 )
                * Zeff32 * exp(-p/2);
        return R;
    }

    //waiting for checking
    else if (AOName.startsWith("7S"))
    {
        n=7;l=0;
        p = 2.0 * Z * r / (n*a0);
        p2=p*p;
        p3=p2*p;
        p4=p2*p2;
        p5=p2*p3;
        p6=p3*p3;
        double k=1.0;
        R = k * (5040.0 - 15120.*p + 16200.*p2 - 4200.0*p3 + 630.*p4 + 42.*p5 + p6 )
                * Zeff32 * exp(-p/2);
        return R;
    }

    /*
    R2p  = 1/(2*sqrt(6)) * p * Zeff32 * exp(-p/2);
    R3p  = 1/(9*sqrt(6)) * p * ( 4 - p ) * Zeff32 * exp(-p/2);
    R4p  = 1/(32*sqrt(15)) * p* ( 20 - 10*p + p2 ) * Zeff32 * exp(-p/2);
    R5p  = 1/(150/sqrt(30)) * p *( 120 - 90*p + 18*p2 - p3 ) * Zeff32 * exp(-p/2);
    R6p  = 1/(432/sqrt(210)) * p * ( 840 - 840*p + 252*p2 - 28*p3 + p4 ) *  Zeff32 * exp(-p/2);
*/

    else if (AOName.startsWith("2P"))
    {
        n=2; l=1;
        p = 2.0 * Z * r / (n*a0);
        R  = 1/(2.*sqrt(6.0)) * p * Zeff32 * exp(-p/2);
        return R;
    }

    else if  (AOName.startsWith("3P"))
    {
        n=3;l=1;
        p = 2.0 * Z * r / (n*a0);
        R  = 1/(9.*sqrt(6)) * p * ( 4. - p ) * Zeff32 * exp(-p/2.0);
        return R;
    }

    else if  (AOName.startsWith("4P"))
    {
        n=4;l=1;
        p = 2.0 * Z * r / (n*a0);p2=p*p;
        R  = 1./(32.*sqrt(15.)) * p* ( 20. - 10.*p + p2 ) * Zeff32 * exp(-p/2.0);
        return R;
    }

    else if  (AOName.startsWith("5P"))
    {
        n=5;l=1;
        p = 2.0 * Z * r / (n*a0);p2=p*p;p3=p2*p;
        R  = 1./(150.*sqrt(30.)) * p *( 120. - 90.*p + 18.*p2 - p3 ) * Zeff32 * exp(-p/2.0);
        return R;
    }

    else if  (AOName.startsWith("6P"))
    {
        n=6;l=1;
        p = 2.0 * Z * r / (n*a0);p2=p*p;p3=p2*p;p4=p2*p2;
        R  = 1./(432.*sqrt(210.)) * p * ( 840. - 840.*p + 252.*p2 - 28.*p3 + p4 ) *  Zeff32 * exp(-p/2.);
        return R;
    }

    /*
    R3d = 1/(9*sqrt(30)) * p2 * Zeff32 * exp(-p/2);
    R4d = 1/(96*sqrt(5)) * p2 *( 6 - p ) * Zeff32 * exp(-p/2);
    R5d = 1/(150*sqrt(70) ) * p2 *( 42 - 14*p + p2 ) * Zeff32 * exp(-p/2);
    R6d = 1/(864*sqrt(105) ) * p2 *( 336 - 168*p + 24*p2 - p3 ) * Zeff32 * exp(-p/2);
    */

    else if  (AOName.startsWith("3D"))
    {
        n=3; l=2;
        p = 2.0 * Z * r / (n*a0);p2=p*p;
        R = 1./(9.0*sqrt(30)) * p2 * Zeff32 * exp(-p/2);
        return R;
    }

    else if (AOName.startsWith("4D"))
    {
        n=4;  l=2;
        p = 2.0 * Z * r / (n*a0);p2=p*p;
        R = 1.0/(96.*sqrt(5)) * p2 *( 6. - p ) * Zeff32 * exp(-p/2);
        return R;
    }

    else if (AOName.startsWith("5D"))
    {
        n=5; l=2;
        p = 2.0 * Z * r / (n*a0);
        p2=p*p;

        R = 1.0/(150.*sqrt(70.) ) * p2 *( 42.0 - 14.0*p + p2 ) * Zeff32 * exp(-p/2.0);
        return R;
    }


    else if (AOName.startsWith("6D"))
    {
        n=5; l=2;
        p = 2.0 * Z * r / (n*a0);
        p2=p*p;
        p3=p2*p;

        R = 1.0/(864.*sqrt(105.) ) * p2 *( 336. - 168.*p + 24.*p2 - p3 ) * Zeff32 * exp(-p/2.0);
        return R;
    }


    else if (AOName.startsWith("4F"))
    {
        n=4; l=3;
        p = 2.0 * Z * r / (n*a0);
        p2=p*p;
        p3=p2*p;

        R = 1/(96.*sqrt(35.)) * p3 * Zeff32 * exp(-p/2.0);
        return R;

    }

    else if  (AOName.startsWith("5F"))
    {
        n=5; l=3;
        p = 2.0 * Z * r / (n*a0);
        p3=p*p*p;

        R = 1.0/(300.*sqrt(70.)) * p3 * ( 8.0 - p ) * Zeff32* exp(-p/2.0);
        return R;
    }

    else if  (AOName.startsWith("6F"))
    {
        n=6;l=3;
        p = 2.0 * Z * r / (n*a0);

        p2=p*p;
        p3=p2*p;

        R = 1./(2592.*sqrt(35.)) * p3 * ( 72.0 - 18.0*p + p2 ) * Zeff32* exp(-p/2.0);
        return R;
    }


   //7F
   else if  (AOName.startsWith("7F")) {
        n=7;l=3;
        p = 2.0 * Z * r / (n*a0);p2=p*p;p3=p2*p;
        R = 1.0/300.0/sqrt(70.0) *(8.0-p)*p3*Zeff32*exp(-p/2.0);
        return R;
   }


    else if  (AOName.startsWith("5G"))
    {
        n=5; l=4;
        p = 2.0 * Z * r / (n*a0);
        p2=p*p;p4=p2*p2;

        R =  1.0/(900.*sqrt(70.0)) * p4 * Zeff32*exp(-p/2.0);
        return R;
    }

    else if  (AOName.startsWith("6G"))
    {
        n=6; l=4;
        p = 2.0 * Z * r / (n*a0);
        p2=p*p;
        p4=p2*p2;

        R =  1.0 /(12960.8*sqrt(7.0)) * p4 * (10.0-p) * Zeff32* exp(-p/2.0);
        return R;
    }

   //waiting?
   else if  (AOName.startsWith("7G"))
   {
        n=7; l=4;
        p = 2.0 * Z * r / (n*a0);
        p2=p*p;p4=p2*p2;

        R=1.0;
        return R;
   }




    else if  (AOName.startsWith("6H"))
    {
        n=6; l=5;
        p = 2.0 * Z * r / (n*a0);
        p2=p*p;
        p5=p2*p2*p;

        R =  1.0 /(12960.*sqrt(77.)) * p5 * Zeff32* exp(-p/2.0);
        return R;
    }

    else if  (AOName.startsWith("7H"))
    {
          n=6; l=5;
          p = 2.0 * Z * r / (n*a0);

          p2=p*p;
          p5=p2*p2*p;
          R =  1.0 ;

          return R;
     }
}



//https://reference.wolfram.com/language/ref/SphericalHarmonicY.html
double  HAO::SphericalHarmonicY_byName(double theta, double phi) //radian
{
   if (ObitalName=="none")
           nlm2Name();

   //cout << ObitalName.toStdString().c_str()<<endl;
   //cout << n <<" " << l <<" "<< m<<endl;
   //cout << theta <<" " << phi <<" "<<endl;

    QString AOName1=ObitalName;
    AOName1.remove(0,1);

    double sinT,cosT,sinP,cosP;

    if(abs(theta) <0.01 )
    {
        sinT=0.0;
        cosT=1.0;
    }
    else {
        sinT=sin(theta);
        cosT=cos(theta);
    }

    if(abs(phi) <0.01 )
    {
        sinP=0.0;
        cosP=1.0;
    }
    else
    {
       sinP=sin(phi);
       cosP=cos(phi);
    }



    double Y=1.0;
     if ( AOName1.startsWith ("S")  ) {
         Y=1.0/sqrt(4.0*PI);
         m=0;
         return Y;
     }

     else if ( AOName1.startsWith("P")  )
     {
         if  (AOName1.startsWith("Px"))  {
             Y = sqrt(3.0/PI/4.0) * sinT*cosP;
             m=1;
             return Y;
         }

         if  (AOName1.startsWith("Py"))  {
             Y= sqrt(3.0/PI/4.0) * sinT*sinP;
             m=-1;
             return Y;
         }

         if  (AOName1.startsWith("Pz"))  {
             Y = sqrt(3.0/PI/4.0) * cosT;
             m=0;
             return Y;
         }

     }

     else if ( AOName1.startsWith("D") )
     {

          if  (AOName1.startsWith("Dxz"))     {
              Y = sqrt(15.0/PI)/2.0 * sinT*cosT*cosP;
              m=1;
              return Y;
          }

          if  (AOName1.startsWith("Dyz"))     {
              Y = sqrt(15.0/PI)/2.0 * sinT*cosT*sinP;
              m=-1;
              return Y;
          }

          if  (AOName1.startsWith("Dx2-y2"))  {
              Y = sqrt(15.0/PI)/4.0 *sinT*cos(2.0*phi);
              m=2;
              return Y;
          }

          if  (AOName1.startsWith("Dxy"))     {
              Y = sqrt(15.0/PI)/2.0 *sinT*sin(2.0*phi);
              m=-2;
              return Y;
          }


          if  (AOName1.startsWith("Dz2"))     {
              Y = sqrt(5.0/PI)/4.0 * (3.0*cosT*cosT-1.0);
              m=0;
              return Y;
          }
     }



     else if ( AOName1.startsWith("F")  )
     {
         if  (AOName1.startsWith("Fx3"))
         {
             Y = sqrt(70.0/PI)/8.0 *sinT*sinT*sinT*cos(3*phi);
             m=0;
             return Y;
         }

         if  (AOName1.startsWith("Fy3"))
         {
             Y = sqrt(70.0/PI)/8.0 *sinT*sinT*sinT*sin(3*phi);
             m=0;
             return Y;
         }

         if  (AOName1.startsWith("Fz3"))
         {
             Y = sqrt(7.0/PI)/4.0 * (5.0*cosT*cosT*cosT-3*cosT) ;
             m=0;
             return Y;
         }

         if  (AOName1.startsWith("Fxz2"))    {
             Y =  sqrt(42./PI)/8.0 *sinT*(5*cosT*cosT-1.0)*cosP ;
             m=1;return Y;
         }

         if  (AOName1.startsWith("Fyz2"))    {
             Y =  sqrt(42./PI)/8.0 *sinT*(5*cosT*cosT-1.0)*sinP;
             m=-1;return Y;
         }


         if  (AOName1.startsWith("Fz(x2-y2)"))     {
             Y =   sqrt(105.0/PI)/4.0 *sinT*sinT*cosT*cos(2.0*phi) ;
             m=2;return Y;
         }


         if  (AOName1.startsWith("Fxyz") || AOName1.startsWith("Fzxy")) {
             Y =   sqrt(105.0/PI)/2.0 *sinT*sinT*cosT*sin(2.0*phi);
             m=-2;return Y;
         }


         //x(x2-3y2)
         if  (AOName1.startsWith("Fx(x2-3y2)"))    {
             Y = sqrt(70./PI)/8.0 *sinT*sinT*sinT*cos(3.0*phi);
             m=3;return Y;
         }

         //y(3x2-y2)
         if  (AOName1.startsWith("Fy(3x2-y2)"))    {
             Y = sqrt(70./PI)/8.0  *sinT*sinT*sinT*sin(3.0*phi);
             m=-3;return Y;
         }
    }


     //formular based on mathematica ShpericalHarmonicY[l,m,theta,phi]
     //name form https://chem.libretexts.org/Ancillary_Materials/Reference/Reference_Tables/Mathematical_Functions/M4%3A_Spherical_Harmonics
     else if ( AOName1.startsWith("G") )
     {
         double cosT2=cosT*cosT,
                cosT4=cosT2*cosT2;

         if  (AOName1.startsWith("Gz4")) {
             m=0;

             Y = 3.0/16.0/sqrt(PI)*(3.0-30.0*cosT2+35.0*cosT4);
             return Y;
         }

         if  (AOName1.startsWith("Gz3x") || AOName1.startsWith("Gxz3"))
         {
             Y = 3.0/8.0*sqrt(5.0/PI)*cosT*sinT*(7.0*cosT2-3.0)*cosP ;
             m=1;
             return Y;
         }

         if  (AOName1.startsWith("Gz3y") || AOName1.startsWith("Gyz3"))
         {
             Y = 3.0/8.0*sqrt(5.0/PI)*cosT*sinT*(7.0*cosT2-3.0)*sinP ;
             m=-1;
             return Y;
         }

         if  (AOName1.startsWith("Gz2(x2-y2)") || AOName1.startsWith("G(x2-y2)z2"))
         {
             Y = 3.0/8.0*sqrt(5.0/PI)*sinT*sinT*(-7.0*cosT2+1)*cos(2.0*phi) ;
             m=2;
             return Y;
         }

         if (AOName1.startsWith("Gz2xy") || AOName1.startsWith("Gxyz2"))
         {
             Y = 3.0/8.0*sqrt(5.0/PI)*sinT*sinT*(-7.0*cosT2+1)*sin(2.0*phi) ;
             m=-2;
             return Y;
         }

         if  (AOName1.startsWith("Gzx3") || AOName1.startsWith("Gx3z"))
         {
             Y = 3.0/8.0*sqrt(35.0/PI)*sinT*sinT*sinT*cosT*cos(3.0*phi) ;
             m=3;
             return Y;
         }

         if (AOName1.startsWith("Gzy3") || AOName1.startsWith("Gy3z"))
         {
             Y = 3.0/8.0*sqrt(35.0/PI)*sinT*sinT*sinT*cosT*sin(3.0*phi) ;
             m=-3;
             return Y;
         }


         if (AOName1.startsWith("Gx4+y4"))
         {
             Y = 3.0/16*sqrt(35.0/PI)*sinT*sinT*sinT*sinT*cos(4.0*phi) ;
             m=4;
             return Y;
         }

         if (AOName1.startsWith("Gxy(x2-y2)"))
         {
             Y = 3.0/16*sqrt(35.0/PI)*sinT*sinT*sinT*sinT*sin(4.0*phi) ;
             m=-4;
             return Y;
         }

     }

     /* based on mathematica, and no name is available in web
     else if ( AOName1.startsWith("H"))
     {
         if (AOName1.startsWith("H")) {
             m=0;
             Y=1.0/16*sqrt(11/PI)*(15.0*cosT-70.0*cosT*cosT*cosT + 63.0*cosT*cosT*cosT*cosT*cosT);
         }

         if (AOName1.startsWith("H")) {
            m=1;
            Y=1.0/16.0*sqrt(165/2.0/PI)*(1.0-14*cosT*cosT+21.0*cosT*cosT*cosT*cosT)*sinT*cosP;
         }

         if (AOName1.startsWith("H")) {
            m=-1;
            Y=1.0/16.0*sqrt(165/2.0/PI)*(1.0-14*cosT*cosT+21.0*cosT*cosT*cosT*cosT)*sinT*sinP;
         }

         if (AOName1.startsWith("H")) {
            m=2;
            Y=1.0/8.0*sqrt(1155.0/2.0/PI)*cosT*(-1.0+3.0*cosT*cosT)*sinT*sinT*cos(2.0*phi);
         }

         if (AOName1.startsWith("H")) {
            m=-2;
            Y=1.0/8.0*sqrt(1155.0/2.0/PI)*cosT*(-1.0+3.0*cosT*cosT)*sinT*sinT*sin(2.0*phi);
         }

         if (AOName1.startsWith("H")) {
            m=3;
            Y=1.0/32.0*sqrt(385.0/PI)*(-1.0+9.0*cosT*cosT)*sinT*sinT*sinT*cos(3.0*phi);
         }


        if (AOName1.startsWith("H")) {
            m=-3;
            Y=1.0/32.0*sqrt(385.0/PI)*(-1.0+9.0*cosT*cosT)*sinT*sinT*sinT*sin(3.0*phi);
        }

        if (AOName1.startsWith("H")) {
            m=4;
            Y=3.0/16.0*sqrt(385.0/2.0/PI)*cosT*sinT*sinT*sinT*sinT*cos(4.0*phi);
         }

        if (AOName1.startsWith("H")) {
            m=-4;
            Y=3.0/16.0*sqrt(385.0/2.0/PI)*cosT*sinT*sinT*sinT*sinT*sin(4.0*phi);
        }

        if (AOName1.startsWith("H")) {
            m=5;
            Y=3.0/32.0*sqrt(77.0/PI)*sinT*sinT*sinT*sinT*sinT*cos(5.0*phi);
        }

        if (AOName1.startsWith("H")) {
            m=-5;
            Y=-3.0/32.0*sqrt(77.0/PI)*sinT*sinT*sinT*sinT*sinT*sin(5.0*phi);
         }
     }
     */


}

double  HAO::SphericalHarmonicY_byName(vector3 pos1)
{

    QString AOName1=ObitalName;

    AOName1.remove(0,1);

    vector3 pos0 = pos1 - pos;
    double  x=pos0[0],
            y=pos0[1],
            z=pos0[2];

    double r=sqrt(x*x+y*y+z*z);
    if(r<0.001) r=0.001;


    double  x2=x*x;
    double  y2=y*y;
    double  z2=z*z;

    double  x4=x2*x2, y4=y2*y2,z4=z2*z2;

    double  r2=r*r;
    double  r3=r2*r;
    double  r4=r2*r2;

    double Y=1.0;
     if ( AOName1.startsWith ("S")  ) {
         Y=1.0/sqrt(PI)/2.0;
         m=0;
         return Y;
     }

     else if ( AOName1.startsWith("P")  )
     {
         // |m|=abs(m)
         // NY = 1/sqrt(2*PI) * sqrt( (2*l+1)! * (l-|m|)! / (2* (l+|m| )! )
         //double NPY=1/sqrt(4*PI) * sqrt(3);
         //Ypx = NPY * x / r, Ypy = NPY * y / r, Ypz = NPY * z / r;

         if  (AOName1.startsWith("Px"))  {Y = sqrt(3.0/PI/4.0) * x / r; m=1; }
         if  (AOName1.startsWith("Py"))  {Y = sqrt(3.0/PI/4.0) * y / r; m=-1;}
         if  (AOName1.startsWith("Pz"))  {Y = sqrt(3.0/PI/4.0) * z / r; m=0;}

         return Y;
     }

     else if ( AOName1.startsWith("D") ) {
               /*
               Ydxy = NDY * x * y / r2 ;
               Ydxz = NDY * x * z / r2 ;
                dyz = NDY * y * z / r2 ;

               Ydx2_y2 = 1/sqrt(4*PI)*sqrt(15/4) * ( x2 - y2 ) / r2 ;
               Ydz2 = 1/sqrt(4*PI)* sqrt(5/4) * ( 2*z2 - ( x2 + y2 ) ) / r2
               */

         if  (AOName1.startsWith("Dz2"))     {
             Y = sqrt(5.0/PI)/4.0 * ( 2*z2 - ( x2 + y2 ) ) / r2 ;
             m=0;
             return Y;
         }

          if  (AOName1.startsWith("Dxz"))     {
              Y = sqrt(15.0/PI)/2.0 * x * z / r2 ;
              m=1;
              return Y;
          }

          if  (AOName1.startsWith("Dyz"))     {
              Y = sqrt(15.0/PI)/2.0 * y * z / r2 ;
              m=-1;
              return Y;
          }

          if  (AOName1.startsWith("Dxy"))     {
              Y = sqrt(15.0/PI)/2.0 * x * y / r2 ;
              m=2;
              return Y;
          }

          if  (AOName1.startsWith("Dx2-y2"))  {
              Y = sqrt(15.0/PI)/4.0 * ( x2 - y2 ) / r2 ;
              m=-2;
              return Y;
          }


     }

     else if ( AOName1.startsWith("F")  )  {
         /* https://winter.group.shef.ac.uk/orbitron/AOs/4f/equations.html
               double NFY= 1/sqrt(4*PI) *sqrt(7/4);
               double C = 1/sqrt(4*PI);
               Yfx3  = C * sqrt(7/4) * x * ( 5*x2 - 3*r2 ) / r3 ;
               Yfy3  = C * sqrt(7/4) * y * ( 5*y2 - 3*r2 ) / r3 ;
               Yfz3  = C * sqrt(7/4) * z * ( 5*z2 - 3*r2 ) / r3 ;

               Yfxz2 = C * sqrt(42/16) * x *( 5*z2 - r2 ) / r3 ;
               Yfyz2 = C * sqrt(42/16) * y *( 5*z2 - r2 ) / r3 ;

               Yfy_3x2_y2 = C * sqrt(70/16) * y *( 3*x2 - y2 ) / r3 ;
               Yfx_x2_3y2 = C * sqrt(70/16) * x* ( x2 - 3*y2 ) / r3 ;

               Yfz_x2_y2 =  C * sqrt(105/4) * z * ( x2 - y2 ) / r3 ;
               Yfxyz =      C * sqrt(105/4) * x * y * z / r3 ;

               Yfx_z2_y2 = C * sqrt(105/4) * x *( z2 - y2 ) / r3 ;
               Yfy_z2_x2 = C * sqrt(105/4) * y *( z2 - x2 ) / r3 ;
                         */

         /*
               if  (AOName1.startsWith("Fx3"))    {
                   Y = sqrt(70.0/PI)/8.0 * x * ( 5*x2 - 3*r2 ) / r3 ;
               }

               if  (AOName1.startsWith("Fy3"))    {
                   Y =  sqrt(70.0/PI)/8.0  * y * ( 5*y2 - 3*r2 ) / r3 ;
               }
                */

         if  (AOName1.startsWith("Fz3"))    {
             Y =  sqrt(7.0/PI)/4.0 * z * ( 5*z2 - 3*r2 ) / r3 ;
             m=0;
             return Y;
         }

         if  (AOName1.startsWith("Fxz2"))    {
             Y =  sqrt(42./PI)/8.0 * x *( 5*z2 - r2 ) / r3 ;
             m=1;
             return Y;
         }

         if  (AOName1.startsWith("Fyz2"))    {
             Y =  sqrt(42./PI)/8.0 * y *( 5*z2 - r2 ) / r3;
             m=-1;
             return Y;
         }


         if  (AOName1.startsWith("Fz(x2-y2)"))     {
             Y =   sqrt(105.0/PI)/4.0 * z * ( x2 - y2 ) / r3 ;
             m=2;
             return Y;
         }

         if  (AOName1.startsWith("Fxyz") || AOName1.startsWith("Fzxy")) {
             Y =   sqrt(105.0/PI)/2.0 * x * y * z / r3 ;
             m=-2;
             return Y;
         }


         if  (AOName1.startsWith("Fx(x2-3y2)"))    {
             Y = sqrt(70./PI)/8.0  * x * ( x2 - 3*y2 ) / r3 ;
             m=3;
             return Y;
         }

         if  (AOName1.startsWith("Fy3(x2-y2)"))    {
             Y = sqrt(70./PI)/8.0  * y * ( 3*x2 - y2 ) / r3 ;
             m=-3;
             return Y;
         }

     }


     else if ( AOName1.startsWith("G"))
     {

         /*Gz4   =  3.0/16.0/sqrt(pi) * ( 35.0 * z4 - 30. * z2 * r2  + 3. * r4 ) / r4 ; m=0;

               Gz3x  = 3.0/4.0*sqrt(5.0/2.0/pi)* x * z *( 7*z2 - 3*r2 ) / r4 ; m=1
               Gz3y  = 3.0/4.0*sqrt(5.0/2.0/pi)* y * z *( 7*z2 - 3*r2 ) / r4 ; m=-1

               Gz2xy      = 3.0/4.0*sqrt(5.0/pi)*  x*y*( 7.0*z2 - r2 ) / r4 ; m=-2;
               Gz2(x2-y2) = 3.0/8.0*sqrt(5.0/pi)* (x2-y2)*(7*z2 - r2 ) / r4 ; m=2;


               Gzy3 = 3.0/4.0*sqrt(35.0/2/pi) *y*z* ( 3.0*x2 - y2 ) / r4 ; m=-3;
               Gzx3 = 3.0/4.0*sqrt(35.0/2/pi) *x*z* ( x2 - 3.0*y2 ) / r4 ; m=3;

               Gxy(x2-y2) =  3.0/4.0*sqrt(35.0/pi)* x * y* ( x2 - y2 ) / r4 ; m=-4
               Gx4+y4   =  3.0/16.*sqrt(35.0/pi) * ( x2*(x2 -3.0*y2) - y2*( 3.0*x2-y2) / r4 ; m=4;
          */

         if  (AOName1.startsWith("Gz4"))
         {
             Y   = 3.0/16.0/sqrt(PI) * ( 35.0 * z4 - 30.0 * z2 * r2  + 3.0 * r4 ) / r4 ;
             m=0;
             return Y;
         }

         if  (AOName1.startsWith("Gz3x"))
         {
             Y = 3.0/4.0*sqrt(5.0/2.0/PI)* x * z *( 7.0*z2 - 3.0*r2 ) / r4 ;
             m=1;
             return Y;
         }

         if  (AOName1.startsWith("Gz3y"))
         {
             Y = 3.0/4.0*sqrt(5.0/2.0/PI)* y * z *( 7.0*z2 - 3.0*r2 ) / r4 ;
             m=-1;
             return Y;
         }

         if  (AOName1.startsWith("Gz2xy"))
         {
             Y = 3.0/4.0*sqrt(5.0/PI)*  x*y*( 7.0*z2 - r2 ) / r4 ;
             m=-2;
             return Y;
         }

         if  (AOName1.startsWith("Gz2(x2-y2)"))
         {
             Y =  3.0/8.0*sqrt(5.0/PI)* (x2-y2)*(7.0*z2 - r2 ) / r4 ;
             m=2;
             return Y;
         }

         if  (AOName1.startsWith("Gzx3"))
         {
             Y = 3.0/4.0*sqrt(35.0/2.0/PI) *x*z* ( x2 - 3.0*y2 ) / r4 ;
             m=3;
         }

         if  (AOName1.startsWith("Gzy3"))
         {
             Y = 3.0/4.0*sqrt(35.0/2.0/PI) *y*z* ( 3.0*x2 - y2 ) / r4 ;
             m=-3;
             return Y;
         }

         if  (AOName1.startsWith("Gxy(x2-y2)"))
         {
             Y =  3.0/4.0*sqrt(35.0/PI)* x * y* ( x2 - y2 ) / r4 ;
             m=-4;
             return Y;
         }

         if  (AOName1.startsWith("G(x4+y4)"))
         {
             Y   = 3.0/16.*sqrt(35.0/PI) * ( x2*(x2 -3.0*y2) - y2*( 3.0*x2-y2) ) / r4 ;
             m=4;
             return Y;
         }
         return Y;
     }
}



double  HAO::SphericalHarmonicY_byName(vector3 pos1, QString AOName)
{
    ObitalName=AOName;
    return SphericalHarmonicY_byName (pos1);
}






void HAO::buildNodes()
{
     if(hasNodesBuild) return;

     lml=abs(m);
     uint nR=n-l-1;
     uint nT=l-lml;
     uint nP=lml;
     uint total=n-1;


     if (nR>0) buildRadialNodes();
     if (l>0)  buildYlmNodes();

     hasNodesBuild=true;

     cout <<"\n\n----------------------------------"<<endl;
     cout << "Hydrogen Atomic Nodes of "<< ObitalName.toStdString().c_str()<<":"<<endl;
     cout << "  Quantum number  n   l   m:"<< "  "<<n <<"  " <<l<<"  "<<m<< endl;
     cout << "  There are: n-l-1="<< nR <<" radial nodes"<<endl;
     cout << "  There are: l-|m|="<< nT <<" Theta/angular nodes"<<endl;
     cout << "  There are: |m|="<< nP <<" Phi/angular nodes"<<endl;
}





void HAO::buildRadialNodes()
{
    if (hasNodesBuild) return;


    lml=abs(m);

    uint nR=n-l-1;


    if (nR<1) return;

     vector < double >  poly_R, poly_gradR; //radial
     poly_R.clear(), poly_gradR.clear();

     double alpha=2.0*Z/n/a0;
     double  coeff_R=pow(alpha,3/2.0)*sqrt(Factorial(n-l-1)*Factorial(n+l)/n/2.0);
     double term=1.0;

     int k=n-l-1,j;
     for (j=0; j<=k; j++){
                 term=coeff_R*powl(-1.0,j+1)/Factorial(2*l+j+1)/Factorial(j)/Factorial(n-l-j-1);
                 poly_R.push_back(term);
                 //poly_gradR.push_back(term*(n-l-j-1));
     }

     double term0=poly_R[poly_R.size()-1];
     for (int i=0;i<poly_R.size();i++)
         poly_R[i]=poly_R[i]/term0;

  
    SolveEquation roots(poly_R);
    roots.Solve();

    for(int j=0; j<nR; j++)
       cout << roots.answer[j]<<endl;

    Nodes_R.clear();
    if (roots.answer.size()>0)
    for(int j=0; j<nR; j++)
       Nodes_R.push_back(roots.answer[j]/alpha);

     //sort
     sort(Nodes_R.begin(), Nodes_R.end());
     std::reverse(Nodes_R.begin(),Nodes_R.end());

/*
     cout << poly_R.size()<<endl;
     cout << Nodes_R.size()<<endl;
     cout <<"------input-----------"<<endl;
     for (int i=0;i<poly_R.size();i++)
        cout << poly_R[i]<<endl;
     cout <<"------solution-----------"<<endl;
     for(int j=0; j<nR; j++)
        cout << Nodes_R[j]<<endl;

     cout <<"-----------------"<<endl;
*/
     hasNodesBuild=true;
}


double HAO::calc_least_r(double eps)
{
    buildRadialNodes();

    double r0=3.0;
    if (Nodes_R.size()>0)
        r0=Nodes_R[0];
    else
        r0=1.0*n;


    double r=r0;



    //scan R
    cout << "begin scan R:"<<endl;
    while (1)
    {
         r=r+1.0;
         if (abs(Hydrogen_R(r))>eps) continue;
         break;
    }

    cout << "done!"<<endl;
    cout << "the least r is "<<r<<endl;

    return r;
}


double HAO::calc_least_rdf()
{
    buildRadialNodes();

    double eps=0.001;

    double r0=3.0;
    if (Nodes_R.size()>0)
        r0=Nodes_R[0];
    else
        r0=1.0*n;


    double r=r0;

    //scan R
    cout << "begin scan R:"<<endl;
    while (1)
    {
         r=r+0.5;
         if (abs(Hydrogen_RDF(r))>eps) continue;
         break;
    }

    cout << "done!"<<endl;
    cout << "the least r is "<<r<<endl;

    return r;
}





 void HAO::buildYlmNodes()
 {
     lml=abs(m);
     uint nT=l-lml;
     uint nP=lml;


    if (nT>0) {
        int m2=m+lml;
        QVector < double >  poly_T, poly_gradT; //theta
        poly_T.clear(), poly_gradT.clear();

        double term=1.0;
        double  Coeff_T=powl(-1.0, m2/2)/powl(2.0,l)*sqrt(l+0.5) * sqrt( Factorial(l-lml)/Factorial(l+lml));

        int k=floor((l-lml)/2);
        for (int j=0; j<=k; j++) {
                 term=Coeff_T*powl(-1.0,j)*Factorial(2*l-2*j)/Factorial(j)/Factorial(l-j)/Factorial(l-lml-2*j);
                 poly_T.push_back( term );
                 poly_gradT.push_back( term * (l-lml-2*j));
        }

        int size=poly_T.size();
        QRRoots roots(size-1);
        double term0=poly_T[size-1];
        for (int i=0;i<size;i++) {
              roots.a[i]=poly_T[size-i-1]/term0;
              cout <<roots.a[i]<<endl;
        }


        //the roots of associated is [cos(theta)]^2
        roots.qrSolve();
        Nodes_T.clear();
        uint n=0, j=0;

        while (1)
        {
            if (abs(roots.xr[j]) <0.0001) {
                Nodes_T.push_back(0.0);
                n=n+1;
                isXOYNode=true;
            }
            else {
                Nodes_T.push_back(roots.xr[j]);
                n=n+2;
            }

            if (n>=nT) break;
            j=j+1;
        }
    }



    Nodes_P.clear();
    if (lml<1) return;
    double phi=180.0/2/lml;
    for(int k=0; k<lml; k++)
    {
        if (m>0) //sin
            Nodes_P.push_back(phi*k*2+phi);
        else  //cos
            Nodes_P.push_back(phi*k*2);
    }

}
//=======================================================================//




//=======================================================================//
 void HMO::calc_Ylm(double theta, double theta1, double interval_t,
                    double phi,  double phi1, double interval_p)
 {
     surfaceAngular_positive.clear();
     surfaceAngular_negative.clear();

     while (theta < theta1)
     {
         calc_Ylm_phi(theta, phi,  phi1, interval_p);
         theta=theta+interval_t;
     }

     if(surfaceAngular_positive.size()>100)
        pos_Ylm.push_back(surfaceAngular_positive);

     if(surfaceAngular_negative.size()>100)
        neg_Ylm.push_back(surfaceAngular_negative);

     surfaceAngular_positive.clear();
     surfaceAngular_negative.clear();
 }

//fixed theta
 void HMO::calc_Ylm_phi(double theta, double phi, double phi1, double interval)
 {
     double scale=3.0;
     double d2r=3.141592654/180.0;

     double sinP=0.0,cosP=0.0,Y=0.0,r;
     double sinT,cosT;

     if (abs (theta)<0.1) {
         sinT=0.0;
         cosT=1.0;
     }
     else  {
         sinT=sin(theta*d2r);
         cosT=cos(theta*d2r);
     }

     append_surfaceYlm_pos(0.0,0.0,0.0);
     append_surfaceYlm_neg(0.0,0.0,0.0);

     while (phi < phi1)
     {
         r=scale*AOs[0]->SphericalHarmonicY_byName(theta*d2r,phi*d2r);
         Y=abs(r);

         sinP=sin(phi*d2r);
         cosP=cos(phi*d2r);

         if(r>0.0)  append_surfaceYlm_pos(Y*sinT*cosP,Y*sinT*sinP,Y*cosT);
         else       append_surfaceYlm_neg(Y*sinT*cosP,Y*sinT*sinP,Y*cosT);

         phi=phi+interval;
     }
 }



 //fixed phi
 void HMO::calc_Ylm_theta(double phi, double theta, double theta1, double interval)
 {
     //phi is fixed, and scan theta-->theta1

     double scale=3.0;
     double d2r=3.141592654/180.0;

     double Y=0.0,r;

     double sinP=sin(phi*d2r), cosP=cos(phi*d2r);

     theta1=theta1;
     while (theta < theta1)
     {
         r=scale*AOs[0]->SphericalHarmonicY_byName(theta*d2r,phi*d2r);
         Y=abs(r);

         double sinT=sin(theta*d2r);
         double cosT=cos(theta*d2r);

         if(r>0.0)  append_surfaceYlm_pos(Y*sinT*cosP,Y*sinT*sinP,Y*cosT);
         else       append_surfaceYlm_neg(Y*sinT*cosP,Y*sinT*sinP,Y*cosT);

        theta=theta+interval;
     }
 }


 void HMO::collect_All_Ylm() //trans all 3d cloud points to surface
 {
     //positive points
     if(pos_Ylm.size()>0)
     {
         auto appendFilter = vtkSmartPointer<vtkAppendPolyData>::New();

         uint sum=0;
         for(uint i=0;i<pos_Ylm.size();i++)
         {
             if(pos_Ylm[i].size()<100) return;
             sum+=pos_Ylm[i].size();

             auto m_Points=vtkSmartPointer<vtkPoints>::New();
             for (uint j=0;j<pos_Ylm[i].size();j++)
             {
                 m_Points->InsertPoint(j,pos_Ylm[i][j].x(),
                                         pos_Ylm[i][j].y(),
                                         pos_Ylm[i][j].z());
                 //if(lengthYlm<l) lengthYlm=l;
             }

             auto data=vtkSmartPointer<vtkPolyData>::New();
             data->SetPoints(m_Points);

             auto surf= vtkSmartPointer<vtkSurfaceReconstructionFilter>::New();
             surf->SetInputData(data);
             surf->Update();

             auto contour=vtkSmartPointer<vtkContourFilter>::New();
             contour->SetInputConnection(surf->GetOutputPort());
             contour->SetValue(0,0.0);
             contour->Update();

             appendFilter->AddInputData(contour->GetOutput());
             appendFilter->Update();
         }

         if (sum>0)
         {
             Ylm_pos_existed=true;
             auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
             cleanFilter->SetInputConnection(appendFilter->GetOutputPort());
             //cleanFilter->SetTolerance(0.1);
             cleanFilter->Update();

             ylmData=vtkPolyData::New();
            // yData->DeepCopy(cleanFilter->GetOutput());

             //restore
             ylmData->DeepCopy(cleanFilter->GetOutput());

             for(uint i=0;i<pos_Ylm.size();i++)
                 pos_Ylm[i].clear();
             pos_Ylm.clear();
         }
     }



     //negtive points
     if(neg_Ylm.size()>0)
     {
         uint sum=0;
         auto appendFilter = vtkSmartPointer<vtkAppendPolyData>::New();
         for(uint i=0;i<neg_Ylm.size();i++)
         {
             if(neg_Ylm[i].size()<100) return;
             sum+=neg_Ylm[i].size();

             auto m_Points=vtkSmartPointer<vtkPoints>::New();
             for (uint j=0;j<neg_Ylm[i].size();j++)
             {
                 m_Points->InsertPoint(j,neg_Ylm[i][j].x(),
                                         neg_Ylm[i][j].y(),
                                         neg_Ylm[i][j].z());

             }

             auto data=vtkSmartPointer<vtkPolyData>::New();
             data->SetPoints(m_Points);

             auto surf= vtkSmartPointer<vtkSurfaceReconstructionFilter>::New();
             surf->SetInputData(data);
             surf->Update();

             auto contour=vtkSmartPointer<vtkContourFilter>::New();
             contour->SetInputConnection(surf->GetOutputPort());
             contour->SetValue(0,0.0);
             contour->Update();

             appendFilter->AddInputData(contour->GetOutput());
             appendFilter->Update();
         }

         if (sum>0)
         {
             Ylm_neg_existed=true;
             auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
             cleanFilter->SetInputConnection(appendFilter->GetOutputPort());
             //cleanFilter->SetTolerance(0.1);
             cleanFilter->Update();

             ylmData1=vtkPolyData::New();
             ylmData1->DeepCopy(cleanFilter->GetOutput());

             for(uint i=0;i<neg_Ylm.size();i++)
                 neg_Ylm[i].clear();
             neg_Ylm.clear();
         }
     }

     //filter largest length and height
     double x,y,z;
     if(ylmData->GetNumberOfPoints()>100)
     for (int i=0;i<ylmData->GetNumberOfPoints();i++)
     {
         double * p = ylmData->GetPoint(i);

         //x=abs(p[0]); y=abs(p[1]); z=abs(p[2]);
         x=p[0];  y=p[1];   z=p[2];

         if(lengthYlm<x)   lengthYlm=x;
         if(lengthYlm<y)   lengthYlm=y;
         if(heigthYlm<z)   heigthYlm=z;
     }

     if(ylmData1->GetNumberOfPoints()>100)
     for (int i=0;i<ylmData1->GetNumberOfPoints();i++)
     {
         double * p = ylmData1->GetPoint(i);

         //x=abs(p[0]); y=abs(p[1]); z=abs(p[2]);
         x=p[0];  y=p[1];   z=p[2];


         if(lengthYlm<x)   lengthYlm=x;
         if(lengthYlm<y)   lengthYlm=y;
         if(heigthYlm<z)   heigthYlm=z;
     }

    // cout << "------------------------- filter out inside collect_All_Ylm :" << lengthYlm << " "<<heigthYlm<<endl;

 }



 //only calcuate s and p orbital
  void HMO::calc_SphericalHarmonicY_SP()
  {
      double scale=3.0;

      uint n=180;
      uint m=n/2;

      double phi0=360.0/n;    //0--->2Pi
      double theta0=180.0/m;  //0--->Pi

      double x=0.0,y=0.0,z=0.0;
      double r=0.0,Y=0.0;
      double sinT=0.0,cosT=0.0;
      double d2r=3.141592654/180.0; //degree to radian
      double theta=0.0,phi=0.0;
      double sinP, cosP;


      surfaceAngular_positive.clear();
      surfaceAngular_negative.clear();


      for (uint i=0;i<n-1;i++)
      {
           phi=phi0*i*d2r+180.*d2r;
           sinP=sin(phi);
           cosP=cos(phi);

          for (uint j=1;j<m-1;j++)
          {
              theta=theta0*j*d2r;
              r=AOs[0]->SphericalHarmonicY_byName(theta,phi);

              Y=scale*abs(r);

              sinT=sin(theta);
              cosT=cos(theta);
              x = sinT*cosP;
              y = sinT*sinP;
              z = cosT;

              x *= Y;
              y *= Y;
              z *= Y;

             if(r>0.01) {
                 append_surfaceYlm_pos(x,y,z);
                 continue;
             }
             if(r<-0.01) {
                 append_surfaceYlm_neg(x,y,z);
             }

          }
      }



      //positive points
      //cout << "\n-------------------------------"<<endl;
      cout << surfaceAngular_positive.size()<<" positive points"<<endl;
      if(surfaceAngular_positive.size()>100)
      {
          Ylm_pos_existed=true;

          auto m_Points=vtkSmartPointer<vtkPoints>::New();
          for (uint i=0;i<surfaceAngular_positive.size();i++)
          {
              m_Points->InsertPoint(i,surfaceAngular_positive[i].x(),
                                    surfaceAngular_positive[i].y(),
                                    surfaceAngular_positive[i].z());

          }

          auto data=vtkSmartPointer<vtkPolyData>::New();
          data->SetPoints(m_Points);

          auto surf= vtkSmartPointer<vtkSurfaceReconstructionFilter>::New();
          surf->SetInputData(data);
          surf->Update();

          auto contour=vtkSmartPointer<vtkContourFilter>::New();
          contour->SetInputConnection(surf->GetOutputPort());
          contour->SetValue(0,0.0);
          contour->Update();


          auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
          cleanFilter->SetInputConnection(contour->GetOutputPort());
          //cleanFilter->SetTolerance(0.1);
          cleanFilter->Update();


          ylmData=vtkPolyData::New();
          ylmData->DeepCopy(cleanFilter->GetOutput());

      }



      //negtive points
      //cout << surfaceAngular_negative.size()<<" negtive positive size"<<endl;
      if(surfaceAngular_negative.size()>100)
      {
         Ylm_neg_existed=true;
         auto m_Points=vtkSmartPointer<vtkPoints>::New();
         for (uint j=0;j<surfaceAngular_negative.size();j++)
         {
             m_Points->InsertPoint(j,surfaceAngular_negative[j].x(),
                                      surfaceAngular_negative[j].y(),
                                      surfaceAngular_negative[j].z());
         }

         auto data=vtkSmartPointer<vtkPolyData>::New();
         data->SetPoints(m_Points);

         auto surf= vtkSmartPointer<vtkSurfaceReconstructionFilter>::New();
         surf->SetInputData(data);
         surf->Update();

         auto contour=vtkSmartPointer<vtkContourFilter>::New();
         contour->SetInputConnection(surf->GetOutputPort());
         contour->SetValue(0,0.0);
         contour->Update();


         auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
         cleanFilter->SetInputConnection(contour->GetOutputPort());
         //cleanFilter->SetTolerance(0.1);
         cleanFilter->Update();


         ylmData1=vtkPolyData::New();
         ylmData1->DeepCopy(cleanFilter->GetOutput());
      }



      //filter length and height
      if(surfaceAngular_positive.size()>100)
      for (int i=0;i<ylmData->GetNumberOfPoints();i++)
      {
          double * p = ylmData->GetPoint(i);

          //x=abs(p[0]); y=abs(p[1]);  z=abs(p[2]);
          x=p[0];  y=p[1];   z=p[2];

          if(lengthYlm<x)   lengthYlm=x;
          if(lengthYlm<y)   lengthYlm=y;
          if(heigthYlm<z)   heigthYlm=z;
      }

      if(surfaceAngular_negative.size()>100)
      for (int i=0;i<ylmData1->GetNumberOfPoints();i++)
      {
          double * p = ylmData1->GetPoint(i);

          //x=abs(p[0]); y=abs(p[1]);  z=abs(p[2]);
          x=p[0];  y=p[1];   z=p[2];

          if(lengthYlm<x)   lengthYlm=x;
          if(lengthYlm<y)   lengthYlm=y;
          if(heigthYlm<z)   heigthYlm=z;
      }

      surfaceAngular_positive.clear();
      surfaceAngular_negative.clear();
 }


 void HMO::calc_SphericalHarmonicY()
 {
     if(isSphericalHarmonicYOK)
         return;

     //only one AO inside, index=0
     uint idx=0;
     QString AOName=AOs[idx]->getName();
     AOs[idx]->buildYlmNodes();

     AOName.remove(0,1);
     if( AOName.startsWith("S") || AOName.startsWith("P") )
     {
         calc_SphericalHarmonicY_SP();
         return;
     }


     double scale=3.0;
     double d2r=3.141592654/180.0;


     vector3 data;
     double sinT=0.0,cosT=0.0,sinP=0.0,cosP=0.0,Y=0.0,r;

     //theta and phi
     uint nodes_Phi=getAO(0)->Nodes_P.size();
     uint nodes_Theta=getAO(0)->Nodes_T.size();

     double theta0=0.0,phi0=0.0;


     //initial
     vector <double> interval_p;
     if (nodes_Phi>0) {
            for (uint i=0;i<nodes_Phi;i++) {
                double angle=getAO(0)->Nodes_P[i];
                interval_p.push_back(angle);
                interval_p.push_back(angle+180.0);
            }
            sort(interval_p.begin(), interval_p.end());
            if(interval_p[interval_p.size()-1]<360.0)
                interval_p.push_back(360.0+interval_p[0]);
     }


     //the node solutions of Lengendre are [cos(theta)*cos(theta)]
     vector <double> interval_t;
     if (nodes_Theta>0) {
            interval_t.push_back(0.0);
            for (uint i=0;i<nodes_Theta;i++) {

                double angle=acos(sqrt(getAO(0)->Nodes_T[i]))/3.141592654*180.0;
                interval_t.push_back(angle);

                //cout<<getAO(0)->Nodes_T[i]<<"  "<< angle <<" answer of Theta node "<<endl;

                if(angle<89.0) interval_t.push_back(180.0-angle);
            }

            sort(interval_t.begin(), interval_t.end());
            if(interval_t[interval_t.size()-1]<180.0)
                interval_t.push_back(180.0);
            sort(interval_t.begin(), interval_t.end());
     }


/*

     cout << "\n-------------------------------------\n";
     cout << "numbers of Phi: "<< nodes_Phi <<" "<<endl;
     cout << "begin of phi: "<< phi0<<endl;
     cout << "interval of phi : ";
     for (uint i=0;i<interval_p.size();i++) cout << interval_p[i] <<" ";


     cout << "\n\nnumbers of Theta: " << nodes_Theta <<" "<<endl;
     cout << "begin of theta: "<< theta0<<endl;
     cout << "interval of theta : ";
     for (uint i=0;i<interval_t.size();i++) cout << interval_t[i] <<"   ";
     cout << "\n-------------------------------------\n";
*/

     pos_Ylm.clear();
     neg_Ylm.clear();


     //phi=0.0-->360.0
     if(nodes_Phi<1)
     {
         for (uint j=0;j<interval_t.size()-1;j++)
         {
             double theta=interval_t[j];
             double theta1=interval_t[j+1];
             //cout << "times : "<< j+1<<"  " << theta<<"--->"<<theta1<<endl;
             calc_Ylm(theta, theta1, 1.0,
                     0.0,   360.0,   2.0);
         }
         collect_All_Ylm();
         return;
     }

     //theta=0.0-->180.0
     if(nodes_Theta<1)
     {
         //cout << "  scan phi : \n";
         for (uint j=0;j<interval_p.size()-1;j++)
         {
             double phi=interval_p[j];
             double phi1=interval_p[j+1];
             //cout << "times : "<< j+1<<" " << phi<<"-->"<<phi1<<endl;
             calc_Ylm(0.0, 180.0, 1.0,
                      phi,   phi1,  2.0);

         }
         collect_All_Ylm();
         return;
     }


     //general cases
     for (uint j=0;j<interval_t.size()-1;j++)
     {
         double theta=interval_t[j];
         double theta1=interval_t[j+1];

         for (uint j=0;j<interval_p.size()-1;j++)
         {
             double phi=interval_p[j];
             double phi1=interval_p[j+1];

             calc_Ylm(theta, theta1, 1.0,
                      phi,   phi1,   2.0);
         }
     }

     collect_All_Ylm();
 }


void HMO::append_surfaceYlm_pos(double x, double y, double z)
{
    vector3 data(x,y,z);
    double eps=0.02;

    uint size=surfaceAngular_positive.size();

    if(data.length()<0.01)
        data.Set(0.0,0.0,0.0);

    if(size<1) {
        surfaceAngular_positive.push_back(data);
        return;
    }

    bool isExisted=false;
    for (uint i=0;i<size;i++)
    {

        if((surfaceAngular_positive[i]-data).length()<eps)
        {
            isExisted=true;
            break;
        }
    }

    if (!isExisted) surfaceAngular_positive.push_back(data);
}



void HMO::append_surfaceYlm_neg(double x, double y, double z)
{
    double eps=0.02;

    vector3 data(x,y,z);

    if(data.length()<0.01)
        data.Set(0.0,0.0,0.0);

    uint size=surfaceAngular_negative.size();
    if(size<1) {
        surfaceAngular_negative.push_back(data);
        return;
    }

    bool isExisted=false;
    for (uint i=0;i<size;i++)
    {
        if((surfaceAngular_negative[i]-data).length()<eps)
        {
            isExisted=true;
            break;
        }
    }

    if (!isExisted) surfaceAngular_negative.push_back(data);
}


void HMO::buildYlmSurface_wedge()
{
    uint nodes_Phi=getAO(0)->Nodes_P.size();
    uint nodes_Theta=getAO(0)->Nodes_T.size();

    vector <double> Phi;
    if (nodes_Phi>0) {
        for (uint i=0;i<nodes_Phi;i++) {
            double angle=getAO(0)->Nodes_P[i];
            if (angle<181.0)
                Phi.push_back(angle);
        }
        sort(Phi.begin(), Phi.end());
    }

    bool needProj2XOY=true,
         needProj2XOZ=true,
         needProj2YOZ=true;

    for (uint i=0;i<Phi.size();i++)
    {
        if( abs(Phi[i])<1.0){
            needProj2XOZ=false;
            break;
        }
    }
    for (uint i=0;i<Phi.size();i++)
    {
        if( abs(Phi[i]-90.0)<1.0){
            needProj2YOZ=false;
            break;
        }
    }


    double max_theta=0.0,cosTheta=1.0;
    double min_phi=0.0,sinPhi=0.0;
    double max_phi=0.0,cosPhi=0.0;

    vector <double> Theta;
    if (nodes_Theta>0) {
        for (uint i=0;i<nodes_Theta;i++) {
            double angle=acos(sqrt(getAO(0)->Nodes_T[i]))/3.141592654*180.0;
            Theta.push_back(angle);
        }
        sort(Theta.begin(), Theta.end());
    }


    if(Phi.size()>0) {
        min_phi=Phi[0];
        if (min_phi<1.0 && Phi.size()>1)
            min_phi=Phi[1];

        sinPhi=sin(min_phi*3.141592654/180.0);
    }

    if (needProj2YOZ)
        for (uint i=0;i<Phi.size();i++)
        {
            max_phi=Phi[i];
            if(max_phi>90.0)  {
                cosPhi=-cos(max_phi*3.141592654/180.0);
                break;
            }
        }

    if (Theta.size()==1) {
        max_theta=Theta[0];
        if (abs(max_theta-90.0) <1.0)
            needProj2XOY=false;
    }

    if (Theta.size()>1) {
        max_theta=Theta[Theta.size()-1];
        if (abs(max_theta-90.0) <1.0)
            needProj2XOY=false;
    }
    cosTheta=cos(max_theta*3.141592654/180.0);

    //remove data with (90>theta>0 and 180>phi>0) or (y>0 and z>0)



    vector3 v;
    if(isPosYlmExisted())
    {
        //building XOY
        for (int i=0;i<yData->GetNumberOfPoints();i++)
        {
            double * p = yData->GetPoint(i);
            if (p[2] < 0.0) continue;

            if(needProj2XOY)
            {
                v.Set(p[0],p[1],p[2]); v.normalize();

                //remove this point
                if (dot (v,VZ) > cosTheta) { p[2]=0.0;   p[1]=0.0;  p[0]=0.0;}

                //if (p[1] < 0.0) { p[2]=0.0;   p[1]=0.0;  p[0]=0.0;}

                //projection
                p[2]=0.0;
            }
            else //remove this point
            { p[2]=0.0;    p[1]=0.0;  p[0]=0.0;}

            yData->GetPoints()->SetPoint(i,p);
        }

        //building one corner
        auto data=vtkSmartPointer<vtkPolyData>::New();
        data->DeepCopy(ylmData);
        for (int i=0;i<data->GetNumberOfPoints();i++)
        {
            double * p = data->GetPoint(i);
            if (p[2] > 0.0) continue;

            if(needProj2XOY)
            {
                v.Set(p[0],p[1],p[2]); v.normalize();

                //remove this point
                if (dot (v,VZ) > cosTheta) { p[2]=0.0;   p[1]=0.0;  p[0]=0.0;}
                //projection
                p[2]=0.0;
            }
            else //remove this point
            { p[2]=0.0;    p[1]=0.0;  p[0]=0.0;}

            data->GetPoints()->SetPoint(i,p);
        }

        for (int i=0;i<data->GetNumberOfPoints();i++)
        {
            double * p = data->GetPoint(i);
            if (p[1] < 0.0) continue;
            if(needProj2XOZ)
            {
                v.Set(p[0],p[1],0.0);v.normalize();

                //remove this point
                if (v[1] > sinPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                //projection
                else    p[1]=0.0;
            }
            else { //remove this point
                p[2]=0.0;    p[1]=0.0;  p[0]=0.0;
            }

            data->GetPoints()->SetPoint(i,p);
        }

        //merge
        auto appendFilter = vtkSmartPointer<vtkAppendPolyData>::New();
        appendFilter->AddInputData(data);
        appendFilter->AddInputData(yData);
        appendFilter->Update();


        auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
        cleanFilter->AddInputData(appendFilter->GetOutput());
        cleanFilter->Update();
        yData->DeepCopy(cleanFilter->GetOutput());
    }





    if(isNegYlmExisted())
    {
        //building XOY
        for (int i=0;i<yData1->GetNumberOfPoints();i++)
        {
            double * p = yData1->GetPoint(i);
            if (p[2] < 0.0) continue;

            if(needProj2XOY)
            {
                v.Set(p[0],p[1],p[2]); v.normalize();

                //remove this point
                if (dot (v,VZ) > cosTheta) { p[2]=0.0;   p[1]=0.0;  p[0]=0.0;}

                //if (p[1] < 0.0) { p[2]=0.0;   p[1]=0.0;  p[0]=0.0;}

                //projection
                p[2]=0.0;
            }
            else //remove this point
            { p[2]=0.0;    p[1]=0.0;  p[0]=0.0;}

            yData1->GetPoints()->SetPoint(i,p);
        }

        //building one corner
        auto data=vtkSmartPointer<vtkPolyData>::New();
        data->DeepCopy(ylmData1);
        for (int i=0;i<data->GetNumberOfPoints();i++)
        {
            double * p = data->GetPoint(i);
            if (p[2] > 0.0) continue;

            if(needProj2XOY)
            {
                v.Set(p[0],p[1],p[2]); v.normalize();

                //remove this point
                if (dot (v,VZ) > cosTheta) { p[2]=0.0;   p[1]=0.0;  p[0]=0.0;}
                //projection
                p[2]=0.0;
            }
            else //remove this point
            { p[2]=0.0;    p[1]=0.0;  p[0]=0.0;}

            data->GetPoints()->SetPoint(i,p);
        }

        for (int i=0;i<data->GetNumberOfPoints();i++)
        {
            double * p = data->GetPoint(i);
            if (p[1] < 0.0) continue;
            if(needProj2XOZ)
            {
                v.Set(p[0],p[1],0.0);v.normalize();

                //remove this point
                if (v[1] > sinPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                //projection
                else    p[1]=0.0;
            }
            else { //remove this point
                p[2]=0.0;    p[1]=0.0;  p[0]=0.0;
            }

            data->GetPoints()->SetPoint(i,p);
        }

        //merge
        auto appendFilter = vtkSmartPointer<vtkAppendPolyData>::New();
        appendFilter->AddInputData(data);
        appendFilter->AddInputData(yData1);
        appendFilter->Update();


        auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
        cleanFilter->AddInputData(appendFilter->GetOutput());
        cleanFilter->Update();
        yData1->DeepCopy(cleanFilter->GetOutput());
    }

}




void HMO::buildYlmSurface()
{
    calc_SphericalHarmonicY();

    uint l=getAO(0)->l;
    uint m=getAO(0)->m;
    bool isOrbitalS=false;
    if (l<1) isOrbitalS=true;



    if(isPosYlmExisted()) {
        yData=vtkPolyData::New();
        yData->DeepCopy(ylmData);
    }


    if(isNegYlmExisted()) {
        yData1=vtkPolyData::New();
        yData1->DeepCopy(ylmData1);
    }



    if(orbital_type==FULL) return;

    //special cases
    if (orbital_type==Wedge)
    {
        buildYlmSurface_wedge();
        return;
    }


    if(!isOrbitalS) { //general cases
        buildYlmSurface_g();
        return;
    }
    else {
        switch (orbital_type)
        {
        case  XOY :
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[2] > 0.0) {
                    p[2]=0.0;
                    yData->GetPoints()->SetPoint(i,p);
                }
            }
            break;

        case  YOZ :
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[0] > 0.0) {
                    p[0]=0.0;
                    yData->GetPoints()->SetPoint(i,p);
                }
            }
            break;

        case  XOZ :
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[1] > 0.0) {
                    p[1]=0.0;
                    yData->GetPoints()->SetPoint(i,p);
                }
            }
            break;

        case  Quarter :
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[2] > 0.0) {
                    p[2]=0.0;
                    yData->GetPoints()->SetPoint(i,p);
                }
            }
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[1] > 0.0) {
                    p[1]=0.0;
                    yData->GetPoints()->SetPoint(i,p);
                }
            }
            break;

        case  Corner :
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[0] > 0.0) {
                    p[0]=0.0;
                    yData->GetPoints()->SetPoint(i,p);
                }
            }
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[2] > 0.0) {
                    p[2]=0.0;
                    yData->GetPoints()->SetPoint(i,p);
                }
            }
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[1] > 0.0) {
                    p[1]=0.0;
                    yData->GetPoints()->SetPoint(i,p);
                }
            }
            break;

        case  Wedge :
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[2] > 0.0 &&   p[1] > 0.0)
                {
                    if(p[1] < 0.1) p[1]=0.0;
                    p[2]=0.0;
                    yData->GetPoints()->SetPoint(i,p);
                }
            }
            break;
        }

        auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
        cleanFilter->AddInputData(yData);
        cleanFilter->Update();
        yData->DeepCopy(cleanFilter->GetOutput());
    }

}

//general cases
void HMO::buildYlmSurface_g()
{
    uint nodes_Phi=getAO(0)->Nodes_P.size();
    uint nodes_Theta=getAO(0)->Nodes_T.size();

    vector <double> Phi;
    if (nodes_Phi>0) {
        for (uint i=0;i<nodes_Phi;i++) {
            double angle=getAO(0)->Nodes_P[i];
            if (angle<181.0)
                Phi.push_back(angle);
        }
        sort(Phi.begin(), Phi.end());
    }

    bool needProj2XOY=true,
         needProj2XOZ=true,
         needProj2YOZ=true;

    for (uint i=0;i<Phi.size();i++)
    {
        if( abs(Phi[i])<1.0){
            needProj2XOZ=false;
            break;
        }
    }
    for (uint i=0;i<Phi.size();i++)
    {
        if( abs(Phi[i]-90.0)<1.0){
            needProj2YOZ=false;
            break;
        }
    }



    double max_theta=0.0,cosTheta=1.0;
    double min_phi=0.0,sinPhi=0.0;
    double max_phi=0.0,cosPhi=0.0;


    //the node solutions of Lengendre are [cos(theta)*cos(theta)]
    vector <double> Theta;
    if (nodes_Theta>0) {
        for (uint i=0;i<nodes_Theta;i++) {
            double angle=acos(sqrt(getAO(0)->Nodes_T[i]))/3.141592654*180.0;
            Theta.push_back(angle);
        }
        sort(Theta.begin(), Theta.end());
    }


    if(Phi.size()>0) {
        min_phi=Phi[0];
        if (min_phi<1.0 && Phi.size()>1)
            min_phi=Phi[1];

        sinPhi=sin(min_phi*3.141592654/180.0);
    }

    if (needProj2YOZ)
        for (uint i=0;i<Phi.size();i++)
        {
            max_phi=Phi[i];
            if(max_phi>90.0)  {
                cosPhi=-cos(max_phi*3.141592654/180.0);
                break;
            }
        }

/*

    cout << "used min PHI :"<< min_phi <<endl;
    cout << "used max PHI :"<< max_phi <<endl;

    cout << " theta: -------------------"<<endl;
    for (uint i=0;i<Theta.size();i++)
        cout << Theta[i]<<endl;
    cout << " theta: -------------------"<<endl;


    cout << " phi: -------------------"<<endl;
    for (uint i=0;i<Phi.size();i++)
        cout << Phi[i]<<endl;
    cout << " phi: -------------------"<<endl;

*/
    if (Theta.size()==1) {
        max_theta=Theta[0];
        if (abs(max_theta-90.0) <1.0)
            needProj2XOY=false;
    }

    if (Theta.size()>1) {
        max_theta=Theta[Theta.size()-1];
        if (abs(max_theta-90.0) <1.0)
            needProj2XOY=false;
    }
    cosTheta=cos(max_theta*3.141592654/180.0);


    if(needProj2XOZ)
        cout << "needProj2XOZ"<<endl;
    else
        cout << "do not needProj2XOZ"<<endl;

    vector3 v;
    if(isPosYlmExisted())
        switch (orbital_type)
        {
        case  XOY :
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[2] < 0.0) continue;

                if(needProj2XOY)
                {
                    v.Set(p[0],p[1],p[2]); v.normalize();

                    //if(vectorAngle(v,VZ)<max_theta) {
                    if (dot (v,VZ) > cosTheta) { //remove this point
                        p[2]=0.0;   p[1]=0.0;  p[0]=0.0;
                    }
                    p[2]=0.0; //projection
                }
                else //remove this point
                { p[2]=0.0;    p[1]=0.0;  p[0]=0.0; }
                yData->GetPoints()->SetPoint(i,p);
            }
            break;


        case  XOZ :
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[1] < -0.01) continue;

                if(needProj2XOZ)
                {
                    v.Set(p[0],p[1],0.0);v.normalize();

                    //remove this point
                    if (v[1] > sinPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                    //projection
                    else    p[1]=0.0;
                }
                else { //remove this point
                    p[2]=0.0;    p[1]=0.0;  p[0]=0.0;
                }

                yData->GetPoints()->SetPoint(i,p);
            }
            break;

        case  YOZ :
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);

                if (p[0] < 0.0) continue;

                if(needProj2YOZ)
                {
                    v.Set(p[0],p[1],0.0);
                    v.normalize();

                    //cout << " needProj2YOZ "<<cosPhi<<endl;

                    //remove this point
                    if (v[0] > cosPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                    //projection
                    else  p[0]=0.0;
                }
                else { //remove this point
                    p[2]=0.0;
                    p[1]=0.0;
                    p[0]=0.0;
                }
                yData->GetPoints()->SetPoint(i,p);
            }
            break;

        case  Quarter : //Quarter=XOY+XOZ
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[2] < 0.0) continue;

                if(needProj2XOY)
                {
                    v.Set(p[0],p[1],p[2]); v.normalize();

                    //if(vectorAngle(v,VZ)<max_theta) {
                    if (dot (v,VZ) > cosTheta) { //remove this point
                        p[2]=0.0;   p[1]=0.0;  p[0]=0.0;
                    }
                    p[2]=0.0; //projection
                }
                else //remove this point
                { p[2]=0.0;    p[1]=0.0;  p[0]=0.0; }
                yData->GetPoints()->SetPoint(i,p);
            }

            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[1] < 0.0) continue;

                if(needProj2XOZ)
                {
                    v.Set(p[0],p[1],0.0);v.normalize();

                    //remove this point
                    if (v[1] > sinPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                    //projection
                    else    p[1]=0.0;
                }
                else { //remove this point
                    p[2]=0.0;    p[1]=0.0;  p[0]=0.0;
                }

                yData->GetPoints()->SetPoint(i,p);
            }
            break;

        case  Corner : //Corner=XOY+XOZ+YOZ
            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[2] < 0.0) continue;

                if(needProj2XOY)
                {
                    v.Set(p[0],p[1],p[2]); v.normalize();

                    //if(vectorAngle(v,VZ)<max_theta) {
                    if (dot (v,VZ) > cosTheta) { //remove this point
                        p[2]=0.0;   p[1]=0.0;  p[0]=0.0;
                    }
                    p[2]=0.0; //projection
                }
                else //remove this point
                { p[2]=0.0;    p[1]=0.0;  p[0]=0.0; }
                yData->GetPoints()->SetPoint(i,p);
            }

            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);
                if (p[1] < 0.0) continue;

                if(needProj2XOZ)
                {
                    v.Set(p[0],p[1],0.0);v.normalize();

                    //remove this point
                    if (v[1] > sinPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                    //projection
                    else    p[1]=0.0;
                }
                else { //remove this point
                    p[2]=0.0;    p[1]=0.0;  p[0]=0.0;
                }

                yData->GetPoints()->SetPoint(i,p);
            }

            for (int i=0;i<yData->GetNumberOfPoints();i++)
            {
                double * p = yData->GetPoint(i);

                if (p[0] < 0.0) continue;

                if(needProj2YOZ)
                {
                    v.Set(p[0],p[1],0.0);
                    v.normalize();

                    //cout << " needProj2YOZ "<<cosPhi<<endl;

                    //remove this point
                    if (v[0] > cosPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                    //projection
                    else  p[0]=0.0;
                }
                else { //remove this point
                    p[2]=0.0;
                    p[1]=0.0;
                    p[0]=0.0;
                }
                yData->GetPoints()->SetPoint(i,p);
            }
            break;
        }


     //--------------------------------------------------//
     if(isNegYlmExisted())
         switch (orbital_type) {

         case  XOY :
             for (int i=0;i<yData1->GetNumberOfPoints();i++)
             {
                 double * p = yData1->GetPoint(i);

                 if (p[2] < 0.0) continue;

                 if(needProj2XOY)
                 {
                     v.Set(p[0],p[1],p[2]);  v.normalize();

                     //remove this point which inside maximum-theta-node angle
                     if (dot (v,VZ) > cosTheta)  {p[2]=0.0; p[1]=0.0; p[0]=0.0; }

                     //projection
                     p[2]=0.0;
                 }
                 else //remove this point
                 { p[2]=0.0;    p[1]=0.0;  p[0]=0.0; }
                 yData1->GetPoints()->SetPoint(i,p);
             }

             break;

         case  XOZ :
             for (int i=0;i<yData1->GetNumberOfPoints();i++)
             {
                 double * p = yData1->GetPoint(i);
                 if (p[1] < 0.0) continue;

                 if(needProj2XOZ)
                 {
                     //remove this point
                     cout << "needProj2XOZ :  "<<sinPhi <<endl;
                     v.Set(p[0],p[1],0.0);v.normalize();

                     if (v[1] > sinPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                     //projection
                     else             p[1]=0.0;
                 }
                 else { //remove this point
                     p[2]=0.0;    p[1]=0.0;  p[0]=0.0;
                 }

                 yData1->GetPoints()->SetPoint(i,p);
             }
             break;

         case  YOZ :
             for (int i=0;i<yData1->GetNumberOfPoints();i++)
             {
                 double * p = yData1->GetPoint(i);

                 if (p[0] < 0.0) continue;

                 if(needProj2YOZ)
                 {
                     v.Set(p[0],p[1],0.0);  v.normalize();

                     //remove this point
                     if (v[0] > cosPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                     //projection
                     else  p[0]=0.0;
                 }
                 else { //remove this point
                     p[2]=0.0;
                     p[1]=0.0;
                     p[0]=0.0;
                 }
                 yData1->GetPoints()->SetPoint(i,p);
             }
             break;


         case  Quarter :
             for (int i=0;i<yData1->GetNumberOfPoints();i++)
             {
                 double * p = yData1->GetPoint(i);

                 if (p[2] < 0.0) continue;

                 if(needProj2XOY)
                 {
                     v.Set(p[0],p[1],p[2]);  v.normalize();

                     //remove this point which inside maximum-theta-node angle
                     if (dot (v,VZ) > cosTheta)  {p[2]=0.0; p[1]=0.0; p[0]=0.0; }

                     //projection
                     p[2]=0.0;
                 }
                 else //remove this point
                 { p[2]=0.0;    p[1]=0.0;  p[0]=0.0; }
                 yData1->GetPoints()->SetPoint(i,p);
             }
             for (int i=0;i<yData1->GetNumberOfPoints();i++)
             {
                 double * p = yData1->GetPoint(i);
                 if (p[1] < 0.0) continue;

                 if(needProj2XOZ)
                 {
                     //remove this point
                     //cout << "needProj2XOZ :  "<<sinPhi <<endl;
                     v.Set(p[0],p[1],0.0);v.normalize();

                     if (v[1] > sinPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                     //projection
                     else             p[1]=0.0;
                 }
                 else { //remove this point
                     p[2]=0.0;    p[1]=0.0;  p[0]=0.0;
                 }

                 yData1->GetPoints()->SetPoint(i,p);
             }
             break;

         case  Corner :
             for (int i=0;i<yData1->GetNumberOfPoints();i++)
             {
                 double * p = yData1->GetPoint(i);

                 if (p[2] < 0.0) continue;

                 if(needProj2XOY)
                 {
                     v.Set(p[0],p[1],p[2]);  v.normalize();

                     //remove this point which inside maximum-theta-node angle
                     if (dot (v,VZ) > cosTheta)  {p[2]=0.0; p[1]=0.0; p[0]=0.0; }

                     //projection
                     p[2]=0.0;
                 }
                 else //remove this point
                 { p[2]=0.0;    p[1]=0.0;  p[0]=0.0; }
                 yData1->GetPoints()->SetPoint(i,p);
             }

             for (int i=0;i<yData1->GetNumberOfPoints();i++)
             {
                 double * p = yData1->GetPoint(i);
                 if (p[1] < 0.0) continue;

                 if(needProj2XOZ)
                 {
                     //remove this point
                     cout << "needProj2XOZ :  "<<sinPhi <<endl;
                     v.Set(p[0],p[1],0.0);v.normalize();

                     if (v[1] > sinPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                     //projection
                     else             p[1]=0.0;
                 }
                 else { //remove this point
                     p[2]=0.0;    p[1]=0.0;  p[0]=0.0;
                 }

                 yData1->GetPoints()->SetPoint(i,p);
             }
             for (int i=0;i<yData1->GetNumberOfPoints();i++)
             {
                 double * p = yData1->GetPoint(i);

                 if (p[0] < 0.0) continue;

                 if(needProj2YOZ)
                 {
                     v.Set(p[0],p[1],0.0);  v.normalize();

                     //remove this point
                     if (v[0] > cosPhi)   {p[2]=0.0;  p[1]=0.0;  p[0]=0.0; }

                     //projection
                     else  p[0]=0.0;
                 }
                 else { //remove this point
                     p[2]=0.0;
                     p[1]=0.0;
                     p[0]=0.0;
                 }
                 yData1->GetPoints()->SetPoint(i,p);
             }
             break;
         }


     if(isPosYlmExisted()) {
         auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
         cleanFilter->AddInputData(yData);
         cleanFilter->Update();
         yData->DeepCopy(cleanFilter->GetOutput());
     }

     if(isNegYlmExisted()) {
         auto cleanFilter1 =  vtkSmartPointer<vtkCleanPolyData>::New();
         cleanFilter1->AddInputData(yData1);
         cleanFilter1->Update();
         yData1->DeepCopy(cleanFilter1->GetOutput());
     }

}






double HMO::calc_Psi  (double x, double y, double z)
{
    vector3 pos(x,y,z);
    return calc_Psi(pos);
}


double HMO::calc_Psi(vector3 pos)
{
    Psi=0.0;
    for (int i=0;i<AOs.size();i++)
    {
        if (isHybridizedOrbital || isMolecularOrbital)
            Psi+=AOs[i]->Slater_Psi(pos);
        else {
            if(isCoulombSturmianOrbital)
                Psi+=AOs[i]->Coulomb_Sturmian_Psi(pos);
            else
                Psi+=AOs[i]->Hydrogen_Psi(pos);
        }
    }
    return Psi;
}




void HMO::buildCloudPoints(long int NP)
{
    NP=80000;
    vector3 p;
    double Psi, probability;
    double *randnum=new double[NP*3+10]; 
    double x,y,z;
    double *randnumP=new double[NP];
    int   i=0, m=0;
    



    for(long int i=0;i<NP*3+10;i++)
	{
    static std::default_random_engine e(time(NULL));
    static std::uniform_real_distribution<double> u(0., 2.);
    randnum[i]= u(e);
    }

    for(long int i=0;i<NP;i++)
	{
    static std::default_random_engine e(time(NULL));
    static std::uniform_real_distribution<double> u(0., 1.);
    randnumP[i]= u(e);
    }

    //no data existed
    if( cloudPoints_pos.size()<20 && cloudPoints_neg.size()<20)
    {
        cloudPoints_pos.clear();
        cloudPoints_neg.clear();
        long int i=0;
		while (NP--)
        {
            //-maxBox<----->maxBox
           
            p.Set((maxBox/1.2)*(randnum[i++]-1.0),(maxBox/1.2)*(randnum[i++]-1.0),(maxBox/1.2)*(randnum[i++]-1.0));
            Psi=AOs[0]->Hydrogen_Psi(p);
            probability=(fabs(Psi))/(MaxPsi);
            //skip
            if(probability<randnumP[NP]||probability<0.01)  continue;

            //cout <<NP<<" "<< p.x()<<" "<<  p.y()<<"  "<< p.z()<<":  "<<probability<<" < "<<Psi<< endl;

            if (Psi>0.0)
                cloudPoints_pos.push_back(p);
            if (Psi<0.0)
                cloudPoints_neg.push_back(p);
        }
    }

    cout << "\n\nnumber of random points: "<<endl;
    cout << cloudPoints_pos.size()<<endl;
    cout << cloudPoints_neg.size()<<endl;
    cout << "---------------------------"<<endl;






    auto  points0 =vtkSmartPointer<vtkPoints>::New();
    auto  points1 =vtkSmartPointer<vtkPoints>::New();



    switch (orbital_type)
    {
    case FULL:
        for (int i=0;i<cloudPoints_pos.size();i++)
        {
            points0->InsertNextPoint(cloudPoints_pos[i][0],
                                     cloudPoints_pos[i][1],
                                     cloudPoints_pos[i][2]);
        }

        for (int i=0;i<cloudPoints_neg.size();i++)
        {
            points1->InsertNextPoint(cloudPoints_neg[i][0],
                                     cloudPoints_neg[i][1],
                                     cloudPoints_neg[i][2]);
        }
        break;

    case  XOY :
        for (int i=0;i<cloudPoints_pos.size();i++)
        {
            if (cloudPoints_pos[i][2] > 0.0)
                continue;
            points0->InsertNextPoint(cloudPoints_pos[i][0],
                                     cloudPoints_pos[i][1],
                                     cloudPoints_pos[i][2]);
        }

        for (int i=0;i<cloudPoints_neg.size();i++)
        {
            if (cloudPoints_neg[i][2] > 0.0)
                continue;
            points1->InsertNextPoint(cloudPoints_neg[i][0],
                                     cloudPoints_neg[i][1],
                                     cloudPoints_neg[i][2]);
        }
        break;

    case  YOZ :
        for (int i=0;i<cloudPoints_pos.size();i++)
        {
            if (cloudPoints_pos[i][0] > 0.0)
                continue;
            points0->InsertNextPoint(cloudPoints_pos[i][0],
                                     cloudPoints_pos[i][1],
                                     cloudPoints_pos[i][2]);
        }

        for (int i=0;i<cloudPoints_neg.size();i++)
        {
            if (cloudPoints_neg[i][0] > 0.0)
                continue;
            points1->InsertNextPoint(cloudPoints_neg[i][0],
                                   cloudPoints_neg[i][1],
                                   cloudPoints_neg[i][2]);
        }
        break;

    case  XOZ :
        for (int i=0;i<cloudPoints_pos.size();i++)
        {
            if (cloudPoints_pos[i][1] > 0.0)
                continue;
            points0->InsertNextPoint(cloudPoints_pos[i][0],
                                   cloudPoints_pos[i][1],
                                   cloudPoints_pos[i][2]);
        }

        for (int i=0;i<cloudPoints_neg.size();i++)
        {
            if (cloudPoints_neg[i][1] > 0.0)
                continue;
            points1->InsertNextPoint(cloudPoints_neg[i][0],
                                   cloudPoints_neg[i][1],
                                   cloudPoints_neg[i][2]);
        }
        break;

    case  Quarter : //remove y>0, z>0
        for (int i=0;i<cloudPoints_pos.size();i++)
        {
            if (cloudPoints_pos[i][1] > 0.0)
                continue;
            if (cloudPoints_pos[i][2] > 0.0)
                continue;
            points0->InsertNextPoint(cloudPoints_pos[i][0],
                                   cloudPoints_pos[i][1],
                                   cloudPoints_pos[i][2]);
        }

        for (int i=0;i<cloudPoints_neg.size();i++)
        {
            if (cloudPoints_neg[i][1] > 0.0)
                continue;
            if (cloudPoints_neg[i][2] > 0.0)
                continue;
            points1->InsertNextPoint(cloudPoints_neg[i][0],
                                     cloudPoints_neg[i][1],
                                     cloudPoints_neg[i][2]);
        }
        break;

    case  Corner : //remove x<0, y>0 , z>0
        for (int i=0;i<cloudPoints_pos.size();i++)
        {
            if (cloudPoints_pos[i][0] < 0.0)
                continue;
            if (cloudPoints_pos[i][1] > 0.0)
                continue;
            if (cloudPoints_pos[i][2] > 0.0)
                continue;

            points0->InsertNextPoint(  cloudPoints_pos[i][0],
                                       cloudPoints_pos[i][1],
                                       cloudPoints_pos[i][2]);
        }

        for (int i=0;i<cloudPoints_neg.size();i++)
        {
            if (cloudPoints_neg[i][0] < 0.0)
                continue;
            if (cloudPoints_neg[i][1] > 0.0)
                continue;
            if (cloudPoints_neg[i][2] > 0.0)
                continue;

            points1->InsertNextPoint(cloudPoints_neg[i][0],
                                     cloudPoints_neg[i][1],
                                     cloudPoints_neg[i][2]);
        }
        break;

    case  Wedge :
        for (int i=0;i<cloudPoints_pos.size();i++)
        {

            if (cloudPoints_pos[i][1] > 0.0 && cloudPoints_pos[i][2] > 0.0 )
                continue;

            points0->InsertNextPoint(cloudPoints_pos[i][0],
                                   cloudPoints_pos[i][1],
                                   cloudPoints_pos[i][2]);
        }

        for (int i=0;i<cloudPoints_neg.size();i++)
        {
            if (cloudPoints_neg[i][1] > 0.0 && cloudPoints_neg[i][2] > 0.0 )
                continue;
            points1->InsertNextPoint(cloudPoints_neg[i][0],
                                     cloudPoints_neg[i][1],
                                     cloudPoints_neg[i][2]);
        }
        break;
    }


    glyphFilter_pos = vtkSmartPointer<vtkVertexGlyphFilter>::New();
    glyphFilter_neg = vtkSmartPointer<vtkVertexGlyphFilter>::New();

    if(cloudPoints_pos.size()>20)
    {
        auto data0= vtkSmartPointer<vtkPolyData>::New();
        data0->SetPoints(points0);

        //cout << data0->GetNumberOfPoints()<<" inside if(cloudPoints_pos.size()>20)"<< endl;

        glyphFilter_pos->SetInputData(data0);
        glyphFilter_pos->Update();
    }

    if(cloudPoints_neg.size()>20)
    {
        auto data1=vtkSmartPointer<vtkPolyData>::New();
        data1->SetPoints(points1);

        glyphFilter_neg->SetInputData(data1);
        glyphFilter_neg->Update();
    }



 }





void HMO::clear()
{
    cout <<"-----------------------------"<<endl;
    cout << "Cleaning HMO begins..."<<endl;

    visible_pos_Lobe_Mesh=true;
    visible_neg_Lobe_Mesh=true;
    orbital_type=FULL;


    if (dataXOY.size()>0) {
        for (uint i=0;i<dataXOY.size();i++)
            dataXOY[i].clear();
        dataXOY.clear();
        cout << "dataXOY  are done!"<<endl;
    }

    if (dataXOZ.size()>0) {
        for (uint i=0;i<dataXOZ.size();i++)
            dataXOZ[i].clear();
        dataYOZ.clear();
        cout << "dataYOZ  are done!"<<endl;
    }

    if (dataXOZ.size()>0) {
        for (uint i=0;i<dataYOZ.size();i++)
            dataYOZ[i].clear();
        dataXOZ.clear();
        cout << "dataXOZ  are done!"<<endl;
    }

   uint size=AOs.size();
   if (size>0) {
       while (size--) {
           if (AOs[size]!=nullptr)
               delete AOs[size];
       }
       AOs.clear();
       cout << "AOs  are done!"<<endl;
   }

   if (RData.size()+R2Data.size() + RDFData.size()>0) {
       if (RData.size()>0)  RData.clear();
       if (R2Data.size()>0)  R2Data.clear();
       if (RDFData.size()>0)  RDFData.clear();
       cout << "RData  is done!"<<endl;
   }

  if (pData)   {
      pData=vtkPolyData::New();
      pData->Delete();
      pData=nullptr;
      cout << "pData  is done!"<<endl;
  }

  if (pData1)   {
      pData1=vtkPolyData::New();
      pData1->Delete();
      pData1=nullptr;
      cout << "pData1  is done!"<<endl;

  }

  if (yData)   {
      yData=vtkPolyData::New();
      yData->Delete();
      yData=nullptr;
      cout << "yData  is done!"<<endl;
  }

  if (yData1)   {
      yData1=vtkPolyData::New();
      yData1->Delete();
      yData1=nullptr;
      cout << "yData1  is done!"<<endl;
  }


  if (ylmData)   {
      ylmData=vtkPolyData::New();
      ylmData->Delete();
      ylmData=nullptr;
      cout << "ylm-Data  is done!"<<endl;
  }

  if (ylmData1)   {
      ylmData1=vtkPolyData::New();
      ylmData1->Delete();
      ylmData1=nullptr;
      cout << "ylm-Data1  is done!"<<endl;
  }





   if (surfaceMC0) {
       surfaceMC0=vtkSmartPointer<vtkMarchingCubes>::New();
       surfaceMC0->Delete();
       //surfaceMC0=nullptr;
       cout << "surfaceMC0  is done!"<<endl;
   }


   if (surfaceMC1) {
       surfaceMC1=vtkSmartPointer<vtkMarchingCubes>::New();
       surfaceMC1->Delete();
       //surfaceMC1=nullptr;
       cout << "surfaceMC1  is done!"<<endl;
   }


   if (Surface_MC_Zero) {
       Surface_MC_Zero=vtkSmartPointer<vtkMarchingCubes>::New();
       Surface_MC_Zero->Delete();
       //Surface_MC_Zero=nullptr;
       cout << "Surface_MC_Zero  is done!"<<endl;
   }


   cout << "surfaceMC is done!"<<endl;

   if (surfaceFE0) {
       surfaceFE0=vtkSmartPointer<vtkFlyingEdges3D>::New();
       surfaceFE0->Delete();
       //surfaceFE0=nullptr;

       cout << "surfaceFE0 is done!"<<endl;
   }


   if (surfaceFE1) {
       surfaceFE1=vtkSmartPointer<vtkFlyingEdges3D>::New();
       surfaceFE1->Delete();
       //surfaceFE1=nullptr;
       cout << "surfaceFE1 is done!"<<endl;
   }


   if (Surface_FE_Zero) {
       Surface_FE_Zero=vtkSmartPointer<vtkFlyingEdges3D>::New();
       Surface_FE_Zero->Delete();
       //Surface_FE_Zero=nullptr;
       cout << "Surface_FE_Zero is done!"<<endl;
   }



    //Psi
   if (CubeDataXOY)     {delete CubeDataXOY;CubeDataXOY=nullptr;}
   if (CubeDataXOZ)     {delete CubeDataXOZ;CubeDataXOZ=nullptr;}
   if (CubeDataYOZ)     {delete CubeDataYOZ;CubeDataYOZ=nullptr;}
   if (CubeDataWedge)   {delete CubeDataWedge;CubeDataWedge=nullptr;}
   if (CubeDataQuarter) {delete CubeDataQuarter;CubeDataQuarter=nullptr;}
   if (CubeDataCorner)  {delete CubeDataCorner;CubeDataCorner=nullptr;}

   if (CubeDataQuarter1) {delete CubeDataQuarter1;CubeDataQuarter1=nullptr;}
   if (CubeDataQuarter2) {delete CubeDataQuarter2;CubeDataQuarter2=nullptr;}





   proj_scale=2;

   cout << "CubeData is done!"<<endl;
   cout <<"-----------------------------"<<endl;
}

void HMO::sendMessage(QString message)
{
    if (!m_parent || m_parent==nullptr) return;
    ((MainWindow *) m_parent)->sendMessage(message);
}

void HMO::appendMessage(QString  message)
{
    if (!m_parent || m_parent==nullptr) return;
    ((MainWindow *) m_parent)->appendMessage(message);
}



void HMO::buildCubeData()
{
    if (isCubeDataOK) return;

    uint n = getAO(0)->n;
    uint m = getAO(0)->m;

    bool hasNodesBuild=getAO(0)->hasNodesBuild;
    uint NumRadialNodes=getAO(0)->Nodes_R.size();


    if (n>=7 ) {
        isoValue=0.0001;
        maxBox=220.0; //200
        NPoints=120;
        if (NumRadialNodes<1)
            NPoints=60;
    }


    switch (n)
    {
    case 6:
        isoValue=0.0005;
        maxBox=180.0;
        NPoints=120;
        if (NumRadialNodes<1)    NPoints=80;
        break;

    case 5:
        isoValue=0.001;
        maxBox=150.0;
        NPoints=120;
        if (NumRadialNodes<1)   NPoints=80;

        break;

    case 4:
        isoValue=0.002;
        maxBox=90.0;
        NPoints=120;
        if (NumRadialNodes<1) NPoints=60;
        break;

    case 3:
        isoValue=0.006;
        maxBox=40.0;
        NPoints=100;
        if (NumRadialNodes<1) NPoints=60;
        break;

    case 2:
        isoValue=0.01;
        maxBox=50.0;
        NPoints=100;
        break;

    case 1:
        isoValue=0.05;
        maxBox=5.0;
        NPoints=50;
        break;
    }

    int Nx=NPoints,Ny=NPoints,Nz=NPoints;
    int N=NPoints;


    //find the smallest r
    double r=0;
    if (this->NumAOs()<2){
        r=this->getAO(0)->calc_least_r(isoValue/5.0);
    }

    //cout << "the least r is "<<r <<" inside buildCubeData()"<<endl;

    //5G4,6G4
    if (n==5 && m==0) {
        //isoValue=0.001;
        r=r*1.5;
    }


    //cout << "the least r is "<<r <<" inside buildCubeData()"<<endl;


    if (r>1.0) maxBox=floor(r);
    minBox=-maxBox;


/*
    cout << "the least r is "<<r <<" inside buildCubeData()"<<endl;
    cout << "default :"<<endl;
    cout << " "<< maxBox<<  " "<< minBox<< " " <<isoValue<< endl;

    maxBox=r;
    minBox=-r;
    isoValue=isov*2.0;

    cout << "modified :"<<endl;
    cout << " "<< maxBox<<  " "<< minBox<< " " <<isoValue<< endl;
*/

    //includes (0,0,0), and do not jump over
    interval=(maxBox-minBox)/N;
    maxBox=interval*N/2.0;

    minBox=-maxBox;

    int x,y,z;
    double  x0=minBox,
            y0=minBox,
            z0=minBox;


    sendMessage("Building cube data ... ");
    sendMessage(QString("dim:     %1*%1*%1").arg(N));
    sendMessage(QString("range:   %1   %2").arg(minBox).arg(maxBox));
    sendMessage(QString("interval:  %1").arg(interval));
    sendMessage(QString("interval:  %1").arg(isoValue));



    cout << "\nbuilding cube data  " <<endl;
    cout << "dim: " <<N <<endl;
    cout << "range: " <<minBox  <<" " << maxBox<< endl;
    cout << "interval: " <<interval  << endl;
    cout << "isovalue: " <<isoValue  << endl<< endl;


    if (CubeData || CubeData!=nullptr ) {
        delete CubeData;
        CubeData=nullptr;
    }
    CubeData = new double [Nx*Ny*Nz];

    //calculate Psi
    double psi=0.0,sum=0.0, psi2=0.0;

#pragma omp parallel for
    for( z=0; z < Nz ; z++)
        for( y=0; y < Ny;  y++)
            for( x=0; x < Nx;  x++){
                psi=calc_Psi(x0+interval*x,y0+interval*y , z0+interval*z);
                //psi2=psi*psi;
                //sum += psi2;
                if(MaxPsi<fabs(psi)) MaxPsi=fabs(psi); 
                //if  (psi>0.0)     CubeData[(z*N+y)*N+x]=psi2;
                //else              CubeData[(z*N+y)*N+x]=-psi2;
                
                CubeData[(z*N+y)*N+x]=psi;
            }


    /*
    sum=sum/(Nx*Ny*Nz);
    //normalize
    for( z=0; z < Nz;  z++){
        for( y=0; y < Ny;  y++){
            for( x=0; x < Nx;  x++){
                psi=CubeData[(z*N+y)*N+x];
                CubeData[(z*N+y)*N+x]=psi/sum;
            }
        }
    }
*/




    //dispose five kinds of data
    if (CubeDataXOY || CubeDataXOY!=nullptr) {
        delete CubeDataXOY;
    }

    if (CubeDataXOZ || CubeDataXOZ!=nullptr) {
         delete CubeDataXOZ;
    }

    if (CubeDataYOZ || CubeDataYOZ!=nullptr) {
         delete CubeDataYOZ;
    }

    if (CubeDataWedge || CubeDataWedge!=nullptr) {
         delete CubeDataWedge;
    }

    if (CubeDataQuarter || CubeDataQuarter!=nullptr) {
         delete CubeDataQuarter;
    }

    if (CubeDataQuarter1 || CubeDataQuarter1!=nullptr) {
         delete CubeDataQuarter1;
    }

    if (CubeDataQuarter2 || CubeDataQuarter2!=nullptr) {
         delete CubeDataQuarter2;
    }

    if (CubeDataCorner || CubeDataCorner!=nullptr) {
         delete CubeDataCorner;
    }




    CubeDataXOY= new double [Nx*Ny*Nz];
    CubeDataXOZ= new double [Nx*Ny*Nz];
    CubeDataYOZ= new double [Nx*Ny*Nz];

    CubeDataWedge= new double [Nx*Ny*Nz];
    CubeDataQuarter= new double [Nx*Ny*Nz];
    CubeDataCorner= new double [Nx*Ny*Nz];

    CubeDataQuarter1= new double [Nx*Ny*Nz];
    CubeDataQuarter2= new double [Nx*Ny*Nz];



    //a[M][N][P],  a[m][n][p]， a[(m*N+n)*P+p]
    //a[Nz][Ny][Nx],a[z][y][x], a[(z*Ny+y)*Nx+x]

    double d=0.0;


#pragma omp parallel for
    for( z=0; z < Nz;  z++){
        for( y=0; y < Ny;  y++){
            for( x=0; x < Nx;  x++)
            {
                d=CubeData[(z*Ny+y)*Nx+x];
                CubeDataXOY[(z*Ny+y)*Nx+x]=d;
                if (z0+interval*z > 0.0)
                    CubeDataXOY[(z*Ny+y)*Nx+x]=0.0;

                CubeDataYOZ[(z*Ny+y)*Nx+x]=d;
                if (x0+interval*x > 0.0)
                    CubeDataYOZ[(z*Ny+y)*Nx+x]=0.0;

                CubeDataXOZ[(z*Ny+y)*Nx+x]=d;
                if (y0+interval*y > 0.0)
                    CubeDataXOZ[(z*Ny+y)*Nx+x]=0.0;

/*
                CubeDataWedge[(z*Ny+y)*Nx+x]=d;
                if ( (y0+interval*y > 0.0)  &&  (z0+interval*z > 0.0) )
                    CubeDataWedge[(z*Ny+y)*Nx+x]=0.0;
*/
                //z<0 and y<0;
                CubeDataQuarter[(z*Ny+y)*Nx+x]=d;
                if ( (z0+interval*z > 0.0)  )
                    CubeDataQuarter[(z*Ny+y)*Nx+x]=0.0;
                if ( (y0+interval*y > 0.0)  )
                    CubeDataQuarter[(z*Ny+y)*Nx+x]=0.0;

                //z<0 and y>0;
                CubeDataQuarter1[(z*Ny+y)*Nx+x]=d;
                if ( (z0+interval*z > 0.0)  )
                    CubeDataQuarter1[(z*Ny+y)*Nx+x]=0.0;
                if ( (y0+interval*y < 0.0)  )
                    CubeDataQuarter1[(z*Ny+y)*Nx+x]=0.0;


                //z>0 and y>0;
                CubeDataQuarter2[(z*Ny+y)*Nx+x]=d;
                if ( (z0+interval*z < 0.0)  )
                    CubeDataQuarter2[(z*Ny+y)*Nx+x]=0.0;
                if ( (y0+interval*y < 0.0)  )
                    CubeDataQuarter2[(z*Ny+y)*Nx+x]=0.0;

                CubeDataCorner[(z*Ny+y)*Nx+x]=d;
                if ( (x0+interval*x > 0.0)  )
                    CubeDataCorner[(z*Ny+y)*Nx+x]=0.0;
                if ( (z0+interval*z > 0.0)  )
                    CubeDataCorner[(z*Ny+y)*Nx+x]=0.0;
                if ( (y0+interval*y > 0.0)  )
                    CubeDataCorner[(z*Ny+y)*Nx+x]=0.0;
            }
        }
    } 

    isCubeDataOK=true;
    appendMessage("OK!");
    cout << "building Cube Data OK!"<<endl;
}





void HMO::ExtractIsosurface(vtkImageData * volume0, vtkImageData * volume1)
{
    //extractIsoSurfMethod=FlyingEdge;
    extractIsoSurfMethod=MarchingCube;

    switch (extractIsoSurfMethod)
    {
    case MarchingCube:
        sendMessage("Extract isosurface based on MarchingCube algorithms...");

        //positlve lobe
        surfaceMC0 = vtkSmartPointer<vtkMarchingCubes>::New();
        surfaceMC0->SetInputData(volume0);
        surfaceMC0->SetValue(0, isoValue);

        surfaceMC0->ComputeNormalsOn();
        //MoSurface_positive->ComputeGradientsOn();
        //MoSurface_positive->ComputeScalarsOn();
        surfaceMC0->Update();

        pData=vtkPolyData::New();
        pData=surfaceMC0->GetOutput();
        //MoSurface_positive->Delete();

        //negative
        surfaceMC1 = vtkSmartPointer<vtkMarchingCubes>::New();
        surfaceMC1->SetInputData(volume1);
        surfaceMC1->SetValue(0, isoValue);


        surfaceMC1->ComputeNormalsOn();
        //MoSurface_positive->ComputeGradientsOn();
        //MoSurface_positive->ComputeScalarsOn();
        surfaceMC1->Update();

        pData1=vtkPolyData::New();
        pData1=surfaceMC1->GetOutput();
        //MoSurface_positive->Delete();


        /*
        Surface_MC_Zero=vtkSmartPointer<vtkMarchingCubes>::New();
        Surface_MC_Zero->New();
        Surface_MC_Zero->SetInputData(volume0);
        Surface_MC_Zero->ComputeNormalsOn();
        Surface_MC_Zero->SetValue(0, 0.0);
        Surface_MC_Zero->ComputeGradientsOn();
        Surface_MC_Zero->ComputeScalarsOn();
        Surface_MC_Zero->Update();
        pData0=Surface_MC_Zero->GetOutput();
        */
        break;

    case FlyingEdge:
        sendMessage("Extract isosurface based on FlyingEdge algorithms...");
        //positive
        surfaceFE0 = vtkSmartPointer<vtkFlyingEdges3D>::New();
        surfaceFE0->SetInputData(volume0);

        surfaceFE0->ComputeNormalsOn();
        surfaceFE0->SetValue(0, isoValue);
        surfaceFE0->ComputeGradientsOn();
        surfaceFE0->ComputeScalarsOn();
        surfaceFE0->Update();
        pData=surfaceFE0->GetOutput();


        //negative
        surfaceFE1 = vtkSmartPointer<vtkFlyingEdges3D>::New();
        surfaceFE1->SetInputData(volume1);

        surfaceFE1->ComputeNormalsOn();
        surfaceFE1->SetValue(0, isoValue);
        surfaceFE1->ComputeGradientsOn();
        surfaceFE1->ComputeScalarsOn();
        surfaceFE1->Update();
        pData1=surfaceFE1->GetOutput();

        /*
        Surface_FE_Zero=vtkSmartPointer<vtkFlyingEdges3D>::New();
        Surface_FE_Zero->New();
        Surface_FE_Zero->SetInputData(volume0);
        Surface_FE_Zero->ComputeNormalsOn();
        Surface_FE_Zero->SetValue(0, 0.0);
        Surface_FE_Zero->ComputeGradientsOn();
        Surface_FE_Zero->ComputeScalarsOn();
        Surface_FE_Zero->Update();
        pData0=Surface_FE_Zero->GetOutput();
        */
        break;

    case  MarchingTetrahedra:
        break;

    case  DualContouring:
        sendMessage("Extract isosurface based on DualContouring algorithms...");
        break;

    case  DiscretekdHierachy:
        sendMessage("Extract isosurface based on Discrete k-d Hierachy algorithms...");
        break;
    }

    appendMessage("OK!");
}



//method1
void HMO::buildWedgeIsosurface1()
{
    int dim=NPoints;
    interval=(maxBox-minBox)/dim;

    vtkImageData * volume0 = vtkImageData::New();
    volume0->SetDimensions(dim,dim,dim);
    volume0->SetSpacing(interval, interval,interval);
    volume0->AllocateScalars(VTK_DOUBLE,1);
    volume0->SetOrigin(-maxBox,-maxBox,-maxBox);
    volume0->Modified();

    vtkImageData * volume1 = vtkImageData::New();
    volume1->SetDimensions(dim,dim,dim);
    volume1->SetSpacing(interval, interval,interval);
    volume1->AllocateScalars(VTK_DOUBLE,1);
    volume1->SetOrigin(-maxBox,-maxBox,-maxBox);
    volume1->Modified();


#pragma omp parallel for
    for(int z=0; z < dim;  z++)
        for(int y=0; y < dim;  y++)
            for(int x=0; x < dim;  x++)
            {
                double * d = static_cast<double*>(volume0->GetScalarPointer(x,y,z));
                double * d1 = static_cast<double*>(volume1->GetScalarPointer(x,y,z));
                d[0]=CubeDataXOY[(z*dim+y)*dim+x];
                d1[0]=-CubeDataXOY[(z*dim+y)*dim+x];
            }


    ExtractIsosurface(volume0, volume1);

#pragma omp parallel for
    for (int i=0;i<pData->GetNumberOfPoints();i++)
    {
        double * p = pData->GetPoint(i);
        if (p[2] < 0.0) continue;
        p[2]=0.0;
        pData->GetPoints()->SetPoint(i,p);
    }
    auto appendFilter = vtkSmartPointer<vtkAppendPolyData>::New();
    appendFilter->AddInputData(pData);


 #pragma omp parallel for
    for (int i=0;i<pData1->GetNumberOfPoints();i++)
    {
        double * p = pData1->GetPoint(i);
        if (p[2] < 0.0) continue;
        p[2]=0.0;
        pData1->GetPoints()->SetPoint(i,p);
    }

    auto appendFilter1 = vtkSmartPointer<vtkAppendPolyData>::New();
    appendFilter1->AddInputData(pData1);


#pragma omp parallel for
    for(int z=0; z < dim;  z++)
        for(int y=0; y < dim;  y++)
            for(int x=0; x < dim;  x++)
            {
                double * d = static_cast<double*>(volume0->GetScalarPointer(x,y,z));
                double * d1 = static_cast<double*>(volume1->GetScalarPointer(x,y,z));
                d[0]=CubeDataXOZ[(z*dim+y)*dim+x];
                d1[0]=-CubeDataXOZ[(z*dim+y)*dim+x];
            }


    ExtractIsosurface(volume0, volume1);
#pragma omp parallel for
    for (int i=0;i<pData->GetNumberOfPoints();i++)
    {
        double * p = pData->GetPoint(i);
        if (p[1] < 0.0) continue;
        p[1]=0.0;
        pData->GetPoints()->SetPoint(i,p);
    }
    appendFilter->AddInputData(pData);
    appendFilter->Update();

#pragma omp parallel for
    for (int i=0;i<pData1->GetNumberOfPoints();i++)
    {
        double * p = pData1->GetPoint(i);
        if (p[1] < 0.0) continue;
        p[1]=0.0;
        pData1->GetPoints()->SetPoint(i,p);
    }
    appendFilter1->AddInputData(pData1);
    appendFilter1->Update();


    auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
    cleanFilter->SetInputConnection(appendFilter->GetOutputPort());
    //cleanFilter->SetTolerance(0.01);
    cleanFilter->Update();


    auto cleanFilter1 =  vtkSmartPointer<vtkCleanPolyData>::New();
    cleanFilter1->SetInputConnection(appendFilter1->GetOutputPort());
    //cleanFilter->SetTolerance(0.01);
    cleanFilter1->Update();


    pData->DeepCopy(cleanFilter->GetOutput());
    pData1->DeepCopy(cleanFilter1->GetOutput());
}


//method2, also not good
void HMO::buildWedgeIsosurface()
{
    int dim=NPoints;
    interval=(maxBox-minBox)/dim;

    vtkImageData * volume0 = vtkImageData::New();
    volume0->SetDimensions(dim,dim,dim);
    volume0->SetSpacing(interval, interval,interval);
    volume0->AllocateScalars(VTK_DOUBLE,1);
    volume0->SetOrigin(-maxBox,-maxBox,-maxBox);
    volume0->Modified();

    vtkImageData * volume1 = vtkImageData::New();
    volume1->SetDimensions(dim,dim,dim);
    volume1->SetSpacing(interval, interval,interval);
    volume1->AllocateScalars(VTK_DOUBLE,1);
    volume1->SetOrigin(-maxBox,-maxBox,-maxBox);
    volume1->Modified();

    //build XOY ------------------------------------------------------------------
#pragma omp parallel for
    for(int z=0; z < dim;  z++)
#pragma omp parallel for
        for(int y=0; y < dim;  y++)
#pragma omp parallel for
            for(int x=0; x < dim;  x++)
            {
                double * d = static_cast<double*>(volume0->GetScalarPointer(x,y,z));
                double * d1 = static_cast<double*>(volume1->GetScalarPointer(x,y,z));
                d[0]=CubeDataXOY[(z*dim+y)*dim+x];
                d1[0]=-CubeDataXOY[(z*dim+y)*dim+x];
            }
    ExtractIsosurface(volume0, volume1);

    //adjust manually
#pragma omp parallel for
    for (int i=0;i<pData->GetNumberOfPoints();i++)
    {
        double * p = pData->GetPoint(i);
        if (p[2] > 0.0) {
            p[2]=0.0;
            pData->GetPoints()->SetPoint(i,p);
        }
    }

#pragma omp parallel for
    for (int i=0;i<pData1->GetNumberOfPoints();i++)
    {
        double * p = pData1->GetPoint(i);
        if (p[2] > 0.0) {
            p[2]=0.0;
            pData1->GetPoints()->SetPoint(i,p);
        }
    }




    //cut
    auto  planeYZ  =   vtkSmartPointer<vtkPlane>::New();
    planeYZ->SetOrigin(0, 0, 0);
    planeYZ->SetNormal(0, 1, 0);

    auto clipperYZ =vtkSmartPointer<vtkClipPolyData>::New();
    clipperYZ->SetInputData(pData);
    clipperYZ->SetClipFunction(planeYZ);
    clipperYZ->GenerateClipScalarsOn();
    clipperYZ->GenerateClippedOutputOn();
    //clipperYZ->SetValue(0.0);
    clipperYZ->Update();


    //dispose negative data
    auto clipperYZ1 =vtkSmartPointer<vtkClipPolyData>::New();
    clipperYZ1->SetInputData(pData1);
    clipperYZ1->SetClipFunction(planeYZ);
    clipperYZ1->GenerateClipScalarsOn();
    clipperYZ1->GenerateClippedOutputOn();
    //clipperYZ1->SetValue(0.0);
    clipperYZ1->Update();


    //store
    auto data1_p =  vtkSmartPointer<vtkPolyData>::New();
    auto data1_n =  vtkSmartPointer<vtkPolyData>::New();
    data1_p->DeepCopy(clipperYZ->GetOutput());
    data1_n->DeepCopy(clipperYZ1->GetOutput());




    //build XOZ ------------------------------------------------------------------
#pragma omp parallel
    #pragma omp for
    for(int z=0; z < dim;  z++)
#pragma omp parallel
        #pragma omp for
        for(int y=0; y < dim;  y++)
#pragma omp parallel
            #pragma omp for
            for(int x=0; x < dim;  x++)
            {
                double * d = static_cast<double*>(volume0->GetScalarPointer(x,y,z));
                double * d1 = static_cast<double*>(volume1->GetScalarPointer(x,y,z));
                d[0]=CubeDataXOZ[(z*dim+y)*dim+x];
                d1[0]=-CubeDataXOZ[(z*dim+y)*dim+x];
            }

    ExtractIsosurface(volume0, volume1);


    //adjust
#pragma omp parallel
    #pragma omp for
    for (int i=0;i<pData->GetNumberOfPoints();i++)
    {
        double * p = pData->GetPoint(i);
        if (p[1] > 0.0) {
            p[1]=0.0;
            pData->GetPoints()->SetPoint(i,p);
        }
    }

#pragma omp parallel
    #pragma omp for
    for (int i=0;i<pData1->GetNumberOfPoints();i++)
    {
        double * p = pData1->GetPoint(i);
        if (p[1] > 0.0) {
            p[1]=0.0;
            pData1->GetPoints()->SetPoint(i,p);
        }
    }


    //cut
    auto  planeXY  =   vtkSmartPointer<vtkPlane>::New();
    planeXY->SetOrigin(0, 0, 0);
    planeXY->SetNormal(0, 0, 1);


    auto clipperXY =vtkSmartPointer<vtkClipPolyData>::New();
    clipperXY->SetInputData(pData);
    clipperXY->SetClipFunction(planeXY);
    clipperXY->GenerateClipScalarsOn();
    clipperXY->GenerateClippedOutputOn();
    clipperXY->Update();

    //dispose negative data
    auto clipperXY1 =vtkSmartPointer<vtkClipPolyData>::New();
    clipperXY1->SetInputData(pData1);
    clipperXY1->SetClipFunction(planeXY);
    clipperXY1->GenerateClipScalarsOn();
    clipperXY1->GenerateClippedOutputOn();
    clipperXY1->Update();



    //store
    auto data2_p =  vtkSmartPointer<vtkPolyData>::New();
    auto data2_n =  vtkSmartPointer<vtkPolyData>::New();
    data2_p->DeepCopy(clipperXY->GetOutput());
    data2_n->DeepCopy(clipperXY1->GetOutput());


    //build quarter ------------------------------------------------------------------
#pragma omp parallel for
    for(int z=0; z < dim;  z++)
#pragma omp parallel for
        for(int y=0; y < dim;  y++)
#pragma omp parallel for
            for(int x=0; x < dim;  x++)
            {
                double * d = static_cast<double*>(volume0->GetScalarPointer(x,y,z));
                double * d1 = static_cast<double*>(volume1->GetScalarPointer(x,y,z));
                d[0]=CubeDataQuarter[(z*dim+y)*dim+x];
                d1[0]=-CubeDataQuarter[(z*dim+y)*dim+x];
            }


    ExtractIsosurface(volume0, volume1);

    //adjust
#pragma omp parallel for
    for (int i=0;i<pData->GetNumberOfPoints();i++)
    {
        double * p = pData->GetPoint(i);
        if (p[2] > 0.0) p[2]=0.0;
        if (p[1] > 0.0) p[1]=0.0;

        pData->GetPoints()->SetPoint(i,p);
    }

#pragma omp parallel for
    for (int i=0;i<pData1->GetNumberOfPoints();i++)
    {
        double * p = pData1->GetPoint(i);
        if (p[2] > 0.0) p[2]=0.0;
        if (p[1] > 0.0) p[1]=0.0;

        pData1->GetPoints()->SetPoint(i,p);
    }


    planeXY->SetNormal(0, 0, -1);
    clipperXY->SetInputData(pData);
    clipperXY->SetClipFunction(planeXY);
    clipperXY->GenerateClipScalarsOn();
    clipperXY->GenerateClippedOutputOn();
    clipperXY->Update();

    planeYZ->SetNormal(0, -1, 0);
    clipperYZ->SetInputData(clipperXY->GetOutput());
    clipperYZ->SetClipFunction(planeYZ);
    clipperYZ->GenerateClipScalarsOn();
    clipperYZ->GenerateClippedOutputOn();
    clipperYZ->Update();


    clipperXY1->SetInputData(pData1);
    clipperXY1->SetClipFunction(planeXY);
    clipperXY1->GenerateClipScalarsOn();
    clipperXY1->GenerateClippedOutputOn();
    clipperXY1->Update();

    clipperYZ1->SetInputData(clipperXY1->GetOutput());
    clipperYZ1->SetClipFunction(planeYZ);
    clipperYZ1->GenerateClipScalarsOn();
    clipperYZ1->GenerateClippedOutputOn();
    clipperYZ1->Update();

    //store
    auto data3_p =  vtkSmartPointer<vtkPolyData>::New();
    auto data3_n =  vtkSmartPointer<vtkPolyData>::New();
    data3_p->DeepCopy(clipperYZ->GetOutput());
    data3_n->DeepCopy(clipperYZ1->GetOutput());



    //combine three parts
    auto appendFilter = vtkSmartPointer<vtkAppendPolyData>::New();
    appendFilter->AddInputData(data1_p);
    appendFilter->AddInputData(data2_p);
    appendFilter->AddInputData(data3_p);

    auto appendFilter1 = vtkSmartPointer<vtkAppendPolyData>::New();
    appendFilter1->AddInputData(data1_n);
    appendFilter1->AddInputData(data2_n);
    appendFilter1->AddInputData(data3_n);

    //the latest filter
    auto cleanFilter =  vtkSmartPointer<vtkCleanPolyData>::New();
    cleanFilter->SetInputConnection(appendFilter->GetOutputPort());
    //cleanFilter->SetTolerance(0.1);
    cleanFilter->Update();


    auto cleanFilter1 =  vtkSmartPointer<vtkCleanPolyData>::New();
    cleanFilter1->SetInputConnection(appendFilter1->GetOutputPort());
    //cleanFilter->SetTolerance(0.1);
    cleanFilter1->Update();

    pData->DeepCopy(cleanFilter->GetOutput());
    pData1->DeepCopy(cleanFilter1->GetOutput());

}


void HMO::buildMOIsosurface()
{
    if (isMolecularOrbital) {
        NPoints=80;
        minBox=-20.0;
        maxBox=20.0;
        isoValue=0.001;
        cout << "Build Molecular Obital " <<endl;


        for (uint i=0;i<NumAOs();i++)
            if (getAO(i)->getZ()>1) {
                NPoints=200;
                break;
            }
    }

    if (isHybridizedOrbital ) {
        NPoints=100;
        minBox=-8.0;
        maxBox=8.0;
        isoValue=0.001;
        cout << "Build Hybridized Obital " <<endl;
    }


    int Nx=NPoints,Ny=NPoints,Nz=NPoints;
    int N=NPoints;



    //includes (0,0,0), and do not jump over
    interval=(maxBox-minBox)/N;
    maxBox=interval*N/2.0;

    minBox=-maxBox;

    int x,y,z;
    double  x0=minBox,
            y0=minBox,
            z0=minBox;


    sendMessage("Building cube data ... ");
    sendMessage(QString("dim:     %1*%1*%1").arg(N));
    sendMessage(QString("range:   %1   %2").arg(minBox).arg(maxBox));
    sendMessage(QString("interval:  %1").arg(interval));
    sendMessage(QString("interval:  %1").arg(isoValue));


    cout << "\nbuilding cube data for hybridized/molecular orbital " <<endl;
    cout << "dim: " <<N <<endl;
    cout << "range: " <<minBox  <<" " << maxBox<< endl;
    cout << "interval: " <<interval  << endl;
    cout << "isovalue: " <<isoValue  << endl<< endl;


    if (CubeData || CubeData!=nullptr ) {
        delete CubeData;
        CubeData=nullptr;
    }
    CubeData = new double [Nx*Ny*Nz];

    //calculate Psi
    double psi=0.0,
           sum=0.0,
           psi2=0.0;


#pragma omp parallel for
    for( z=0; z < Nz ; z++)
        for( y=0; y < Ny;  y++)
            for( x=0; x < Nx;  x++){
                psi=calc_Psi(x0+interval*x,y0+interval*y , z0+interval*z);
                //psi2=psi*psi;
                //sum += psi2;

                //if  (psi>0.0)     CubeData[(z*N+y)*N+x]=psi2;
                //else              CubeData[(z*N+y)*N+x]=-psi2;


                CubeData[(z*N+y)*N+x]=psi;

                //cout << psi<<endl;
            }

    int dim=NPoints;
    interval=(maxBox-minBox)/dim;
    vtkImageData * volume0 = vtkImageData::New();
    volume0->SetDimensions(dim,dim,dim);
    volume0->SetSpacing(interval, interval,interval);
    volume0->AllocateScalars(VTK_DOUBLE,1);
    volume0->SetOrigin(-maxBox,-maxBox,-maxBox);
    volume0->Modified();

    vtkImageData * volume1 = vtkImageData::New();
    volume1->SetDimensions(dim,dim,dim);
    volume1->SetSpacing(interval, interval,interval);
    volume1->AllocateScalars(VTK_DOUBLE,1);
    volume1->SetOrigin(-maxBox,-maxBox,-maxBox);
    volume1->Modified();

    double v=0.0;
#pragma omp parallel for
    for(int z=0; z < dim;  z++)
        for(int y=0; y < dim;  y++)
            for(int x=0; x < dim;  x++)
            {
                double * d = static_cast<double*>(volume0->GetScalarPointer(x,y,z));
                double * d1 = static_cast<double*>(volume1->GetScalarPointer(x,y,z));

                d[0]=CubeData[(z*dim+y)*dim+x];
                d1[0]=-CubeData[(z*dim+y)*dim+x];
            }


    ExtractIsosurface(volume0, volume1);


    cout << "Done"<<endl;
    appendMessage("Done!");
}


//build when orbital type changed
void HMO::buildIsosurface()
{
    if (isMolecularOrbital || isHybridizedOrbital )
    {
         buildMOIsosurface();
         return;
    }

    buildCubeData();
    buildYlmSurface();
    buildCloudPoints();

    if (orbital_type==Wedge){
        buildWedgeIsosurface();
        //buildWedgeIsosurface1();
        return;
    }


    int dim=NPoints;
    interval=(maxBox-minBox)/dim;
    vtkImageData * volume0 = vtkImageData::New();
    volume0->SetDimensions(dim,dim,dim);
    volume0->SetSpacing(interval, interval,interval);
    volume0->AllocateScalars(VTK_DOUBLE,1);
    volume0->SetOrigin(-maxBox,-maxBox,-maxBox);
    volume0->Modified();

    vtkImageData * volume1 = vtkImageData::New();
    volume1->SetDimensions(dim,dim,dim);
    volume1->SetSpacing(interval, interval,interval);
    volume1->AllocateScalars(VTK_DOUBLE,1);
    volume1->SetOrigin(-maxBox,-maxBox,-maxBox);
    volume1->Modified();


    double  x0=minBox,
            y0=minBox,
            z0=minBox;

    interval=(maxBox-minBox)/dim;


    double v=0.0;
#pragma omp parallel for
    for(int z=0; z < dim;  z++){
        for(int y=0; y < dim;  y++){

            for(int x=0; x < dim;  x++)
            {
                double * d = static_cast<double*>(volume0->GetScalarPointer(x,y,z));
                double * d1 = static_cast<double*>(volume1->GetScalarPointer(x,y,z));

                switch (orbital_type) {
                case  FULL :
                    d[0]=CubeData[(z*dim+y)*dim+x];
                    d1[0]=-CubeData[(z*dim+y)*dim+x];
                    break;

                case  XOY :
                    d[0]=CubeDataXOY[(z*dim+y)*dim+x];
                    d1[0]=-CubeDataXOY[(z*dim+y)*dim+x];
                    break;

                case  XOZ :
                    d[0]=CubeDataXOZ[(z*dim+y)*dim+x];
                    d1[0]=-CubeDataXOZ[(z*dim+y)*dim+x];
                    break;

                case  YOZ :
                    d[0]=CubeDataYOZ[(z*dim+y)*dim+x];
                    d1[0]=-CubeDataYOZ[(z*dim+y)*dim+x];
                    break;
/*
                case  Wedge :
                    d[0]=CubeDataWedge[(z*dim+y)*dim+x];
                    d1[0]=-CubeDataWedge[(z*dim+y)*dim+x];
                    break;
*/
                case  Quarter :
                    d[0]=CubeDataQuarter[(z*dim+y)*dim+x];
                    d1[0]=-CubeDataQuarter[(z*dim+y)*dim+x];
                    break;

                case  Corner:
                    d[0]=CubeDataCorner[(z*dim+y)*dim+x];
                    d1[0]=-CubeDataCorner[(z*dim+y)*dim+x];
                    break;
                }

            }
        }
    }

     //obtained pData(positive),pData1(negative);
     ExtractIsosurface(volume0, volume1);
     vector <vector3> points;

     switch (orbital_type) {
     case  XOY :
#pragma omp parallel for
         for (int i=0;i<pData->GetNumberOfPoints();i++)
         {
             double * p = pData->GetPoint(i);
             if (p[2] > 0.0)
             {
                 p[2]=0.0;
                 pData->GetPoints()->SetPoint(i,p);
             }
         }
         break;


     case  XOZ :
#pragma omp parallel for
         for (int i=0;i<pData->GetNumberOfPoints();i++)
         {
             double * p = pData->GetPoint(i);
             if (p[1] > 0.0)
             {
                 p[1]=0.0;
                 pData->GetPoints()->SetPoint(i,p);
             }
         }
         break;

     case  YOZ :
#pragma omp parallel for
         for (int i=0;i<pData->GetNumberOfPoints();i++)
         {
             double * p = pData->GetPoint(i);
             if (p[0] > 0.0) {
                 p[0]=0.0;
                 pData->GetPoints()->SetPoint(i,p);
             }
         }
         break;

    case  Wedge :
#pragma omp parallel for
         for (int i=0;i<pData->GetNumberOfPoints();i++)
         {
             double * p = pData->GetPoint(i);
             if (p[2] > 0.0 &&   p[1] > 0.0) {
                 p[2]=0.0; //z=0
                 //p[1]=0.0;
                 pData->GetPoints()->SetPoint(i,p);

                 vector3 a(p[0],0.0,p[2]);
                 points.push_back(a);
             }     
         }
         for (int i=0;i<points.size();i++)
         {

         }
         break;

     case  Quarter :
#pragma omp parallel for
         for (int i=0;i<pData->GetNumberOfPoints();i++)
         {
             double * p = pData->GetPoint(i);
             if (p[2] > 0.0) p[2]=0.0;
             if (p[1] > 0.0) p[1]=0.0;
             pData->GetPoints()->SetPoint(i,p);
         }
         break;

     case  Corner :
#pragma omp parallel for
         for (int i=0;i<pData->GetNumberOfPoints();i++)
         {
             double * p = pData->GetPoint(i);
             if (p[2] > 0.0) p[2]=0.0;
             if (p[1] > 0.0) p[1]=0.0;
             if (p[0] > 0.0) p[0]=0.0;
             pData->GetPoints()->SetPoint(i,p);
         }
         break;
     }


     switch (orbital_type) {
     case  XOY :
#pragma omp parallel for
         for (int i=0;i<pData1->GetNumberOfPoints();i++)
         {
             double * p = pData1->GetPoint(i);
             if (p[2] > 0.0)
             {
                 p[2]=0.0;
                 pData1->GetPoints()->SetPoint(i,p);
             }
         }
         break;


     case  XOZ :
#pragma omp parallel for
         for (int i=0;i<pData1->GetNumberOfPoints();i++)
         {
             double * p = pData1->GetPoint(i);
             if (p[1] > 0.0)
             {
                 p[1]=0.0;
                 pData1->GetPoints()->SetPoint(i,p);
             }
         }
         break;

     case  YOZ :
#pragma omp parallel for
         for (int i=0;i<pData1->GetNumberOfPoints();i++)
         {
             double * p = pData1->GetPoint(i);
             if (p[0] > 0.0) {
                 p[0]=0.0;
                 pData1->GetPoints()->SetPoint(i,p);
             }
         }
         break;

         /*case  Widge :
             if (p[2] > 0.0 &&   p[1] > 0.0) {
                 p[2]=0.0;
                 p[1]=0.0;
                 pData->GetPoints()->SetPoint(i,p);
             }
             break;*/

     case  Quarter :
#pragma omp parallel for
         for (int i=0;i<pData1->GetNumberOfPoints();i++)
         {
             double * p = pData1->GetPoint(i);
             if (p[2] > 0.0) p[2]=0.0;
             if (p[1] > 0.0) p[1]=0.0;
             pData1->GetPoints()->SetPoint(i,p);
         }
         break;

     case  Corner :
#pragma omp parallel for
         for (int i=0;i<pData1->GetNumberOfPoints();i++)
         {
             double * p = pData1->GetPoint(i);
             if (p[2] > 0.0) p[2]=0.0;
             if (p[1] > 0.0) p[1]=0.0;
             if (p[0] > 0.0) p[0]=0.0;
             pData1->GetPoints()->SetPoint(i,p);
         }
         break;
     }

     cout <<"Done!"<<endl;
}


void HMO::setProjType(uint type)
{
    projType=proj_NONE;
    switch (type){
    case 1:
        projType=proj_XOY;
        break;
    case 2:
        projType=proj_XOZ;
        break;
    case 3:
        projType=proj_YOZ;
        break;
    }
}


void HMO::build_MOProjectionData()
{
    if ( (projType!=proj_XOY) && (projType!=proj_YOZ) && (projType!=proj_XOZ) )
        return;


    cout << "Building projection for molecular orbitals ..."<<endl;
    sendMessage("Building projection for molecular orbitals ...");

    //includes (0,0,0)
    proj_scale=2;
    uint N=proj_scale*NPoints;

    double interval0=(maxBox-minBox)/N;
    maxBox=interval0*N/2.0;
    minBox=-maxBox;

    double  x0=minBox,
            y0=minBox,
            z0=minBox;
    uint i,j,k;


    if (projType==proj_XOY)
    {
        sendMessage("Projection to XOY plane");
        cout <<" Projection to XOY plane"<<endl;

        if(dataXOY.size()>0)    dataXOY.clear();

        dataXOY.resize(N);
        #pragma omp parallel for
        for ( i=0;i<N;i++) dataXOY[i].resize(N);

        #pragma omp parallel for
        for( i=0; i < N;  i++)
        #pragma omp parallel for
            for( j=0; j < N;  j++) {
                dataXOY[i][j]=calc_Psi(x0+interval0*i,y0+interval0*j, 0.0);
            }

    }

    if (projType==proj_YOZ)
    {
        sendMessage("Projection to YOZ plane");
        cout <<" Projection to YOZ plane"<<endl;

        if(dataYOZ.size()>0)
            dataYOZ.clear();

        dataYOZ.resize(N);

        #pragma omp parallel for
        for (j=0;j<N;j++) dataYOZ[j].resize(N);

        #pragma omp parallel for
        for( j=0; j < N;  j++)

        #pragma omp parallel for
            for( k=0; k < N;  k++)
                dataYOZ[j][k]=calc_Psi(0.0,y0+interval0*j, z0+interval0*k);
        return;
    }

    if (projType==proj_XOZ)
    {
        sendMessage("Projection to XOZ plane");
        cout <<" Projection to XOZ plane"<<endl;

        if(dataXOZ.size()>0)
            dataXOZ.clear();

        dataXOZ.resize(N);
#pragma omp parallel for
        for ( i=0;i<N;i++) dataXOZ[i].resize(N);

#pragma omp parallel for
        for( i=0; i < N;  i++)
#pragma omp parallel for
            for( k=0; k < N;  k++)
                dataXOZ[i][k]=calc_Psi(x0+interval0*i, 0.0,z0+interval0*k);
        return;
    }


    cout <<"Done!"<<endl;
}


//build Ylm(theta,phi), only 3d-surface
void HMO::buildSurfaceAngular_positive()
{
    surfaceAngular_positive.clear();

    double phi=0.0,theta=0.0;

    //only one type is generated based on AO'name
    HAO *ao = getAO(0);
    QString AOName=ao->getName();
    AOName.remove(0,1);

}

//build Ylm(theta,phi), only 3d-surface
void HMO::buildSurfaceAngular_negtive()
{
    surfaceAngular_negative.clear();
}





void HMO::build_AOProjectionData()
{
    sendMessage("Building projection for atomic orbitals ...");

    //includes (0,0,0)
    proj_scale=3;
    uint Nx=NPoints,
         Ny=NPoints,
         Nz=NPoints,
         N=proj_scale*NPoints;

   // cout << "------------"<<endl;
  //  cout << maxBox<<endl;
  //  cout << interval<<endl;
  //  cout<<N<<endl;


    double interval0=(maxBox-minBox)/N;
    maxBox=interval0*N/2.0;
    minBox=-maxBox;

    cout << "------------"<<endl;
    cout << maxBox<<endl;
    cout << interval0<<endl;


    double  x0=minBox,
            y0=minBox,
            z0=minBox;
    uint i,j,k;



    //only one type is generated based on AO'name
    HAO *ao = getAO(0);
    QString AOName=ao->getName();
    AOName.remove(0,1);

    cout <<" calculating AO projection data:"<<endl;
    //cout << AOName.toStdString().c_str()<<endl;


    projType=proj_NONE;

    if ( AOName.startsWith("S")
         || AOName.startsWith("Px") || AOName.startsWith("Py")
         || AOName.startsWith("Dxy") || AOName.startsWith("Dx2-y2")
         || AOName.startsWith("Fx3") || AOName.startsWith("Fy3")
         || AOName.startsWith("Fx(x2-3y2)") || AOName.startsWith("Fy(3x2-y2)")
         || AOName.startsWith("Gxy(x2-y2)") || AOName.startsWith("G(x4+y4)")
         )
    {
        sendMessage("Projection to XOY plane");

        projType=proj_XOY;

        cout <<" Projection to XOY plane"<<endl;

        if(dataXOY.size()>0)    dataXOY.clear();
        dataXOY.resize(N);
        #pragma omp parallel for
        for ( i=0;i<N;i++) dataXOY[i].resize(N);

        #pragma omp parallel for
        for( i=0; i < N;  i++)
        #pragma omp parallel for
            for( j=0; j < N;  j++)
                dataXOY[i][j]=calc_Psi(x0+interval0*i,y0+interval0*j, 0.0);

        cout <<" ... Done!"<<endl;
        return;
    }

    if ( AOName.startsWith("Dyz") ||AOName.startsWith("Fyz2")
         || AOName.startsWith("Gz3y") || AOName.startsWith("Gzy3")
        )
    {
        projType=proj_YOZ;
        sendMessage("Projection to YOZ plane");
        cout <<" Projection to YOZ plane"<<endl;

        if(dataYOZ.size()>0)    dataYOZ.clear();
        dataYOZ.resize(N);
        #pragma omp parallel for
        for ( i=0;i<N;i++) dataYOZ[i].resize(N);

        #pragma omp parallel for
        for( j=0; j < N;  j++)
        #pragma omp parallel for
            for( k=0; k < N;  k++)
                dataYOZ[j][k]=calc_Psi(0.0,y0+interval0*j, z0+interval0*k);

        cout <<" ... Done!"<<endl;
        return;
    }

    else if ( AOName.startsWith("Pz")
              || AOName.startsWith("Dz2")
              || AOName.startsWith("Dxz")
              || AOName.startsWith("Fz3") || AOName.startsWith("Fxz2")
              || AOName.startsWith("Gz4") || AOName.startsWith("Gz3x")
              || AOName.startsWith("Gzx3") || AOName.startsWith("Gz3x")
              )
    {
        sendMessage("Projection to XOZ plane");

        projType=proj_XOZ;
        cout <<" Projection to XOZ plane"<<endl;

        if(dataXOZ.size()>0)    dataXOZ.clear();
        dataXOZ.resize(N);
#pragma omp parallel for
        for ( i=0;i<N;i++) dataXOZ[i].resize(N);


#pragma omp parallel for
        for( i=0; i < N;  i++)
#pragma omp parallel for
            for( k=0; k < N;  k++)
                dataXOZ[i][k]=calc_Psi(x0+interval0*i, 0.0,z0+interval0*k);

        cout <<" ... Done!"<<endl;

        return;
    }
}




void HMO::calc_RadialThreeKindsData ()
{
    sendMessage("Calculating R,R2 and RDF functions ...");

    RData.clear();
    R2Data.clear();
    RDFData.clear();

   double interval=0.1;

   double r_max=1.2*AOs[0]->calc_least_r();
   double r=0.0;

   for (int i=0; ;i++)
   {
       if(r>r_max) break;

       r+=interval;

       double  R=0.0,
               R2=0.0,
               RDF=0.0;
       double value=0.0;

       for (int j=0;j<AOs.size();j++)
       {
           value=AOs[j]->Hydrogen_R(r);
           R+=value;
           R2+=value*value;
           RDF+=value*value*r*r;
       }
       RData.append(QPointF(i, R));
       R2Data.append(QPointF(i, R2));
       RDFData.append(QPointF(i, RDF));
   }

    appendMessage("Done!");
}



