#include <stdio.h>
#include <string.h>

char *Replace(char *str, char *substr, char *newstr);

void main()
{
	char a[80], b[80], c[80], *d;
	gets(a);
	gets(b);
	gets(c);
    d = Replace(a, b, c);
	printf("%s", a);
}

char *Replace(char *str, char *substr, char *newstr)
{
	int a, b, i, j, k, flag = 1;
	a = strlen (str);
	b = strlen (substr);
	for (i = 0; i < a; i++)
	{
		if(str[i] == substr[0])
			flag = 0;
			for (j = i+1, k = 1; k < b; j++,k++)
				if (str[j] != substr[k])
					flag = 1;
		if (flag == 0)
			for (j = 0; j < b; j++)
			{
				str[i] = newstr[j];
				i += 1;
			}
	}
	return str;
}