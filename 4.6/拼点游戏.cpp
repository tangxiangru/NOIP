#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int c[10000],s[10000];
int main()
{
while(cin>>n&&n)
{
memset(c,0,sizeof(c));
memset(s,0,sizeof(s));
for(int i=1;i<=n;i++)cin>>c[i];
for(int j=1;j<=n;j++)cin>>s[j];
sort(c+1,c+n+1);
sort(s+1,s+n+1);
int qc=1,zc=n,qs=1,zs=n;
int ans=0;
while(qc<=zc&&qs<=zs)
{
if(c[qc]<s[qs])
{
qc++;
qs++;
ans+=3;
}
else if(c[zc]<s[zs])
{
zc--;
zs--;
ans+=3;
}
else if(c[zc]==s[qs])
{
zc--;
qs++;
ans+=2;
}
else
{
qs++;
zc--;
ans+=1;
}
}
cout<<ans<<' ';
qc=qs=1;zc=zs=n;ans=0;

while(qc<=zc&&qs<=zs)
{
if(s[qs]<c[qc])
{
qs++;
qc++;
ans+=3;
}
else if(s[zs]<c[zc])
{
zs--;
zc--;
ans+=3;
}
else if(s[zs]==c[qc])
{
zs--;
qc++;
ans+=2;
}
else
{
qc++;
zs--;
ans+=1;
}
}
cout<<4*n-ans<<endl;
}

return 0;
}
