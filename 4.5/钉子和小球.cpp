#include<stdio.h>
char c[51][51];
long long f[51][51];
int main()
{
int n,m,i,j;
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
for(j=1;j<=i;j++)
do c[i][j]=getchar();
while(c[i][j]!='*'&&c[i][j]!='.');
f[0][1]=1;
for(i=1;i<=n;i++)
for(j=1;j<=i+1;j++)
{
if(c[i][j-1]=='*')
f[i][j]+=f[i-1][j-1];
if(c[i][j]=='*')
f[i][j]+=f[i-1][j];
if(c[i-1][j-1]=='.')
f[i][j]+=f[i-2][j-1]*4;
}
long long a=f[n][m+1],b=0;
for(i=1;i<=n+1;i++)
b+=f[n][i];
while(a%2==0)
a/=2,b/=2;
printf("%lld/%lld",a,b);
return 0;
}
