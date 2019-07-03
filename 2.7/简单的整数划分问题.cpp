#include<cstdio>
#include<cstring>
using namespace std;
int n,ans=0;
void dfs(int x,int k)
{
if(x==0)
{
ans++;return ;
}
else if(x>0)
{
for(int i=k;i<=x;i++)
{
if((x-i)>=0)
{
dfs(x-i,i);
}
else return ;
}
}
else return ;
}
int main()
{
while(scanf("%d",&n)!=EOF)
{
ans=0;
dfs(n,1);
printf("%d\n",ans);
}
return 0;
}
