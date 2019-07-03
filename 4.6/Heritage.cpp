#include<cstdio>
#include<cstdlib>
#define inf 1000000000
#define maxn 100000
using namespace std;
int len1,len2,len3,len[18];
long long a[maxn],b[maxn],ans[maxn],res[18][maxn];
void setAns()
{
for(int i=0;i<len3;i++)
ans[i]=0;
}
void copy()
{
for(int i=0;i<len3;i++)
a[i]=ans[i];
len1=len3;
}
void multiply()
{
int i,j;
setAns();
for(i=0;i<len2;i++)
{
for(j=0;j<len1;j++)
{
ans[i+j]+=a[j]*b[i];
ans[i+j+1]+=ans[i+j]/inf;
if (ans[i+j+1] && len3<=i+j+1)
len3=i+j+2;
else if (len3<=i+j)
len3=i+j+1;
ans[i+j]%=inf;
}
}
}
void plus()
{
int r;
for(len2=0,r=1;len2<len1;len2++)
{
r+=a[len2];
if(r>=inf)
{
b[len2]=r-inf;
r=1;
}
else
{
b[len2]=r;
r=0;
}
}
if(r)
b[len2++]=r;
}
int main()
{
int i,j,n;
scanf("%d",&n);
a[0]=2;
len1=1;
printf("2\n");
for(i=2;i<=n;i++)
{
plus();
printf("%lld",b[len2-1]);
for(j=len2-2;j>=0;j--)
printf("%.9lld",b[j]);
printf("\n");
if (i<n)
{
multiply();
co();
}
}
return 0;
}
