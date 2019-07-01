#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
//How to do:素数表+max 可以剪枝
//难度：2
//启示：
//time:2018.2.18
//writer:hrf
int m,n;
bool p[10000];
void prime(int n)
{
memset(p,1,sizeof(p));
for(int i=2;i<=sqrt(n);i++)
if(p[i])
for(int j=2;j<=n/i;j++)
p[i*j]=false;
}
int main()
{
freopen("cin.in","r",stdin);
scanf("%d%d",&m,&n);
prime(n);
for(int i=m;i<=n;i++)
{
if(p[i])printf("%d",i);
else
for(int j=i/2;j>=1;j--)
if(i%j==0&&p[j]){printf("%d",j);break;}
if(i!=n)printf(",");
}
return 0;
}
