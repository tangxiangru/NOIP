#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
int i,j,k,m,n,s,l,t;
cin>>n;
m=1;
while (++m)
for (i=1; i<=m; ++i)
{
if (n==(m+1)*m/2-2*i)
{
cout<<i<<' '<<m<<endl;
return 0;
}
}
}
