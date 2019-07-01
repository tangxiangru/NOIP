#include<iostream>
#include<cmath>
using namespace std;
int fanxu(int n)//返回n的反序数
{
int sum=0,l;
while(n!=0)
{
l=n%10;
sum=sum*10+l;
n/=10;
}
return sum;
}
int prime(int n)
{
int i;
if(n==1)return 0;
for(i=2;i<=sqrt(n);i++)
{
if(n%i==0)
return 0;
}
return 1;
}
int main()
{
int n,m,v=1,i;
cin>>m>>n;
for(i=m;i<=n;i++)
{
if(prime(i)==1&&prime(fanxu(i))==1)
{
if(v==0)
{
cout<<",";
}
v=0;
cout<<i;
}
}
if(v==1)
cout<<"No"<<endl;
return 0;
}
