#include<cstdio>
#include <iostream>
using namespace std;
int main()
{
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int y[13]={0,3,0,3,2,3,2,3,3,2,3,2,3};
int i,n,l=1,year,f=0,m;
scanf("%d%d",&year,&m);
if((year%4==0&&year%100!=0)||(year%400==0))
{
month[2]=29;
y[2]=1;
}
printf("Sun Mon Tue Wed Thu Fri Sat\n");
l=l+(year-1900)+((year-1900)/4);
for(i=1;i<=m;i++)
{
l=l+y[i-1];
if(l>=7) l=l%7;
}
if(y[2]==1) l=l-1;
for(i=1;i<=l;i++)
{
printf(" ");
f++;
}
for(i=1;i<=month[m];i++)
{
printf("%3ld ",i);
f++;
if(f==7)
{
printf("\n");
f=0;
}
}
return 0;
}
