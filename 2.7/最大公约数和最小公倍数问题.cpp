#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a,int b)
{
int c=a%b;
while(c!=0)
{
a = b;
b = c;
c=a%b;
}
return b;
}
int main()
{
int x,y,i,v,s,ans;
cin>>x>>y;
v=x*y;
s=(int)sqrt(v);
ans=0;
for(i=x;i<=s;i++)
if((v%i==0)&&(gcd(v/i,i)==x)) ans++;
ans*=2;
cout<<ans;
return 0;
}
