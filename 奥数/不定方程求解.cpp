#include<stdio.h>
#include<stdlib.h>

int main()
{
int a,b,c,x,y;
int count;
count=0;
scanf("%d %d %d",&a,&b,&c);
for(x=0;x<=c;x++){
for(y=0;y<=c;y++){
if(a*x+b*y==c) count++;
}
}
printf("%d",count);

return 0;
}
