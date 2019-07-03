#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

int ad(int p){
int a=(1+p)*p/2;
return a;
}

int main(){
int n;
cin>>n;
for(int i=1;i<=999999;i++){
if(ad(i)==n){
if(i%2==0) cout<<i<<"/"<<1<<endl;
else cout<<1<<"/"<<i<<endl;
break;
}
else if(ad(i)<=n&&ad(i+1)>n){
int h=i+2;
int gs=n-ad(i);
if(h%2==1) cout<<gs<<"/"<<h-gs<<endl;
else cout<<h-gs<<"/"<<gs<<endl;
break;
}
}
}
