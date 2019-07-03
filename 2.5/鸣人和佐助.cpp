# include <iostream>
using namespace std;
int d[100000];
bool mr[210][210][11];
char a[210][210];
int u[5]={0,0,0,1,-1},
v[5]={0,1,-1,0,0};
int zx[100000],zy[100000],zz[100000];
int main()
{
int m,n,x1,y1,chark;
cin>>m>>n>>chark;
for(int i=1;i<=m;i++)
for(int j=1;j<=n;j++)
{
cin>>a[i][j];
if(a[i][j]=='@')
x1=i,y1=j;
}
mr[x1][y1][chark]=1;
int head=0,tail=1;
d[1]=0;
zx[1]=x1,zy[1]=y1,zz[1]=chark;
while(head<tail)
{
head++;
for(int i=1;i<=4;i++)
{
int x=zx[head]+u[i];
int y=zy[head]+v[i];
int z=zz[head];
if(x>0&&x<=m&&y>0&&y<=n&&mr[x][y][z]==0&&a[x][y]!='#')
{
tail++;
mr[x][y][z]=1;
zx[tail]=x;
zy[tail]=y;
zz[tail]=z;
d[tail]=d[head]+1;
if(a[x][y]=='+')
{
cout<<d[tail];
return 0;
}
}
if(x>0&&x<=m&&y>0&&y<=n&&mr[x][y][z]==0&&a[x][y]=='#'&&z>0)
{
tail++;
mr[x][y][z-1]=1;
zx[tail]=x;
zy[tail]=y;
zz[tail]=z-1;
d[tail]=d[head]+1;
}
}
}
cout<<-1;
return 0;
}
