#include<bits/stdc++.h>
using namespace std;

int pe[21];
int l;
int ans=0;
int n;

int main()
{
scanf("%d",&l);

for (int v=1;v<=l;v++)
{
ans=0;

scanf("%d",&n);

for(int i=0;i<n;i++)
scanf("%d",&pe[i]);

sort(pe,pe+n);

int i;
int ans=0;

for(i=n;i>=4;i=i-2)
{
int a1=pe[i-1]+pe[0]+pe[i-2]+pe[0];
int a2=pe[1]+pe[0]+pe[i-1]+pe[1];

ans=ans+min(a1,a2);
}

if(i==3)
ans=ans+pe[0]+pe[1]+pe[2];
if(i==2)
ans=ans+pe[1];
if(i==1)
ans=ans+pe[0];

printf("%d\n",ans);
}

return 0;
}
