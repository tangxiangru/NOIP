#include<cstdio>
int n,m,money[100005]={},sum=0,max=-1e8;
//总天数，要求划分的fajo月数，每天的开销，总开销，最大开销（每天）
bool flag(int mid)
{
    int sflag=0,k=1; //累计fajo月，fajo月总数
    for(int i=0;i<n;i++)
        if(sflag+money[i]<=mid) //还可以继续划分
            sflag+=money[i]; //累计
        else
        {
            k++,sflag=money[i]; //总数+1，fajo月重新计算
            if(sflag>mid) return false; //若超出，则错误
        }
    return k<=m? true:false; //总月数是否比m小
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&money[i]);
        sum+=money[i]; //计算总和
        max=max<money[i]? money[i]:max; //计算最大值
    }
    int left=max,right=sum;
    while(left<=right) //不可使用 left+1<right
    {
        int mid=left+right>>1;
        if(flag(mid)) right=mid-1; //正确则向下查找
        else left=mid+1; //否则向上查找
    }
    printf("%d\n",left);
    return 0;
}
