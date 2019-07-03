#include<stdio.h>
long long inv[1000007];
long long f[1000007];
int main()
{
int mod=1e9+7;
inv[0]=1,inv[1]=1;
f[0]=1,f[1]=1;
int x;
scanf("%d",&x);
for(int i=2;i<=x;i++)
inv[i]=(mod-mod/i)*inv[mod%i]%mod;
for(int i=2;i<x;i++)
f[i]=((6*i-3)*f[i-1]%mod-(i-2)*f[i-2]%mod+mod)%mod*inv[i+1]%mod;
printf("%d",f[x-2]);
}
