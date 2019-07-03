#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int v[105],sum[105],f[105][105];

int main()
{
ios::sync_with_stdio(false);
int T;
cin>>T;
while(T--)
{
cin>>n;
for(int i=1;i<=n;i++)cin>>v[i],sum[i]=sum[i-1]+v[i];
for(int len=2;len<=n;len++)
for(int i=1;i+len-1<=n;i++)
{
f[i][len]=INT_MAX;
for(int k=i;k<=i+len-1;k++)
f[i][len]=min(f[i][len],f[i][k-i]+v[k]*(len-1)+f[k+1][i+len-k-1]+(sum[i+len-1]-sum[k])*(k-i));
}
cout<<f[1][n]<<endl;
}
return 0;
}
