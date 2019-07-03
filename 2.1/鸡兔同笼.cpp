#include<bits/stdc++.h>
using namespace std;
int a,ma=0,mi=32768;
int main()
{
cin>>a;
for(int i=0;i<=a/2;i++)
for(int j=0;j<=a/4;j++)
{
if(i*2+j*4==a)
{
if(i+j>ma)ma=i+j;
if(i+j<mi)mi=i+j;
}
}
if((ma==0) && (mi==32768)) cout<<"0 0";
else cout<<mi<<" "<<ma;
return 0;
}
