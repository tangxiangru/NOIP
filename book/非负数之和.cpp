#include<stdio.h>

int main()
{ int a[20] ;
int k=0,sum=0,i;

for (i=0;i<20;i++)
{
scanf("%d",&a[i]);
if(a[i]<0)
{
sum+=a[i];/负数之和/
k++;/计数/
}
}
printf("%d %d",sum,k);
return 0;
}
