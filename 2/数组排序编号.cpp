#include<stdio.h>
#include<string.h>

void main()
{
	int a[100];
	int s[2][100];
	int i, j, k, p ,t, num;
	char ch;
	printf("���������֣����ּ��ÿո�������س����������룩��");
	for (i = 0, j = 0; i < 100 && ch!='\n'; i++)
	{
		scanf("%d",&a[i]);
		ch=getchar();
		j++;
	}
	num = j;
	for (i = 0, p = 0; p < j; i++,p++)
	{
		s[0][i] = a[p];
		for (k = 0; k < i; k++)
		{
			if(s[0][k] == s[0][i])
			{
				i--;
			}
		}
	}
	for (j = 0; j < i-1; j++)
 	{
 		k=j;
 		for (p=j+1;p<i;p++)
 			if (s[0][p]<s[0][k])
 			k=p;
 		if (k!=p)
 		{
 			t=s[0][j];
 			s[0][j]=s[0][k];
 			s[0][k]=t;
		}
	}
	for (j = 0; j < i; j++)
		s[1][j] = j + 1;

	printf("��Щ���ֵı�ŷֱ�Ϊ��");
	for (j = 0; j < num; j++)
	{
		for (k = 0; k < i; k++)
		{
			if(a[j] == s[0][k])
				printf("%d ",s[1][k]);
		}
	}
	printf("\n");
}
