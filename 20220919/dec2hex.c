#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef unsigned char* pointer;

bool is64bit() {
	return sizeof(long) == 8;
}

bool isBigEndian(){
	unsigned int x = 1;
	return !(int)(((char *) &x)[0]);
}

void le_show_bytes(pointer a, int size) {
	for (int n = size - 1; n >= 0; n--) {
		printf("%.2X", (int) a[n]);
	}
	printf("\n");

	return;
}

void be_show_bytes(pointer a, int size){
	for (int n = 0; n < size; n++) {
		printf("%.2X", (int) a[n]);
	}
	printf("\n");

	return;
}

int main(int argc, char* argv[]) {
	if(argc < 2){
		printf("Usage: ./a.out number\n");
		exit(0);
	}
	unsigned int a = atoi(argv[1]);
	printf("ARCH=%d\n", is64bit()? 64 : 32);
	printf("ORDERING=%s\n", isBigEndian()? "BIG_ENDIAN" : "LITTLE_ENDIAN");

	printf("MYANS: DEC=%d HEX=", a);
	isBigEndian()? 
		//be_show_bytes(): le_show_bytes();
		be_show_bytes((pointer)&a, sizeof(unsigned int)): le_show_bytes((pointer)(&a), sizeof(unsigned int));

	printf("CHECK: DEC=%d HEX=%.8X\n", a, a);
	return 0;
}
