#include<cstdio>
#include<cstring>
const int N=5005;
const int MOD=1000007;
int n,m,k;
int f[N][N];//放到第i个格子,加上这一个格子已经放了j个球有多少种不同的方案
int o[N][N];
int mymin (int x,int y)
{
return x<y?x:y;
}
int main()
{
memset(f,0,sizeof(f));
scanf("%d%d%d",&n,&m,&k);
if (k>n) k=n;
for (int u=0;u<=k;u++)
f[1][u]=1;
o[1][0]=f[1][0];
for (int u=1;u<=n;u++)
o[1][u]=o[1][u-1]+f[1][u];;
for (int u=2;u<=m;u++)
{
for (int i=0;i<=mymin(n,k*u);i++)
{
int j=mymin(k,i);
f[u][i]=f[u][i]+o[u-1][i]+MOD-o[u-1][i-j-1];
f[u][i]%=MOD;
}
o[u][0]=f[u][0];
for (int i=1;i<=n;i++)
{
o[u][i]=o[u][i-1]+f[u][i];
o[u][i]%=MOD;
}
}
printf("%d\n",f[m][n]%MOD);
return 0;
}
