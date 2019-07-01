#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[45]={'\0'},b[85]={'\0'};//a数组是每次读取的一个单词（以空格分割的字符串），b数组是准备输出的一行（符合题目要求的字符串）。 
    int lenA=0,lenB=0;
    freopen("4.in","r",stdin);
    freopen("result.out","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        lenA=strlen(a);
        if(lenB+1+lenA<79)
        {
            if(lenB>0)
                strcat(b," ");
            strcat(b,a);
            lenB=strlen(b);
        }
        else if(lenB+1+lenA==80||lenB+1+lenA==79)
        {
            printf("%s %s\n",b,a);
            lenB=0;
            b[0]='\0';//清空b数组的数据 
        }
        else //当lenB+1+lenA>80
        {
            printf("%s\n",b);
            strcpy(b,a);
            lenB=strlen(b);
        }
    }
    printf("%s\n",b);//前面的循环可能会使最后一行没输出并一直留在b数组里面 
    return 0;
}
