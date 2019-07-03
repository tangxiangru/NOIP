#include <iostream>
#include<cmath>
using namespace std;
int f(int a,int b)
{
int i,ans=0;
for(i=b;i<=sqrt(a);i++)
if(a%i==0)ans+=f(a/i,i);
return ans+1;
}
int main()
{
int n,a;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>a;
cout<<f(a,2)<<endl;
}
}
