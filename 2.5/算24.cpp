#include<bits/stdc++.h>
using namespace std;
double a[5];
bool isZero(double x)
{
return fabs(x)<=1e-6;
}
bool solve(double a[],int n)//数组a里有n个元素
{
if(n==1)
return isZero(24-a[0]);
double b[5];int m;
for(int i=0;i<n;i++)
for(int j=i+1;j<n;j++)
{
m=0;
for(int k=0;k<n;k++)
if(k!=i&&k!=j)b[m++]=a[k];
b[m]=a[i]+a[j];
if(solve(b,m+1))return true;
b[m]=a[i]-a[j];
if(solve(b,m+1))return true;
b[m]=a[j]-a[i];
if(solve(b,m+1))return true;
b[m]=a[i]*a[j];
if(solve(b,m+1))return true;
if(!isZero(a[i]))
{
b[m]=a[j]/a[i];
if(solve(b,m+1))return true;
}
if(!isZero(a[j]))
{
b[m]=a[i]/a[j];
if(solve(b,m+1))return true;
}
}
return false;
}
int main()
{
while(scanf("%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3]))
{
if(isZero(a[0])&&isZero(a[1])&&isZero(a[2])&&isZero(a[3]))return 0;
if(solve(a,4))printf("YES\n");
else printf("NO\n");
}
}
