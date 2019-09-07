#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	char name[20];
	float math;
	float english;
	float c;
	float total;
	struct Student *next;
};
typedef struct Student STUDENT;

STUDENT *Creat_LinkList ();
void Insert_LinkList (STUDENT *head);
void Display_LinkList (STUDENT *head);
void Free_LinkList (STUDENT *head);

void main()
{
	STUDENT *head;
	int i, t;
	
	printf("输入学生人数:");
	scanf("%d",&i);

	head = Creat_LinkList ();
	if (head == NULL)
		return;

	for (t = 1; t < i; t++)
		Insert_LinkList(head);

	printf("学生成绩（降序）：\n");
	Display_LinkList (head);
	Free_LinkList(head);
}

STUDENT *Creat_LinkList ()
{
	STUDENT *head, *tail, *pnew;

	char name[20];
	float math, english, c, total;

	head = (STUDENT *)malloc (sizeof(STUDENT));
	if (head == NULL)
	{
		printf("no enough memory!\n");
		return (NULL);
	}

	head->next = NULL;
	tail = head;

	fflush(stdin);
	printf("输入学生姓名:");
	gets(name);
	printf("输入数学成绩:");
	scanf("%f",&math);
	printf("输入英语成绩:");
	scanf("%f",&english);
	printf("输入C语言成绩:");
	scanf("%f",&c);
	
	total = math + english + c;

	pnew = (STUDENT *)malloc (sizeof(STUDENT));
	if (pnew == NULL)
	{
		printf("no enough memory!\n");
		return (NULL);
	}

	strcpy(pnew->name,name);
	pnew->math = math;
	pnew->english = english;
	pnew->c = c;
	pnew->total = total;

	pnew->next=NULL;
	
	tail->next=pnew;
	tail=pnew;

	printf("\n");
	return (head);
}

void Free_LinkList (STUDENT *head)
{
	STUDENT *p, *q;

	p = head;
	while(p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free (head);
}

void Display_LinkList (STUDENT *head)
{
	STUDENT *p;

	for (p = head->next; p != NULL; p = p->next)
	{
		printf("姓名:%s\t", p->name);
		printf("数学成绩:%.2f\t", p->math);
		printf("英语成绩:%.2f\t", p->english);
		printf("C语言成绩:%.2f\t", p->c);
		printf("总成绩:%.2f\t", p->total);
		printf("\n");
	}
	printf("\n");
}

void Insert_LinkList (STUDENT *head)
{
	char name[20];
	float math, english, c, total;
	STUDENT *p, *pnew;

	pnew = (STUDENT *)malloc (sizeof(STUDENT));

	if (pnew == NULL)
	{
		printf("no enough memory!\n");
		Free_LinkList(head);
		return ;
	}

	fflush(stdin);
	printf("输入学生姓名:");
	gets(name);
	printf("输入数学成绩:");
	scanf("%f",&math);
	printf("输入英语成绩:");
	scanf("%f",&english);
	printf("输入C语言成绩:");
	scanf("%f",&c);
	
	total = math + english + c;

	strcpy(pnew->name,name);
	pnew->math = math;
	pnew->english = english;
	pnew->c = c;
	pnew->total = total;
	printf("\n");

	for (p = head; p->next != NULL; p = p->next)
	{
		if(p->next->total < total)
			break;
	}

	pnew->next=p->next;
	p->next=pnew;
}