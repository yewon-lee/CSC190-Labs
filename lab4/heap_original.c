#include <stdio.h>
#include <stdlib.h>
/*#include"heapmain.c"*/

typedef struct{
	int *store;
	unsigned int size;
	unsigned int end;
} HeapType;

struct llnode{
	int val;
	struct llnode *next;
};typedef struct llnode llnode;

int power(int *x, int n);
int initHeap(HeapType *pHeap, int size);
int indexH(int n, int k);
int ll_add_to_tail(llnode **head, int val);
int inorderH(HeapType *pHeap, llnode **root, int *n, int *k);
int countH(llnode *root, int *cnt);
int ll_to_arrayH(llnode *root,int *array);
int inorder(HeapType *pHeap,int **output, int*o_size);
int postorder(HeapType *pHeap, int **output, int *o_size);

int power(int *x, int n){
	int i = 0;
	int answer = 0;
	for (i=0;i<n-1;i++){
		*x = (*x)*(*x);
	}answer = *x;
	return answer;
}


int initHeap(HeapType *pHeap, int size){
	if (pHeap == NULL){
		return -1;
	}if (size != sizeof(pHeap->store)){
		return -1;
	}else{
		pHeap -> end = 0;
		pHeap -> size = size;
		pHeap -> store = malloc(sizeof(int)*size);
		return 0;
	}
}

int indexH(int n, int k){
	int accum = 0;
	int i = 0;
	int two = 2;
	for (i=0;i<n+1;i++){
		accum = accum + power(&two,i);
	}accum = accum - k;
	return accum;
}

int ll_add_to_tail(llnode **head, int val){
	if (head == NULL){
		return -1;
	}else if (*head == NULL){
		*head = (llnode * )malloc(sizeof(llnode));
		(*head)->val = val;
		(*head)->next = NULL;
		return 0;
	}else{
		return ll_add_to_tail(&((*head)->next),val);
	}
}



int inorderH(HeapType *pHeap, llnode **root, int *n, int *k){ /* n = 0, k = 1*/
	if (indexH(*n,*k) < pHeap->end + 1){
		int two = 2;
		*n = *n + 1;
		*k = 2*(*k);
		inorderH(pHeap,root,n,k);
		ll_add_to_tail(root,(pHeap->store)[indexH(*n,*k)]);
		*n = *n+1;
		*k = 2*(*k)-1;
		inorderH(pHeap,root,n,k);
	}return 0;
}
		
int countH(llnode *root, int *cnt){
	if (root != NULL){
		*cnt = *cnt + 1;
		return countH(root->next,cnt);
	}else{
		return *cnt;
	}
}


int ll_to_arrayH(llnode *root, int *array){
	int j = 0;
	int i = 0;
	int size = 0;
	array = (int *)malloc(sizeof(int)*(countH(root,&size)));
	
	for (i = 0; i<countH(root,&j); i++){
		array[i]=root->val;
		root = root -> next;
	}
	return 0;	
}

int inorder(HeapType *pHeap, int **output, int *o_size){
	if (pHeap == NULL){return -1;}
	else{
		llnode *root = NULL;
		int *cnt = malloc(sizeof(int));
		int n = 0;
		int k = 1;
		*cnt = 0;
		
		inorderH(pHeap,&root,&n,&k);
		countH(root, cnt);
		*o_size = *cnt;
		*output = malloc(sizeof(int)*(*cnt));
		ll_to_arrayH(root,*output);

		return 0;
	}
}			
			
					
	


#include"heapmain.c"
















	
