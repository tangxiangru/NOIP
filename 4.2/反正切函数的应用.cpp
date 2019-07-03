#include<cstdio>
int main()
{
int a;scanf("%d",&a);
long long b,den,num,c,ans=0;
for(b=a+1;;++b)
{
num=1+a*b;
den=b-a;
if(b*den>num)break;
if(0==num%den){c=num/den;ans=b+c;}
}
printf("%lld\n",ans);
return 0;
}
