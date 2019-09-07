#include<stdio.h>

#include<string.h>

char str1[100], tmp;

int i,j,b,t;

void JsSort();

void main()

{

    memset(str1,0,100);

 memset(str2,0,100);

 printf("please enter no.");

 for(i=0;(str1[i]=getchar())!='\n';i++);

 str1[i]='\0';

 JsSort();

 printf("%s\n",str1);

 system("pause");

}

void JsSort()

{

 b=strlen(str1);

 for(i=0;i<b-2;i+=2)

   for(j=0;j<b-2-i;j+=2)

    if (str1[j]<str1[j+2])

    {t=str1[j]; str1[j]=str1[j+2]; str1[j+2]=t;}

}
