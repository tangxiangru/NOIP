#include<iostream>
#include <iomanip>
using namespace std;
int v,i,j,k,o,n;
int main()
{
cin>>n;
for (int i=0;i<=n/5;i++)
for (int j=0;j<=n/2;j++)
for (int k=0;k<=n;k++)
{ v=i*5+j*2+k;
if (v==n){o++;
if (o>=1&&o<=9)cout<<"00"<<o<<setw(12)<<k<<setw(12)<<j<<setw(12)<<i<<endl;
else if(o>=10&&o<=99)cout<<"0"<<o<<setw(12)<<k<<setw(12)<<j<<setw(12)<<i<<endl;
else cout<<o<<setw(12)<<k<<setw(12)<<j<<setw(12)<<i<<endl;
}
}
return 0;
}
