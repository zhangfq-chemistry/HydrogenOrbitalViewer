#include "SolveEquation.h"






void QRRoots::qrInit()
{
     int i,j;
     for(i=0; i<n; i++)
        for(j=0; j<n; j++)   q[i][j]=0.0;
     for(j=0; j<=n-1; j++)   q[0][j]=-a[n-j-1]/a[n];
     for(i=0; i<=n-2; i++)   q[i+1][i]=1.0;

}

void QRRoots::qrSolve()
{
    qrInit();

    int m, it, i, j, k, l;
    double b,c,w,g,xy,p,qq,r,x,s,e,f,z,y;
    it=0;
    m=n;
    while(m!=0)
    {
        l=m-1;
        while((l>0) && (fabs(q[l][l-1])>eps* (fabs(q[l-1][l-1])+fabs(q[l][l]))))
            l=l-1;

        if(l==m-1){
            xr[m-1]=q[m-1][m-1];
            xi[m-1]=0.0;
            m=m-1;
            it=0;
        }
        else if(l==m-2){
            b=-(q[m-1][m-1]+q[m-2][m-2]);
            c=q[m-1][m-1]*q[m-2][m-2]-q[m-1][m-2]*q[m-2][m-1];
            w=b*b-4.0*c;
            y=sqrt(fabs(w));

            if(w>0.0){
                xy=1.0;
                if(b<0.0)
                    xy=-1.0;
                xr[m-1]=(-b-xy*y)/2.0;
                xr[m-2]=c/xr[m-1];
                xi[m-1]=0.0;
                xi[m-2]=0.0;
            } else {
                xr[m-1]=-b/2.0;
                xr[m-2]=xr[m-1];
                xi[m-1]=y/2.0;
                xi[m-2]=-xi[m-1];
            }
            m=m-2;
            it=0;
        }
        else {
            if(it>=Max)
            {
                cout<<"\nstop!"<<endl;
                return;
            }

            it=it+1;
            for(j=l+2;j<=m-1; j++)
                q[j][j-2]=0.0;
            for(j=l+3; j<=m-1; j++)
                q[j][j-3]=0.0;
            for(k=l; k<=m-2; k++)
            {
                if(k!=l)
                {
                    p=q[k][k-1];
                    qq=q[k+1][k-1];
                    r=0.0;
                    if(k!=m-2)  r=q[k+2][k-1];
                }
                else
                {
                    x=q[m-1][m-1]+q[m-2][m-2];
                    y=q[m-2][m-2]*q[m-1][m-1]
                            -q[m-2][m-1]*q[m-1][m-2];
                    p=q[l][l]*(q[l][l]-x)+q[l][l+1]*q[l+1][l]+y;
                    qq=q[l+1][l]*(q[l][l]+q[l+1][l+1]-x);
                    r=q[l+1][l]*q[l+2][l];
                }
                if((fabs(p)+fabs(qq)+fabs(r))!=0.0)
                {
                    xy=1.0;
                    if(p<0.0)     xy=-1.0;
                    s=xy*sqrt(p*p+qq*qq+r*r);
                    if(k!=l)     q[k][k-1]=-s;
                    e=-qq/s;
                    f=-r/s;
                    x=-p/s;
                    y=-x-f*r/(p+s);
                    g=e*r/(p+s);
                    z=-x-e*qq/(p+s);
                    for(j=k; j<=m-1; j++)
                    {
                        p=x*q[k][j]+e*q[k+1][j];
                        qq=e*q[k][j]+y*q[k+1][j];
                        r=f*q[k][j]+g*q[k+1][j];
                        if(k!=m-2)
                        {
                            p=p+f*q[k+2][j];
                            qq=qq+g*q[k+2][j];
                            r=r+z*q[k+2][j];
                            q[k+2][j]=r;
                        }
                        q[k+1][j]=qq;
                        q[k][j]=p;
                    }
                    j=k+3;
                    if(j>=m-1)
                        j=m-1;
                    for(i=l; i<=j; i++)
                    {
                        p=x*q[i][k]+e*q[i][k+1];
                        qq=e*q[i][k]+y*q[i][k+1];
                        r=f*q[i][k]+g*q[i][k+1];
                        if(k!=m-2)
                        {
                            p=p+f*q[i][k+2];
                            qq=qq+g*q[i][k+2];
                            r=r+z*q[i][k+2];
                            q[i][k+2]=r;
                        }
                        q[i][k+1]=qq;
                        q[i][k]=p;
                    }
                }
            }
        }
    }
}

