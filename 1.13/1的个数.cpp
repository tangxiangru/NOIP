#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
int a[501],b[501],c[501];
char a1[501],b1[501];
void convert(char s[],int a[])
{
reverse(s,s+strlen(s));
for(int i=0;i<strlen(s);i++)a[i]=s[i]-48;
}
int cheng(int a[],int b[],int lena,int lenb)
{
int x=0,i,j;
for(i=0;i<lenb;i++)
{
x=0;
for(j=0;j<lena;j++)
{
c[i+j]=c[i+j]+a[j]*b[i]+x;
x=c[i+j]/10;
c[i+j]=c[i+j]%10;
}
c[i+j]=x;
}
if(x)
{
c[i+j-1]=x;
return i+j-1;
}
else
return i+j-2;
}
void print(int a[],int len)
{
while(a[len]==0)len--;
if(len<0)
cout<<0;
else
for(int i=len;i>=0;i--)cout<<a[i];
}
int main()
{
int i,j,k,len,w;
cin>>a1;
cin>>b1;
convert(a1,a);
convert(b1,b);
len=cheng(a,b,strlen(a1),strlen(b1));
print(c,len);
return 0;
}
