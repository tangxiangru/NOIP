#include<cstdio>
using namespace std;
long long n;
int main()
{
while(scanf("%lld",&n)!=0)
{
if(!n)
{
break;
}
if(n<3)
{
printf("Alice\n");
}
else
{
printf("Bob\n");
}
}
return 0;
}
