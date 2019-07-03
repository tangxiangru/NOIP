#include<iostream>
#include<cstring>
using namespace std;
const char text=92;
const int hang[11]={0,2,4,8,16,32,64,128,256,512,1024};
const int lie[11]={0,4,8,16,32,64,128,256,512,1024,2048};
char ans[11][1025][2050]={};
int main(){
memset(ans,' ',sizeof(ans));
ans[1][0][0]=' ';
ans[1][0][1]='/';
ans[1][0][2]=text;
ans[1][1][0]='/';
ans[1][1][1]='_';
ans[1][1][2]='_';
ans[1][1][3]=text;
for(int i=2;i<=10;++i){
for(int k=0;k<hang[i-1];++k){
for(int j=lie[i-1]/2;j<lie[i-1]/2+lie[i-1];++j)
ans[i][k][j]=ans[i-1][k][j-lie[i-1]/2];
}
for(int k=hang[i-1];k<hang[i];++k)
for(int j=0;j<lie[i-1];++j)
ans[i][k][j]=ans[i-1][k-hang[i-1]][j];
for(int k=hang[i-1];k<hang[i];++k){
for(int j=lie[i-1];j<lie[i];++j)
ans[i][k][j]=ans[i-1][k-hang[i-1]][j-lie[i-1]];
}
}
int n;
while(cin>>n,n!=0){
for(int i=0;i<hang[n];++i){
for(int j=0;j<lie[n]/2+i+2;++j)
cout<<ans[n][i][j];
cout<<endl;
}
cout<<endl;
}
}
