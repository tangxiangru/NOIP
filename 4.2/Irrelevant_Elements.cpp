#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn= 32000;
int prime[maxn+1];
int nprime;
void getPrime()
{
int m=sqrt(maxn+0.5);
for(int i=2; i<=m; ++i) if(!prime[i])
for(int j=i*i; j<=maxn; j+=i) prime[j]=1;
nprime=0;
for(int i=2; i<=maxn; ++i)
{
if(!prime[i])
prime[nprime++]=i;
}
}
int n,m;
int pm[20];
int em[20];
int im;
void init()
{
memset(pm,0,sizeof(pm));
memset(em,0,sizeof(em));
im=0;
for(int i=0; i<nprime&&m>=prime[i]; i++)
{
if(m%prime[i]==0)
{
pm[im]=prime[i];
while((m%prime[i]==0)&&(m/=prime[i]))
em[im]++;
im++;
}
if(n==0||n==1)
break;
}
if(m>1)
{
pm[im]=m;
em[im]=1;
im++;
}
}
bool getFactors(int x,int y)
{
bool ff=true;
for(int i=0; i<im; ++i)
{
while((x%pm[i]==0)&&(x/=pm[i]))
em[i]--;
while(y%pm[i]==0&&(y/=pm[i]))
em[i]++;
if(em[i]>0)
ff=false;
}
return ff;
}
bool flag[100010];
int main()
{
getPrime();
while(scanf("%d%d",&n,&m)!=EOF)
{
init();
memset(flag,false,sizeof(flag));
int ans=0;
int ends=0;
for(int i=1; i<=n; ++i)
if(getFactors(n-i,i))
{
flag[i+1]=true;
ans++;
ends=i+1;
}
printf("%d\n",ans);
if(ans!=0)
{
for(int i=1; i<ends; i++)
if(flag[i])
printf("%d ",i);
printf("%d",ends);
}
printf("\n");
}
return 0;
}
