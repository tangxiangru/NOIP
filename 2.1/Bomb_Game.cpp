#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int mp[110][110] = {-1};
int r,s,p,t,n,m,k,ans,maxx;

int main() {
int x1,y1,x2,y2;
cin>>n>>m>>k;
for(int i=1; i<=n; i++) {
for(int j=1; j<=m; j++) {
mp[i][j]=1;
}
}
for(int i=1; i<=k; i++) {
cin>>r>>s>>p>>t;
x1=max(1,r-p/2);
y1=max(1,s-p/2);
x2=min(n,r+p/2);
y2=min(m,s+p/2);
if(t==0) {
for(int x=x1; x<=x2; x++) {
for(int y=y1; y<=y2; y++) {
mp[x][y]=0;
}
}
}
if(t==1){
for(int x=1; x<=n; x++){
for(int y=1; y<=m; y++){
if(x<x1||y<y1||x>x2||y>y2){
mp[x][y]=0;
}
}
}
}
}
for(int i=1; i<=n; i++)
for(int j=1; j<=m; j++)
if(mp[i][j]==1)
ans++;
cout<<ans<<endl;
return 0;
}
