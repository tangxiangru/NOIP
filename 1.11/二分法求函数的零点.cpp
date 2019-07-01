#include<stdio.h>
#include<math.h>
double f(double x)
{
    double ans=0;
    ans=pow(x,5)-15*pow(x,4)+85*pow(x,3)-225*pow(x,2)+274*x-121;
    return ans;
}
int main(int argc, char *argv[])
{
    double x,y,mid,fx,fy,fm;
    x=1.5;
    y=2.4;
    mid=(x+y)/2;
    fx=f(x);
    fy=f(y);
    fm=f(mid);
    while( fabs(fm-0) > 1e-6)
    {
        if(fx*fm<0) { y=mid; fy=f(y); }
        else { x=mid; fx=f(x); }
        mid=(x+y)/2;
        fm=f(mid);
    }
    printf("%.6lf\n",mid);
    return 0;
}

