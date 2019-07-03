#include<iostream>
using namespace std;
int Do(int x,int y){
if(x)return x;
return y;
}
int main(){
int i,j,n,k,p,f[2][110]={0};
cin>>n>>k;
f[0][0]=1;
for(i=1;i<=n;i++){
cin>>p;
for(j=0;j<=k;j++)
f[1][j]=Do(f[0][(k+j-p%k)%k],f[0][(k+j+p%k)%k]);
for(j=0;j<=k;j++)
f[0][j]=f[1][j];
}
if(f[0][0])cout<<"YES";
else cout<<"NO";
return 0;
}
