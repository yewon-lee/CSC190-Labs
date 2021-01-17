
struct bstNode{
	int val;
	struct bstNode *l;
	struct bstNode *r;
};
typedef struct bstNode bstNode;

struct avlNode(
	int balance; /* -1 Left, 0 Balanced, 1 Right*/
	int val;
	struct avlNode *l;
	struct avlNode *r;
}
typedef struct avlNode avlNode;

struct qNode{
	avlNode *pval;
	struct qNode *nxt;
};
typedef struct qNode qNode;

int add_bst(avlNode **root, int val){
	if (root == NULL){ return -1;}
	if (*root == NULL){
		*root = (avlNode *)malloc(sizeof(avlNode));
		(*root) -> val = val;
		(*root) -> l = NULL;
		(*root) -> r = NULL;
		(*root) -> val = 0;
	}else{
		if ((*root) -> val > val) {
			return add_bst(&((*root)->l),val);
		}else{
			return add_bst(&((*root) -> r), val)
		}
	}
	return 0;
}

int printLevelOrder(avlNode *root){
/*	if (root == NULL){
		return -1;
	}else if ((*root) -> l  == NULL){
		return 0;
	}else{
		printLevelOrder((*root) -> l);
		printLevelOrder((*root));
		printLevelOrder((*root) -> r);
	}
}	*/
	if (root != NULL){
		printLevelOrder(root -> l);
		printf(root -> val);
		printLevelOrder(root -> r);
	}				 		
int main(void){
	avlNode *root = NULL;
	addNonAvl




