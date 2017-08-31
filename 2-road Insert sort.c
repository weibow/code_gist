/*
*    2-road Insert sort algorithm
*    Post at 2012.10.8
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 20
typedef int KeyType;
typedef struct {
    KeyType key;
}RedType;
typedef struct{
    RedType r[MAXSIZE+1];
    int length;
}Sqlist;


void initSqlist(Sqlist &L){
    printf("input the sort record length:");
    if(!scanf("%d",&L.length) && L.length <= MAXSIZE ){
        printf("input error!\n");
        exit(-1);
    }
    int i;
    for(i=1; i<= L.length; ++i){
        //printf("input the record:");
        scanf("%d",&L.r[i].key);
    }
} 

bool LT(KeyType r1, KeyType r2){
    if(r1<r2){
        return true;
    }else{
        return false;
    }
}

bool LE(KeyType r1, KeyType r2){
    if(r1<=r2){
        return true;
    }else{
        return false;
    }
}

/* 2 Path Insert Sort */ 
void twoPathInsertSort(Sqlist &L){
    if(!L.length)
        return;
    KeyType d[MAXSIZE]={0};
    // 设置第一个记录和最后一个记录的指针 
    int first=0;
    int final=0;
    // 设置d[0]为哨兵元素 
    d[0]=L.r[1].key;
    int i;
    for(i=2; i<= L.length; ++i){
        if(LT(L.r[i].key,d[first])){  // 不需移动元素 
            first = (first-1+L.length)%L.length;
            d[first] = L.r[i].key ;
        }else if(LT(d[final],L.r[i].key)){ // 不需要移动元素 
            final = final+1 ;
            d[final] = L.r[i].key;
        }else {    // 中间插入，需要移动元素 
            int j=final-1;
            final += 1;
            d[final] = d[final-1];
            while(LT(L.r[i].key,d[j])){
                d[j+1] = d[j];
                --j;
            }
            d[j+1] = L.r[i].key;
        }
    }
    // 将辅助数组的数据按序复制到表L 
    for(i=1; i<= L.length; ++i){
        L.r[i].key = d[first%L.length];
        ++first;
    }
}

/* 2 path quick insert sort ,has some problem not deal with*/
void twoPQInsertSort(Sqlist &L){
    int i=1;
    int j=L.length;
    L.r[0].key = L.r[i].key;
    // Quick insert sort from two path 
    while(i<j){
        while(LE(L.r[0].key,L.r[j].key) && i<j){
            // 下面是折半插入代码 
            int left=j+1;
            int right=L.length;
            while( left <= right ){
                int m = (left+right)/2 ;
                if(LT(L.r[j].key,L.r[m].key))
                    right = m - 1;
                else
                    left = m + 1;
            }
            KeyType tmp = L.r[j].key;
            int tmpj;
            for(tmpj=j; tmpj <= right-1; ++tmpj){
                L.r[tmpj].key = L.r[tmpj+1].key;
            }
            L.r[right].key = tmp;
            --j;
        }
        L.r[i].key = L.r[j].key;
        
        while(LE(L.r[i].key,L.r[0].key) && i<j){
            // 下面是折半插入代码 
            int left = 1;
            int right = i-1;
            while(left<=right){
                int m = (left+right)/2;
                if(LT(L.r[i].key,L.r[m].key))
                    right = m - 1;
                else
                    left = m + 1;
            }
            int tmpi;
            int tmp = L.r[i].key;
            for(tmpi=i-1; tmpi>= right+1; --tmpi){
                L.r[tmpi+1].key = L.r[tmpi].key;
            }
            L.r[right+1].key = tmp;
            ++i;
        }
        L.r[j].key = L.r[i].key;
        
    }
    L.r[j].key = L.r[0].key;
}

void printSqlist(Sqlist &L){
    printf("Sorted Sqlist as follow:");
    int i;
    for(i=1; i <= L.length; ++i){
        printf(" %d ",L.r[i].key);
    }
    printf("\n");
}


int main(int argc, char **argv){
    Sqlist L;
    L.length = 0;
    initSqlist(L);
    //twoPathInsertSort(L);    
    twoPQInsertSort(L);
    printSqlist(L);
    return 0;
}