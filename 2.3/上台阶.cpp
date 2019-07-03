#include<bits/stdc++.h>
using namespace std;
int dg(int n)
{
if(n==1)
return 1;
if(n==2)
return 2;
if(n==3)
return 4;
else
return dg(n-1)+dg(n-2)+dg(n-3);
}
int main()
{
int n;
while((cin>>n)&&(n!=00))
cout<<dg(n)<<endl;
return 0;
}
