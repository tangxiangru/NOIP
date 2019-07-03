#include<cstdio>
#include<algorithm>
#include <cmath>
using namespace std;
int a[520],b[520];//a里存放答案
void work(int x){//高精度
if(x==2){//平方
for(int i=1;i<=500;i++){
b[i]=a[i];
a[i]=0;
}
for (int i=1;i<=500;i++)
for (int j=1;j<=501-i;j++)
{
a[i+j-1]+=b[i]*b[j];
a[i+j]+=a[i+j-1]/10;
a[i+j-1]=a[i+j-1]%10;
}
a[500]=a[500]%10;
}
if(x==1){//乘二
for (int i=1;i<=500;i++)
a[i]*=2;
for (int i=1;i<=499;i++){
a[i+1]+=a[i]/10;
a[i]%=10;
}
a[500]%=10;
}
}
void ans(int q){//分治思想
if(q!=0){
ans(q/2);
work(2);//平方
work(q%2);//如果是奇数还要乘二
}
}
int main(){
a[1]=1;
int q;
scanf("%d",&q);
printf("%d\n",int(log(2)*q/log(10))+1);//求位数
ans(q);
a[1]--;
for (int i=500;i>=1;i--)
{
printf("%d",a[i]);
if ((i-1)%50==0)
printf("\n");
}
return 0;
}
