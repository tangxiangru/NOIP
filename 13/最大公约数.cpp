#include<stdio.h>

void factor(int a, int b);

void main()
{
	int a, b;
	printf("�����������֣�");
	scanf("%d",&a);
	scanf("%d",&b);
    printf("%d��%d�����������",a,b);
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