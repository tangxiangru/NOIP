#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;
string
c[20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
int i,n,dd,y=2000,m=1,d=0;
cin>>n;dd=(n-1)%7;++n;
while (n>366){
if (y%4==0&&(y%100!=0||y%400==0))n-=366;
else n-=365;
++y;
}
if (n==366)
if (y%4==0&&(y%100!=0||y%400==0));
else {++y;n-=365;}
d=n;
if (y%4==0&&(y%100!=0||y%400==0)) ++a[2];
for (i=1;i<=12;i++){
if (d>a[i]){++m;d-=a[i];}
else break;
}
printf("%d-%02d-%02d",y,m,d);
cout<<" "<<c[dd];
return 0;
}
