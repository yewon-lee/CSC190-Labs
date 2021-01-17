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
int calculateBFeverywhere(avlNode *root);
int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1);

int printLevelOrderAVL(avlNode *root);
int printByGivenHeight(avlNode *root, int height);

int XprintLevelOrder(avlNode *root);
int Xheight_LevelOrder_HELPER(avlNode *root);
int XPrintByGivenLevel_HELPER(avlNode *root, int level);

/*
int main(void){	
	unsigned int val = 1;
	int a = 16;
	int b = 10;
	int c = 18;
	int d = 8;
	int e = 12;
	int f = 11;
	int BF = 100;
	int rval = 100;
	avlNode *root = NULL;
	add_avl(&root,a,BF);
	add_avl(&root,b,BF);
	add_avl(&root,c,BF);
        add_avl(&root,d,BF);
	add_avl(&root,e,BF);
	add_avl(&root,f,BF);
	calculateBFeverywhere(&root);
	printf("INFO: original in lvl order\n");
	XprintLevelOrder(root);
	printf("INFO: original increasing orde\n");
	printTreeInOrder(root);
	printf("INFO: this is an RR\n");
	rval = dblrotate(&root,val);
	if (rval == -1){
		printf("dblrotate returned an error\n");
	}	
	return 0;
}*/

/*THIS IS THE REAL ONE!!!!*/









