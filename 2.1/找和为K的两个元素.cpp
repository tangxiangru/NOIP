#include<iostream>
#include<cstring>
using namespace std;
int main()
{
int n,i,j,k,ans=0;
int a[1005];
cin>>n>>k;
for(i=1;i<=n;++i)cin>>a[i];
for(i=1;i<=n-1;++i)
for(j=i+1;j<=n;++j)
if(a[i]+a[j]==k) ++ans;
if(ans>0) cout<<"yes";
else cout<<"no";
return 0;
}
