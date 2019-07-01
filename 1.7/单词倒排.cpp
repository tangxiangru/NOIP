#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char a[500],temp,b[500];//a数组存贮整个句子，b存储某一个单词
    int i,len,j,k;
    gets(a);
    len=strlen(a);
    for(i=0;i<len/2;i++)//对整个字符串进行翻转
    {
        temp=a[i];
        a[i]=a[len-1-i];
        a[len-1-i]=temp;
    }
    //printf("\n%s\n",a);
    i=0;
    j=0;
    while(a[i]!='\0')
    {
        if(a[i]!=' ')
        {//扫描句子，遇到非空格字符则存到b数组
            b[j]=a[i];
            j++;
        }
        else
        {//扫描句子时遇到空格，逆向输出b数组存贮的那个被逆序的单词
            for(k=j-1;k>=0;k--)
            {
                printf("%c",b[k]);
            }
            printf(" ");//如果有多的空格也可以输出
            j=0;
        }
        i++;
    }/**/
    for(k=j-1;k>=0;k--)//最后一个单词需要单独处理。因为末尾是终止符不是空格
    {
        printf("%c",b[k]);
    }
    return 0;
}
