#include <bits/stdc++.h>
using namespace std;

string a,b;
void work()
{
char a1[200],b1[200];
int a[200],b[200],c[400],lena,lenb,lenc,i,j,x;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
memset(c,0,sizeof(c));
gets(a1);gets(b1);
lena=strlen(a1);lenb=strlen(b1);
for (i=0;i<=lena-1;i++) a[lena-i]=a1[i]-48;
for (i=0;i<=lenb-1;i++) b[lenb-i]=b1[i]-48;
for (i=1;i<=lena;i++)
{
x=0;
for (j=1;j<=lenb;j++)
{
c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
x=c[i+j-1]/10;
c[i+j-1] %= 10;
}
c[i+lenb]=x;
}
lenc=lena+lenb;
while (c[lenc]==0&&lenc>1)
lenc--;
for (i=lenc;i>=1;i--)
cout<<c[i];
cout<<endl;
}

int main()
{
work();
return 0;
}
