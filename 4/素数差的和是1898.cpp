#include<stdio.h>

void main()
{
	int m, i, p = 1, num = 0, a[1000], b[1000], sum;
	a[0] = 2;
	for(m = 3; m <= 2000;m = m+2)
	{
		for(i = 2; i < m; i++)
		if(m%i == 0)
			break;
		if(i == m)
		{
			a[p] = m;
			p++;
		}
	}

	printf("��һ���ǣ�");
	for(i = 0; i < p; i++)
		printf("%4d  ",a[i]);
	printf("\n\n");

	printf("�ڶ����ǣ�");
	for(i = 1, m = 0; i < p; i++, m++)
	{
		b[m] = a[i] - a[i-1];
		printf("%3d  ",b[m]);
	}
	printf("\n\n");

	for (i = 0; i < p; i++)
	{	
		sum = 0;
		for(m = i; m < p; m++)
		{
			sum = sum + b[m];
			if (sum == 1898)
			{
				num++;
				printf("���ڵ�%d��������%d�����ĺ���1898\n",i+1,m+1);
			}
		}
		i++;
	}
	if (num == 0)
		printf("������!\n");
}