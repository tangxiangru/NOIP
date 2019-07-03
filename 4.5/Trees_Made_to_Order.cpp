#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define LL long long
#define MAXN 550000000
using namespace std;
LL dp[201];
LL ans[201];
struct list
{
LL l,r;
}node[51];
void init()
{
LL i,j;
memset(dp,0,sizeof(dp));
dp[0]=1;
dp[1]=1;
for(i=2;;i++)
{
for(j=0;j<=i-1;j++)
{
dp[i]=dp[i]+dp[j]*dp[i-j-1];
}
if(dp[i]>MAXN)break;
}
for(j=1;j<=i;j++)ans[j]=ans[j-1]+dp[j];
}
void dos(LL x,LL n,LL shu)
{
if(shu==0)return;
if(n==0)return;
node[x].l=0;
node[x].r=0;
LL ff;
ff=0;
LL i;
for(i=0;i<=n-1;i++)
{
ff+=dp[i]*dp[n-1-i];
if(ff>=shu)
{
ff=shu-(ff-dp[i]*dp[n-1-i]);
LL ks;
ff--;
ks=ff/(dp[n-1-i]);
ff++;
ks++;
dos(x+1,i,ks);
if(i)node[x].l=x+1;
ks=ff%(dp[n-1-i]);
if(ks==0)ks=dp[n-1-i];
dos(x+1+i,n-1-i,ks);
if(n-1-i)node[x].r=x+1+i;
return;
}
}
}
string lian(int x)
{
string ss;
if(node[x].l)ss=ss+"("+lian(node[x].l)+")";
ss=ss+"X";
if(node[x].r)ss=ss+"("+lian(node[x].r)+")";
return ss;
}
int main()
{
LL n,i;
init();
while(~scanf("%I64d",&n)&&n)
{
for(i=1;;i++)
{
if(ans[i]>=n)break;
}
dos(0,i,n-ans[i-1]);
string str;
str=lian(0);
cout<<str<<endl;
}
return 0;
}
