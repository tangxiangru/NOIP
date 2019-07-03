#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,a,b,c,ans=9999999;
int main()
{
cin>>n;
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
if(n%(j*i)==0&&2*(n/(j*i)*j+i*j+i*n/(j*i))<ans){
ans=2*(n/(j*i)*j+i*j+i*n/(j*i));
}
}
}
cout<<ans;
}
