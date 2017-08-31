#include <stdio.h>

#define n 100
#define m 2*n-1

typedef struct {
	float weight;
	int lchild, rchild, parent;
} HTNode;

typedef HTNode HuffmanTree[m];

void CreateHuffmanTree(HuffmanTree T)
{
	//Construct the huffman tree
	int i, p1, p2;
	InitHuffmanTree(T);
	InputWeight(T);
	for (i = n; i < m; i++) {
		SelectMin(T, i - 1, &p1, &p2);
		T[p1].parent = T[p2].parent = i;
		T[i].lchild = p1;
		T[i].rchild = p2;
		T[i].weight = T[p1].weight + T[p2].weight;
	}
}

typedef struct {
	char ch;
	char bits[n + 1];
} CodeNode;

typedef CodeNode HuffmanCode[n];

void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H)
{
}
