#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t[1100],a[1100];
int main()
{
int n,num=0,i;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
t[a[i]]++;
}
for(i=0;i<=100;i++)
{
if(t[i]>(n)/2)
{
printf("%d",i);
return 0;
}
}
printf("no\n");
return 0;
}
