#include<bits/stdc++.h>
int n,m,f[20][20];
int main()
{
scanf("%d%d",&m,&n);
for(int i=1;i<=m;i++) f[i][1]=1;
for(int i=1;i<=n;i++) f[1][i]=1;
for(int i=2;i<=m;i++)
{
for(int j=2;j<=n;j++)
f[i][j]=f[i-1][j]+f[i][j-1];
}
printf("%d",f[m][n]);
return 0;
}
