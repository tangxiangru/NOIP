#include<stdio.h>
#include<string.h>

void main()
{
	int i, len;
	char a[20];
	printf("����һ�����ʣ�");
	gets(a);
	len = strlen(a);
	printf("%s�ĸ�����ʽ�ǣ�",a);
	if (a[len-1] == 'y')
	{
		for (i = 0; i < len - 1; i++)
			printf("%c",a[i]);
		printf("ies\n");
	}

	else if (a[len-1] == 'o')
	{
		for (i = 0; i < len; i++)
			printf("%c",a[i]);
		printf("es\n");
	}

	else if (a[len-1] == 's' || a[len-1] == 'x' || (a[len-1] == 'h' && a[len-2] == 's') || (a[len-1] == 'h' && a[len-2] == 'c'))
	{
		for (i = 0; i < len; i++)
			printf("%c",a[i]);
		printf("es\n");
	}
	else
	{
		printf("%s",a);
		printf("s\n");
	}
}