#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n=0,ch;
    while((ch=getchar())!='\n')   //用ch保存getchar接收到的输入字符ascii码
    {
        n+=(ch-'0');     //-'0' 是ascii码转数字
 
    }
    printf("%d",n);
    system("pause");
}
 
