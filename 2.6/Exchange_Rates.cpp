#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int mymax(int x,int y){return x>y?x:y;}
double a[400],b[400],c[400];
int n,i,j;
int main()
{
while(scanf("%d",&n)&&n)
{
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
for(i=0;i<n;i++)scanf("%lf",&c[i]);
b[0]=100000;
double sum=0.00;
a[0]=b[0]/c[0]*0.97;
for(i=1;i<n;i++)
{
for(j=0;j<i;j++)
{
a[i]=mymax(a[i-1],b[j]/c[i]*0.97);
b[i]=mymax(b[i-1],a[j]*c[i]*0.97);
}
}
for(i=0;i<=n;i++)sum=mymax(sum,b[i]);
printf("%.2lf\n",sum/100.0);
}
return 0;
}
