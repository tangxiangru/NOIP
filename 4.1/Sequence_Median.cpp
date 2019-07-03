#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
int T, a[300000];
double median;
scanf("%d",&T);
for(int j=0;j<T;j++)
{
scanf("%d",&a[j]);
}
sort(a,a+T);
if(T%2==0)
{
median=a[T/2-1]/2.0+a[T/2]/2.0; //因为 不能超过2^32-1所以要分开除以2
}
else if(T%2!=0)
{
median=a[(T-1)/2];
}
printf("%.1f\n",median);
return 0;
}
