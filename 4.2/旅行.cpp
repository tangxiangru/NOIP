#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<algorithm>
using namespace std;
int a[201][1001];
int top[201];
int main()
{
int n;
scanf("%d",&n);
a[1][1]=0;
a[2][1]=1;
top[1]=1;
top[2]=1;
if(n==1) {cout<<0;return 0;}
if(n==2) {cout<<1;return 0;}
for(int i=3;i<=n;i++)
{
for(int j=1;j<=top[i-1];j++)
{
a[i][j]=a[i-1][j]+a[i-2][j];
a[i][j]=a[i][j]*(i-1);
}
top[i]=top[i-1];
for(int j=1;j<=top[i];j++)
{
if(a[i][j]>9)
{
a[i][j+1]+=a[i][j]/10;
a[i][j]=a[i][j]%10;
if(j==top[i]) top[i]++;
}
}
}
for(int i=top[n];i>=1;i--) cout<<a[n][i];
return 0;
}
