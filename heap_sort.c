/**
 * ????D����????������?? O(nlogn)(��?2?a�̡���???��y��?
 * ��??��?��?? O(nlogn) 
 * ?��?����?��� o(n)
 */

/**
 * ��?D???��??����??a 1)Ki <= K2i;
		  2)Ki <= K(2i+1);
   ��?�䨮??��??����??a 1)Ki >= k2i;
		  2)Ki >= k(2i+1);
 * ������????t2?���¦�?��??��?a0��??����?������y?an0��?
    ?��?a1��??����?������y?an1��?
    ?��?a2��??����?������y?an2��?
    ������??����?��y?an��?
    ?��?����?��?3?��???��???1?��?��o
    1��? n = n0 + n1 + n2;
    2)  ��y��?o�����?����?������y?a��on1 + 2n2, ???��?����D?����??D??��D?��?����?2?��?��?o??����?��?o�����
    ������? n = n1 + 2n2 + 1;(1?a?��?����?��y��?
    �䨮???����?��?��? n0 = n2 + 1��?
    ??????������???������??t2?����?��?a1��??����?������yn1?a1?��??0��?
    ������??����?��?��?n0 = n - n1 - n2 = n - n1 - n0 + 1 <=> 2n0 = n- n1 + 1 => n0 = [n - n1 + 1] / 2;
    n0 -> n/2, (n1 = 1, n?a??��y?? ��?��?�䨮?����?��y?a2^k - 1;     
    n0 -> (n+1)/2; (n = 0, n?a??��y??
    ?��?��?a1?��? n0 = (n+1)/2 ;\\
    ������??��???����?��?3?????D�����¦�?��??????����?��y?? (n - 1)/2;
 *  ???����???��y������?���?��3����?��???������??t2?���¡�? 
 */
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
	
typedef SqList HeapType; //??2����??3D����?��������?

/**
 * HeapAdjust ��������� 
 */ 
void HeapAdjust(HeapType* H, int s, int m) //��s�ڵ㿪ʼ��m�ڵ�����Ķ����� 
{
	struct record rc;
	int j ;	
	int tmp_key; 
	
	rc.key = H->r[s].key;//��¼s�ڵ�Ĺؼ�ֵ 	
	/*Construct the ��С������ �����õ��˷������뱣֤j������0*/ 
	for (j = 2 * s; j <= m; j *= 2) { 	//����s�������ӽڵ�(2*s, 2*s+1) 	 
		#ifdef MINIMUM_HEAP
		if (j < m && (H->r[j].key < H->r[j + 1].key))	//�Ƚ������ӽڵ�Ĵ�С����ȡ���������Ľڵ� 
			++j;	
		if (H->r[j].key < rc.key) //�ؼ��ڵ���������ӽڵ㣬����Ҫ������Ƚ�ֱ���˳� {
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
 * Heap sort ����
 */ 
void HeapSort(HeapType *H) 
{
	int i;
	int tmp_key;
	
	for (i = (H->length) / 2; i > 0; --i)  //��ջ �����������ʼ���������� build the heap sort
		HeapAdjust(H, i, H->length);	
	for (i = H->length; i > 0; --i) {	//H->r[1].key �洢�ؼ��ڵ� 
		tmp_key = H->r[i].key;
		H->r[i].key = H->r[1].key; 	//���Ѷ���¼�͵�ǰδ�������������H��r��1..r���� 
		H->r[1].key = tmp_key;
		HeapAdjust(H, 1, i - 1); 
	}	
}


//ִ�������� 
int main(void)
{
	HeapType heaptree;
	int i;
 	srand(time(0));
	heaptree.length = NODE_NUM;  		//˳��洢����ֵ 
	for (i = NODE_NUM; i > 0; i--) {	//��ʼ������˳�����У������������ 
		heaptree.r[i].key = rand()%100+1;;
	}
	printf("Heap sort before:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}
	
	HeapSort(&heaptree); //������ 
	 
	printf("Heap sort after:\r\n");
	for (i = 1; i <= NODE_NUM; i++) {
		printf("Heap record[%02d]=%d\r\n", i, heaptree.r[i].key);
	}	
	
	return 0;
}