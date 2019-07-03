#include <cstdio>
int f[51]={},n,i,j;
int main()
{
f[0]=1;f[2]=3;
for (i=4; i<=50; i++)
{
f[i]=f[i-2];
for (j=0; j<=i-2; j++)
if ((i-2-j)%2==0) f[i]+=f[j]*2;
}
while (scanf("%d",&n),n!=-1) printf("%d\n",f[n]);
}
