#include<iostream>
#include<cstdio>
using namespace std;
int main(){
int n,m,a[101],i;
while(cin>>n){
for(i=n;i>=0;i--){
cin>>a[i];
}
if(a[n]!=1&&a[n]!=-1)
cout<<a[n]<<"x^"<<n;
if(a[n]==1)
cout<<"x^"<<n;
if(a[n]==-1)
cout<<"-"<<"x^"<<n;
for(i=n-1;i>1;i--){
if(a[i]>0&&a[i]!=1)
cout<<"+"<<a[i]<<"x^"<<i;
if(a[i]==1)
cout<<"+"<<"x^"<<i;
if(a[i]<0&&a[i]!=-1)
cout<<a[i]<<"x^"<<i;
if(a[i]==-1)
cout<<"-"<<"x^"<<i;
}
if(a[1]>0&&a[1]!=1)
cout<<"+"<<a[1]<<"x";
if(a[i]==1)
cout<<"+x";
if(a[1]<0&&a[1]!=-1)
cout<<a[1]<<"x";
if(a[i]==-1)
cout<<"-x";
if(a[0]>0)
cout<<"+"<<a[0];
if(a[0]<0)
cout<<a[0];
cout<<endl;
}
return 0;
}
