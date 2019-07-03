#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <iostream>
#include <memory.h>
#include <limits.h>
#include <queue>
#define shability 85
using namespace std;

int shabi[shability][shability];
int zhizhangel[shability][shability];
int bendan[shability][shability];
int n,m;
struct NODE
{
int x,y;
int zhizhang;
}hahaha,start,jilao;

queue<NODE> SB;

bool naocan(const int &x,const int &y,const int mode)
{
if(mode<4)
{
if(mode==0)
return shabi[x-1][y-1] && shabi[x-1][y];
else
return shabi[x][y] && shabi[x][y-1];
}
else
{
if(mode==4)
return shabi[x][y-1] && shabi[x-1][y-1];
else
return shabi[x][y] && shabi[x-1][y];
}
}

void pushQueue(const int &x,const int &y,const int &zhizhang)
{
NODE temp;
temp.x=x;
temp.y=y;
temp.zhizhang=zhizhang;
SB.push(temp);
}

int main(void)
{
int dis[]={-1,0,1,0,0,-1,0,1};
int ncases;
char ch;
int x,y,zhizhang,a,b;
scanf("%d",&ncases);
while(ncases--)
{
scanf("%d%d",&n,&m);
scanf("%d%d%d%d",&start.x,&start.y,&hahaha.x,&hahaha.y);

memset(shabi,0,sizeof(shabi));
memset(zhizhangel,0,sizeof(zhizhangel));
for (int i=0;i<=n;++i)
for (int j=0;j<=m;++j)
bendan[i][j]=INT_MAX;

for(int i=0;i<n;++i)
{
getchar();
for(int j=0;j<m;++j)
{
scanf("%c",&ch);
shabi[i][j]=ch-'0';
if(shabi[i][j])
{
zhizhangel[i][j]=zhizhangel[i][j+1]=zhizhangel[i+1][j]=zhizhangel[i+1][j+1]=n+m;
pushQueue(i,j,n+m);
pushQueue(i,j+1,n+m);
pushQueue(i+1,j,n+m);
pushQueue(i+1,j+1,n+m);
}
}
}

while(!SB.empty())
{
jilao=SB.front();
SB.pop();
x=jilao.x,y=jilao.y,zhizhang=jilao.zhizhang-1;
for(int i=0;i<8;i+=2)
{
a=x+dis[i];
b=y+dis[i+1];
if(a>=0 &&a<=n &&b>=0 &&b<=m && !naocan(x,y,i) && zhizhang>zhizhangel[a][b])
{
zhizhangel[a][b]=zhizhang;
jilao.x=a;
jilao.y=b;
jilao.zhizhang=zhizhang;
SB.push(jilao);
}
}
}
start.zhizhang=bendan[start.x][start.y]=zhizhangel[start.x][start.y];
hahaha.zhizhang=zhizhangel[hahaha.x][hahaha.y];
SB.push(start);
while(!SB.empty())
{
jilao=SB.front();
SB.pop();
x=jilao.x;
y=jilao.y;
zhizhang=jilao.zhizhang;
for(int i=0;i<8;i+=2)
{
a=x+dis[i];
b=y+dis[i+1];
if(a>=0 &&a<=n &&b>=0 &&b<=m && !naocan(x,y,i) && zhizhang+zhizhangel[a][b]<bendan[a][b])
{
bendan[a][b]=zhizhang+zhizhangel[a][b];
jilao.x=a;
jilao.y=b;
jilao.zhizhang=bendan[a][b];
SB.push(jilao);
}
}

}
if(bendan[hahaha.x][hahaha.y]==INT_MAX)
printf("no solution\n");
else
printf("%d\n",bendan[hahaha.x][hahaha.y]);

}
return 0;
}
