#include<cstdio>
#include<iostream>
#include<cstring>
#define M 1000005
using namespace std;
int p[M],n,m,g[M][2],t;
int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
int main()
{
for(;;)
{
t++;
scanf("%d%d",&n,&m);
if(n==0&&m==0)return 0;
int ans=n;
for(int i=1;i<=n;i++)p[i]=i;
memset(g,0,sizeof(g));
for(int i=0;i<m;i++)
scanf("%d%d",&g[i][0],&g[i][1]);
for(int i=0;i<m;i++)
{
int x=find(g[i][0]);
int y=find(g[i][1]);
if(x!=y)
{
p[y]=x;ans--;
}
}
printf("Case %d: %d\n",t,ans);
}
return 0;
}
