#include <stdio.h>
 
#include <string.h>
 
   
 
int totsubstrnum (char *str,char *substr);
 
   
 
void main()
 
{
 
char str[80],substr[80]；
 
   
 
printf("Input string:");
 
gets(str);
 
printf("Input substring:");
 
gets(substr)；
 
printf("count=%d\n",totsubstrnum (str,substr))；
 
}
 
   
 
//统计子串substr在字符串str中出现的次数
 
int totsubstrnum(char *str,char *substr)
 
{
 
int i=0,count=0,len1,len2；
 
   
 
len1=strlen (str)；
 
len2=strlen (substr)；
 
while(i<= 1en1-len2)
 
{
 
if(strncmp (str+i,substr,len2) == 0)
 
{
 
count++；
 
i+=1en2；
 
}
 
else
 
i++；
 
}
 
return (count)；
 
} 
