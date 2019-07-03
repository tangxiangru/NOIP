#include<bits/stdc++.h>
using namespace std;
int main()
{
int f[102][102];
int dp[102];
int now[102];
int n,x,max1=0;
cin>>n;//输入行、列数
memset(f,0,sizeof(f));
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
cin>>x;
f[i][j]=f[i-1][j]+x;//求每个点的所在列前缀和
}
max1=0;
for(int i=1;i<=n;i++)
for(int j=i;j<=n;j++)//前两层列举行
for(int k=1;k<=n;k++)//第三层列举列
{
now[k]=f[j][k]-f[i-1][k];//记录当前列段的和
dp[k]=max(dp[k-1]+now[k],now[k]);//递推
if(dp[k]>max1)
max1=dp[k];//更新最大值
}
cout<<max1;//输出最大值
return 0;
}
