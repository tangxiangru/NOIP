#include <stdio.h>
#include <string.h>

void func(int a, int *num);

void main()
{	
	int a, i;
	int num[9];
	for (i = 0; i < 9; i++)
		num[i] = 0;
	for (a = 1; a < 10000; a++)
		func(a, num);
	for (i = 0; i < 9; i++)
		printf("乘积根为%d的有%d个\n",i+1,num[i]);
}

void func(int a, int *num)
{
	int sum = 1,r;

	while(a != 0)
		{
			r = a % 10;
			if (r != 0)
				sum = sum * r;
			a = a / 10;
		}
	if(sum > 9)
		func(sum, num);
	if(sum == 1)
		num[0]++;
	if(sum == 2)
		num[1]++;
	if(sum == 3)
		num[2]++;
	if(sum == 4)
		num[3]++;
	if(sum == 5)
		num[4]++;
	if(sum == 6)
		num[5]++;
	if(sum == 7)
		num[6]++;
	if(sum == 8)
		num[7]++;
	if(sum == 9)
		num[8]++;
}