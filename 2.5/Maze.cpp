#include<iostream>
#include<cstring>
using namespace std;
char a[30][30];int c[30][30],d[30][30];
int b[5],bb[5],cx[4]={1,-1},cy[4]={0,0,1,-1};
int m,n,x1,y1,f;
void ys(int x,int y)
{
if(f)return;
for(int i=0;i<4;i++)
{
int x2=x+cx[i],y2=y+cy[i];
if(a[x2][y2]=='G')//如果找钥匙时找到宝藏，做标记，然后直接结束所有过程。
{
f=1;
return;
}
if(a[x2][y2]>='a'&&a[x2][y2]<='e')
{
b[a[x2][y2]-'a']--;//每找到一个钥匙，对应的b数组自减，值为0时代表全部集齐
a[x2][y2]='.';//将被找到的钥匙标记为空地
}
if(a[x2][y2]=='.'&&!c[x2][y2])
{
c[x2][y2]=1; //标记找钥匙时走过的路
ys(x2,y2);
}//由于找钥匙时只要把所有路径走一遍，所以不需要回溯。
}
}
void ljq(int x,int y)
{
if(f)return;//找到宝藏后直接结束
for(int i=0;i<4;i++)
{
int x2=x+cx[i],y2=y+cy[i];
if(a[x2][y2]>='A'&&a[x2][y2]<='E'&&!b[a[x2][y2]-'A']&&bb[a[x2][y2]-'A'])
{ //找到门后，如果已经集齐全部钥匙，则把门打开
a[x2][y2]='.';//将被打开的门标记为空地
memset(d,0,sizeof(d));/*d数组纪录找门时走过的路，由于会找到新的钥匙，可能原来没打
开的门可以打开，所以将d数组清零。*/
ys(x2,y2);//每打开一个门，从被打开门的位置开始找钥匙。
}

if(a[x2][y2]=='.'&&!d[x2][y2])
{
d[x2][y2]=1;
ljq(x2,y2);
}//同上 ，不需要回溯。
}
}
int main()
{
cin>>m>>n;
while(m)
{
f=0;
memset(a,0,sizeof(a));
memset(c,0,sizeof(c));
memset(d,0,sizeof(d));
memset(b,0,sizeof(b));
memset(bb,0,sizeof(bb));
for(int i=1;i<=m;i++)
for(int j=1;j<=n;j++)
{
cin>>a[i][j];
if(a[i][j]=='S')
{
x1=i;y1=j;
a[i][j]='.';
}
if(a[i][j]>='a'&&a[i][j]<='e')
{
b[a[i][j]-'a']++;
bb[a[i][j]-'a']=1;
}//b数组纪录每种钥匙的数目，bb数组纪录有没有出现这种钥匙，0下标代表a,依此类推

}
ys(x1,y1);
ljq(x1,y1);
if(f)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
cin>>m>>n;
}
}
