#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *store;
	unsigned int size;
	unsigned int end;
}HeapType;


int main(void){
	int i = 0;
	int j = 0;
	int sze = 10;
	int key = 188;
	int *KEY = malloc(sizeof(int));
	int rval = 100;
	
	
	HeapType *pHeap = malloc(sizeof(HeapType));
	initHeap(pHeap,sze);
	addHeap(pHeap,2);
	addHeap(pHeap,1);
	addHeap(pHeap,3);
	addHeap(pHeap,4);
	addHeap(pHeap,100);
	addHeap(pHeap,93);
	addHeap(pHeap,88);
	printf("INFO: before deletion the array looked like\n");
	for (i=0;i<(pHeap->end);i++){
		printf("%d\n",(pHeap->store)[i]);
	}
	printf("INFO: delHeap is called\n");
	delHeap(pHeap,KEY);
	printf("the delted val is %d\n and the array now looks like\n",*KEY);
	for (j=0;j<(pHeap->end);j++){
		printf("%d\n",(pHeap->store)[j]);
	}
	delHeap(pHeap,KEY);	




/*	for(i=0;i<(pHeap->end);i++){
		printf("%d\n",(pHeap->store)[i]);
*/	



/*

	int array[7];
	int i = 0;
	int *output = NULL;
	int o_size = 0;
	int key = 3;	
	int rval = 100;

	HeapType *pHeap = NULL;
	
	pHeap = malloc(sizeof(HeapType));
	
	for (i=0;i<7;i++){
		array[i]=i;
	}
	pHeap -> store = array;
	pHeap -> end = 7;
	
	inorder(pHeap, &output, &o_size);
	printf("INFO: printing heap in X order\n");
	for (i=0;i<o_size;i++){
		printf("%d\n",output[i]);
	}
	printf("INFO: printing o_size\n");
	printf("%d\n",o_size);
*/		
	return 0;
}	
	
