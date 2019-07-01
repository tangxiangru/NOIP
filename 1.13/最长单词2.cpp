#include<stdio.h>
#include<string.h>
int main()
{
    int maxLen,len;
    char str1[200],str2[200];
    freopen("5.in","r",stdin);
    maxLen=-1;
    while(scanf("%s",str1)!=EOF)
    {
        len=strlen(str1);
        if(str1[len-1]=='.')//如果读到了最后一个单词，要修正一下：删掉最后的'.' 
        {
            str1[len-1]='\0';
            len--;
        }
        if(len>maxLen)
        {
            strcpy(str2,str1);
            maxLen=len;
        }
    }
    printf("%s\n",str2);
    return 0;
}
