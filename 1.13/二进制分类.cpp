#include<stdio.h>
int main(){
int n1,n0,a=0,b=0;
for(int i=1;i<=1000;i++){
n1=0;n0=0;
for(int j=0;(1<<j)<=i;j++)(i>>j)&1?n1++:n0++;
n1>n0?a++:b++;
}
printf("%d %d",a,b);
}
