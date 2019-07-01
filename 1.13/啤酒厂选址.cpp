#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;


int main(){
int n,jl,sum=0,minn=999999999;
cin>>n;
int a[10010],s[10010];
memset(a,0,sizeof(a));
memset(s,0,sizeof(s));
for(int i=0;i<n;i++){
cin>>a[i]>>s[i];
sum+=s[i];
}
for(int i=0;i<n;i++){
// cout<<i<<endl;
int cost=0;
for(int j=0;j<n;j++){
// cout<<j<<endl;
int se;
if(i!=j){
if(i>j){
int s1=0,s2=0;
for(int p=j;p<i;p++) s1+=s[p];
s2=sum-s1;
se=min(s1,s2);
// cout<<se<<endl;
}else{
int s1=0,s2=0;
for(int p=i;p<j;p++) s1+=s[p];
s2=sum-s1;
se=min(s1,s2);
// cout<<se<<endl;
}
cost+=se*a[j];
// cout<<cost<<" "<<j<<endl;
}

}
if(cost<minn){
minn=cost;jl=i;
}
}
cout<<jl<<","<<minn<<endl;
}
