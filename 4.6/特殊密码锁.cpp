#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
    char src[35],target[35],temp[35];
    int i,len;
    int count,ans=1e9;
    
    scanf("%s%s",src,target);
    len=strlen(src);
    strcpy(temp,src);
    
    //第一种方案：第一个字符不修改，从下一个字符开始。
    i=0;count=0;
    i++;
    while(src[i]!='\0')
    {
        if(src[i-1]!=target[i-1])//前一个元素不等，需要操作当前元素。操作当前元素影响到其左右元素。 
        {
            src[i]=src[i]^1;//取反
            src[i-1]=src[i-1]^1;
            if(i+1<len) src[i+1]=src[i+1]^1;
            count++;
        }
        i++;
    }
    if(src[len-1]==target[len-1]) ans=count;
        
    //第二种方案：第一个字符修改
    strcpy(src,temp);
    i=0;//i重新指向第一个字符
    src[i]=src[i]^1;
    if(i+1<len) src[i+1]=src[i+1]^1;
    count=1;
    i++;
    while(src[i]!='\0')
    {
        if(src[i-1]!=target[i-1])//前一个元素不等，需要操作当前元素。操作当前元素影响到其左右元素。 
        {
            src[i]=src[i]^1;//取反
            src[i-1]=src[i-1]^1;
            if(i+1<len) src[i+1]=src[i+1]^1;
            count++;
        }
        i++;
    }
    if(src[len-1]==target[len-1]) ans=ans<count?ans:count;
        
    if(ans==1e9) printf("impossible\n");
    else printf("%d\n",ans);
    return 0;
}
