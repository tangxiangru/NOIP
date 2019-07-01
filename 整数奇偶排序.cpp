#include<stdio.h>
int main()
{
    int n=10,i,j,k,t,a[13];
    freopen("5.in","r",stdin);
    while(scanf("%d",&a[0])!=EOF)
    {
        //下面是输入剩余的9个数 
        for(i=1;i<10;i++)
        {
            scanf("%d",&a[i]);
        }
        //下面是 选择排序 
        for(i=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if(a[j]>a[k])  k=j;
            }
            if(k!=i)
            {
                t=a[k];
                a[k]=a[i];
                a[i]=t;
            }
        }
        //下面 是输出结果 
        /*for(i=0;i<n;i++)  printf("%d ",a[i]);
        printf("\n");*/
        for(i=0;i<n;i++)
        {
            if(a[i]%2==1)  printf("%d ",a[i]);
        }
        for(i=n-1;i>=0;i--)
        {
            if(a[i]%2==0)  printf("%d ",a[i]);
        }
        printf("\n");
    } 
    return 0;
}
