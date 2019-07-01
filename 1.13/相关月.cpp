#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int a[n+1],b[n+1],c[n+1];
for(int i=1;i<=n;i++){
cin>>a[i]>>b[i]>>c[i];
}
for(int i=1;i<=n;i++){
int s=0;
if(a[i]%4==0&&a[i]%100!=0||a[i]%400==0){
m[2]=29;
}
else{
m[2]=28;
}
for(int j=min(b[i],c[i]);j<max(b[i],c[i]);j++){
s+=m[j];
}
if(s%7==0){
cout<<"YES"<<endl;
}
else{
cout<<"NO"<<endl;
}
}
}
