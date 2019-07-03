#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int a[1010];
int main()
{
int n,i,j;
while(scanf("%d",&n)&&n)
{
for(i=0;i<n;++i)
scanf("%d",&a[i]);
sort(a,a+n);
int ans=INF,cnt;
for(i=n-1;i>=0;--i)
{
for(j=n-1;j>=0;--j)
{
if(i==j)
continue;
cnt=a[i]-a[j];
for(int l=0,r=j-1;l<r;)
{
if(a[l]+a[r]==cnt)
{
ans=a[i];
break;
}
if(a[l]+a[r]>cnt)
r--;
else
l++;
}
if(ans!=INF)
break;
}
if(ans!=INF)
break;
}
if(ans!=INF)
printf("%d\n",ans);
else
printf("no solution\n");
}
return 0;
}
