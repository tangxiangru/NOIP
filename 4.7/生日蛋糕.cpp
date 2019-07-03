/*
搜索，剪枝
前两个最优性剪枝比较好想
关键是第三个：2*(n-V)/R>=ans-S
这是一个将体积与表面积结合的可行性剪枝
因为这一题搜索涉及两个变量，单纯对每一个变量剪枝效果甚微
所以这个剪枝最强效！！
证明：
剩余表面积=2*Σ（ri*hi）
剩余体积= Σ （ri*ri*hi）
剩余表面积=剩余体积*2/ri>=剩余体积*2/当前r
（剩下的ri一定比当前的r小，如果只剩一层就是等于，所以上式是>=）
即剩余最小表面积=剩余体积*2/当前r
如果它+当面表面积>=ans return
*/
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans=2e9;
int rest_V[20],rest_S[20];
void dfs(int now,int V,int S,int R,int H)
{
    if(now>m)
    {
        if(V==n) ans=min(ans,S);
        return ;
    }
    if(S+rest_S[m-now+1]>=ans) return;
    if(V+rest_V[m-now+1]>n) return;
    if(2*(n-V)/R>=ans-S) return;
    for(int i=R-1;i>=m-now+1;i--)
     for(int j=H-1;j>=m-now+1;j--)
      if(V+i*i*j<=n) dfs(now+1,V+i*i*j,S+2*i*j+(now==1)*i*i,i,j);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        rest_V[i]=rest_V[i-1]+i*i*i;
        rest_S[i]=rest_S[i-1]+2*i*i;
    }
    dfs(1,0,0,sqrt(n),n);
    if(ans==2e9) ans=0;
    printf("%d",ans);
}
