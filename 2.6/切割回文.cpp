#include<bits/stdc++.h>
using namespace std;

char ss[1005];
int f[1005];

inline bool is_hw(int x,int y)
{
int t=(x+y)>>1;
for(int i=x;i<=t;i++)if(ss[i]!=ss[y-i+x])return false;
return true;
}

int main()
{
ios::sync_with_stdio(false);
int T;
cin>>T;
while(T--)
{
cin>>ss;
int n=strlen(ss);
memset(f,0x7f,sizeof(f));
for(int i=0;i<n;i++)
if(is_hw(0,i))f[i]=0;
else for(int j=0;j<i;j++)
if(is_hw(j+1,i))f[i]=min(f[i],f[j]+1);
cout<<f[n-1]<<endl;
}
return 0;
}
