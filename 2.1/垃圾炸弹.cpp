#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
int x;
int y;
int value;
};
int cmp(node a,node b){
return a.x<b.x;
}
node point[25];
int p[1030][1030];
int ylw[1030][1030];
int main(){
int d,n,t;
memset(ylw,0,sizeof(ylw));
memset(p,0,sizeof(p));
memset(point,0,sizeof(point));
cin>>d>>n;
for(int i=1;i<=n;i++)
cin>>point[i].x>>point[i].y>>point[i].value;
for(int i=1;i<=n;i++){
for(int tep1=-d;tep1<=d;tep1++)
for(int tep2=-d;tep2<=d;tep2++)
if(point[i].x+tep1<=1024&&point[i].x+tep1>=1&&point[i].y+tep2<=1024&&point[i].y+tep2<=1024)
ylw[point[i].x+tep1][point[i].y+tep2]+=point[i].value;
}
int ans=0,sum=0;
for(int i=0;i<=1024;i++)
for(int j=0;j<=1024;j++){
if(ylw[i][j]){
if(ans<ylw[i][j]){
ans=ylw[i][j];
sum=1;
}
else if(ans==ylw[i][j])
sum++;
}
}
cout<<sum<<" "<<ans<<endl;
return 0;
}
