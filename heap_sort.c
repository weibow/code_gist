/**
 * ????Dòμ????ùê±?? O(nlogn)(ò?2?aμ×μ???êy￡?
 * ×??μ?é?? O(nlogn) 
 * ?¨?ú′?′￠ o(n)
 */

/**
 * ×?D???μ??¨ò??a 1)Ki <= K2i;
		  2)Ki <= K(2i+1);
   ×?′ó??μ??¨ò??a 1)Ki >= k2i;
		  2)Ki >= k(2i+1);
 * éèò????t2?ê÷μ?μ??è?a0μ??úμ?×üêy?an0￡?
    ?è?a1μ??úμ?×üêy?an1￡?
    ?è?a2μ??úμ?×üêy?an2￡?
    ×üμ??úμ?êy?an￡?
    ?ò?éò?μ?3?ò???á???1?ê?￡o
    1￡? n = n0 + n1 + n2;
    2)  êyμ?o￠×ó?úμ?×üêy?a￡on1 + 2n2, ???ú?ùóD?úμ??D??óD?ù?úμ?2?ê?è?o??úμ?μ?o￠×ó
    òò′? n = n1 + 2n2 + 1;(1?a?ù?úμ?êy￡?
    ′ó???éò?μ?μ? n0 = n2 + 1￡?
    ??????óúò???íêè??t2?ê÷?è?a1μ??úμ?×üêyn1?a1?ò??0￡?
    óé′??éò?μ?μ?n0 = n - n1 - n2 = n - n1 - n0 + 1 <=> 2n0 = n- n1 + 1 => n0 = [n - n1 + 1] / 2;
    n0 -> n/2, (n1 = 1, n?a??êy?? ò?×?′ó?úμ?êy?a2^k - 1;     
    n0 -> (n+1)/2; (n = 0, n?a??êy??
    ?ò?ˉ?a1?ê? n0 = (n+1)/2 ;\\
    óé′??ò???éò?μ?3?????Dòê÷μ?·??????úμ?êy?? (n - 1)/2;
 *  ???·ò???êy×é′?′￠?′3éê?ò???íêè??t2?ê÷￡? 
 */
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
 * HeapAdjust 堆排序调整 
 */ 
void HeapAdjust(HeapType* H, int s, int m) //从s节点开始，m节点结束的堆排序 
{
	struct record rc;
	int j ;	
	int tmp_key; 
	
	rc.key = H->r[s].key;//记录s节点的关键值 	
	/*Construct the 最小堆排序 这里用到乘法，必须保证j不等于0*/ 
	for (j = 2 * s; j <= m; j *= 2) { 	//查找s的两个子节点(2*s, 2*s+1) 	 
		#ifdef MINIMUM_HEAP
		if (j < m && (H->r[j].key < H->r[j + 1].key))	//比较两个子节点的大小，择取两者中最大的节点 
			++j;	
		if (H->r[j].key < rc.key) //关键节点大于两个子节点，符合要求无需比较直接退出 {
			break;
		#else 
		if (j < m && (H->r[j].key > H->r[j + 1].key))
			++j;
		if (H->r[j].key > rc.key)
			break;		
		#endif
		H->r[s].key = H->r[j].key;						//
		s = j;		 
	}	
	H->r[s].key = rc.key;	
}

/**
 * Heap sort 排序
 */ 
void HeapSort(HeapType *H) 
{
	int i;
	int tmp_key;
	
	for (i = (H->length) / 2; i > 0; --i)  //堆栈 构造堆树，初始化堆排序树 build the heap sort
		HeapAdjust(H, i, H->length);	
	for (i = H->length; i > 0; --i) {	//H->r[1].key 存储关键节点 
		tmp_key = H->r[i].key;
		H->r[i].key = H->r[1].key; 	//将堆顶记录和当前未经排序的子序列H。r【1..r】中 
		H->r[1].key = tmp_key;
		HeapAdjust(H, 1, i - 1); 
	}	
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
	
	HeapSort(&heaptree); //堆排序 
	 
	printf("Heap sort after:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}	
	
	return 0;
}