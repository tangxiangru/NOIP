#include<iostream>
using namespace std;
int m[5][5],m2[5][5],p[5]={0},mincnt=0x7fff,cnt;
void dfs(int s){
if(s==4){
cnt=0;
for(int i=1;i<5;i++)
for(int j=1;j<5;j++)
m2[i][j]=m[i][j];
for(int i=1;i<5;i++)
if(p[i]){
cnt++;
m2[1][i]^=1;
m2[1][i+1]^=1;
m2[1][i-1]^=1;
m2[2][i]^=1;
}
for(int i=2;i<5;i++)
for(int j=1;j<5;j++)
if(m2[i-1][j]){
cnt++;
m2[i][j]^=1;
m2[i-1][j]^=1;
m2[i+1][j]^=1;
m2[i][j+1]^=1;
m2[i][j-1]^=1;
}
for(int j=1;j<5;j++)
if(m2[4][j])
return;
if(cnt<mincnt)
mincnt=cnt;
return;
}
p[s+1]=1;
dfs(s+1);
p[s+1]=0;
dfs(s+1);
return;
}

int main(){
char d[5][5];
for(int i=1;i<5;i++){
cin>>d[i];
for(int j=0;j<4;j++)
if(d[i][j]=='b')
m[i][j+1]=1;
else if(d[i][j]=='w')
m[i][j+1]=0;
}
dfs(0);
for(int i=1;i<5;i++)
for(int j=1;j<5;j++)
m[i][j]^=1;
dfs(0);
if(mincnt!=0x7fff)
cout<<mincnt;
else cout<<"Impossible";
return 0;
}