//a*x^3 + b*x^2 + c*x + d =0.0
void SolveEquation::calculate_Cubic(double a,double b,double c,double d)
{
    double A,B,C;
    double delt;

    A = pow(b,2)-3*a*c;
    B = b*c-9*a*d;
    C = pow(c,2)-3*b*d;
    delt = pow(B,2)-4*A*C;

    if ((A==0&&B==0)||(delt==0&&A==0))
    {
        x1 = -b/(3*a);
        x2 = x1;
        x3 = x1;
    }

    if (delt>0)
    {
        double Y1 = A*b+3*a*((-B+pow(delt,0.5))/2);
        double Y2 = A*b+3*a*((-B-pow(delt,0.5))/2);

        double Y1_three,Y2_three;
        if (Y1<0)
            Y1_three = - pow(-Y1,1.0/3.0);
        else
            Y1_three = pow(Y1,1.0/3.0);
        if (Y2<0)
            Y2_three = - pow(-Y2,1.0/3.0);
        else
            Y2_three = pow(Y2,1.0/3.0);
        x1 = (-b-(Y1_three+Y2_three))/(3*a);
    }

    if (delt==0 && (A!=0))
    {
        double K = B/A;
        x1 = -b/a + K;
        x2 = -K/2.0;
        x3 = x2;
    }


    if (delt<0)
    {
        double T = (2*A*b-3*a*B)/(2*A*pow(A,0.5));//（A>0，－1<T<1）
        double theita = acos(T);
        x1 = (-b-2*pow(A,0.5)*cos(theita/3.0))/(3*a);
        x2 = (-b+pow(A,0.5)*(cos(theita/3.0)+pow(3,0.5)*sin(theita/3.0)))/(3*a);
        x3 = (-b+pow(A,0.5)*(cos(theita/3.0)-pow(3,0.5)*sin(theita/3.0)))/(3*a);
    }

    answer.clear();
    answer.push_back(x1);
    answer.push_back(x2);
    answer.push_back(x3);
}




void SolveEquation::setCoeff(vector <double> c)
{
    N =  c.size()-1;
    for (uint i=0;i<c.size();i++)
        coeff.push_back(c[i]);
}


void SolveEquation::Solve()
{
    answer.clear();


    if (N==1)   // a*x + b =0.0
        calculate_Single(coeff[1],coeff[0]);

    else if(N==2) // a*x^2 + b*x + c =0.0
        calculate_Square(coeff[2],coeff[1],coeff[0]);


    else if(N==3) //cubic a*x^3 + b*x^2 + c*x + d =0.0
        calculate_Cubic(coeff[3],coeff[2],coeff[1],coeff[0]);


    else {
        QRRoots roots(N);
        for (int i=0;i<coeff.size();i++)
            roots.a[i]=coeff[i];
        roots.qrSolve();

        answer.clear();
        for(int j=0; j<N; j++)
            answer.push_back(roots.xr[j]);

        if (abs(roots.xr[0])+abs(roots.xr[1])+abs(roots.xr[2])+abs(roots.xr[3]) > 1.0)
        {
            answer.clear();
            for(int j=0; j<N; j++)
                answer.push_back(roots.xr[j]);
        }
        else
            answer=GeneralSolve(coeff,N);
    }


    //sort
    sort(answer.begin(), answer.end());
    std::reverse(answer.begin(),answer.end());
}


void SolveEquation::calculate_Square(double a, double b,double c)
{
    double term=sqrt(b*b-4*a*c);

    answer.clear();
    answer.push_back((-b+term)/2.0/a);
    answer.push_back((-b-term)/2.0/a);
}

//ax+b=0
void SolveEquation::calculate_Single(double a, double b)
{
    answer.clear();

    if(abs(a)>0.00001)
        answer.push_back(-b/a);
    else
        answer.push_back(0.0);

}





double SolveEquation::Get(const vector<double> &coef,double x)
{
    double e=1,s=0;//e=x^i (i=0,1,2,...,n)   coef.size():n+1
    for(int i=0;i<coef.size();++i) s+=coef[i]*e,e*=x;
    return s;
}

double SolveEquation::Find(const vector <double> &coef,int n,double lo,double hi){
    double sign_lo,sign_hi;
    if((sign_lo=sign(Get(coef,lo)))==0) return lo;
    if((sign_hi=sign(Get(coef,hi)))==0) return hi;
    if(sign_hi*sign_lo>0) return inf;
    for(int step=0;step<100 && hi-lo>eps;++step){
        double m=(lo+hi)*.5;
        int sign_mid=sign(Get(coef,m));
        if(sign_mid==0) return m;
        if(sign_lo*sign_mid<0) hi=m;
        else lo=m;
    }
    return (lo+hi)*.5;
}


vector <double> SolveEquation::GeneralSolve(vector<double> coef,int n)
{
    vector<double> ret;

    if(n==1){
        if(sign(coef[1])) ret.push_back(-coef[0]/coef[1]);
        return ret;
    }
    vector<double> dcoef(n);
    for(int i=0;i<n;++i) dcoef[i]=coef[i+1]*(i+1);
    vector<double> droot=GeneralSolve(dcoef,n-1);
    droot.insert(droot.begin(),-inf);
    droot.push_back(inf);
    for(int i=0;i+1<droot.size();++i){
        double tmp=Find(coef,n,droot[i],droot[i+1]);
        if(tmp<inf) ret.push_back(tmp);
    }
    return ret;
}







