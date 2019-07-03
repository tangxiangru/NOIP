#include<bits/stdc++.h>
using namespace std;
long long a[11],b[11];
int main()
{
long long k=1,n,i,m,x,y,c1=0;
cin>>n;
for(i=1;i<=n;i++){
cin>>a[i];b[i]=1;
}
b[1]=a[1];c1=1;
for(i=2;i<=n;i++){y=0;
for(x=1;x<=c1;x++){
if(__gcd(a[i],b[x])==1){
b[x]=b[x]*a[i];y=1;break;
}
}
if(y!=1){
c1++;
b[c1]=a[i];
}
}
cout<<c1;
} 
