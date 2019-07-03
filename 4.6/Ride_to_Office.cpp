#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int n,tz,v,t,s=4.5*3600;
while(cin>>n)
{
if(!n) break;
int mint=10000;
for(int i=1;i<=n;i++)
{
cin>>v>>t;
if(t>=0)
{
tz=ceil(s*1.0/v)+t;
if(tz<mint) mint=tz;
}
}
cout<<mint<<endl;
}
return 0;
}
