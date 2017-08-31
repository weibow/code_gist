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
 * Quick sort
 * 递归的解决方程 
 * 思想==》 
 * 选择一个基点，用第一个元素作为基点，将基点元素为分界，其左边的元素小于或等于基点， 其右边的元素大于或等于基点元素；
 * 调换其间不满足的元素；
 * 递归的进行； 
 */
void quick_sort(HeapType *SR, int start_point, int end_point)
{
	int i, j;
	int temp;
	
	i = start_point;
	j = end_point;
	temp = SR->r[start_point].key;
	if (j > i) {
		while(i != j) {
			while (j != i) {
				if (temp > SR->r[j].key) {
					SR->r[i++].key = SR->r[j].key;									
					break;
				}
				j--;		
			}
			
			while (i != j) {
				if (temp < SR->r[i].key) {
					SR->r[j--].key = SR->r[i].key;
					break;
				}
				i++;
			}
		}
		SR->r[i].key = temp;	 
		quick_sort(SR, start_point, i - 1);
		quick_sort(SR, i + 1, end_point);
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
	quick_sort(&heaptree, 1, heaptree.length);
	printf("The second Heap sort after:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}	
	

	return 0;
}