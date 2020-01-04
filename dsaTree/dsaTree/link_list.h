#pragma once
typedef int LElemType;

typedef struct  LNode{
	struct LNode *next;
	LElemType data;
}LNode,*Link,*Position;

typedef struct LinkList {
	Link head, tail;
	int len;
}LinkList;

int InitList(LinkList *l);
int MakeLNode(Link *p, LElemType e);
int InsertFirst(LinkList *l, Link head, Link src);
int InsertAfter(LinkList *l, Link dest, Link src);
int DelNode(LinkList *l, Link dest, LElemType *e);
void LVisit(LElemType e);
void TraverseList(LinkList l, void(*visit)(LElemType e));
