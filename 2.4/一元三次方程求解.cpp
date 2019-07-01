#include<cstdio>
#include<cmath>
using namespace std;
double a,b,c,d;

double f(double x)
{
  return a*x*x*x+b*x*x+c*x+d;   
}

double search(double left,double right)
{
   double mid=(left+right)/2;
    if (right-left<1e-4) return mid;
    else
     {
        if (f(mid)==0) return mid;
        else if (f(left)*f(mid)<0) return search(left,mid);
        else return search(mid,right);
     }
}

int main()
{
    double x1,x2;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    if (a<0)
     {
        a=-a;b=-b;c=-c;d=-d;
     }
     x1=(-2*b-sqrt(4*b*b-12*a*c))/(a*6);
     x2=(-2*b+sqrt(4*b*b-12*a*c))/(a*6);
     double ans1,ans2,ans3;
     ans1=search(-101,x1);
     ans2=search(x1,x2);
     ans3=search(x2,101);
     printf("%.2f %.2f %.2f",ans1,ans2,ans3);
  return 0;
}
