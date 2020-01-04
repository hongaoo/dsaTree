#define _CRT_SECURE_NO_WARNG
#include "bi_tree.h"
#include <stdio.h>
#include <Windows.h>
#include <assert.h>
int InitBiTree(BiNode **root_ptr)
{
	(*root_ptr) = NULL;
	return 0;
}

FILE *g_fp;
int GetBiNodeElemt(BTElemType *e)
{
	int temp = 0;
	if(fopen_s(&g_fp, "dat.txt", "r") != 0)
	{
		printf("fopen_s failed\n");
		return -1;
	}
	printf("fopen_s success\n");
	if ((temp = fgetc(g_fp)) > 0)
	{
		*e = temp;
	}
	else
	{
		printf("GetBiNodeElemt failed\n");
		return -1;
	}
	printf("%d ",*e);
	fclose(g_fp);
	return 0;
}

int CreateBiTree(BiNode **root_ptr)
{
	BTElemType e = 0;
	if (GetBiNodeElemt(&e) < 0)
	{
		return -1;
	}
	*root_ptr = (BiNode *)malloc(sizeof(BiNode));
	assert(*root_ptr);
	(*root_ptr)->data = e;
	//CreateBiTree(&((*root_ptr)->lchild));
	//CreateBiTree(&((*root_ptr)->rchild));
}

void TestBiTree()
{
	BiNode *root;
	InitBiTree(&root);
	CreateBiTree(&root);

}

//int main()
//{
//	TestBiTree();
//	system("pause");
//
//}