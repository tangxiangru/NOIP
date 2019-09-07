#include<stdio.h>
#include<string.h>
int main()
{
    char str[]="0123456789";
    char sstr[80]={0}; //使用一数组储存移动后的字符串
    char *p;
    int c,j;
    static int i,n;
    p=&str[0];
    printf("input the number: \n");
    scanf("%d",&n); //输入要左移的前n个字符，即将这n个字符移动到最后面
    c=n;
    while( c-- && p++ ); //找到没有移动过的剩下的全部字符，把它们储存在数组sstr 中

        for(i=0;i<strlen(str)-n;i++)
        {
            sstr[i]= *p;
            p++;
        }
        p=&str[0];  //指针指向第一个字符
        for(j=i;j<strlen(str);j++) //将要移动的字符一个一个地“接”到数组sstr后面
        {
            sstr[j]= *p;
            p++;
        }
        sstr[j]='\0'; //最后字符串结尾用'\0'
        printf("%s",sstr);  
        return 0;
}

