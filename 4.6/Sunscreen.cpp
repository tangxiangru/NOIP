#include<iostream>
#include<algorithm>
using namespace std;
struct abc
{
int l,r,f;
}cow[2501];
int a[1001];
int cmp(abc x,abc y)
{
return x.r<y.r;
}
int main()
{
int n,s,ans=0;
cin>>n>>s;
for(int i=1;i<=n;i++)
cin>>cow[i].l>>cow[i].r;
for(int i=1;i<=s;i++)
{
int c,b;
cin>>c>>b;
a[c]+=b;
}
sort(cow+1,cow+n+1,cmp);
for(int i=1;i<=1001;i++)
if(a[i])
for(int j=1;j<=n;j++)
if(!cow[j].f)
if(cow[j].l<=i&&i<=cow[j].r)
if(a[i])
{
a[i]--;
ans++;
cow[j].f=1;
continue;
}
else
break;
cout<<ans;
}
