#include<iostream>
#include<cstring>
using namespace std;
long long dp[2][501][501]={};
long long dist[501][501]={};
int main(){
int n,m;
while(cin>>n>>m){
for(int i=0;i<=n;++i)
for(int j=0;j<=n;++j){
dist[i][j]=30000000;
dp[0][i][j]=30000000;
dp[1][i][j]=30000000;
}
dp[0][0][0]=0;
for(int i=0;i<=n;++i)
dist[i][i]=0;
for(int i=0;i<m;++i){
long long x,y,len;
cin>>x>>y>>len;
dist[x][y]=min(dist[x][y],len);
dist[y][x]=min(dist[x][y],dist[y][x]);
dist[x][y]=dist[y][x];
}
for(int k=0;k<=n;++k)
for(int i=0;i<=n;++i)
for(int j=0;j<=n;++j)
dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
for(int i=0;i<n;++i){
for(int j=0;j<=i;++j)
for(int k=j;k<=i;++k){
dp[(i+1)%2][j][k]=min(dp[(i+1)%2][j][k],dp[i%2][j][k]+dist[i+1][i]);
dp[(i+1)%2][k][i]=min(dp[(i+1)%2][k][i],dp[i%2][j][k]+dist[j][i+1]);
dp[(i+1)%2][j][i]=min(dp[(i+1)%2][j][i],dp[i%2][j][k]+dist[k][i+1]);
}
memset(dp[i%2],0x6f,sizeof(dp[i%2]));
}
long long result=1<<30;
for(int i=0;i<=n;++i)
for(int j=i;j<=n;++j){
result=min(result,dp[n%2][i][j]+dist[i][0]+dist[j][0]+dist[n][0]);
}
cout<<result<<endl;
}
}
