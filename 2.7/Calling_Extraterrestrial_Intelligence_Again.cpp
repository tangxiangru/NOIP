#include<cstdio>
#include<iostream>
#include<cstring>
#define M 100010
using namespace std;
int prime[10010],cnt;
bool p[M];
void getpri()
{
memset(p,1,sizeof(p));
p[0]=p[1]=0;
for(int i=2;i<=M;i++)
{
if(p[i])prime[++cnt]=i;
for(int j=1;j<=cnt&prime[j]*i<=M;j++)
{
p[prime[j]*i]=0;
if(!(i%prime[j]))break;
}
}
}
int main()
{
getpri();
while(1)
{
int m,a,b;
scanf("%d%d%d",&m,&a,&b);
if(!m)break;
int mx=0,ans1,ans2;
for(int i=1;i<=cnt;i++)
{
int k=min(m/prime[i],b*prime[i]/a);
int tmp=i;
for(int j=14;j>=0;j--)
{
if(tmp+(1<<j)<=cnt&&prime[tmp+(1<<j)]<=k)
tmp+=(1<<j);
}
if(tmp==i&&prime[i]*prime[i]>m)break;
if(prime[i]*prime[tmp]>mx)
{
mx=prime[i]*prime[tmp];
ans1=prime[i],ans2=prime[tmp];
}
}
printf("%d %d\n",ans1,ans2);
}
return 0;
}
