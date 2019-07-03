#include<bits/stdc++.h>
char ma[110][110];
int n,m,sx,sy,ex,ey;
struct nod{int x,y,t;} f[10010];
int tou,wei;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
void bfs()
{
tou=1,wei=2;
f[1].x=sx; f[1].y=sy; f[1].t=0;
while(tou<wei)
{
for (int i=0;i<=3;i++)
{
int nx=f[tou].x+dx[i];
int ny=f[tou].y+dy[i];
if (nx==ex&&ny==ey)
{
printf("%d\n",f[tou].t+1);
return ;
}
if (nx>=1&&nx<=n&&ny>=1&&ny<=m)
{
if (ma[nx][ny]=='.')
{
ma[nx][ny]='#';
f[wei].x=nx;f[wei].y=ny;
f[wei].t=f[tou].t+1;wei++;
}
}
}
tou++;
}
}
int main()
{
scanf("%d %d",&n,&m);
int tt=0;
for (int i=1;i<=n;i++)
{
scanf("%s",ma[i]+1);
for (int j=1;j<=m;j++)
{
if (ma[i][j]=='S') {sx=i; sy=j; tt++;}
if (ma[i][j]=='T') {ex=i; ey=j; tt++;}
}
}
if(tt==2)
{
bfs();
}
return 0;
}
