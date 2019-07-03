#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
long long N,i,p;
cin>>N;
long long ans=N+1ll;
for(i=2;i<=N;i++)
{
cin>>p;
ans=ans+i*p-p;
}
cout<<ans<<endl;
}
