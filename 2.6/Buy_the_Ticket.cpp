#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
#define N 110

struct node
{
    int s[510];
    int l;
    node() {l=0;memset(s,0,sizeof(s));}
};
node multi(node x,int y)//dif from +
{
    node z;
    z.l=x.l;
    for (int i=1;i<=x.l;i++)
    {
      z.s[i]+=x.s[i]*y;
      if (z.s[i]>9) z.s[i+1]+=z.s[i]/10,z.s[i]%=10;
    }
    while (z.s[z.l+1])
    {
      z.l++;
      if (z.s[z.l]>9) z.s[z.l+1]+=z.s[z.l]/10,z.s[z.l]%=10;
    }
    return z;
}
node conv(node x)
{
    node z;
    z.l=x.l;
    for (int i=1;i<=x.l;i++)
      z.s[x.l-i+1]=x.s[i];
    return z;
}
node div(node x,int y)
{
    node z;
    int t=x.l+1,h=0;
    while (h<y && t>1) h=10*h+x.s[--t];
    z.s[++z.l]=h/y,h%=y;
    while (t>1)
    {
      h=10*h+x.s[--t];
      z.s[++z.l]=h/y,h%=y;
    }
    z=conv(z);
    return z;
}
/*另一种打法
node div(node x,int y)//crucial
{
    node z;
    int t=x.l+1,h=0;
    while (t>1)//converse!
    {
      bool tf=true;
      while (h<y && t>1)
      {
        h=10*h+x.s[--t];
        if (!tf&&z.l) z.s[++z.l]=0;//商最高位之后才开始赋值0，并且要是加入新的一位为0
        tf=false;
      }
      z.s[++z.l]=h/y,h%=y;
    }
    z=conv(z);
    return z;
}
*/
void print(node x)
{
    for (int i=x.l;i>=1;i--)
      printf("%d",x.s[i]);
    printf("\n");
}
node P(int x)
{
    node z;
    z.l=z.s[1]=1;
    for (int i=x;i>=1;i--)
      z=multi(z,i);
    return z;
}
int main()
{
    int n,m;
    while (1)
    {
      scanf("%d%d",&n,&m);
      if (!n&&!m) break;
      if (n<m) {printf("0\n");continue;}
      print(div(multi(P(n+m),n-m+1),n+1));
    }
    return 0;
}

