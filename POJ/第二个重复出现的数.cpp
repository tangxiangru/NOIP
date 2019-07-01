#include<stdio.h>
int main()
{
    int m,n,a[505],i,j,flag;
    freopen("3.in","r",stdin);
    scanf("%d",&m);
    while(m>0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        flag=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]==a[i])
                {
                    flag++;
                    break;
                }
            }
            if(flag==2)
            {
                printf("%d\n",a[i]);
                break;
            }
        }
        if(flag!=2) printf("NOT EXIST\n");
        m--;
    }
    return 0;
}
