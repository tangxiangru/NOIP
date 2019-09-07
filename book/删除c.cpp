#include <stdio.h>
 
char *del_char(char *str, char ch)
{
    unsigned char i=0,j=0;
    while(str[i] != '\0')
    {
        if(str[i] != ch)  //只有在不是空格的情况下目标才会移动赋值
        {
            str[j++] = str[i];
        }
        i++;  //源一直移动
    }
    str[j] = '\0';
    return str;
}
 
int main(int argc, const char *argv[])
{
    char ch;
    int i=0;
    char a[1024] = {'\0'};
    while((ch=getchar()) != '\n')
    {
        a[i++] = ch;
    }
    char *s = del_char(a,' ');
    puts(s);
    return 0;
}




#include <stdio.h>
/*从字符串S中删除字符c*/
void squeeze(char[], char);
int main()
{
    char s[] = "hdsjalfh";
    char c;//保存需要删除的字符
    printf("请输入需要删除的字符：");
    c = getchar();
    squeeze(s, c);
    printf("%s\n", s);
    return 0;
}
void squeeze(char s[], char c)
{
    int i = 0, j = 0;
    while(s[i] != '\0'){
        if(s[i] != c){
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}
