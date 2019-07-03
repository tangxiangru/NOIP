#include"iostream"
#include"stdio.h"
#include"string.h"
#include"algorithm"
#include"queue"
#include"vector"
using namespace std;
#define N 105
#define LL __int64
const int inf=1000000;
char str[N][N];
int n,m;
int dir[4][2]= {0,1,0,-1,1,0,-1,0};
int mark[N][N];
int ans;
int vis[N][N][11];
struct node
{
int x,y,t,id;
int s; //记录该条路径每个蛇的状态
friend bool operator<(node a,node b)
{
return a.t>b.t;
}
};
int min(int a,int b)
{
return a<b?a:b;
}
bool judge(int x,int y)
{
if(x>=0&&x<n&&y>=0&&y<n&&str[x][y]!='#')
return true;
return false;
}
int bfs(int x,int y)
{
int i,di,dj;
priority_queue<node>q;
node cur,next;
cur.x=x;
cur.y=y;
cur.t=0;
cur.id=1;
cur.s=0;
q.push(cur);
while(!q.empty())
{
cur=q.top();
q.pop();
x=cur.x;
y=cur.y;
//printf("%c t=%d id=%d num=%d\n",str[x][y],cur.t,cur.id,cur.num);
if(str[x][y]=='T'&&cur.id==m+1)
{
ans=min(ans,cur.t);
break;
}
for(i=0; i<4; i++)
{
next.x=di=cur.x+dir[i][0];
next.y=dj=cur.y+dir[i][1];
next.t=cur.t+1;
next.id=cur.id;
next.s=cur.s;
if(judge(di,dj))
{
if(str[di][dj]=='S')
{
int k=mark[di][dj];
if(((1<<k)&next.s)==0)
{
next.t++;
next.s|=(1<<k);
}
}
if(str[di][dj]-'0'==cur.id)
{
next.id=cur.id+1;
}
if(next.t<vis[di][dj][next.id]&&next.t<ans)
{
vis[di][dj][next.id]=next.t;
q.push(next);
}
}
}
}
}
int main()
{
int i,j;
while(scanf("%d%d",&n,&m),n||m)
{
int k=0;
memset(mark,-1,sizeof(mark));
for(i=0; i<n; i++)
{
scanf("%s",str[i]);
for(j=0; j<n; j++)
{
if(str[i][j]=='S')
{
mark[i][j]=k++;
}
for(int l=0; l<11; l++)
vis[i][j][l]=inf;
}
}
ans=inf;
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
if(str[i][j]=='K')
{
bfs(i,j);
break;
}
}
if(j<n)
break;
}
if(ans==inf)
printf("impossible\n");
else
printf("%d\n",ans);
}
return 0;
}
