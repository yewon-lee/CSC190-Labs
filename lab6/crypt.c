#include<stdio.h>
#include<stdlib.h>
unsigned char FSR(unsigned char x);
unsigned char prng(unsigned char x, unsigned char pattern);
int crypt(char *data,unsigned int size, unsigned char password);

unsigned char FSR(unsigned char x){
	unsigned char oldbit0 = x & 0x1;
	unsigned char r = x >> 1;
	unsigned char newbit7 = oldbit0 << 7;
	r = r | newbit7;
	return r;
}

unsigned char prng(unsigned char x, unsigned char pattern){
	unsigned char oldbit0 = x & 0x1;
        unsigned char r = x >> 1;
        unsigned char newbit7 = oldbit0 << 7;
        r = r | newbit7;
	r = r^pattern;
        return r;
}	

int crypt(char *data,unsigned int size, unsigned char password){
	if(prng==0){return -1;}
	else if(data==NULL){return -1;}
	else{		
		int i=0;
		unsigned char prngVal = password;
		for(i=0;i<size-1;i++){
			prngVal = prng(prngVal,0xb8);
			data[i] = data[i]^prngVal;	
		}return 0;
	}
}
