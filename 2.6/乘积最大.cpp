#include<iostream>
#define ll long long
#include<cstdio>
using namespace std;
char a[10006];
ll ans[1006][1006];
ll n,k;
ll change(int x,int y)
{
ll ans=0;
for(int i=x;i<=y;i++)
ans=ans*10+(a[i]-'0');
return ans;
}
int main()
{
scanf("%d%d",&n,&k);
for(int i=1;i<=n;i++)
{
cin>>a[i];
ans[i][0]=change(1,i);
}
for(int i=1;i<=k;i++)
for(int j=1;j<=n;j++)
for(int m=1;m<=j;m++)
if(ans[m][i-1]*change(m+1,j)>ans[j][i])
ans[j][i]=ans[m][i-1]*change(m+1,j);
printf("%d",ans[n][k]);
return 0;
}
