#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#define maxn 1100
#define inf 99999
using namespace std;
int t,n,x,y,MAX;
struct Plat//用结构体定义木板
{
int lx,rx,h;
}p[maxn];
bool cmp(Plat a,Plat b)
{
return a.h>b.h;
}
int ltime[maxn];//记录从左端点开始的最少下落时间
int rtime[maxn];//记录从右端点开始的最少下落时间
int main()
{
int i,j;
scanf("%d",&t);
while(t--)
{
scanf("%d%d%d%d",&n,&x,&y,&MAX);
for(i=1;i<=n;i++)
{
scanf("%d%d%d",&p[i].lx,&p[i].rx,&p[i].h);
if(p[i].lx>p[i].rx)
swap(p[i].lx,p[i].rx);
}
p[0].lx=p[0].rx=x,p[0].h=y;
p[n+1].lx=-20001,p[n+1].rx=20001,p[n+1].h=0;//这里我把地面也当成了一块木板，便于下面统一分析
sort(p+1,p+n+1,cmp);//记得把木板排序
for(i=n;i>=0;i--)
{
for(j=i+1;j<=n+1;j++)
{
if(p[i].lx>=p[j].lx&&p[i].lx<=p[j].rx)//当第i块木板下面有j木板时
{
if(p[i].h-p[j].h>MAX)
ltime[i]=inf;
else if(j==n+1)//当第j块木板是地面时
ltime[i]=p[i].h;
else
ltime[i]=p[i].h-p[j].h+min(ltime[j]+p[i].lx-p[j].lx,rtime[j]+p[j].rx-p[i].lx);
break;
}
}
for(j=i+1;j<=n+1;j++)//这个循环和上面那个是同理的
{
if(p[i].rx>=p[j].lx&&p[i].rx<=p[j].rx)
{
if(p[i].h-p[j].h>MAX)
rtime[i]=inf;
else if(j==n+1)
rtime[i]=p[i].h;
else
rtime[i]=p[i].h-p[j].h+min(ltime[j]+p[i].rx-p[j].lx,rtime[j]+p[j].rx-p[i].rx);
break;
}
}
}
printf("%d\n",min(ltime[0],rtime[0]));//其实这时ltime[0]==rtime[0]
}
return 0;
}
