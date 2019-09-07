#include <stdio.h>
#include <stdlib.h>

int year(int year);
int check(char *str);
void main(int argc, char *argv[])
{
	int y;
	int i, j, sum=0;
	int day, week;
	int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	if ( argc != 2)
	{
		printf ("请以正确格式输入年份（例如:Calendar 2003）");
		exit(0);
	}

	y = check(argv[1]);

	for(i = 1; i < y; i++)
		sum = sum + year(i);

	week=(sum+1)%7;

	if(year(y)==366)
		mon[1]=29;

	printf("\n%d年日历如下：\n\n",y);
	
	for(i=0;i<12;i++)
	{
		printf("\t\t\t    ====%d月====\n",i+1);
		printf("\tSun\tMon\tTues\tWed\tThur\tFri\tSat\n");
		day=1;
		for(j = 0; j < week; j++)
			printf("\t");
		while(day <= mon[i])  
		{
			printf("\t %d",day);
			day++;
			week=(week+1)%7;
			if(week == 0)
				printf("\n");
		}  
		printf("\n\n");
	}
}

int check(char *str)
{
	int k, i = 0;
	while (str[i] != 0)
	{
		if(str[i] < '0' || str[i] > '9')
			return (-1);
		else
			i++;
	}
	k = atoi(str);
	return (k);
}

int year(int year)
{
	if ((year%4==0) && (year%100!=0) || year%400==0)
		return 366;
	else
		return 365;
}