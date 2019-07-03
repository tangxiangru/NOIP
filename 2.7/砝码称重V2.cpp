#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool f[100005];
int z[7]={0,1,2,3,5,10,20},a[7];
int main(){
f[0]=1;
scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
int zhong=a[1]+a[2]*2+a[3]*3+a[4]*5+a[5]*10+a[6]*20;
for(int i=1;i<=6;i++){
int zhi=z[i],k=1;
while(k<a[i]){
for(int j=zhong;j>=0;j--)
if(f[j])f[j+k*zhi]=1;
a[i]-=k;k=k*2;
}
if(a[i]>0)
for(int j=zhong;j>=0;j--)
if(f[j])f[j+a[i]*zhi]=1;
}
int ans=0;
for(int i=1;i<=zhong;i++)if(f[i])ans++;
cout<<"Total="<<ans;
return 0;
}
