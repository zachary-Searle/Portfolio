/*Zachary Searle
CS3060-001 Spring 2020
Assignment number 1
Promise of Originalty
I promise that his source code file has, int it's entirety, been written by myself and by
no other person or persons. If at any time an exact copy of this source code is found to
be used by another person in this term, I understand that both myself and the student
that submitted the copy will recieve a zero on this assignment
*/
#include <stdio.h>
int main(int argc, char* argv[]){
	printf("This program prints all the arguments passed to the function\n");
	for(int i = 0; i < argc; i++){
		printf("Argument %d:%s \n", i, argv[i]);
	}
	printf("The number of arguments passed was %d \n", argc);
	return 0;
}
