#include<iostream>
#include<algorithm>
using namespace std;
int n,p[11],q[11];
char c;
int gcd(int a,int b)//求最大公约数 
{
    if(a<b) swap(a,b);
    return !b ? a:gcd(b,a%b); 
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i]>>c>>q[i];
    int m=q[1],t=1;
    for(int i=2;i<=n;i++)//求最小公倍数 
      { 
        int h=m;//h与m不能合为一个变量，在翻倍过程中，h逐渐改变，但翻的倍数仍然是m的倍数 
        while(h%q[i])
        {
            t++;
            h=m*t;
        }
        m=h;t=1; 
      }       
   for(int i=1;i<=n;i++)//通分 
     p[i]=m/q[i]*p[i];
   int tot=0;
   for(int i=1;i<=n;i++) tot+=p[i];//分子和 
   if(tot%m==0)//tot分子的和，m最小公倍数 
   {//分母为1 
           cout<<tot/m;
           return 0;
   }
   int k=gcd(tot,m);//k，最大公约数 
   cout<<tot/k<<'/'<<m/k;
}
