#include "bintree.h"

/* Interna funktioner som bara ska kunna användas internt i denna fil */
void insert(CmpFunc cmp,TreeNode **oldNode,TreeNode *newNode, void *extra);
void* find(CmpFunc cmp,TreeNode *node, void *data, void *extra);
TreeNode* GetSuccessor(TreeNode *node);
void doforall(TreeNode *node, ForAllFunc all, void *extra);
void preorder(TreeNode *node, ForAllFunc all, void *extra);
void postorder(TreeNode *node, ForAllFunc all, void *extra);
void delall(TreeNode *node, DelFunc del, void *extra);

/* Skapar ett nytt tomt träd */
BinTree* InitTree(CmpFunc cmp)
{
	BinTree *btree=malloc(sizeof(BinTree));
	btree->cmp=cmp;
	btree->root=NULL;
	return(btree);
}

/* Lägger till en nod i trädet */
void AddItem(BinTree *tree, void *data, void *extra)
{
	TreeNode *node=malloc(sizeof(TreeNode));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	insert(tree->cmp,&(tree->root),node, extra);
}

/* Interna add funktionen */
void insert(CmpFunc cmp,TreeNode **oldNode,TreeNode *newNode, void *extra)
{
	if((*oldNode)==NULL)
		(*oldNode)=newNode;
	else if(cmp((*oldNode)->data,newNode->data,extra)<0)
		insert(cmp,&(*oldNode)->left,newNode,extra);
	else
		insert(cmp,&(*oldNode)->right,newNode,extra);
}

/* Tar bort alla noder från trädet */
int DeleteAll(BinTree *tree, DelFunc del, void *extra)
{
	delall(tree->root,del,extra);
	tree->root=NULL;
	return(1);
}

/* Intern ta bort funktion */
void delall(TreeNode *node, DelFunc del, void *extra)
{
	if(node)
	{
		postorder(node->left,del,extra);
		postorder(node->right,del,extra);
		del(node->data,extra);
		free(node);
	}
}

/* Tar bort en nod från trädet */
int DeleteItem(BinTree *tree, void *data, void *extra)
{
	TreeNode *current=tree->root;
	TreeNode *parent=tree->root;
	TreeNode *successor=NULL;
	int isLeftChild=1;

	while(tree->cmp(current->data,data,extra))
	{
		parent=current;
		if(tree->cmp(current->data,data,extra)<0)
		{
			isLeftChild=1;
			current=current->left;
		}
		else
		{
			isLeftChild=0;
			current=current->right;
		}
		if(current==NULL)
		{
			return(0);
		}
	}
	if((current->left==NULL)&&(current->right==NULL))
	{
		if(current==tree->root)
			tree->root=NULL;
		else if(isLeftChild)
			parent->left=NULL;
		else
			parent->right=NULL;
		free(current);
	}
	else if(current->right==NULL)
	{
		if(current==tree->root)
			tree->root=NULL;
		else if(isLeftChild)
			parent->left=current->left;
		else
			parent->right=current->left;
		free(current);
	}
	else if(current->left==NULL)
	{
		if(current==tree->root)
			tree->root=NULL;
		else if(isLeftChild)
			parent->left=current->right;
		else
			parent->right=current->right;
		free(current);
	}
	else
	{
		successor=GetSuccessor(current);
		if(current==tree->root)
			tree->root=successor;
		else if(isLeftChild)
			parent->left=successor;
		else
			parent->right=successor;
		successor->left=current->left;
		free(current);
	}
	return(1);
}

/* Hittar och retunerar den vänstraste noden */
TreeNode* GetSuccessor(TreeNode *node)
{
	TreeNode *successorParent=node;
	TreeNode *successor=node;
	TreeNode *current=node->right;

	while(current)
	{
		successorParent=successor;
		successor=current;
		
		current=current->left;
	}
	
	if(successor!=node->right)
	{
		successorParent->left=successor->right;
		successor->right=node->right;
	}
	return(successor);
}

/* Publik sökfunktion som hittar det som användaren söker efter */
void* FindItem(BinTree *tree, void *data, void *extra)
{
	return(find(tree->cmp,tree->root,data,extra));
}

/* Sökfunktionen som hittar datan genom att anroppa den användande applikationens */
/* compare funktion */
void* find(CmpFunc cmp,TreeNode *node, void *data, void *extra)
{
	if(node==NULL)
		return(NULL);
	else if(cmp(node->data,data,extra)==0)
		return(node->data);
	else if(cmp(node->data,data,extra)<0)
		return(find(cmp,node->left,data,extra));
	else
		return(find(cmp,node->right,data,extra));
}

/* Loppar igenom hela trädet i sorterings ordning och anroppar ForAll funktionen*/
/* för varje nod */
void DoForAll(BinTree *tree, ForAllFunc all, void *extra)
{
	doforall(tree->root,all,extra);
}

/* Loppar igenom hela trädet i post order, dvs den anroppar först funktionen med noden
/* och går sedan igenom alla subträd */
void PreOrder(BinTree *tree, ForAllFunc all, void *extra)
{
	preorder(tree->root,all,extra);
}

/* Loppar igenom hela trädet i post order, dvs den går först igenom alla subträd */
/* innan den anroppar funktionen med noden */
void PostOrder(BinTree *tree, ForAllFunc all, void *extra)
{
	postorder(tree->root,all,extra);
}

/* Loppar igenom hela trädet i sorterings ordning och anroppar ForAll funktionen*/
/* för varje nod */
void doforall(TreeNode *node, ForAllFunc all, void *extra)
{
	if(node)
	{
		doforall(node->left,all,extra);
		all(node->data,extra);
		doforall(node->right,all,extra);
	}
}

/* Loppar igenom hela trädet i post order, dvs den anroppar först funktionen med noden
/* och går sedan igenom alla subträd */
void preorder(TreeNode *node, ForAllFunc all, void *extra)
{
	if(node)
	{
		all(node->data,extra);
		preorder(node->left,all,extra);
		preorder(node->right,all,extra);
	}	
}

/* Loppar igenom hela trädet i post order, dvs den går först igenom alla subträd */
/* innan den anroppar funktionen med noden */
void postorder(TreeNode *node, ForAllFunc all, void *extra)
{
	if(node)
	{
		postorder(node->left,all,extra);
		postorder(node->right,all,extra);
		all(node->data,extra);
	}
}
