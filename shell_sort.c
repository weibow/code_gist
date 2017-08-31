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
	
typedef SqList HeapType; //??2éó??3Dò′?′￠±íê?

/**
 *  shell sort 
 *  combine the direct insert sort
 */ 
void shell_insert(HeapType* H, int step) //从s节点开始，m节点结束的堆排序 
{
	struct record rc;
	int i, j;	
	int tmp; 		
	
	for (i = 1 + step; i <= H->length; i++) {		
		H->r[0].key = H->r[i].key;
		tmp = i;
		 for (j = i - step; j > 0; j -= step) {
		 	if (H->r[j].key < H->r[0].key) {
		 	  	break;
		 	} 
		 	H->r[j + step].key = H->r[j].key;
		 	tmp = j;
		 }	 
		 H->r[tmp].key = H->r[0].key;
	}
}


void shell_sort(HeapType *H)
{
	int length;
    
	
	for (length = H->length	; length >= 1; length /= 3) {
		shell_insert(H, length);
	};
		
}


//执行主函数 
int main(void)
{
	HeapType heaptree;
	int i;
 	srand(time(0));
	heaptree.length = NODE_NUM;  		//顺序存储长度值 
	for (i = NODE_NUM; i > 0; i--) {	//初始化输入顺序序列，随机函数生成 
		heaptree.r[i].key = rand()%100+1;;
	}
	printf("Heap sort before:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}
	
	shell_sort(&heaptree); //堆排序 
	 
	printf("Heap sort after:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}	
	
	return 0;
}