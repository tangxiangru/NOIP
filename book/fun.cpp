#include <stdio.h>
#include <string.h>
 
void fun(char str[1000])
{
int i,j=0,n,b[1000];
n=strlen(str);
for(i=0;i<n;i++)
if(str[i]<48||str[i]>57)
{b[j]=str[i];j++;}
for(i=0;i<j;i++)
printf("%c",b[i]);
}
 
int main()
{
char str[1000];
gets(str);
fun(str);
}
