#include "queue.h"
#include<stdio.h>
#include<assert.h>

FILE *g_fp;
int DatEnqueue(void)
{
	QElemType data_t = 0;
	assert(!fopen_s(&g_fp,"dat.txt","r"));
	while (fscanf_s(g_fp, "%d", &data_t, sizeof(QElemType)) != EOF)
	{
		printf("%d ", data_t);
	}
	fclose(g_fp);
}
int main() {
	//TestQueue();
	DatEnqueue();
	system("pause");
}