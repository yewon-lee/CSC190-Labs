#include<stdlib.h>
#include<stdio.h>

int lt(int x,int y);
int gt(int x, int y);

int main(void){	
	int i=0;
	int vals[10];
	for(i=0;i<10;i++){
		vals[i]=100-i;
	}
	for(i=0;i<10;i++){
		printf("in[%d]=%d\n",i,vals[i]);
	}
	bs(vals,10,lt);		
	for(i=0;i<10;i++){
		printf("out[%d]=%d\n",i,vals[i]);
	}
	return 0;
}
