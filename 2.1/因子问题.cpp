#include<cstdio>
int main()
{
int m,n;
scanf("%d%d",&m,&n);
for(int i=1;i<=n/2;i++)
if(m%i==0&&m%(n-i)==0)
{
printf("%d",i);
return 0;
}
printf("-1");
return 0;
}

