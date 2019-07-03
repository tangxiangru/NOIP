#include<bits/stdc++.h>
using namespace std;

int n;
int f[2][2];
bool k=true;

inline int read()
{
int x=0,f=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
return x*f;
}

int main()
{
ios::sync_with_stdio(false);
n=read();
f[1][1]=1;f[1][0]=8;
for(int i=2;i<=n;i++)
{
k=!k;
f[k][0]=(f[!k][0]*9+f[!k][1])%12345;
f[k][1]=(f[!k][1]*9+f[!k][0])%12345;
}
cout<<f[k][0]<<endl;
return 0;
}
