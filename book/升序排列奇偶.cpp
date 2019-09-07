链接：https://www.nowcoder.com/questionTerminal/c5d82b96de9342eba9b1d67e5e702837
来源：牛客网

#include<stdio.h> 
   
void main() 
{ 
int i,j,odd,even,n,t,a[10]; 
   
odd=0；
even=9；
for (i=0;i<10;i++)                      //将键盘输入的数据存入数组中
{ 
scanf("%d",&n)；
if (n %2!=0)                      
//将奇数放置在数组的左边
a[odd++]=n; 
else 
a[even--]=n;                     
//将偶数放置在数组的右边
} 
for (i=0;i<odd-1;i++)                 //通过选择排序对奇数进行升序排列
{ 
 n=i; 
for (j=i+1;j<odd;j++) 
if(a[j]<a[n]) 
n=j；
if(n!=i) 
{ 
t=a[i]；
a[i]=a[n]；
a[n]=t；
} 
} 
   
for(i=odd;i<9;i++)                    //通过选择排序对偶数进行升序排列
{ 
n=i；
for(j=i+1;j<10;j++) 
if(a[j]<a[n]) 
n=j；
if(n!=i) 
{ 
t=a[i]；
a[i]=a[n]；
a[n]=t；
} 
} 
   
for (i=0;i<10;i++)              
//输出排序结果
printf("%d",a[i])；
printf("\n")；
} 
