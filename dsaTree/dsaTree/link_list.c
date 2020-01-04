#include "link_list.h"
#include "debug.h"
#include <stdlib.h>
#include <stdio.h>


int InitList(LinkList *l)
{
	Link p = (Link)malloc(sizeof(LNode));
	CHECK_NULL_PTR(p);
	p->next = NULL;
	l->head = l->tail = p;
	l->len = 0;
	return 0;
}

int MakeLNode(Link *p,LElemType e)
{
	*p = (Link)malloc(sizeof(LNode));
	CHECK_NULL_PTR(*p);
	(*p)->data = e;
	return 0;
}

int InsertFirst(LinkList *l,Link head,Link src)
{
	src->next = head->next;
	head->next = src;
	if (head == (l->tail))
	{
		l->tail = src;
	}
	l->len++;
	return 0;
}

//insert src after dest
int InsertAfter(LinkList *l,Link dest,Link src)
{
	src->next = dest->next;
	dest->next = src;
	if (dest == l->tail)
	{
		l->tail = src;
	}
	l->len++;
	return 0;
}

int DelNode(LinkList *l,Link dest,LElemType *e)
{
	Link pre = l->head;
	CHECK_NULL_PTR(dest);
	while (pre&&(pre->next!=dest))
	{
		pre = pre->next;
	}
	CHECK_NULL_PTR(pre);
	if (dest == l->tail)
	{
		l->tail = pre;
	}
	pre->next = dest->next;
	*e = dest->data;
	free(dest);
	l->len--;
	return 0;
}

void LVisit(LElemType e)
{
	printf("%d ",e);
}
void TraverseList(LinkList l,void(* visit)(LElemType e))
{
	Link p = (l.head)->next;
	while (p)
	{
		visit(p->data);
		p = p->next;	
	}
}


//
void TestLinkList()
{
	LinkList list_1;
	Link link;
	int i = 0;
	LElemType data_t = 0;
	InitList(&list_1);
	printf("insert node after head test\n");
	for (i = 0; i < 10; i++)
	{
		MakeLNode(&link,i);
		InsertAfter(&list_1,list_1.head,link);
	}
	TraverseList(list_1,LVisit);
	printf("\ndelete tail node test\n");
	for (i = 0;i<5;i++)
	{
		DelNode(&list_1, list_1.tail, &data_t);
	}
	TraverseList(list_1, LVisit);

	printf("\ninsert node after tail test\n");
	for (i = 0; i < 10; i++)
	{
		MakeLNode(&link, i);
		InsertAfter(&list_1, list_1.tail, link);
	}
	TraverseList(list_1, LVisit);
	printf("\ndelete node after head test\n");
	for (i = 0; i < 5; i++)
	{
		DelNode(&list_1, list_1.head, &data_t);
	}
	TraverseList(list_1, LVisit);
}

//int main()
//{
//	TestLinkList();
//	system("pause");
//
//}

