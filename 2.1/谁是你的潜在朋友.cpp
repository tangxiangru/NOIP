#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
int n,m,a[200],b[200]={0},i,j;
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
scanf("%d",&a[i]),b[a[i]]++;
for(i=1;i<=n;i++)
if(b[a[i]]==1)
printf("BeiJu\n");
else
printf("%d\n",b[a[i]]-1);
return 0;
}
