#include<stdio.h>
#include<string.h>
struct number
{
    char n[60];//表示化为最简形式后的数
    int num;//表示这个数出现的次数。
};
void fun(char a[]);//完成对输入的每个数字进行化简的工作 .结果放在原数组
int main()
{
    struct number a[130];//存储化简后的数据，每个不同的数存一次，同时记录它的次数
    int N,i,len;//共有N个数，len表示a数组已经使用的单元个数
    char str1[500];
    int j;
    int max;//众数在数组a的下标

    freopen("5.in","r",stdin);
    scanf("%d",&N);
    len=0;
    for(i=0;i<N;i++)
    {
        scanf("%s",str1);
        fun(str1);//化简刚刚输入的这个字符串
        /*printf("%s\n",str1);*/
        for(j=0;j<len;j++)//检测先前是否遇到过和str1一样的数字
        {
            if(strcmp(a[j].n,str1)==0)
            {
                a[j].num++;
                break;
            }
        }
        if(j>=len)
        {
            strcpy(a[len].n,str1);
            a[len].num=1;
            len++;
        }
    }
    if(len==1&&len<N)//统计完了，a数组只有一个元素。而且输入的数字个数不是只有1个，说明输入的N个数大小是一样的
    {
        printf("no\n");
    }
    else
    {
        max=0;//默认第0号是众数所在的位置
        for(i=1;i<len;i++)
        {
            if(a[i].num>a[max].num)
                max=i;
        }
        printf("%s\n",a[max].n);
    }
    /*for(i=0;i<len;i++)
    {
        printf("%d  %s\n",a[i].num,a[i].n);
    }*/
    return 0;
}
void fun(char a[])//完成对输入的每个数字进行化简的工作 .结果放在原数组
{
    char temp[65];
    int len=strlen(a);
    int i;
    char flag;
    int first=0;//表示是已经否遇到第一个有效字符
    int j=0;//记录数组b的长度
    int k;
    
    //下面检测第一个字符是否是正号或者负号
    flag='0';
    if(a[0]=='-')    flag='-';
    else if(a[0]=='+')    flag='+';

    //根据第一字符的结果决定循环变量i的初值
    if(flag!='0')   i=1;
    else i=0;
    //下面是化简数组a代表的数字，结果暂存在temp数组。
    for( ;i<len;i++)
    {
        if(a[i]=='0')
        {
            if(first==1)//先前已经遇到了第一个有效字符,所以这个0是有效字符
            {
                temp[j]=a[i];
                j++;
            }//如果first==0则是当前这个字符是无效字符，可以直接忽略当前的这个a[i]
        }
        else
        {
            first=1;//标记一下：遇到了有效字符
            temp[j]=a[i];
            j++;
        }
    }
    //下面把temp数组存储的化简结果复制到a数组以便返回结果 
    if(j==0)//整个数字是0
    {
        a[0]='0';
        a[1]='\0';
    }
    else
    {
        if(flag=='-')
        {
            a[0]=flag;
            k=1;
        }
        else
        {
            k=0;
        }
        for(i=0;i<j;i++)
        {
            a[k]=temp[i];
            k++;
        }
        a[k]='\0';//截止符号
    }
}
