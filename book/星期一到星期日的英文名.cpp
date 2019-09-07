
#include <stdio.h>
 
#include <stdlib.h>
 
#include <math.h>
int GetWeek(char *str);
char *week_str[]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
int main (int argc,char *argv[ ])
{
int k；
if(argc !=2)
{
printf ("Use this program like this:example9-8 3");
exit(0);
}
 
k=GetWeek (argv[1]);
 
if (k == -1)
 
{
 
printf("command line argument must be in [0..6]\n");
 
exit (0);
 
}
 
printf("%s\n",week_str[k]);
 
}
 
   
 
//功 能：判断命令行参数中的星期数是否合法，
 
//返回值：合法返回星期的整型值，不合法则返回-1
 
int GetWeek (char *str)
 
{
 
int k,i=0;
 
   
 
while (str[i] !=0)
 
{
 
if (str[i]<'0' || str[i]>'9') return(-1);
else i++;
}
 
k=atoi(str);
 
if ( k<0 || k>6 ) return (-1);

return (k);
}

