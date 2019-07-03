#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define inf 1<<30

int main()
{
int n,m,i,j,t,ans,a,low[105],high[105],d[105];
while(scanf("%d%d",&n,&m)==2)
{
scanf("%d",&a);
for(i=1;i<=100;i++)
d[i]=i<a?inf:(a-i)*(a-i);
for(i=1;i<n;i++)
{
scanf("%d",&a);
for(t=inf,j=100;j>0;j--)
low[j]=t=min(t,d[j]+j*m);
for(t=inf,j=1;j<=100;j++)
{
high[j]=t=min(t,d[j]-j*m);
d[j]=inf;
}
for(j=a;j<=100;j++)
d[j]=(j-a)*(j-a)+min(low[j]-j*m,high[j]+j*m);
}
for(ans=inf,i=1;i<=100;i++)
ans=min(ans,d[i]);
printf("%d\n",ans);
}
}
