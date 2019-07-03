#include <iostream>
using namespace std;
typedef long long ll;
ll a[10000000];
int main()
{
int n;
cin>>n;
a[0]=2;
a[1]=3;
for(int i=2;i<n;i++)
a[i]=a[i-1]+a[i-2];
cout<<a[n-1];
return 0;
}
