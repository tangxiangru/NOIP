#include<stdio.h>
int sum(int, int);
int power(int, int);
int main()
{
    int n, k;
    int result;
    scanf("%d%d",&n,&k);
    result = sum(n,k);
    printf("%d\n",result);
    return 0;
}

int sum(int n, int k)
{
    int s, i;  s=0;
    for(i=1;i<=n;i++)
        s+=power(i,k);
    return s;
}

int power(int x, int k)
{
    int i, t=1;
    for(i=1;i<=k;i++)
        t*=x;
    return t;
}
