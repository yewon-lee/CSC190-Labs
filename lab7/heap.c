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

int store(intHeap_T* heap, int value);
int retrieve(intHeap_T* heap, int *rvalue);


int lt(int x, int y){
	if(x<=y){return 0;}
	else{return -1;}
}
int gt(int x, int y){
	if(x>=y){return 0;}
	else{return -1;}
}

int store(intHeap_T *heap, int value){
	if(heap == NULL){
		return -1;
	}else{
		int temp = (heap->end);
		(heap->store)[heap->end] = value;
		(heap->end)=(heap->end)+1;
		while(1){
			
			if(temp==0 || temp==-1){
				break;
			}if((heap->compare)((heap->store)[temp],(heap->store)[temp-1])==-1){ /* greater equals -1*/
				int important = (heap->store)[temp];
				(heap->store)[temp]=(heap->store)[temp-1];
				(heap->store)[temp-1]=important;
				temp = temp -1;
			}else{
				break;
			}
		}
		return 0;
	}
}

int retrieve(intHeap_T *heap, int *rvalue){
	if(heap->end==0){
		return -1;
	}if(rvalue==NULL){
		return -1;
	}else{
		int curr=0;
		*rvalue=(heap->store)[0];
		heap->end = heap->end-1;
		if (heap->end > 1){
			(heap->store)[0] = (heap->store)[heap->end];
			while(1){
				if (2*(curr+1)-1 > heap->end-1 && 2*(curr+1) > heap->end-1){
					break;	
				}else if (2*(curr+1)-1 < heap->end && 2*(curr+1) >= heap->end){ 
					if ((heap->compare)(heap->store[curr],heap->store[2*(curr+1)-1])==0){
						int temp = (heap->store)[curr];
                                                (heap->store)[curr] = (heap->store)[2*(curr+1)-1];
                                                (heap->store)[2*(curr+1)-1] = temp;
                                                curr = 2*(curr+1)-1;
						break;
					}else{
						break;
					}
				}else if ((heap->compare)((heap->store)[curr],(heap->store)[2*(curr+1)-1])==0 || (heap->compare)((heap->store)[curr],(heap->store)[2*(curr+1)])==0){
					if((heap->compare)((heap->store)[2*(curr+1)-1],(heap->store)[2*(curr+1)])==0){
						int temp = (heap->store)[curr];
						(heap->store)[curr] = (heap->store)[2*(curr+1)];
						(heap->store)[2*(curr+1)] = temp;
						curr = 2*(curr+1);	
					}else{
						int temp = (heap->store)[curr];
						(heap->store)[curr] = (heap->store)[2*(curr+1)-1];
						(heap->store)[2*(curr+1)-1] = temp;
						curr = 2*(curr+1)-1;
					}
	/*			}else if (curr = heap->end - 1){
					break;*/
				}else if ((heap->compare)((heap->store)[curr] , (heap->store)[2*(curr+1)])==-1 && (heap->compare)((heap->store)[curr] , (heap->store)[2*(curr+1)-1])==-1){
					break;
				}
			}
		}return 0;
	}
}

/*					

int retrieve(intHeap_T *heap, int *rvalue){
	if(heap->end == 0){
		return -1;
	}else{
		*rvalue = (heap->store)[0];
		heap->end = heap->end - 1;
		if(heap->end > 1){
			int node = 0;
			(heap->store)[0] = (heap->store)[end];
			node = heap->store[0];
			


*/












		
