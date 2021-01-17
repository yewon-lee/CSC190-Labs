#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i=0;
	unsigned char x=0xc5;
	unsigned char rval;
	unsigned char pattern=0xb8;
	unsigned char *data = NULL;
	unsigned int size = 8;
	unsigned char password = 0x1;
	int j = 0;
	/*x = 'y';*/
	rval = x;
	for (j=0;j<9;j++){
		rval = prng(rval,pattern);
		printf("rval = %02x %d\n",rval,rval);
	}
	
	data = (unsigned char *)malloc(sizeof(unsigned char)*size);
	for(i=0;i<size-1;i++){
		data[i]=0x1;
                printf("%02x\n",data[i]);
        }

	crypt(data,size,password);	
	for(i=0;i<size-1;i++){
		printf("%x\n",data[i]);
	}

	return 0;
}
