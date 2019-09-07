#include<stdio.h>
 
void main()
{
	int i, j, k, n;
	for(i = 0;i<=9;i++)
		for(j = 0;j<=9;j++)
			for (k = 1; k <= 9; k++)
			{
				n = i + j * 10 + k * 100;
				if (i*i*i + j *j*j + k*k*k == n)
					printf("%d\n", n);
			}
}
