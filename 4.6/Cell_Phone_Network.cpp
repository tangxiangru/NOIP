#include <stdio.h>
#include <vector>
#include <string.h>
#define N 10005
#define INF 2000000
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

vector<int>gra[N];
int fa[N],dp[N][3],n;

void dfs(int s,int f)
{
fa[s]=f;
dp[s][0]=0;
dp[s][1]=1;
dp[s][2]=0;
if(gra[s].size()==1&&gra[s][0]==f)
{
dp[s][2]=INF;
return ;
}
int mark=0;
for(int i=0;i<gra[s].size();i++)
{
int t=gra[s][i];
if(t==f)continue;
dfs(t,s);
dp[s][1]+=MIN(MIN(dp[t][0],dp[t][1]),dp[t][2]);
dp[s][0]+=dp[t][2];
if(dp[t][1]<=dp[t][2])
{
mark=1;
dp[s][2]+=dp[t][1];
}
else
dp[s][2]+=dp[t][2];
}
if(mark)return ;
int temp=INF;
for(int i=0;i<gra[s].size();i++)
{
int t=gra[s][i];
if(t==f)continue;
temp=MIN(temp,dp[s][2]+dp[t][1]-dp[t][2]);
}
if(temp!=INF)
dp[s][2]=temp;
}

void re(void)
{
scanf("%d",&n);
memset(fa,0,sizeof(fa));
memset(dp,0,sizeof(dp));
for(int i=1;i<=n;i++)
gra[i].clear();
for(int i=1;i<n;].push_back(a);
}
}

void run(void)
{
dfs(1,-1);
printf("%d\n",MIN(dp[1][1],dp[1][2]));
}

int main()
{
re();
run();
}
