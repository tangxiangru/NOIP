#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
crope a="4567",b="123",c;
int n;
int main()
{
cin>>n;
do
{
c=b+a;a=b;b=c;
}while(c.length()<n);
cout<<c[n-1]<<endl;
return 0;
}
