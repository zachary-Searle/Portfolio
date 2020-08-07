#include <stdio.h>
int main(int argc, char* argv[]){
	printf("This program prints all the arguments passed to the function\n");
	for(int i = 0; i < argc; i++){
		printf("Argument %d:%s \n", i, argv[i]);
	}
	printf("The number of arguments passed was %d \n", argc);
	return 0;
}
