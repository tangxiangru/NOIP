#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1010];
int main()
{
int t,n;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
int ans=0;
sort(a,a+n);
if(n&1)
{
ans^=(a[0]-1);
for(int i=2;i<n;i+=2)
ans^=(a[i]-a[i-1]-1);
}
else
for(int i=1;i<n;i+=2)
ans^=(a[i]-a[i-1]-1);
//cout<<ans<<endl;
if(ans!=0)
puts("Georgia will win");
else
puts("Bob will win");
}
}
