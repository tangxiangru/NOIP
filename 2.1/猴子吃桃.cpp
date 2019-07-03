#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m=1,a,b,c,ans=9999999;
bool f(int x,int n){
int i,m=0,j;
m=x*n+1;
for(i=1;i<=n-1;i++){
if(m%(n-1)==0){
m=m/(n-1)*n+1;
}
else return 0;
}
return 1;
}
int main()
{
cin>>n;
for(i=1;;i++){
if(f(i,n)==1){
m=i*n+1;
for(j=1;j<=n-1;j++){
m=m/(n-1)*n+1;
}
cout<<m;
return 0;
}
}
cout<<m;
}
