#include <stdio.h>
#include <stdlib.h>

struct llnode{
	char value;
	struct llnode *next;
};
typedef struct llnode llnode;

int llnode_add_to_tail(llnode **x, char value){
	if (x==NULL){return -1;}
	if (*x==NULL){
		*x = (llnode *) malloc(sizeof(llnode));
		(*x)->value = value;
		(*x)->next = NULL;
		return 0;
	}else{
		return llnode_add_to_tail(&((*x)->next),value);
	}
}

int llnode_add_to_head(llnode **x, char value){
	if (x==NULL){return -1;}
	if (*x==NULL){
		*x = (llnode *) malloc(sizeof(llnode));
		(*x)->value=value;
		(*x)->next = NULL;
		return 0;
	}else{
		llnode *temp = *x;
		*x = (llnode *)malloc(sizeof(llnode));
		(*x) -> value = value;
		(*x) -> next = temp;
		/*printf("we here bois\n");*/
		return 0;
	}
}

int llnode_print_from_head(llnode *x){
	if (x==NULL){
		/*printf("uhh really??\n");*/
		return 0;
	}else{
		printf("%c\n",x->value);
		return llnode_print_from_head(x->next);
		/*printf("this should print like 7 or 6 times\n");*/
	}
}

int llnode_print_from_tail(llnode *x){
	if (x==NULL){ return 0; }
	else{
		if (x->next == NULL) {
			printf("%c\n",x->value);
			return 0;
		}else{
			llnode_print_from_tail(x->next);
			printf("%c\n",x->value);
			return 0;
		}
	}
}

int push (llnode **x, char value){
	return llnode_add_to_head(x,value);
}
	
int pop (llnode **x, char *return_value){
	if(x==NULL){
		return -1;
	}else{
		/*printf("got here\n");*/
		llnode *temp = *x;
		*return_value = temp -> value;
		*x = (*x)->next;
		free(temp);
		return 0;
	}
}


int main (void){
	int n=0;
	char value='\0';
	int rvalue=0;
	llnode *input_list=NULL;
	char *A=NULL;
	char *B=NULL;
	char *C=NULL;
	char *D=NULL;
	char *E=NULL;
	
	A = (char *)malloc(sizeof(char));
	B = (char *)malloc(sizeof(char));
	C = (char *)malloc(sizeof(char));
	D = (char *)malloc(sizeof(char));
	E = (char *)malloc(sizeof(char));


	/*while (scanf("%c",&value) != EOF) {
		n=n+1;
		llnode_add_to_head(&input_list,value);
	}
	printf("INFO: you entered %d items\n",n);	
	rvalue=llnode_print_from_head(input_list);
	if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }*/

	push(&input_list, 'a');
	push(&input_list, 'b');
	push(&input_list, 'c');
	push(&input_list, 'd');
	push(&input_list, 'e');
	llnode_print_from_head(input_list);


	pop(&input_list,A);
	printf("you've popped %c\n",*A);
	pop(&input_list, B);
	printf("you've popped %c\n", *B);
	llnode_print_from_head(input_list);
	pop(&input_list, C);
        printf("you've popped %c\n", *C);
	pop(&input_list, D);
        printf("you've popped %c\n", *D);
	llnode_print_from_head(input_list);
	pop(&input_list, E);
        printf("you've popped %c\n", *E);
	
	return 0;
}










