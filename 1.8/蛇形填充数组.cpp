#include <stdio.h>
int main()
{
    int n,i,j;
    int kk;
    int o=1;//用来改变数组的变量 
    int k=1;
    int a[101][101];
    scanf("%d",&n);
    kk=2*n-1;//控制总循环次数 
    for(i=0;i<=kk;i++)
    {
        /*===========================*///①部分
        if(i%2==0&&i<n)//递增
        {
            for(j=0;j<=i;j++)
            {
                a[i-j][j]=o;
                o++;
            }
        }
        else if(i%2==1&&i<n)//递减 
        {
            for(j=0;j<=i;j++)
            {
                a[j][i-j]=o;
                o++;
            }
        }
        /*===========================*///②部分
        else if(i%2==0&&i>=n)//递增 
        {
            for(j=0;j<n-k;j++)
            {
                a[i-j-k][j+k]=o;
                o++;
            }
            k++;
        }
        else if(i%2==1&&i>=n)//递减 
        {
            for(j=0;j<n-k;j++)
            {
                a[j+k][i-j-k]=o;
                o++;
            }
            k++;
        }
    }
    for(i=0;i<n;i++)//输出结果 
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
