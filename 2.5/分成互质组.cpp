#include<bits/stdc++.h>
using namespace std;
int n,a[11],e[11][11]={0},num[11],maxs=0;
int gcd(int a,int b)
{
return b==0?a:gcd(b,a%b);
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
for(int i=1;i<n;i++)
for(int j=i+1;j<=n;j++)e[i][j]=gcd(a[j],a[i]);
for(int i=1;i<=n;i++)
{
num[i]=1;
for(int j=1;j<i;j++)if(e[j][i]!=1)num[i]=max(num[i],num[j]+1);
maxs=max(maxs,num[i]);
}
cout<<maxs;
}
