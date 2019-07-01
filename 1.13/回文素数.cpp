#include<bits/stdc++.h>
using namespace std;
int a[10000],s[11],n,ans;
int g(int x)
{
for(int i=2;i<=sqrt(x);i++)
if(x%i==0)
return 0;
return 1;
}
void f(int w)
{
int i;
if(w==n/2+1)
{
for(i=0;i<=9;i++)
{
int x=0,j;
for(j=1;j<w;j++)
if(s[j])
x+=s[j]*pow(10,j-1)+s[j]*pow(10,n-j);
x+=i*pow(10,w-1);
if(g(x))
a[++ans]=x;
}
return;
}
for(i=w==1;i<=9;i++)
{
s[w]=i;
f(w+1);
}
}
int main()
{
scanf("%d",&n);
switch(n)
{
case 0:printf("1\n0");break;
case 1:printf("4\n2 3 5 7");break;
case 2:printf("1\n11");break;
case 4:case 6:case 8:printf("0");break;
default:f(1);break;
}
if(ans)
{
printf("%d\n",ans);
for(int i=1;i<=ans;i++)
printf("%d ",a[i]);
}
return 0;
}

