#include <stdio.h>
#include <stdlib.h>


struct bstNode{
	int val;
	struct bstNode *l;
	struct bstNode *r;
};
typedef struct bstNode bstNode;

struct avlNode{
	int balance;
	int val;
	struct avlNode *l;
	struct avlNode *r;
};
typedef struct avlNode avlNode;

struct qNode{
	bstNode *pval;
	struct qNode *next;
};
typedef struct qNode qNode;

int add_bst(bstNode **root, int val);
int printTreeInOrder(bstNode *root);
int isqNodeEmpty(qNode *root);
int enqueue(qNode *qroot, bstNode *root);
int dequeue(qNode *qroot, bstNode **store);
int printLevelOrder(bstNode *root);

int add_bst(bstNode **root, int val){
	if (root == NULL){return -1;}
	if (*root == NULL){
		(*root)=(bstNode *)malloc(sizeof(bstNode));
		(*root)->val = val;
		(*root)->l = NULL;
		(*root)->r = NULL;
		return 0;
	}else{
		if ((*root)->val >val){
			return add_bst(&((*root)->l),val); 
		}else{
			return add_bst(&((*root)->r),val);
		}
	}
}


int printTreeInOrder(bstNode *root){
	if (root !=NULL){
		printTreeInOrder(root->l);
		printf("%d\n",root->val);
		printTreeInOrder(root->r);
	}
	return 0;
}

int isqNodeEmpty(qNode *root){
	if (root == NULL){
		return 0;
	}else{
		return -1;
	}
}

int enqueue(qNode *qroot, bstNode *root){
	if (root == NULL){
		qroot = qroot;
	}else if (qroot == NULL){
		qroot = (qNode *)malloc(sizeof(qNode));
		(qroot)->pval = root;
		(qroot)->next = NULL;
		return 0;
	}else{
		return enqueue(qroot->next,root);
	}
}

int dequeue(qNode *qroot, bstNode **store){
	if (qroot == NULL){
		return -1;
	}else{	
		qNode *oldhead = qroot;
		*store = oldhead->pval;
		qroot = qroot -> next;
		free(oldhead);
		return 0;
	}
}


int printLevelOrder(bstNode *root){
	qNode *q = NULL;
	bstNode *d = NULL;
	printf("here 1\n");
	q = (qNode *)malloc(sizeof(qNode));
	d = (bstNode *)malloc(sizeof(bstNode));
	enqueue(q,root);
	printf("here 2\n");
	while ((isqNodeEmpty(q)) == -1){
		dequeue(q,&d);
		printf("here 3\n");
		if (d != NULL){
			printf("not even here\n");
			printf("%d ",d->val);
			enqueue(q,d->l);
			enqueue(q,d->r);
			printf("woohoo\n");
		}
	}
	printf("\n");
/*	free(q);*/
	return 0;
}


int main(void){	
	int n = 0;
	int value = 0;
	int rvalue = 0;
	bstNode *input_list=NULL;

	while (scanf("%d",&value) != EOF){
		n = n + 1;
		add_bst(&input_list, value);
	}
	/*printf("INFO: you entered %d items\n",n);*/
	rvalue = printTreeInOrder(input_list);
	/*printLevelOrder(input_list);*/
	/*if (!(rvalue==0)) {printf("ERR: printTreeInOrder returned an error\n");}*/
	
	return 0;
}











