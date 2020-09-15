#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAGESIZE 4096
int main(int argc, char* argv[]){
	argc--;
	argv++;
	char str[100] = "0x";
	char zero = '0';
	int i = 0;
	int tooBig = strlen(argv[0]);
	if(tooBig > 8){
		printf("too big of a hexadecimal\n");
		return 1;
	}
	for(i; i < 8 - strlen(argv[0]); i++){
		strncat(str, &zero, 1);
	}
	strncat(str, argv[0], strlen(argv[0]));
	printf("logical address: %s\n", str);
	long amount = strtol(str,NULL,0);
	int pageNumber = amount/PAGESIZE;
	int offset = amount % PAGESIZE;
	printf("Page Index: 0x%08x\nOffset: 0x%08x\n", pageNumber, offset);
	return 0;
}
