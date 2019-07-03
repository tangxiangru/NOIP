#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int a[100][100]={0};
int main ()
{
int h;
cin>>h;
for (int i=1;i<=h;++i)
{
for (int j=1;j<=i;++j)
cin>>a[i][j];
}
for (int i=h-1;i>=1;--i)
{
for (int j=1;j<=i;++j)
{
if (a[i+1][j]>a[i+1][j+1])
a[i][j]+=a[i+1][j];
else a[i][j]+=a[i+1][j+1];
}
}
cout<<a[1][1]<<endl;
system ("pause");
return 0;
}
