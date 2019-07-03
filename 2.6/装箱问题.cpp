#include<bits/stdc++.h>
using namespace std;
int f[20001],w,n,i,j,a[31];
int main()
{
scanf("%d%d",&w,&n);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
for(i=1;i<=n;i++)
for(j=w;j>=a[i];j--)
f[j]=max(f[j],f[j-a[i]]+a[i]);
printf("%d",w-f[w]);
return 0;
}
