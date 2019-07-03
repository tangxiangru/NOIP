#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<climits>
#include<string>

using namespace std;
struct node
{
double h;
double ds;
double all;
}a[255];
bool cmp(node a,node b)
{
return (a.ds>b.ds)||(a.ds==b.ds&&a.h<b.h);
}
int main()
{
// freopen("x.in","r",stdin);
// freopen("x.out","w",stdout);
long long p;
cin>>p;
while(p--)
{
int w,s;cin>>w>>s;
for(int i = 1;i <= s;i++)
{
cin>>a[i].h;
cin>>a[i].all;
a[i].ds=a[i].all/(double)a[i].h;
}
sort(a+1,a+s+1,cmp);
double ans=0.0;
long long k=1;
while(a[k].h<=w&&k<=s)
{
w-=a[k].h;
ans+=a[k].all;
k++;
}
ans+=(double)w*a[k].ds;
printf("%.2f\n",ans);
}
return 0;
}
