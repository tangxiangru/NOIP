#include<cstdio>
int main()
{
    int N,hf[41][41]={},tot=1; //tot为计数单位
    scanf("%d",&N);
    N=2*N-1; //构造(2N-1)*(2N-1)的幻方
    int i=1,j=(N-1)/2;
    while(tot<=N*N) //遍历每一个元素
    {
        int m,n;
        m=i-1>=0? i-1:N-1;
        n=j;
        if(!hf[m][n]) //无数
        {
            hf[m][n]=tot;
            i--;
            j++;
        }
        else //有数
        {
            m=i+1; //降一排
            if(m>=N)
                m=0;
            n--; //退一列
            if(n<0)
                n=N-1;
            hf[m][n]=tot;
            i++;
        }
        if(i<0)
            i=N-1;
        if(j>=N)
            j=0;
        tot++;
    }
    for(int i=0;i<N;i++)
    {
        if(i) //换行符格式控制
            printf("\n");
        for(int j=0;j<N;j++)
            if(j) //空格格式控制
                printf(" %d",hf[i][j]);
            else
                printf("%d",hf[i][j]);
    }
    return 0;
} 
