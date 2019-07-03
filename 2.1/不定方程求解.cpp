#include<iostream>
using namespace std;
int a,b,c,i,j,k,o;
int main()
{
cin>>a>>b>>c;
for (int i=0;i<=c;i++)
for (int j=0;j<=c;j++)
{ k=a*i+b*j;
if (k==c) o++;
}
cout<<o;
return(0);
}
