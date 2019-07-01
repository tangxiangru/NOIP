#include<cstdio>
#include<cstring>
using namespace std;
int a[10001],ans[1001][1001];
int main()
{
int n,x,k,s,max=0,ans1;
scanf("%d",&n);
while(n--)
{
scanf("%d%d",&x,&k);
while(k--)
{
scanf("%d",&s);
a[s]++;
ans[x][s]=1;
if(a[s]>max){ans1=s;max=a[s];}
}
}
printf("%d\n",ans1);
for(int i=0;i<=100;i++)
if(ans[i][ans1]==1)printf("%d ",i);
printf("\n");
return 0;
}
