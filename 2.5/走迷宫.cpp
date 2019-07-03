#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct XY{ int r,c; };
char g[42][42];
int step[42][42],zl[4][2]={{-1,0},{1,0},{0,-1},{0,1}},R,C;
XY node;
queue<XY> que;
const int INF=2e9;
void BFS()
{
int i;
int u,v;
node.r=1; node.c=1; que.push(node);
while (step[R][C]==INF)
{
u=que.front().r; v=que.front().c; que.pop();
for (i=0;i<4;i++)
if (g[u+zl[i][0]][v+zl[i][1]]=='.' && step[u+zl[i][0]][v+zl[i][1]]==INF)
{
step[u+zl[i][0]][v+zl[i][1]]=step[u][v]+1;
node.r=u+zl[i][0]; node.c=v+zl[i][1]; que.push(node);
}
}
}
int main()
{
int i,j;
scanf("%d %d",&R,&C);
memset(g,'#',sizeof(g));
for (i=1;i<=R;i++)
{
getchar();
for (j=1;j<=C;j++) g[i][j]=getchar();
}
for (i=1;i<=R;i++)
for (j=1;j<=C;j++) step[i][j]=INF;
step[1][1]=1; BFS();
printf("%d",step[R][C]);
return 0;
}
