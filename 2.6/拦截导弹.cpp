#include<iostream>
#include<cstdio>
using namespace std;
int a[10000],maxLen[10000];
int n;
int main(){
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int i=1;i<=n;i++){
maxLen[i]=1;
}
for(int i=1;i<=n;i++){
for(int j=1;j<=i;j++){
if(a[j]>a[i]){
maxLen[i]=max(maxLen[i],maxLen[j]+1);
}
}
}
for(int i=1;i<=n;i++){
if(maxLen[i]>maxLen[0]){
maxLen[0]=maxLen[i];
}
}
cout<<maxLen[0];
return 0;
}
