#include<stdio.h>
int f[1005][505];
int main()
{
int i,i1,i2,n,m,k,balls,dm;
scanf("%d%d%d",&n,&m,&k);
for(i=0;i<k;i++)
{
scanf("%d%d",&balls,&dm);
for(i1=n;i1>=balls;i1--)
{
for(i2=m;i2>=dm;i2--)
{
if(f[i1-balls][i2-dm]+1>f[i1][i2]) f[i1][i2]=f[i1-balls][i2-dm]+1;
}
}
}
printf("%d ",f[n][m]);
i=m;
while(i>=0&&f[n][i]==f[n][m]) i--;
printf("%d",m-i-1);
return 0;
}
