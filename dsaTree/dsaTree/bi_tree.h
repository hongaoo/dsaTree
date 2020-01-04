#pragma once
#ifndef BI_TREE_H
#define BI_TREE_H

typedef int BTElemType;

typedef struct BiNode{
	BTElemType data;
	struct BiNode *lchild, *rchild;
}BiNode;
#endif // !BI_TREE_H
