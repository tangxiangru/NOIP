#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Point
{
int x,y;
void input()
{
scanf("%d%d",&x,&y);
}
}p[101];
double Dis(Point p1,Point p2)
{
return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(double)(p2.y-p1.y)*(p2.y-p1.y));
}
bool cmp(Point m,Point n)
{
return m.x<n.x;
}
int main()
{
int n;
double a[101][101],dp[101][101];
while(scanf("%d",&n)!=EOF)
{
p[0].input();
if(n==1) {printf("0.00\n");continue;}
for(int i=1;i<n;i++)
{
p[i].input();
if(p[0].x>p[i].x) swap(p[0],p[i]);
}
sort(p,p+n,cmp);
for(int i=0;i<n;i++)
{
a[i][i]=0;
for(int j=i+1;j<n;j++)
{
a[i][j]=a[j][i]=Dis(p[i],p[j]);
}
}
dp[0][0]=0;
for(int i=1;i<n;i++)
dp[i][0]=a[i][0];
for(int i=1;i<n-1;i++)
{
dp[i+1][i]=1000000000;
for(int j=0;j<=i-1;j++)
{
dp[i+1][j]=dp[i][j]+a[i][i+1];
dp[i+1][i]=min(dp[i+1][i],dp[i][j]+a[j][i+1]);
}
}
printf("%.2lf\n",dp[n-1][n-2]+a[n-1][n-2]);
}
return 0;
}
