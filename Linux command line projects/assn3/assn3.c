#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* findPrime(void *n){
	int* arr =(int*)malloc(100*sizeof(int)) ;
	int number = atoi(n);
	int f = 2;
	int i = 1;
	while(number > 1){
		if(number % f == 0){
			arr[i] = f;
			number /= f;
			i++;
		}
		else
			f += 1;
	}
	arr[0] = i-1;
	pthread_exit(arr);
}

int main(int argc, char** argv){
	argc--;
	argv++;
	void* factors;
	int* number;
	int argNum;
	pthread_t tid[argc];
	for(int i = 0; i < argc; i++){
		pthread_create(&tid[i], NULL, findPrime, argv[i]);
	}
	for(int i = 0; i < argc; i++){
		pthread_join(tid[i], &factors);
		number = (int*)factors;
		argNum = *number;
		number++;
		printf("%s: ", argv[i]);
		for(int j = 0; j < argNum; j++){
			printf("%d ", *number);
			number++;
		}
		printf("\n");
	}
	free(factors);
	return 0;
}
