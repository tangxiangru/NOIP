//有问题

#include <stdio.h>
#include<math.h>
int main()
{
int c,i,j,t=0,s[10190]={0};///数组开小了，开大一些，恭喜你AC了
int m,a,b,k=0,max=0;
int p,q;

for (c=2;c<10000;c++)
{
for (i=2;i<=(c-1);i++)
if (c%i==0)
break;
if (i>=c)
{
s[t]=c;
t++;
}
}

while(scanf("%d %d %d",&m,&a,&b)!=EOF)
{
max=0; p=0;q=0;
if(a==0&&b==0&&m==0)break;
for (i=t-1;i>=0;i--)
{
if(s[i]>m/2)continue;
for(j=i;j<t;j++)
{
if(s[j]>m/2||s[j]*s[i]>m||a*s[j]>b*s[i]) break;
else if(s[j]*s[i]>max)
{
max=s[i]*s[j];
p=s[i];
q=s[j];
}
}
}

printf("%d %d\n",p,q);
}
return 0;
}
