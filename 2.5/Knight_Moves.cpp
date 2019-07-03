#include<bits/stdc++.h>
using namespace std;
int dx[8]={1,1,-1,-1,2,2,-2,-2},dy[8]={2,-2,2,-2,1,-1,1,-1},s,n,x,y,x2,y2,i,k,l,j,b[301][301],c[1000];struct{int x,y,b;}a[1000000];
int fc(int q,int w)
{
int h=0,t=1;
a[1].x=q;a[1].y=w;b[q][w]=1;
while(h<t&&!j)
{
h++;
for(i=0;i<8;i++)
{
int x1=dx[i]+a[h].x,y1=dy[i]+a[h].y;
if(x1>=0&&y1>=0&&x1<n&&y1<n&&!b[x1][y1])
{
t++;a[t].x=x1;a[t].y=y1;b[x1][y1]=1;a[t].b=a[h].b+1;
if(x1==x2&&y1==y2)
{j=1;c[l]=a[t].b;break;}
}
}
}
}
int main(){
cin>>s;
for(l=1;l<=s;l++)
{
j=0;
cin>>n;
cin>>x>>y>>x2>>y2;
for(i=0;i<n;i++)
for(k=0;k<n;k++)
b[i][k]=0;
fc(x,y);
}
for(i=1;i<l;i++)
cout<<c[i]<<endl;
}
