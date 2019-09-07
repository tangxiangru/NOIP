#include<stdio.h>
void bubblesort(int a[],int n)//n为数组a的元素个数
{
int i,j,temp;
for(j=0;j<n-1;j++)
for(i=0;i<n-1-j;i++)
{
if(a[i]<a[i+1])//数组元素大小按降序排列
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
}
}
}
void main()
{
int repeat, n;
int i, j;
int num[100];
scanf("%d",&repeat);
for(i = 0; i < repeat; i++)
{
scanf("%d",&n);
for(j = 0; j < n; j++)
{
scanf("%d",&num[j]);
}
bubblesort(num,n);
for(j = 0; j < n; j++)
{
printf("%d ",num[j]);
}
printf("\n");
}
} 
