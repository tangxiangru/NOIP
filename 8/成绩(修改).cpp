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
	
	printf("����ѧ������:");
	scanf("%d",&i);

	head = Creat_LinkList ();
	if (head == NULL)
		return;

	for (t = 1; t < i; t++)
		Insert_LinkList(head);

	printf("ѧ���ɼ������򣩣�\n");
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
	printf("����ѧ������:");
	gets(name);
	printf("������ѧ�ɼ�:");
	scanf("%f",&math);
	printf("����Ӣ��ɼ�:");
	scanf("%f",&english);
	printf("����C���Գɼ�:");
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
		printf("����:%s\t", p->name);
		printf("��ѧ�ɼ�:%.2f\t", p->math);
		printf("Ӣ��ɼ�:%.2f\t", p->english);
		printf("C���Գɼ�:%.2f\t", p->c);
		printf("�ܳɼ�:%.2f\t", p->total);
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
	printf("����ѧ������:");
	gets(name);
	printf("������ѧ�ɼ�:");
	scanf("%f",&math);
	printf("����Ӣ��ɼ�:");
	scanf("%f",&english);
	printf("����C���Գɼ�:");
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