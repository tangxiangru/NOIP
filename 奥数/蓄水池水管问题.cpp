#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[4];
double h=0,ans=0;
cin>>a[0]>>a[1]>>a[2]>>a[3];
for(int i=1;i<=10000;i++)
{
int q=(i+3)%4;
if(h+(pow(-1,i+1)*1.0/a[q])>0.99)
{
ans+=((1.0-h)/(1.0/a[q]));
printf("%.2f\n",ans);
return 0;}
else{
h+=pow(-1,i+1)*(1.0/a[q]);
ans+=1.0;
}
}
}
