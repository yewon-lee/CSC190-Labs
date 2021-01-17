#include<stdio.h>

int main(void){
	int i=0;
	unsigned char x=0;
	unsigned short int y=0;
	unsigned int z=0;
	unsigned char a=0,b=0,c=0;
	int cnt=0;
	
	printf("first 8 iterations should show a value; followed by 0s\n");
	for (i=0;i<10;i++){
		x=0x1<<i;
		printf("x_%d = %d %x character: %c\n",i,x,x,x);
	}
	printf("first 16 iterations should show a value; followed by 0s\n");
	for(i=0;i<18;i++){
		y=0x1<<i;
		printf("y_%d = %d %x\n",i,y,y);
	}
	printf("first 32 iterations should show a value; followed by 0s\n");
	for(i=0;i<35;i++){
		z=0x1<<i;
		printf("z_%d = %d %x\n",i,z,z);
	}
	a=0x4;
	printf("this puts a 1 in the 3rd spot from the right since 0x4=2^2\n");
	printf("a=%02x\n %x\n",a);
	
	b=0x1<<3;
	printf("this puts a 1 in the 4th spot from the right\n");
	printf("b=%02x\n",b);

	c=a | b;
	printf("this ORs the ith bit of a with the ith bit of b, for all bits, and assigns it to c; the 3rd and 4th spots should be 1\n");
	printf("c=%02x\n",c);

	a=~(0x1<<2);
	printf("this first computes bit[2] being a 1 amidst a sea of 0s and then inberts it bia ~\n")	;
	printf("a=%02x\n",a);
	b=~(0x1<<3);
	printf("this first computes bit[3] being a 1 amidst a sea of 0s and then inverts it via ~\n");
	printf("b=%02x\n",b);
	c=a&b;
	printf("this ANDs the ith bit of a with the ith bit of b for all bits, and assigns it to c; the [2] and [3] bits should be 0 amidst sea of 1s\n");
	printf("c=%02x\n",c);
	
	a=0xab;
	printf("a=%02x\n",a);
	b=(a>>5)&0x1;
	printf("b=%02x\n",b);
	
	a=0xab;
	b=0x55;
	c=a^b;
	printf("c=%x\n",c);
	for(i=0;i<8;i++){
		if(c&0x1==0x1){cnt=cnt+1;}
		c=c>>1;
	}
	printf("%d positions differ in %02x\n",cnt,a,b);
}
