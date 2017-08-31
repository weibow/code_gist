#include <stdio.h>
#include <time.h> 
#define NODE_NUM 10 //定义节点的数目 

struct record {
	int key;
};
typedef struct {	
	struct record r[NODE_NUM+1];
	int length;
} SqList;
	
typedef SqList HeapType; 

/**
 *  Merge sort main process functions
 * 将有序序列SR[i..m] and SR[m+1, n] merge into TR[i..n]
 */
void Merge(HeapType *SR, HeapType *TR, int i, int m, int n)
{
	int k, j;
	
	for (j = m + 1, k = i; i <= m && j <= n; ++k) {
		if (SR->r[i].key < SR->r[j].key) {
			TR->r[k].key = SR->r[i++].key;
		} else {
			TR->r[k].key = SR->r[j++].key;
		}			
	}
	
	while (i <= m) 
		TR->r[k++].key = SR->r[i++].key;
	while (j <= n)
		TR->r[k++].key = SR->r[j++].key;		
}

/**
 * 将SR[s..t]归并排序为TR[s..t];采用自顶向上的方法 1 递归化的执行方法 
 */
void MSort(HeapType *SR, HeapType *TR, int s, int t)
{
	int j, m;
	
	 if (s == t) 
	 	TR->r[s].key = SR->r[s].key;
 	 else {
 	 	m = (s + t) / 2;
 	 	MSort(SR, TR, s, m);
 	 	MSort(SR, TR, m+1, t);
 	 	Merge(SR, TR, s, m, t);
 	 }
 	 
 	 for (j = s; j <= t; j++) {		//将数据拷贝回原来的数组 
 		SR->r[j].key = TR->r[j].key;
 	 }	
}
/**
 * 归并排序采用 自底向上的方法 由1 2 4 16 倍增方式排序 
 */
void MergePass(HeapType *SR, HeapType *TR, int length)
{
	int i, j;
	
	for (i = 1; i + (2 * length - 1) <= SR->length; i = i + 2 * length)
		Merge(SR, TR, i, i + length - 1, i + 2 * length -1);
		
	if (i + length -1 < SR->length) {
		Merge(SR, TR, i, i + length - 1, SR->length);
	}
	
 	for (j = 1; j <= SR->length; j++) {		//将数据拷贝回原来的数组 
 		SR->r[j].key = TR->r[j].key;
 	}	
}

void MergeSort(HeapType *SR, HeapType *TR)
{
	int length;
	
	for (length = 1; length < SR->length; length *= 2) {
		MergePass(SR, TR, length);
	}		
}


//merging sort 
//归并排序 
//两两合并 
//执行主函数 
int main(void)
{
	HeapType heaptree;
	HeapType newtree;
	int i;
	
 	srand(time(0));
	heaptree.length = NODE_NUM;  		//顺序存储长度值 
	
	/*--------------------------------------*/
	for (i = NODE_NUM; i > 0; i--) {	//初始化输入顺序序列，随机函数生成 
		heaptree.r[i].key = rand()%100+1;;
	}
	printf("The first Method: Heap sort before:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}
	MergeSort(&heaptree, &newtree);
	printf("The second Heap sort after:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}	
	
	/*--------------------------------------*/
	for (i = NODE_NUM; i > 0; i--) {	//初始化输入顺序序列，随机函数生成 
		heaptree.r[i].key = rand()%100+1;;
	}
	printf("The Second Methodes: Heap sort before:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}
	MSort(&heaptree, &newtree, 1, NODE_NUM);
	printf("Heap sort after:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}	
	return 0;
}