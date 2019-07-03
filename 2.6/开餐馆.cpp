#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int m[105],p[105],f[105];

int main()
{
ios::sync_with_stdio(false);
int T;
cin>>T;
while(T--)
{
ans=0;
memset(f,0,sizeof(f));
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>m[i];
for(int i=1;i<=n;i++)cin>>p[i];
for(int i=1;i<=n;i++)
{
f[i]=p[i];
for(int j=1;m[j]+k<m[i]&&j<i;j++)
f[i]=max(f[i],f[j]+p[i]);
ans=max(ans,f[i]);
}
cout<<ans<<endl;
}
return 0;
}
