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
for(int j=40;j>=a;j--)
{
b[j]=b[j]+b[j-a];
}
}
cout<<b[40]<<endl;
return 0;
}
