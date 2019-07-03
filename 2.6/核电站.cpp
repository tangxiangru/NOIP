#include<iostream>
using namespace std;
long long n,m,i,f[100];
int main()
{
cin>>n>>m;
f[0]=1;
if (n<m)
{

for (i=1;i<=n;++i)
f[i]=f[i-1]*2;
cout<<f[n];
return 0;
}

for (i=1;i<=m-1;++i)
f[i]=f[i-1]*2;
f[m]=f[m-1]*2-1;
for (i=m+1;i<=n;++i)
f[i]=f[i-1]*2-f[i-m-1];
cout<<f[n];

}
