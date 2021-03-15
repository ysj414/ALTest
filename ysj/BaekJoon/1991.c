#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char BTData;
typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
} BTreeNode;

BTreeNode *MakeBTreeNode(void);
BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);
BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);
void DeleteTree(BTreeNode *bt);
typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void ShowData(BTData data);
BTreeNode* GetParent(BTreeNode *nd, BTData data);


int main(void)
{
	int length,i;
	char a,b,c;
	BTreeNode* rt;
	BTreeNode* node;
	BTreeNode* left;
	BTreeNode* right;

	scanf("%d",&length);
	getchar();
	scanf("%c %c %c",&a,&b,&c);
	getchar();
	rt = MakeBTreeNode();
	SetData(rt,a);
	if(b != '.')
	{
		left = MakeBTreeNode();
		SetData(left,b);
		MakeLeftSubTree(rt,left);
	}
	if(c != '.')
	{
		right = MakeBTreeNode();
		SetData(right,c);
		MakeRightSubTree(rt,right);
	}
	for(i=0; i<length-1; i++)
	{
		scanf("%c %c %c",&a,&b,&c);
		getchar();
//		printf("%c %c %c\n", a,b,c);
		node = GetParent(rt,a);
//		printf("%c\n",GetData(node));
		if(b != '.')
    	{
        	left = MakeBTreeNode();
        	SetData(left,b);
        	MakeLeftSubTree(node,left);
    	}
    	if(c != '.')
    	{	
        	right = MakeBTreeNode();
        	SetData(right,c);
        	MakeRightSubTree(node,right);
    	}	
	}

	PreorderTraverse(rt,ShowData);
	printf("\n");
	InorderTraverse(rt,ShowData);
	printf("\n");
	PostorderTraverse(rt,ShowData);
	printf("\n");

	DeleteTree(rt);

	return 0;
}

BTreeNode *MakeBTreeNode(void)
{
	BTreeNode *nd;
	nd = (BTreeNode *)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;

	return nd;
}

BTData GetData(BTreeNode *bt)
{
	return (bt->data);
}
void SetData(BTreeNode *bt, BTData data)
{
	bt->data=data;
}
BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
	return (bt->left);
}

BTreeNode *GetRightSubTree(BTreeNode *bt)
{
	return (bt->right);
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
	if(main->left != NULL)
		DeleteTree(main->left);

	main->left=sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
	if(main->right != NULL)
		DeleteTree(main->right);

	main->right=sub;
}

void DeleteTree(BTreeNode *bt)
{
	if(bt->left)
		DeleteTree(bt->left);
	if(bt->right)
		DeleteTree(bt->right);
	free(bt);
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void ShowData(BTData data)
{
	printf("%c", data);
}


BTreeNode *GetParent(BTreeNode* bt, BTData data)
{
    if(bt != NULL)
    {
        if(bt->data == data)
            return bt;
        else
        {
            BTreeNode *btt = GetParent(bt->left, data);
            if(btt != NULL)
                return btt;
            return GetParent(bt->right, data);
        }
    }
    return NULL;
}
/*
BTreeNode *GetParent(BTreeNode* nd, BTData data)
{
	BTreeNode *temp = nd;
	if(temp == NULL)
		return NULL;

	if(temp->data == data)
		return temp;

	temp = GetParent(temp->left, data);
	if(temp != NULL)
		return temp;
	else
		temp = nd;

	temp = GetParent(temp->right, data);
	if(temp != NULL)
		return temp;
}
*/


