#include<stdio.h>

void factor(int a, int b);

void main()
{
	int a, b;
	printf("输入两个数字：");
	scanf("%d",&a);
	scanf("%d",&b);
    printf("%d和%d的最大公因数：",a,b);
	factor(a,b);
}

void factor(int a, int b)
{
	if (a == b)
		printf("%d\n",a);
	else if (a > b)
		factor(a-b,b);
	else if (a < b)
		factor(b-a,a);
}