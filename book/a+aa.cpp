#include<stdio.h>
int main()
{
int a,n,s,p,i;
scanf("%d %d",&a,&n);
s=0;
p=0;
for(i=1; i<=n; i++)
{
s=s*10+a;
p=p+s;//p为最后的结果
}
printf("%d\n",p);
}
