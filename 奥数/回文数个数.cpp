#include<cstdio>
int main()
{
int n,p=9,ans=0;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
if (i&1&&i!=1) p*=10;
ans+=p;
}
printf("%d",ans);
return 0;
}
