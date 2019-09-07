#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

struct Word
{
	char word[20];
	int time;
	struct Word *next;
};
typedef struct Word WORD;

void beep();
void GetPassage(char str[]);
WORD *Creat_LinkList (char str[]);
void Sort (WORD *head, int i);
void Display_LinkList (WORD *head);
void Free_LinkList (WORD *head);

void main()
{
	WORD *head;
	char str[300];

	printf("ÇëÊäÈë×Ö·û´®:");

	GetPassage(str);

	head = Creat_LinkList (str);
	if (head == NULL)
		return;

	Display_LinkList (head);
}

void GetPassage(char str[])
{
	int i = 0;
	char ch;

	while(1)
	{
		ch = getch();
		if (ch == '\r')  //»Ø³µ·û£¬ÍË³ö  
			break;
		if (ch == '\b')  //ÍË¸ñ·û
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
		if (ch != ' ' && ch != ',' && ch != '.' && !isalpha(ch))   //·Ç¿Õ¸ñ¡¢¶ººÅ¡¢¾äºÅ¡¢×ÖÄ¸
		{
			beep();
			continue;
		}
		if (i < 300)   
		{
			printf("%c",ch);
			str[i++] = ch;
		}
		else
			beep();
	}
	str[i] = '\0';  //ÖÃ×Ö·û´®½áÊø±êÖ¾
}

void beep()  //ÏìÁå
{
	printf("\07");
}

WORD *Creat_LinkList (char str[])
{
	WORD *head, *tail, *pnew, *p;

	char wordstr[20];
	int i, j, flag;
	int num = 0;

	head = (WORD *)malloc (sizeof(WORD));
	if (head == NULL)
	{
		printf("no enough memory!\n");
		return (NULL);
	}
	head->next = NULL;
	tail = head;

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

		flag = 1;

		for (p = head->next; p != NULL; p = p->next)
		{
			if (stricmp(wordstr, p->word) == 0)
			{
				(p->time)++;
				flag = 0;
				break;
			}
		}

        if(flag == 1)
		{
			pnew = (WORD *)malloc (sizeof(WORD));
			if (pnew == NULL)
			{
				printf("no enough memory!\n");
				return (NULL);
			}
		
			strcpy(pnew->word,wordstr);
			pnew->time = 1;

			pnew->next=NULL;

			tail->next=pnew;
			tail=pnew;
			num++;
		}
	}
	printf("\n");

	Sort(head, num);

	return (head);
}

void Free_LinkList (WORD *head)
{
	WORD *p, *q;

	p = head;
	while(p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free (head);
}

void Display_LinkList (WORD *head)
{
	WORD *p;

	for (p = head->next; p != NULL; p = p->next)
	{
		printf("%s\t", p->word);
		printf("(%d)\n", p->time);
	}
	printf("\n");
}

void Sort (WORD *head, int n)
{
	WORD *L, *p, *q;
	int t;
	char a[20];
    int i = 0;
    int j = 0;
    
    for (i = 0; i < n - 1; i++)
	{
		L = head->next;
		for (j = 0; j < n - i - 1; j++)
		{
			p = L;
			q = L->next;
			if (p->time < q->time || 
				((p->time) == (q->time) && stricmp((p->word), (q->word)) > 0))
			{
				t = p->time;
				p->time = q->time;
				q->time = t;

				strcpy(a,p->word);
				strcpy(p->word,q->word);
				strcpy(q->word,a);
			}
			L = L->next;
		}
	}
}