#include <stdio.h> 
#define SIZE 10 
void swap (int *x,int *y); 
   
void main() 
{ 
int a[SIZE],b[SIZE],i,n; 
   
printf ("Input array length n<=%d: ",SIZE); 
scanf ("%d",&n)；
printf ("Input array a: ")；
fox (i=0;i< n;i++) 
scanf("%d”,&a[i])；
printf ("Input array b: "); 
for (i=0;i< n;i++) 
scanf(“%d",&b[i])；
for (i=0;i<n;i++)                    //调用交换函数,实现两数组元素互换
swap (&a[i],&b[i]); 
   
printf("After swap:\n"); 
printf("Array a: “), 
for (i=0;i<n;i++) 
printf ("%d”,a[i]); 
printf (“\n")；
printf("Array b: "); 
for (i=0;i<n;i++) 
printf ("%d",b[i])；
printf("\n")；
} 
   
//交换整型指针x和y所指向的两个整数
void swap (int *x,int *y) 
{ 
int temp；
   
temp=*x; 
*x=*y; 
*y=temp; 
} 
