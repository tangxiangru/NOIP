#include<iostream>
#include<string.h>
using namespace std;
string str1,str2,str;
int a[100000];
int main()
{
cin>>str1;
int n,sum=0,t;
n=str1.length();
for(int i=0;i<n;i++)
a[i]=str1[i]-'0';
for(int i=0;i<n;i++)
sum=sum+a[i];
while(sum>9)
{
t=sum;
sum=0;
for(;t>0;t=t/10)
sum=sum+t%10;
}
cout<<sum;
}
