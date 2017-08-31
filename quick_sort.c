#include <stdio.h>
#include <time.h> 
#define NODE_NUM 10 //����ڵ����Ŀ 

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
 * �ݹ�Ľ������ 
 * ˼��==�� 
 * ѡ��һ�����㣬�õ�һ��Ԫ����Ϊ���㣬������Ԫ��Ϊ�ֽ磬����ߵ�Ԫ��С�ڻ���ڻ��㣬 ���ұߵ�Ԫ�ش��ڻ���ڻ���Ԫ�أ�
 * ������䲻�����Ԫ�أ�
 * �ݹ�Ľ��У� 
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


//ִ�������� 
int main(void)
{
	HeapType heaptree;
	HeapType newtree;
	int i;
	
 	srand(time(0));
	heaptree.length = NODE_NUM;  		//˳��洢����ֵ 
	
	/*--------------------------------------*/
	for (i = NODE_NUM; i > 0; i--) {	//��ʼ������˳�����У������������ 
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