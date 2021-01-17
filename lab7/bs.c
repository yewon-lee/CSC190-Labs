#include<stdio.h>
#include<stdlib.h>

int bs(int *x,int size,int (*compare)(int x,int y));
int lt(int x, int y);
int gt(int x, int y);

int bs(int *x, int size, int (*compare)(int x, int y)){
	int swapped=0;
	float tmp=0;
	int i=0;
	int n=0;
	n=size;
	while(1){
		swapped=0;
		for(i=1;i<n;i=i+1){
			if((*compare)(x[i-1],x[i])==0){
				tmp=x[i];
				x[i]=x[i-1];
				x[i-1]=tmp;
				swapped=1;
			}
		}
		if(swapped==0){break;}
	}return 0;
}

int lt(int x, int y){
	if(x<=y){
		return 0;
	}else{
		return -1;
	}
}

int gt(int x, int y){
	if(x>=y){
		return 0;
	}else{
		return -1;
	}
}

