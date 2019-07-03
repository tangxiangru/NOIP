#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define DEBUG(x) cout<<#x<<" = "<<x<<endl
using namespace std;
int R,C;
char Map[30][30];
///标记地图是否访问过
int visited[30][30];
///标记字母是否出现过
int exist[30];
int maxStep=-1;
int tempStep[30][30];
int dirx[]={1,-1,0,0};
int diry[]={0,0,1,-1};
void dfs(int x,int y,int step)
{///当前位于x,y 长度是step
if(maxStep==26)return;///最大不超过26
///无效的情况
if(x<0||y<0||x>=R||y>=C||visited[x][y])return;
int ch=Map[x][y]-'A';
if(exist[ch])return;
exist[ch]=true;
visited[x][y]=true;
maxStep=max(maxStep,step);
for(int i=0;i<4 ;i++ ){
int xx=x+dirx[i];
int yy=y+diry[i];
dfs(xx,yy,step+1);
}
///寻找一条路径，所以需要回溯
exist[ch]=false;
visited[x][y]=false;
}
int main()
{
// freopen("in.txt","r",stdin);
scanf("%d%d",&R,&C);
for(int i=0;i<R ;i++ ){
getchar();
for(int j=0;j<C ;j++ ){
scanf("%c",&Map[i][j]);
}
}
dfs(0,0,1);
printf("%d\n",maxStep);
}
