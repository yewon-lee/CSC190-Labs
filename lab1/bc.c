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
	if (x==NULL){
		return -1;
	}
	if (*x == NULL){
		*x = (llnode *) malloc(sizeof(llnode));
		(*x)->value = value;
		(*x)->next = NULL;
		return 0;
	}else{
		llnode *temp = *x;
		*x = (llnode *)malloc(sizeof(llnode));
		(*x) -> value = value;
		(*x) -> next =  temp;
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
		llnode *temp = *x;
		*return_value = temp -> value;
		*x = (*x)->next;
		free(temp);
		return 0;
	}
}

int bc(llnode *expression){
	
	llnode *stack = NULL; 
	int cnt = -1;
	int printed = 0;
	char *popped_value = NULL;
	
	
	popped_value = (char *)malloc(sizeof(char));
	
		
	while (1){
	
	/* reserve a case for breaking when we reach the end of expression */

		if (expression->next->next == NULL){ /*i actually have no freaking clue why we need to do next next, rather than just next*/
			if (expression->value == '(' || expression->value == '[' || expression->value == '{'){
		 		push(&stack,expression->value);
				cnt = cnt + 1;
				break;
			}else if (expression->value == ')'){
				if (stack == NULL){
					cnt = cnt + 1;
					printf("FAIL,%d\n",cnt);
					printed = 1;
					break;
                                }else if (stack != NULL && stack->value == '('){
                                        pop(&(stack),popped_value);
                                        cnt = cnt + 1;
                                        break;
				}else{
                               	        cnt = cnt + 1;
                                       	printf ("FAIL,%d\n",cnt);
                                        printed = 1;
                                        break;
                       	        }
			}else if (expression->value == ']'){
				if (stack == NULL){
					cnt = cnt + 1;
					printf("FAIL,%d\n",cnt);
					printed = 1;
					break;
                                }else if (stack != NULL && stack->value == '['){
                                        pop(&(stack),popped_value);
                                        cnt = cnt + 1;
                                        break;
				}else{
                                        cnt = cnt + 1;
                                        printf ("FAIL,%d\n",cnt);
                                        printed = 1;
                                        break;
                                }
			}else if (expression->value == '}'){
				if (stack == NULL){
                                        cnt = cnt + 1;
					printf("FAIL,%d\n",cnt);
                                        printed = 1;
                                        break;

				}else if (stack->value == '{'){
                                        pop(&(stack),popped_value);
                                        cnt = cnt + 1;
                                        break;
                                }else{
                                        cnt = cnt + 1;
                                        printf ("FAIL,%d\n",cnt);
                                        printed = 1;
                                        break;
                                }
			}else{
				cnt = cnt + 1;
				break;
			}

	/* reserve the else case when we are note at the end of expression */
	
		}else{
			if (expression->value == '(' || expression->value == '[' || expression->value == '{'){
				push(&stack,expression->value);
				expression = expression->next;
				cnt = cnt + 1;
			}else if (expression->value == ')'){
				if (stack == NULL){
					cnt = cnt + 1;
					printed = 1;
					printf ("FAIL,%d\n",cnt);
					break;
				}else if (stack->value == '('){
					pop(&(stack),popped_value);
					expression = expression -> next;
					cnt = cnt + 1;
				}else{
					cnt = cnt + 1;
					printf ("FAIL,%d\n",cnt);
					printed = 1;
					break;
				}
			}else if (expression->value == ']'){
				if (stack == NULL){
					cnt = cnt + 1;
					printed = 1;
					printf("FAIL,%d\n",cnt);
					break;
				}else if (stack->value == '['){
					pop(&(stack),popped_value);
					expression = expression -> next;
					cnt = cnt + 1;
				}else{
					cnt = cnt +1;
					printf ("FAIL,%d\n",cnt);
					printed = 1;
					break;
				}
			}else if (expression->value == '}'){
				if (stack == NULL){
					cnt = cnt + 1;
					printf("FAIL,%d\n",cnt);
					printed = 1;
					break;
				}else if (stack->value == '{'){
                                        pop(&(stack),popped_value);
                                        expression = expression -> next;
                                        cnt = cnt + 1;
                                }else{
                                        cnt = cnt +1;
                                        printf ("FAIL,%d\n",cnt);
					printed = 1;
                                        break;
                                }
			}else{
				expression = expression -> next;
				cnt = cnt + 1;
			}
		}
	}
	if (printed == 1){
		return 0;
	}else if (printed == 0 && stack == NULL){
		printf("PASS\n");
		return 0;
	}else if (printed == 0){
		printf("FAIL,%d\n",cnt);
		return 0;
	}
	
}



int main (void){
	int n=0;
	char value='\0';
	/*int rvalue=0;*/
	llnode *input_list = NULL;
	int just_integer = 0;
	
		
	while (scanf("%c",&value) != EOF) {
		n=n+1;
		llnode_add_to_tail(&input_list,value);
	}
	/*printf("INFO: you entered %d items\n",n);*/
	/*rvalue = llnode_print_from_head(input_list);
	if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }*/

	just_integer = bc(input_list);
	
		
	return 0;
}






