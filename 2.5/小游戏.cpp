#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a,b;
int qx,qy,zx,zy;
char dt[90][90];
int jsqq;
struct dd{
int x,y,step,zt;
}dl[5000];
int zfx[5]={0,0,0,1,-1};
int zfy[5]={0,1,-1,0,0};
bool zg[100][100];
void bfs()
{
int tail=1;
int head=0;
dl[1].x=qx;
dl[1].y=qy;
zg[qx][qy]=1;
do
{
head++;
for(int i=1;i<=4;i++)
{
int x=dl[head].x+zfx[i];
int y=dl[head].y+zfy[i];
if(x>=0&&y>=0&&x<=b+1&&y<=a+1&&!zg[x][y]&&(dt[x][y]!='X'||(x==zx&&y==zy)))
{
tail++;
dl[tail].x=x;
dl[tail].y=y;
dl[tail].step=dl[head].step;
if(i!=dl[head].zt)dl[tail].step++;
dl[tail].zt=i;
zg[x][y]=1;
if(x==zx&&y==zy)
{
cout<<"Pair "<<jsqq<<": "<<dl[tail].step<<" "<<"segments.";
return;
}
}
}
}while(head<tail);
cout<<"Pair "<<jsqq<<": impossible.";
}
int main()
{
// freopen("1804.in","r",stdin);
// freopen("1804.out","w",stdout);
int jsq=0;
while(cin>>a>>b&&a&&b)
{
jsq++;
getchar();
cout<<"Board #"<<jsq<<":"<<endl;
memset(dt,0,sizeof(dt));
for(int i=1;i<=b;i++)
gets(dt[i]+1);
jsqq=0;
while(cin>>qy>>qx>>zy>>zx&&qx&&qy&&zx&&zy)
{
// qx--;qy--;zx--;zy--;
memset(zg,0,sizeof(zg));
memset(dl,0,sizeof(dl));
jsqq++;
bfs();
cout<<endl;
}
cout<<endl;
}
return 0;
}
