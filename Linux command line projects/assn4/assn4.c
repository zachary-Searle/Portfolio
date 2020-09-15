
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define BUFFER_SIZE 5
#define ARRAY_SIZE 20

int MPBuffer[BUFFER_SIZE];
int* PCBuffer[BUFFER_SIZE];
int MPCounter, PCCounter, in, out, in2, out2, argc2, Pargc, Cargc;
pthread_mutex_t lock1;
pthread_mutex_t lock2;

void *Producer(void *param);
void *Consumer(void *param);
int main(int argc, char* argv[]){
	argc--;
	argc2 = argc;
	argv++;
	pthread_t tid[2];
	int i = 0;
	int number = 0;
	pthread_create(&tid[0], NULL, Producer, NULL);
	pthread_create(&tid[1], NULL, Consumer, NULL);
	MPCounter, PCCounter, in, in2, out, out2 = 0;
	while(1){
		if(i == argc2)
			break;
		while(MPCounter == BUFFER_SIZE);
		pthread_mutex_lock(&lock1);
		number = atoi(argv[i]);
		i++;
		MPBuffer[in] = number;
		in = (in + 1) % BUFFER_SIZE;
		MPCounter++;
		pthread_mutex_unlock(&lock1);
	}
	for(int j = 0; j < 2; j++){
		pthread_join(tid[j], NULL);
	}
	return 0;
}

void *Producer(void *param){
	int number = 0;
	Pargc = 1;
	int* array = (int*)malloc(ARRAY_SIZE * sizeof(int));
	int* clear = (int*)malloc(ARRAY_SIZE * sizeof(int));
	int f = 2;
	int i = 1;
	int j = 0;
	while(Pargc <= argc2){
		while(MPCounter == 0);
		pthread_mutex_lock(&lock1);
		number = MPBuffer[out];
		out = (out + 1) % BUFFER_SIZE;
		MPCounter--;
		pthread_mutex_unlock(&lock1);
		array[0] = number;
		while(number > 1){
			if(number % f == 0){
				array[i] = f;
				i++;
				number /= f;
			}
			else
				f++;
		}
		array[i] = -1;
		while(PCCounter == BUFFER_SIZE);
		pthread_mutex_lock(&lock2);
		PCBuffer[in2] = array;
		in2 = (in2 + 1) % BUFFER_SIZE;
		PCCounter++;
		pthread_mutex_unlock(&lock2);
		i = 1;
		f = 2;
		array = (int*)malloc(ARRAY_SIZE * sizeof(int));
		Pargc++;

		}
		return 0;
}

void *Consumer(void *param){
	int* number;
	int* freeThis;
	Cargc = 1;
	int start = 0;
	int count = 0;
	while(Cargc <= argc2){
		while(PCCounter == 0);
		pthread_mutex_lock(&lock2);
		number = PCBuffer[out2];
		freeThis = PCBuffer[out2];
		out2 = (out2 + 1) % BUFFER_SIZE;
		PCCounter--;
		pthread_mutex_unlock(&lock2);
		while(*number != -1){
			if(start == 0){
				printf("%d: ", *number);
				start++;
				number++;
			}
			if(*number == -1)
				printf("0");
			else{
			printf("%d ", *number);
			number++;
			}
		}
		printf("\n");
		start = 0;
		free(freeThis);
		Cargc++;
	}
}
