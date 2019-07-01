#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
char s[100];
int i;
int w;
scanf("%s%d",s);

n=0;
w=1;
for(i=strlen(s)-1;i>=0;i--){
n+=(s[i]-'0')*w;
w*=8;
}
printf("%d",n);
return 0;
}
