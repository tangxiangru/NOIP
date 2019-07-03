#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<queue>
#define rad 1000
using namespace std;
inline int read()
{
int x=0,f=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
return x*f;
}
int n,d;
struct data{int v[5005],l;}f[30];
void print(data a)
{
printf("%d",a.v[a.l]);
for(int i=a.l-1;i;i--)
printf("%03d",a.v[i]);
printf("\n");
}
data operator*(data a,data b)
{
data c;
for(int i=1;i<=a.l+b.l;i++)c.v[i]=0;
for(int i=1;i<=a.l;i++)
for(int j=1;j<=b.l;j++)
c.v[i+j-1]+=a.v[i]*b.v[j];
c.l=a.l+b.l;
for(int i=1;i<=c.l;i++)
if(c.v[i]>=rad)
{
if(i==c.l)
{
c.l++;
c.v[i+1]=c.v[i]/rad;
}
else c.v[i+1]+=c.v[i]/rad;
c.v[i]%=rad;
}
while(c.l>1&&!c.v[c.l])c.l--;
return c;
}
data operator^(data a,int p)
{
data c;
c.l=1;c.v[1]=1;
for(int i=p;i;i>>=1,a=a*a)
if(i&1)c=c*a;
return c;
}
data operator+(data a,int p)
{
a.v[1]+=p;
int now=1;
while(a.v[now]>=rad)
{
a.l=max(now+1,a.l);
a.v[now+1]+=a.v[now]/rad;
a.v[now]%=rad;
now++;
a.l=max(a.l,now);
}
return a;
}
data operator-(data a,data b)
{
for(int i=1;i<=a.l;i++)
{
a.v[i]-=b.v[i];
if(a.v[i]<0)
{
a.v[i]+=rad;
a.v[i+1]--;
}
}
while(a.l>1&&!a.v[a.l])a.l--;
return a;
}
int main()
{
n=read();d=read();
if(d==0){puts("1");return 0;}
f[0].l=1;f[0].v[1]=1;
for(int i=1;i<=d;i++)
f[i]=(f[i-1]^n)+1;
print(f[d]-f[d-1]);
return 0;
}

