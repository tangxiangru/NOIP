
#include<cstdio>

int a,b,c,d;
int k;

int main()
{
scanf("%d %d %d %d",&a,&b,&c,&d);
a=a%23;
b=b%28;
c=c%33;
k=d;
while(1)
{
k++;
if((k-a)%23==0 && (k-b)%28==0 && (k-c)%33==0)
{
printf("%d",k-d);
break;
}
}
}

