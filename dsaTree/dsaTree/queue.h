#pragma once
#include "link_list.h"
typedef LElemType QElemType;
typedef LinkList LinkQueue;

int InitQueue(LinkQueue *Lq);
int EnQueue(LinkQueue *lq, QElemType e);
int DeQueue(LinkQueue *lq);
void TraverseQueue(LinkQueue lq);
int QueueLen(LinkQueue lq);
void TestQueue(void);