#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void check(char str[]);

void main()
{
	char str[40000];
	int N;
	printf(" ‰»Î:");
	scanf("%d",&N);
	N *= N;
	itoa(N, str, 10);
	check(str);
}

void check(char str[])
{
	char i, j;
	int len;
	len = strlen (str);
	i = 0;
	j = len - 1;
	while (str[i] == str[j] && i <= j)
	{
		i++;
		j--;
	}
	if(i<j)
		printf("No!\n");
	else
		printf("Yes!\n");
}