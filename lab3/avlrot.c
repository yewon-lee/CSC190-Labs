#include <stdio.h>
#include <stdlib.h>
#include "avlrot.h"
/*
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

int max(int a, int b);
int add_avl(avlNode **root, int val, int BF);
int printTreeInOrder(avlNode *root);
int printLevelOrder(bstNode *root);
int height(avlNode *node);
int isAVL(avlNode **root);
int rotate(avlNode **root, unsigned int Left0_Right1);
int calculateBF(avlNode *root);
int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1);

int printLevelOrderAVL(avlNode *root);
int printByGivenHeight(avlNode *root, int height);

int XprintLevelOrder(avlNode *root);
int Xheight_LevelOrder_HELPER(avlNode *root);
int XPrintByGivenLevel_HELPER(avlNode *root, int level);

*/

int XprintLevelOrder(avlNode *root){
	int h = Xheight_LevelOrder_HELPER(root);
	int i = 0;
	for (i=0;i<=h;i++){
		XPrintByGivenLevel_HELPER(root,i);
	}
}

int Xheight_LevelOrder_HELPER(avlNode *root){
	if (root == NULL){
		return 0;
	}else{
		int lheight = Xheight_LevelOrder_HELPER(root->l);
		int rheight = Xheight_LevelOrder_HELPER(root->r);
		
		if (lheight > rheight){
			return (lheight+1);
		}else{
			return (rheight+1);
		}
	}
}

int XPrintByGivenLevel_HELPER(avlNode *root, int level){
	if (root == NULL){
		return 0;
	}if (level == 1){
		printf("%d\n",(root->val));
	}else if (level>1){
		XPrintByGivenLevel_HELPER(root->l, level-1);
		XPrintByGivenLevel_HELPER(root->r, level-1);
	}
}



int max(int a, int b){
	if (a>b){
		return a;
	}else{
		return b;
	}
}

int add_avl(avlNode **root, int val, int BF){
	if (root == NULL){return -1;}
        if (*root == NULL){
                (*root)=(avlNode *)malloc(sizeof(avlNode));
                (*root)->val = val;
                (*root)->l = NULL;
                (*root)->r = NULL;
		(*root)->balance = BF;
                return 0;
        }else{
                if (val < (*root)->val){
                        return add_avl(&((*root)->l),val,BF);
                }else{
                        return add_avl(&((*root)->r),val,BF);
                }
        }
}


int printTreeInOrder(avlNode *root){
	if (root !=NULL){
		printTreeInOrder(root->l);
		printf("%d\n",root->val);
		printTreeInOrder(root->r);
	}
	return 0;
}

int printLevelOrderAVL(avlNode *root){
	int i = 0;
	int h = height(root);
	for (i=h;i>=0;i=i-1){
		return printByGivenHeight(root,i);
	}
}

int printByGivenHeight(avlNode *root, int height){
	if (root != NULL){
		printByGivenHeight(root->l,height);
		if (root -> balance == height){
			printf("%d\n",root->val);
		}
		printByGivenHeight(root->r,height);
	}
}

int height(avlNode *node){
	if (node == NULL){
		return 0;
	}else{
		return max(height(node->l),height(node->r))+1;
	}
}

int isAVL(avlNode **root){
	int heightr = height((*root)->r);
	int heightl = height((*root)->l);
	int BF = heightr - heightl;
	if (BF == 0 || BF == 1 || BF == -1){
		return 0;
	}else{
		return -1;
	}
}	

int calculateBF(avlNode *root){
	int r = height(root->r);
	int l = height(root->l);
	int BF = r - l;
	return BF;
}	

int setBFatNode(avlNode *root){
	root->balance = calculateBF(root);
	return 0;
}

int calculateBFeverywhere(avlNode *root){
	if (root != NULL){
		calculateBFeverywhere(root->l);
		setBFatNode(root);
		/*printf("%d\n",root->balance);*/
		calculateBFeverywhere(root->r);
	}
	return 0;
}

int printBFeverywhere(avlNode *root){
	if (root != NULL){
		printBFeverywhere(root->l);
		printf("%d\n",root->balance);
		printBFeverywhere(root->r);
	}
	return 0;
}

int rotate(avlNode **root, unsigned int Left0_Right1){
	if (root == NULL){return -1;}
	if (*root == NULL){return -1;}
	if ((*root)->r == NULL && (*root)->l == NULL){return -1;}
	if (Left0_Right1 == 0 && (*root)->r == NULL){return -1;}
	if (Left0_Right1 == 1 && (*root)->l == NULL){return -1;}
	if (Left0_Right1 == 0){
			avlNode *t1 = (*root)->r;
			avlNode *t2 = t1->l;
			avlNode *n = *root;
			*root = t1;
			t1 -> l = n;
			n -> r = t2;
			n -> balance = calculateBF(n);
			t1 -> balance = calculateBF(t1);
			calculateBFeverywhere(*root);
	
		/*	printf("INFO: printing tree in order\n");
			printTreeInOrder(*root);
			printf("INFO: printing tree in level order\n");
			XprintLevelOrder(*root);	*/
			
			return 0;
		
	}else if (Left0_Right1 == 1){	
			avlNode *t1 = (*root)->l;
			avlNode *t2 = t1 -> r;
			avlNode *n = *root;
			t1 -> r = n;
			n -> l = t2;
			n -> balance = calculateBF(n);
			t1 -> balance = calculateBF(t1);
			*root = t1;
			calculateBFeverywhere(*root);

		/*	printf("INFO: printing tree in order\n");
      		        printTreeInOrder(*root);
                	printf("INFO: printing tree in level order\n");
            	        XprintLevelOrder(*root);	*/


			return 0;
	}
}				

int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1){
	if (root == NULL){return -1;}
	if (*root == NULL){return -1;}
	if ((*root)->r == NULL && (*root)->l == NULL){return -1;}
	if (MajLMinR0_MajRMinL1 == 0){
		avlNode *subroot = (*root) -> r;
		int val_1 = 1;
		int val_2 = 0;
		rotate(&(subroot),val_1);
		(*root) -> r = subroot;
		rotate(root,val_2);
		calculateBFeverywhere(*root);
		
	/*	printf("INFO: printing tree in order\n");
                printTreeInOrder(*root);
                printf("INFO: printing tree in level order\n");
                XprintLevelOrder(*root);*/

		return 0;
	}else if (MajLMinR0_MajRMinL1 == 1){
		int val_1 = 0;
		int val_2 = 1;
		avlNode *subroot = (*root) -> l;		
		rotate(&(subroot),val_1);
		(*root) -> l = subroot;
		rotate(root,val_2);
		calculateBFeverywhere(*root);
	/*	printf("INFO: printing tree in order\n");
                printTreeInOrder(*root);
                printf("INFO: printing tree in level order\n");
                XprintLevelOrder(*root); */
		
	
		return 0;
	}
}	











