#include<stdio.h>
 
void print(int n)
{
	if(n != 0)
	{
		print(n/10);
		printf("%d",n%10);
	}
}
int main()
{
	int a = 12345;
	print(a);
	printf("\n");
 
	return 0;
}
