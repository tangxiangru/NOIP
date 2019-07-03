#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
#define siji(i,x,y) for(int i=(x);i<=y;i++)
#define gongzi(j,x,y) for(int j=(x);j>=y;j--)
#define ivory(z,x) for(int z=h[x];z;z=e[z].n)
#define pii pair<int,int>
#define pi acos(-1.0)
#define fi first
#define se second
#define mod 1000007
using namespace std;
typedef long long ll;
int n,m,k;
ll dp[16][16],c[16][16];
int main()
{
//freopen("f1.in","r",stdin);
ios::sync_with_stdio(false);
siji(i,0,15) c[i][0]=1;
siji(i,1,15) siji(j,1,i)
{
c[i][j]=c[i-1][j-1]+c[i-1][j];
}
while(1)
{
cin>>n>>m>>k;
if(!n) break;
if(k*m>n) {cout<<0<<endl;continue;}
memset(dp,0,sizeof(dp));
siji(i,k,n) dp[1][i]=c[n][i];
siji(g,2,m)
siji(j,(g-1)*k,n)
{
siji(z,j+k,n)
{
dp[g][z]+=dp[g-1][j]*max(c[n-j][z-j],(ll)1);
}
}
cout<<dp[m][n]<<endl;
}
return 0;
}
