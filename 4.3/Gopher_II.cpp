#include<fstream>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

//ifstream fin("1538.in");
//ofstream fout("1538.out");

int n,m,s,v;
int ans=0;
bool f[150][150]={0};

int vis[150]={0};
int link1[150]={-1};

double dis(double a,double b,double c,double d)
{
double jl;
jl=sqrt((a-c)*(a-c)+(b-d)*(b-d));
return jl;
}

struct node
{
double x;
double y;
}ds[150];

struct node1
{
double x;
double y;
}hole[150];

bool can(int i)
{
for(int j=1;j<=m;j++)
{
if(vis[j]==0&&f[i][j]==1)
{
vis[j]=1;
if(link1[j]==-1||can(link1[j]))
{
link1[j]=i;
return true;
}
}
}
return false;
}

int main()
{
//freopen("1538.in","r",stdin);
//freopen("1538.out","w",stdout);
while(scanf("%d%d%d%d", &n, &m, &s, &v) != EOF)
{
ans=0;
memset(f,0,sizeof(f));
double a,b;
for(int i=1;i<=n;i++)cin>>ds[i].x>>ds[i].y;
for(int i=1;i<=m;i++)cin>>hole[i].x>>hole[i].y;
double d;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
d=dis(ds[i].x,ds[i].y,hole[j].x,hole[j].y);
//fout<<d<<' ';
if(d<=s*v)f[i][j]=1;
}
//fout<<endl;
}
//for(int i=1;i<=n;i++)
//{for(int j=1;j<=m;j++)fout<<f[i][j]<<' ';fout<<endl;}
memset(link1,-1,sizeof(link1));
for(int i=1;i<=n;i++)
{
memset(vis,0,sizeof(vis));
if(can(i))ans++;
}
cout<<n-ans<<endl;
}
return 0;
}
