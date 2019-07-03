#include <iostream>
using namespace std;
int main()
{
int n,i,j,s=0;
bool f=true;
cin >> n;
for (i=1;f;i++)
{

s=(1+i)*i/2;
if (s>n)
{
if ((s-n)/2<=i && s-(s-n)/2*2==n)
{
cout << (s-n)/2 << " " << i;
f=false;
}
}
}
}
