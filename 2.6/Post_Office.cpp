#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf=1000000000;
int b[301][301],a[500],dp[301][301],m,n,ans;
int main(){
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=n;i++){
for(int j=i+1;j<=n;j++)
b[i][j]=inf;
for(int j=1;j<=m;j++)
dp[j][i]=inf;
}
for(int i=1;i<n;i++)
for(int j=i+1;j<=n;j++){
int k=(i+j)/2,t=0;
for(int q=i;q<k;q++)
t+=a[k]-a[q];
for(int q=j;q>k;q--)
t+=a[q]-a[k];
b[i][j]=min(b[i][j],t);
}
for(int i=1;i<=n;i++)
dp[1][i]=b[1][i];
for(int i=2;i<=m;i++)
for(int j=i;j<=n;j++)
for(int q=i;q<j;q++){
dp[i][j]=min(dp[i][j],dp[i-1][q]+b[q+1][j]);
}
cout<<dp[m][n];
return 0;
}

