#include<stdio.h>
#include<conio.h>
#include<string.h>

#define N 100
#define M 200

void beep();
void GetNumberStr (char s[], int *t);
void Mul(char num1[], int a, char num2[], int b);

void main()
{
	char a[N+1]={0}, b[N+1]={0};
	int num1, num2;
	printf("a=");
	while(strlen(a) == 0)
		GetNumberStr(a, &num1);
	printf("b=");
	while(strlen(b) == 0)
		GetNumberStr(b, &num2);
	Mul(a, num1, b, num2);
}

void GetNumberStr(char s[], int *t)
{
	int i = 0;
	char ch;
	
	while(1)
	{
		ch = getch();
		if (ch == '\r')
			break;
		if (ch == '\b')
		{
			if(i > 0)
			{
				printf ("%c %c", ch, ch);
				i--;
			}
			else
				beep();
			continue;
		}
		if (ch < '0' || ch > '9')
		{
			beep();
			continue;
		}
		if (i < N)
		{
			printf ("%c",ch);
			s[i++] = ch;
		}
		else
			beep();
	}
	s[i] = '\0';
	printf("\n");
	*t = i;
}

void beep()
{
	printf("\07");
}

void Mul(char num1[], int a, char num2[], int b)
{
	int i, j, k;
	int result[M + 2];
	memset(result, 0, sizeof(result));
    for (i = 0; i < a; i++)
	{
        for (j = 0; j < b; j++)
		{
            result[i + j + 1] += (int)(num1[i] - '0') * (int)(num2[j] - '0');  //因为进位的问题，最终放置到第i+j+1位
        }
    }

    //单独处理进位
    for(k = a + b - 1; k > 0; k--)
	{
        if(result[k] > 10)
		{
            result[k - 1] += result[k] / 10;
            result[k] %= 10;
        }
    }
	printf("a*b=");

	for (i = 0; i < a+b; i++)
		if(result[i] != 0)
			break;
	for ( ; i < a+b; i++)
		printf("%d",result[i]);
	printf("\n");
}