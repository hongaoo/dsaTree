#include "queue.h"
int InitQueue(LinkQueue *Lq)
{
	InitList(Lq);
}

int EnQueue(LinkQueue *lq, QElemType e)
{
	Link p;
	MakeLNode(&p, e);
	InsertAfter(lq,lq->head,p);
}

int DeQueue(LinkQueue *lq,QElemType *e)
{
	DelNode(lq,lq->tail,e);
}


static void QVisit(QElemType e)
{
	printf("%d ",e);
}
void TraverseQueue(LinkQueue lq)
{
	TraverseList(lq, QVisit);
}

int QueueLen(LinkQueue lq)
{
	return lq.len;
}


void TestQueue(void)
{

	LinkQueue lq;
	int i = 0;
	int len_t = 0;
	QElemType data_t = 0;
	InitQueue(&lq);
	printf("Enqueue test\n");
	for(i = 0;i<10;i++)
		EnQueue(&lq, i);
	printf("queue len:%d\n",lq.len);
	TraverseQueue(lq);
	
	printf("\nDequeue test\n");
	len_t = lq.len;
	for (i = 0; i < len_t; i++)
	{
		DeQueue(&lq, &data_t);
		printf("Dequeue data:%d\n", data_t);
		TraverseQueue(lq);
		printf("\n");
	}

}
