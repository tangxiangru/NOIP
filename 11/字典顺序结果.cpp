#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define N 300

void beep();  //����
void GetPassage(char str[ ]); //��ȡӢ�Ķ���
void WordSepa(char str[ ], char word[ ][20]); //���ʷֽ�
void SaveWord(char wordstr[ ], char word[ ][20]); //���ʱ���
void SortWord(char word[ ][20]); //��������

void main()
{
	char str[N+1], word[50][20] = {0}; 

	GetPassage(str);
	WordSepa(str, word);
	SortWord(word);

	printf("\n");
	for(int i = 0; word[i][0] > 0; i++)
		printf("%s\t%d\n", word[i]+1, word[i][0]);
	printf("\n");
}

//��ȡӢ�Ķ���
void GetPassage(char str[])
{
	int i = 0;
	char ch;

	while(1)
	{
		ch = getch();
		if (ch == '\r')  //�س������˳�  
			break;
		if (ch == '\b')  //�˸��
		{
			if (i > 0)  
			{
				printf("%c %c",ch,ch);
				i--;
			}
			else
				beep();
		continue;
	    }
		if (ch != ' ' && ch != ',' && ch != '.' && !isalpha(ch))   //�ǿո񡢶��š���š���ĸ
		{
			beep();
			continue;
		}
		if (i < N)   
		{
			printf("%c",ch);
			str[i++] = ch;
		}
		else
			beep();
	}
	str[i] = '\0';  //���ַ���������־
}

void beep()  //����
{
	printf("\07");
}

//���ʷֽ�
void WordSepa(char str[], char word[][20])
{
	char wordstr[20];
	int i, j;

	for(i = 0; str[i] != '\0'; )
	{
		if (!isalpha(str[i]))
		{
			i++;
			continue;
		}
		j = 0;
		while (isalpha(str[i]))
			wordstr[j++] = str[i++];
		wordstr[j] = '\0';

		SaveWord(wordstr, word);
	}
}

//���ʱ���
void SaveWord(char wordstr[], char word[][20])
{
	int i;

	for(i = 0; word[i][0] > 0; i++)
	{
		if (stricmp(wordstr, word[i]+1) == 0)
		{
			word[i][0]++;
			return;
		}
	}
	word[i][0] = 1;
	strcpy(word[i]+1, wordstr);
}

//��������
void SortWord(char word[ ][20])
{
	int i, j, k;
	char str[20];

	for(i = 0; word[i][0] > 0; i++)
	{
		k = i;
		for(j = i+1; word[j][0] > 0; j++)
			if ((word[j][0] > word[k][0]) || 
				(word[j][0] == word[k][0] && stricmp(word[j]+1, word[k]+1) < 0))
				k = j;
			if (k != i)
			{
				strcpy(str, word[i]);
				strcpy(word[i], word[k]);
				strcpy(word[k], str);
			}
	}
}