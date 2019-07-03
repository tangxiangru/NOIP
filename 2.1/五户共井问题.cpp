#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;


int main(){
int k,n1,n2,n3,n4,n5;
bool suc=false;
cin>>k>>n1>>n2>>n3>>n4>>n5;
for(int i=1;i<=100*k;i++){
if(suc==true) break;
for(int a=1;a<=i/n1;a++){
int b=i-a*n1;
int c=i-b*n2;
int d=i-c*n3;
int e=i-d*n4;
if(a==b||a==c||a==d||a==e||b==c||b==d||b==e||c==d||c==e||d==e) continue;
if(e*n5+a==i){
cout<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;
suc=true;break;
}
}
}
if(suc==false) cout<<"not found";
}
