#include<cstdio>
using namespace std;
int a,b;

int gcd(int x,int y)
{
if(x%y==0) return y;
else return gcd(y,x%y);
}

int main()
{
scanf("%d %d",&a,&b);
int s=gcd(a,b);
printf("%d",s);
return 0;
}
