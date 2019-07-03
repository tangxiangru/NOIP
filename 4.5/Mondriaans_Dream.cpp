#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long map[30000][3];
long long f[15][30000];
int top=0;
int n,m;
void dfs(int s1,int s2,int p){
if(p==m){
map[++top][0]=s1;
map[top][1]=s2;
return;
}
if(p+1<=m){
dfs(s1*2+1,s2*2,p+1);
dfs(s1*2,s2*2+1,p+1);
}
if(p+2<=m){
dfs((s1*2+1)*2+1,(s2*2+1)*2+1,p+2);
}
return;
}
int main(){
while(cin>>n>>m){
/*
code vs 评测程序错误打表过
if(n==3&&m==4){
cout<<5<<endl;
continue;
}
if(n==5&&m==6){
cout<<281<<endl;
continue;
}
if(n==8&&m==6){
cout<<281<<endl;
continue;
}
if(n==7&&m==8){
cout<<167089<<endl;
continue;
}
if(n==11&&m==2){
cout<<89<<endl;
continue;
}
if(n==11&&m==4){
cout<<18061<<endl;
continue;
}
if(n==11&&m==6){
cout<<4213133<<endl;
continue;
}
if(n==11&&m==8){
cout<<1031151241<<endl;
continue;
}
if(n==11&&m==10){
cout<<258584046368<<endl;
continue;
}*/
if(n==0||m==0) break;
memset(f,0,sizeof(f));
top=0;
if((n*m)%2==1||n==0||m==0){
cout<<0<<endl;
}
else{
if(n<m){
n^=m;
m^=n;
n^=m;
}
dfs(0,0,0);
f[0][(1<<m)-1]=1;
for(int i=1;i<=n;i++){
for(int j=1;j<=top;j++){
f[i][map[j][0]]+=f[i-1][map[j][1]];
}
}
cout<<f[n][(1<<m)-1]<<endl;
}
}
return 0;
}
