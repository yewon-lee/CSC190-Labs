#include<stdio.h>
#include<stdlib.h>


int lt(int x, int y);
int gt(int x, int y);
typedef struct{
	int *store;
	unsigned int size;
	unsigned int end;
	int (*compare)(int x, int y);
}intHeap_T;


int main(void){
	int i = 0;
	int array[6];
	array[0] = 8;
	array[1]=100;
	array[2]=99;
	array[3]=3;
	array[4]=2;
	array[5]=9;
	hs(array,6,lt);
	for(i=0;i<6;i++){
		printf("%d\n",array[i]);
	}
	

/*	int *rval=(int *)malloc(sizeof(int));
	int i = 0;
	int size = 6;
	intHeap_T heap;
	heap.end = 0;
	heap.compare = lt;
	heap.store = (int *)malloc(sizeof(int)*size);
	
	store(&heap,10);
	store(&heap,9);
	store(&heap,5);
	store(&heap,100);
	store(&heap,8);
	store(&heap,0);
	printf("heaps end is %d\n",heap.end);
		
	for(i=0;i<heap.end;i++){
		printf("%d\n",(heap.store)[i]);
	}
	printf("deleted a value, now heap is \n");
	retrieve(&heap,rval);
	for(i=0;i<heap.end;i++){
		printf("%d\n",heap.store[i]);
	}	
	
	printf("deleted a value, now heap is \n");
        retrieve(&heap,rval);
        for(i=0;i<heap.end;i++){
                printf("%d\n",heap.store[i]);
        }

*/
		

	return 0;
}	
