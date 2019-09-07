#include<stdio.h>

#include<stdlib.h>

#include<string.h>

char*substr(char*s,int starloc,int len)

{char *p,*p1,*p2;

p2=p=(char*)malloc(len+1);

p1=s+starloc;

for(;*p1&&p1<s+starloc+len;)

*p++=*p1++;

*p='\0';

return p2;

}

int main()

{char *p,s[]="12345678";

p=substr(s,0,4);

printf("s=%s\ns1=%s\n",s,p);

free(p);

return 0;

}
