#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,n;
cin>>a>>b>>n;
int z=a;
if(a>b) a%=b;
for(int i=1;i<=n;i++)
{
a=z;
a*=10;
z=a%b;
a/=b;
}
cout<<a;
}
