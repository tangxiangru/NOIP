#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[2333];

int main()
{
int m;
scanf("%d",&m);
for(int y=1;y<=m;y++)
{
int n,k;
scanf("%d%d",&n,&k);
for(int i=1;i<=n;i++)
{
scanf("%d",&a[i]);
}
for(int i=1;i<=k;i++)
{
if(!next_permutation(a+1,a+n+1))
sort(a+1,a+n+1);
}
for(int i=1;i<=n;i++)
{
printf("%d ",a[i]);
}
printf("\n");
}
return 0;
}
