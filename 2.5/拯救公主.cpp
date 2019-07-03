# include <iostream>
# include <cstring>
# include <cmath>
# include <cstdio>
using namespace std;
char a[210][210];
int zx[10000],zy[10000],zz[10000],d[10000];
int r[10000],t[10000];
bool b[201][201][100];
int s=0;
bool f;
int w;
int u[]={0,0,1,-1,0},v[]={0,1,0,0,-1};
bool pd(int q)
{
for(int i=1;i<=w;i++)
{
int ee=pow(2,i);
if((q&ee)!=ee)
return 0;
}
return 1;
}
int main()
{
int pp;
cin>>pp;
for(int qq=1;qq<=pp;qq++)
{
int h,l;
cin>>h>>l>>w;
s=0,f=0;
memset(zx,0,sizeof(zx));
memset(a,0,sizeof(a));
memset(r,0,sizeof(r));
memset(t,0,sizeof(t));
memset(zy,0,sizeof(zy));
memset(zz,0,sizeof(zz));
memset(d,0,sizeof(d));
memset(b,0,sizeof(b));
scanf("\n");
for(int i=1;i<=h;i++)
{
for(int j=1;j<=l;j++)
{
char x=getchar();
if(x=='\n')
{
j--;
continue;
}
a[i][j]=x;
if(a[i][j]=='$')
{
s++;
r[s]=i,t[s]=j;
}
if(a[i][j]=='S')
{
zx[1]=i,zy[1]=j;
b[i][j][0]=1;
}
}
}
d[1]=0;
long long head=0,tail=1;
zz[1]=0;
while(head!=tail)
{
head++;
if(head==9999)
head=1;
for(int i=1;i<=4;i++)
{
int x=zx[head]+u[i];
int y=zy[head]+v[i];
int o=zz[head];
if(a[x][y]!='#'&&b[x][y][o]==0&&x>=1&&x<=h&&y>=1&&y<=l)
{
b[x][y][o]=1;
if(a[x][y]=='$')
{
for(int j=1;j<=s;j++)
{
if(b[r[j]][t[j]][o]==0)
{
tail++;
if(tail==9999)
tail=1;
zx[tail]=r[j];
zy[tail]=t[j];
zz[tail]=o;
d[tail]=d[head]+1;
}
}
tail++;
if(tail==9999)
tail=1;
zx[tail]=x;
zy[tail]=y;
zz[tail]=o;
d[tail]=d[head]+1;
continue;
}
if(a[x][y]>='0'&&a[x][y]<='5')
{
tail++;
if(tail==9999)
tail=1;
zx[tail]=x;
zy[tail]=y;
d[tail]=d[head]+1;
int tt=a[x][y]-'0'+1;
int yy=pow(2,tt);
if((o&yy)!=yy)
{
o+=yy;
}
zz[tail]=o;
continue;
}
tail++;
if(tail==9999)
tail=1;
zx[tail]=x;
zy[tail]=y;
d[tail]=d[head]+1;
zz[tail]=o;
if(a[x][y]=='E'&&pd(o)==1)
{
cout<<d[tail]<<endl;
head=tail;
f=1;
break;
}
}
}
}
if(!f)
cout<<"oop!"<<endl;
}
return 0;
}
