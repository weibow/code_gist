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

/*
 * Use the zero element as the sentinel
 * for example, direct sort sequence:
 * compare the data 
 * 1. 8 | 5 4 7 1 (The initial data)
 * 1. 5 8 | 4 7 1
 * 2. 4 5 8 | 7 1
 * 3. 4 5 7 8 | 1
 * 4. 1 4 5 7 8 |
 */
void direct_insert_sort(HeapType *SR)
{
	int i, j;	
	int temp;
	
	for (i = 2; i <= SR->length; i++) {
		SR->r[0].key = SR->r[i].key;
		temp = i;
		for (j = i - 1; j > 0; j--) {
			if (SR->r[j].key < SR->r[0].key) 
				break;
			SR->r[j + 1].key = SR->r[j].key;
			temp = j;
		}		
		SR->r[temp].key = SR->r[0].key;	
	}
}

/*
 * Diminish the comparing data and moving data times
 * 由小到大排序 
 */
void binary_insert_sort(HeapType *SR)
{
	int i, j;
	int mid;
	int low, high;	
	
	for (i = 2; i <= SR->length; i++) {
		low = 1;
		high = i - 1;
		SR->r[0].key = SR->r[i].key;
		while (low <= high) {
			mid = (low + high) / 2;
			if (SR->r[mid].key <= SR->r[0].key) {
				low = mid + 1;				
			} else {
				high = mid - 1;
			}
		}
		
		for (j = i - 1; j >= high + 1; j--) {
			SR->r[j + 1].key = SR->r[j].key;
		}
		
		SR->r[high + 1].key = SR->r[0].key;
	}		
}

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
	//direct_insert_sort(&heaptree);
	binary_insert_sort(&heaptree);
       //	quick_sort(&heaptree, 1, heaptree.length);
	printf("The second Heap sort after:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}	
	
	return 0;
}

/*
 * 摘自于 《数据结构》严蔚敏 版 
 */