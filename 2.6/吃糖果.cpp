#include <iostream>
#include <cstring>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n+10];
a[0]=1;
a[1]=2;
for(int i=2;i<n;i++)
{
a[i]=a[i-1]+a[i-2];
}
cout<<a[n-1];
return 0;
}
