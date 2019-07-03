#include<bits/stdc++.h>
using namespace std;

int n;
int m;
int w[3501];
int v[3501];
int f[12881];

int main()
{
memset (w,0,sizeof (w));
memset (v,0,sizeof (v));
memset (f,0,sizeof (f));

scanf ("%d%d",&n,&m);

for (int i=1;i<=n;i++)
{
scanf ("%d%d",&w[i],&v[i]);
}

for (int i=1;i<=n;i++)
{
for (int j=m;j>=w[i];j--)
{
f[j]=max (f[j],f[j-w[i]]+v[i]);
}
}

printf ("%d",f[m]);

return 0;
}
