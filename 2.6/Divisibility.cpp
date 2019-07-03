#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int num[10005];
bool divi[2][105];

int main(){
int n, k, tmp, m=0;
cin>>n>>k;
for(int i=1;i<=n;i++){
scanf("%d", &tmp);
if(tmp<0) tmp=-tmp;
tmp%=k;
if(tmp!=0)
num[++m]=tmp;
}
if(m==0) { cout<<"Divisible"<<endl; return 0; }
divi[0][0]=true; divi[1][0]=true;
for(int i=1;i<=m;i++){
for(int j=0;j<=k;j++)
if(divi[0][(j+num[i])%k]||divi[0][(j-num[i]+k)%k])
divi[1][j]=true;
else divi[1][j]=false;
for(int l=0;l<=k;l++)
divi[0][l]=divi[1][l];
}
if(divi[1][0]) cout<<"Divisible"<<endl;
else cout<<"Not divisible"<<endl;
return 0;
}
