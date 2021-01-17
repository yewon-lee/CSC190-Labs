#include<stdio.h>
#include<stdlib.h>

int lt(int x, int y);
int gt(int x, int y);
int hs(int *x, int size, int (*compare)(int x,int y));

typedef struct{
	int *store;
	unsigned int size;
	unsigned int end;
	int (*compare)(int x, int y);
}intHeap_T;

int store(intHeap_T* heap, int value);
int retrieve(intHeap_T* heap, int *rvalue);
int heapify(int *array,int size, int to, int(*compare)(int x, int y));
int hs(int *x, int size, int (*compare)(int x,int y));

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
			}if((heap->compare)((heap->store)[temp],(heap->store)[temp-1])==0){ /* greater equals -1*/
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
				if (2*(curr+1)-1 >= heap->end-1 && 2*(curr+1) >= heap->end-1){
					break;	
				}else if (2*(curr+1)-1 <= heap->end && 2*(curr+1) >= heap->end){ 
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
		printf("break\n");
		}return 0;
	}
}

int heapify(int *array, int size, int to, int(*compare)(int x, int y)){ /* to not inclusive */
	intHeap_T *heap = malloc(sizeof(heap));
	int curr = 0;
	int i=0;
	int j=0;
		
	heap->store = (int *)malloc(sizeof(int)*size);
	heap->size = size;
	heap->compare = (*compare);
	for(j=0;j<size;j++){
		(heap->store)[j]=array[j];
	}
	if (to > 1){
                        while(1){
				if (2*(curr+1)-1 >= to && 2*(curr+1) >= to){
					printf("a\n");
                                        break;
                                }else if (2*(curr+1)-1 < to && 2*(curr+1) >= to){
                                        printf("b\n");
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
                                        printf("c\n");
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
                                 }else if ((heap->compare)((heap->store)[curr],(heap->store)[2*(curr+1)])==-1 && (heap->compare)((heap->store)[curr] , (heap->store)[2*(curr+1)-1])==-1){
                                        break;
                                }
			}
	} 
	for(i=0;i<to;i++){
		array[i] = (heap->store)[i];
	}
/*	i=0;
	printf("the array is now\n");
	for(i=0;i<size;i++){
                printf("%d\n",array[i]);
        }
*/
	return 0;
}

int heapify1(int *array, int size,int to, int(*compare)(int x, int y)){
	
	int i=0;
	int j=0;
	intHeap_T *heap = malloc(sizeof(heap));
	heap->store = (int *)malloc(sizeof(int)*size);
	heap->size = size;
	heap->compare = (*compare);
	for(i=0;i<to;i++){
		store(heap,array[i]);
	}
	for(j=0;j<to;j++){
		array[j]=heap->store[j];
	}
	return 0;
}

int hs(int *x,int size, int (*compare)(int x,int y)){	
	int i=0;
	int j=0;
	int k=0;
	heapify1(x,size,size,(*compare));
	
	for(i=1;i<size;i++){
		/*printf("the heap is now\n");
		for (j=0;j<size;j++){
			printf("%d\n",x[i]);
		}*/
		int to = size-i;
		int temp = x[size-i];
		x[size-i] = x[0];
		x[0] = temp;
		heapify1(x,size,to,(*compare));
	}return 0;
}	




	
