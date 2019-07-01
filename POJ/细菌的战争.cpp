#include<stdio.h>
int main()
{
    int n,res,j;
    long long a,b;
    freopen("5.in","r",stdin);
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%I64d%I64d",&a,&b);//Linux使用%lld格式符
        res=0;
        while(a>0)
        {
            a=(a-b)*2;//被消灭的有害菌不能繁殖。
            b=(b*(1+0.05));
            if(a>1000000) a=1000000;//有害菌总数不超过一百万。
            res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
