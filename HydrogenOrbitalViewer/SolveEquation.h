#ifndef SOLVEEQUATION_H
#define SOLVEEQUATION_H

#include <cmath>
#include <math.h>

#include <iostream>
#include <fstream>
#include  <cstdlib>

#include <vector>
#include <string>
#include <QString>
#include <vector>
#include <complex>
#include <complex.h>
#include "matrix3/vector3.h"



using namespace std;


class QRRoots
{
    public:
        int n, Max;
        double *a, *xr, *xi, **q, eps;

        QRRoots(int nn)
        {
                 int i;
                  n = nn;
                  a = new double[n+1];
                  xr = new double[n];
                  xi = new double[n];
                  q = new double*[n];
                  for(i=0; i<n; i++)
                        q[i] = new double[n];

                  Max=100000000;
                  eps = 0.000001;
        }

        ~QRRoots()
         {
                  int i;
                  for(i=0; i<n; i++)
                  {
                     delete[] q[i];
                  }
                   delete[] q;
                   delete[] a, xr, xi;
         }

        void qrInit();
        void qrSolve();
};












class SolveEquation
{
private:
    double x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
    vector <double> coeff;

    uint N;


    const double eps=1e-12;
    const double inf=1e12;


public:
    vector <double> answer;

    SolveEquation(vector <double> c ) {setCoeff(c);};
    ~SolveEquation() {};


    inline int sign(double x){
        return x<-eps ? -1 : x>eps ;
    }
    void Solve() ;
    void setCoeff(vector <double> );
    vector <double > getSolution();


    //a*x^3 + b*x^2 + c*x + d = 0.0
    void calculate_Cubic(double a,double b,double c,double d);

     //a*x^2 + b*x + c = 0.0
    void calculate_Square(double a,double b,double c);

    //a*x + b = 0.0
    void calculate_Single(double a,double b);


     double Get(const vector<double> &coef,double x);
     double Find(const vector <double> &coef,int n,double lo,double hi);
     vector <double> GeneralSolve(vector<double> coef,int n);



};

#endif // SOLVEEQUATION_H
