#include <stdio.h>
#include <string.h>
 
//若str2不在str1中,返回-1
int SearchStrPosition(char* str1, char* str2)
{
	int len1,len2;
	int position = -1;
	len1 = strlen(str1);
	len2 = strlen(str2);
	if(len2 > len1)       //若str2的长度大于str1，则str2必不可能在str1中，直接输出-1
	{
		return -1;
	}
	int i;
	int j;
	for(i = 0; i < len1; i++)
	{
		for(j = 0; j < len2; j++)
		{
			if(i + j >= len1)    //i循环到末端还没找到，导致剩下的字符串数目比str2长度短，肯定不会再有
				return -1;
			if(str1[i + j] != str2[j] && str1[i + j] != str2[j] + 32 && str1[i + j] != str2[j] - 32)
			{
				break;
			}
			
			if(j == len2 - 1)   //j索引到len2的最后，表明前面字符都符合，记录下此时str1的索引位置即为想要的结果
				position = i;
		}
	}
	return position;
}
int main()
{
	char s1[4096], s2[4096];
	char *str1 = s1, *str2 = s2;
	int pos;
 
	printf("please enter one chars for str1\n");
	scanf("%s",str1);
	printf("please enter one chars for str2\n");
	scanf("%s",str2);
 
	pos = SearchStrPosition(str1,str2);
 
	if(pos != -1)
		printf("the position of str2 in the str1 is %d",pos);
	else
		printf("The %s can not been included into %s",str2,str1);
 
	return 0;
}
