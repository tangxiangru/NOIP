#include<iostream>
using namespace std;
int n,m,a,b[1001];
int main()
{
cin>>n;
b[0]=1;
for(int i=1;i<=n;i++)
{
cin>>a;
for(int j=400;j>=a;j--)
{
b[j]=(b[j]+b[j-a])%10000;
}
}
cout<<b[400]<<endl;
return 0;
}
