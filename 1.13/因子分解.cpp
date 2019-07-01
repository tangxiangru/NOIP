#include<cstdio>
#include <iostream>
using namespace std;

int main( )
{
int n,i=2,t=1;
scanf("%d",&n);

while(i*i<=n)
{
if(n%i==0)
{
if((n/i)%i==0)t++;
else
if(t==1) printf("%d*",i);
n/=i;
}
else
{
if(t>1)
{
printf("%d^%d*",i,t);
t=1;
}
i++;
}
}

if(t>1) printf("%d^%d\n",n,t);
else
printf("%d\n",n);

return 0;
}
