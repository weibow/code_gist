#include <stdio.h>

typedef char DataType;
typedef struct node {
	DataType data;
	struct node *lchild, *rchild;
} BinTNode;
typedef BinTNode *BinTree;

void CreateBinTree(BinTree *T)
{
	char ch;
	
	if ((ch == getchar()) == ' ')
		*T = NULL;
	else {
		*T = (BinTNode *) malloc(sizeof(BinTNode));
		(*T)->data = ch;
		CreateBinTree(&(*T)->lchild);
		CreateBinTree(&(*T)->rchild);
	}
}

typedef enum {Link, Thread} PointerTag;
typedef struct Thrnode {
	DataType data;
	PointerTag ltag, rtag;
	struct Thrnode * lchild, *rchild;
} BinThrNode;
typedef BinThrNode *BinThrTree;
BinThrNode *pre = NULL;

void InorderThreading(BinThrTree p)
{
	if (p) {
		InorderThreading(p->lchild);
		p->ltag = (p->lchild) ? Link : Thread;
		p->rtag = (p->rchild) ? Link : Thread;
		if (pre) {
			if (pre->rtag == Thread) 
				pre->rchild = p;
			if (p->ltag == Thread)
				p->rchild = pre;
		}
		pre = p;
		InorderThreading(p->rchild);
	}
}

BinThrNode* InorderSuccessor(BinThrNode *p)
{
	BinThrNode *q;

	if (p->rtag == Thread)
		return p->rchild;
	else {
		q = p->rchild;
		while (q->ltag == Link)
			q = q->lchild;
		return q;
	}
}


void TraverseInorderThrTree(BinThrTree p)
{
	if (p) {
		while (p->ltag == Link)
			p = p->lchild;
		do {
			printf("%c", p->data);
			p =  InorderSuccessor(p);
		} while (p);
	}
}

//

#define MaxTreeSize 100

typedef struct cnode {
	int child;
	struct cnode * next;
} CNode;

typedef struct {
	DataType data;
	CNode *firstchild;
} PTNode;

typedef struct {
	PTNode nodes[MaxTreeSize];
	int n, root;
} CTree;
CTree T;

int main(void)
{
	return 0;
}

