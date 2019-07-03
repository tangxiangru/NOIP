#include <stdio.h>
int main()
{
int t,n,i;
int t1,t2;
int dp[1100]={1,1,5};
for(i=3;i<=1000;i++)
{
dp[i]=dp[i-1]+4*dp[i-2];
t2=i;
t1=i-3;
while(1)
{
if(t1<0)break;
dp[t2]+=2*dp[t1];
t1-=2;
}
t1=i-4;
while(1)
{
if(t1<0)break;
dp[t2]+=3*dp[t1];
t1-=2;
}
}
scanf("%d",&t);
for(int cas=1;cas<=t;cas++)
{
scanf("%d",&n);
printf("%d %d\n",cas,dp[n]);
}
return 0;
}


