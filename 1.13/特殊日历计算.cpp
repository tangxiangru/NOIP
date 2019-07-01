#include<cstdio>
#include<cstdlib>
using namespace std;
long long a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
long long i,n,q,e,c,b,f,g;
char str[10];
int main()
{
scanf("%d",&n);
while(n--)
{
scanf("%d:%d:%d %d.%d.%d",&q,&e,&c,&b,&f,&g);
b+=(g-2000)*365+(g-1997)/4-(g-1901)/100+(g-1601)/400-1;
if(f>2&&((g%4==0&&g%100!=0)||g%400==0))
{
b++;
}
for(i=0;i<f-1;i++)
b+=a[i];
c=(q*3600+e*60+c)*125/108;
printf("%d:%d:%d %d.%d.%d\n",c/10000,(c%10000)/100,c%100,b%100+1,(b/100)%10+1,b/1000);
}
return 0;
}
