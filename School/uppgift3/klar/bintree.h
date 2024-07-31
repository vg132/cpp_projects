#ifndef __94ADE64DCCA8690484D52__BINTREE__H__
#define __94ADE64DCCA8690484D52__BINTREE__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_BINARY_TREE

typedef int (*CmpFunc)(void*, void*, void*);
typedef void (*ForAllFunc)(void *, void *);
typedef void (*DelFunc)(void *, void *);

typedef struct treenode
{
	void *data;
	struct treenode *left, *right;
}TreeNode;

typedef struct bintree
{
	struct treenode *root;
	CmpFunc cmp;
}BinTree;

BinTree* InitTree(CmpFunc cmp);
void DoForAll(BinTree *tree, ForAllFunc all, void *extra);
void PreOrder(BinTree *tree, ForAllFunc all, void *extra);
void PostOrder(BinTree *tree, ForAllFunc all, void *extra);

void* FindItem(BinTree *tree, void *data, void *extra);
void AddItem(BinTree *tree, void *data, void *extra);
int DeleteItem(BinTree *tree, void *data, void *extra);
int DeleteAll(BinTree *tree, DelFunc del, void *extra);

#endif // __94ADE64DCCA8690484D52__BINTREE__H__
