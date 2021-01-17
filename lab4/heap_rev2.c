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
int inorderH(HeapType *pHeap, llnode **root, int n, int k);
int countH(llnode *root, int *cnt);
int ll_to_arrayH(llnode *root,int *array);
int inorder(HeapType *pHeap,int **output, int*o_size);
int preorderH(HeapType *pHeap, llnode **root, int n, int k);
int preorder(HeapType *pHeap, int **output, int *o_size);
int postorderH(HeapType *pHeap, llnode **root, int n, int k);
int postorder(HeapType *pHeap, int **output, int *o_size);
int addHeap(HeapType *pHeap, int key);
int findHeap(HeapType *pHeap, int key);
int delHeap(HeapType *pHeap, int *key);

int printLL(llnode *root);



int power(int *x, int n){
	int i = 0;
	int answer = 0;
	if (n == 1){
		return 1;
	}else{
		for (i=0;i<n-1;i++){
			*x = (*x)*(*x);
		}answer = *x;
		return answer;
	}
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



int inorderH(HeapType *pHeap, llnode **root, int n, int k){ /* n = 0, k = 1*/
	if (indexH(n,k) < pHeap->end){
		/*printf("%d\n",indexH(*n,*k));*/
		/*int two = 2;
		*n = *n + 1;
		*k = 2*(*k);*/
		/*printf("here ??\n");*/
		inorderH(pHeap,root,n+1,2*k);
		ll_add_to_tail(root,(pHeap->store)[indexH(n,k)]);
		/**n = *n+1
		*k = 2*(*k)-1;*/
		inorderH(pHeap,root,n+1,2*k-1);
	}
	return 0;
}

int printLL(llnode *root){
	while (root != NULL){
		printf("%d\n",root->val);
		root = root -> next;
	}
	return 0;
}	

		
int countH(llnode *root, int *cnt){
	if (root != NULL){
		*cnt = *cnt + 1;
		return countH(root->next,cnt);
	}else{
		/*printf("no way\n");*/
		return 0;
	}
}


int ll_to_arrayH(llnode *root, int *array){
	int j = 0;
	int i = 0;
	int size = 0;
	/*array = (int *)malloc(sizeof(int)*(countH(root,&size)));*/
	
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
		int i = 0;
		*cnt = 0;
		
			
		inorderH(pHeap,&root,n,k);
		countH(root, cnt);
		*o_size = *cnt;
		*output = malloc(sizeof(int)*(*cnt));
		for (i=0;i<(*cnt);i++){
			(*output)[i] = root->val;
			root = root -> next;
		}
		


		/*printf("INFO: printing the linked-lists version\n");
		printLL(root);*/
		

		return 0;
	}
}			
	
int preorderH(HeapType *pHeap, llnode **root, int n, int k){
	if (indexH(n,k) < pHeap->end){
		ll_add_to_tail(root,(pHeap->store)[indexH(n,k)]);
		preorderH(pHeap,root,n+1,2*k);
		preorderH(pHeap,root,n+1,2*k-1);		
	}return 0;
}

int preorder(HeapType *pHeap, int **output, int *o_size){
	if (pHeap == NULL){return -1;}
	else{
		llnode *root = NULL;
		int *cnt = malloc(sizeof(int));
		int n = 0;
		int k = 1;
		int i = 0;
		*cnt = 0;
		
		preorderH(pHeap,&root,n,k);
		countH(root,cnt);
		*o_size = *cnt;
		*output = malloc(sizeof(int)*(*cnt));
		for (i=0;i<(*cnt);i++){
			(*output)[i] = root -> val;
			root = root -> next;	
		}
		return 0;
	}
}  				
	
int postorderH(HeapType *pHeap, llnode **root, int n, int k){
        if (indexH(n,k) < pHeap->end){
                preorderH(pHeap,root,n+1,2*k);
                preorderH(pHeap,root,n+1,2*k-1);
                ll_add_to_tail(root,(pHeap->store)[indexH(n,k)]);

        }return 0;
}

int postorder(HeapType *pHeap, int **output, int *o_size){
        if (pHeap == NULL){return -1;}
        else{
                llnode *root = NULL;
                int *cnt = malloc(sizeof(int));
                int n = 0;
                int k = 1;
                int i = 0;
                *cnt = 0;

                postorderH(pHeap,&root,n,k);
                countH(root,cnt);
                *o_size = *cnt;
                *output = malloc(sizeof(int)*(*cnt));
                for (i=0;i<(*cnt);i++){
                        (*output)[i] = root -> val;
                        root = root -> next;
                }
                return 0;
        }
}

int addHeap(HeapType *pHeap, int key){
	if (pHeap == NULL){
		return -1;
	}else{
		int i = 0;
		int j = 0;
		int temp = pHeap->end - 1;
		(pHeap->store)[pHeap->end] = key;
		pHeap->end = pHeap->end + 1; 
		printf("%d\n",temp);
		/*while (1){
			if (2+i == pHeap->end){
				break;
			}else if ((pHeap->store)[pHeap->end -1-i] > (pHeap->store)[pHeap->end-2-i]){ 		
				int temp = (pHeap->store)[pHeap->end-1-i];
				(pHeap->store)[pHeap->end-1-i] = (pHeap->store)[pHeap->end-2-i];
				(pHeap->store)[pHeap->end-2-i] = temp;
				i = i + 1;
			}
		}*/

		while(1){
			if (temp == 0 || temp == -1 || temp == 1){
				break;
			}else if ((pHeap->store)[temp] > (pHeap->store)[temp-1]){
				printf("%d\n",temp);
				(pHeap->store)[temp] = (pHeap->store)[temp -1];
				(pHeap->store)[temp-1] = key;
				temp = temp - 1;
			 }
		}
		return 0;
	}
}

int findHeap(HeapType *pHeap, int key){
	if(pHeap == NULL){
		return -1;
	}else if (pHeap->size == pHeap->end){
		return -1;
	}else{
		int i = 0;
		for (i=0;i<pHeap->end;i++){	
			if ((pHeap->store)[i] == key){
				return 1;
			}
		}
		return 0;
	}
}
/*
int delHeap(HeapType *pHeap, int *key){
*/		

#include"heapmain.c"









	
