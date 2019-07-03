#include<iostream>
#include<cstring>
using namespace std;
char a[210][210];
int b[210][210],c[50000],x[60000],y[60000],f[60000],s,n,m,x1,x2,y1,y2,total;
void in()
{
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
memset(c,0,sizeof(c));
memset(x,0,sizeof(x));
memset(y,0,sizeof(y));
memset(f,0,sizeof(f));

cin>>n>>m;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
{
cin>>a[i][j];
if(a[i][j]=='a')
{
x2=i;
y2=j;
}
if(a[i][j]=='r')
{
x1=i;
y1=j;
}
if(a[i][j]=='#')
b[i][j]=1;
}
}
void ljq(int d)
{
total++;
if(c[d]!=0)ljq(c[d]);
}
void dfs()
{
x[1]=x1;y[1]=y1;total=0;int x3,y3;
int head=0,tail=1;
while(head!=tail)
{
head++;
for(int i=1;i<=4;i++)
{
if(i==1) {x3=x[head]+1,y3=y[head];}
if(i==2) {x3=x[head]-1,y3=y[head];}
if(i==3) {x3=x[head],y3=y[head]+1;}
if(i==4) {x3=x[head],y3=y[head]-1;}
if(a[x[head]][y[head]]=='x'&&f[head]) {x3=x[head];y3=y[head];}
if(x3>=1&&x3<=n&&y3>=1&&y3<=m&&!b[x3][y3])
{

b[x3][y3]=1;
tail++;
x[tail]=x3;
y[tail]=y3;
c[tail]=head;
if(a[x3][y3]=='x'&&!f[head]) {b[x3][y3]=0;f[tail]=1;}
if(x3==x2&&y3==y2)
{
ljq(tail);
cout<<total-1<<endl;
return;
}
if(f[head])continue;
}
}

}
cout<<"Impossible"<<endl;
}
int main()
{
cin>>s;
for(int i=1;i<=s;i++)
{
in();
dfs();
}
return 0;
}
