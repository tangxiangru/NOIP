#include<bits/stdc++.h>
using namespace std;
int riqi[11][30];
int main()
{
int n,xingqi;
cin>>xingqi;
for(int i=0; i<=11; i++)
{
if(i==0||i==2||i==4||i==6||i==7||i==9||i==11)
{
n=30;
}
if(i==3||i==5||i==8||i==10)
{
n=29;
}
if(i==1)
{
n=27;
}
for(int j=0; j<=n; j++)
{
if(j==12&&xingqi%7==5)
{
cout<<i+1<<endl;
}
xingqi++;
}
}
return 0;
}

