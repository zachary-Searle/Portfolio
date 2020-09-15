#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define BUFFERSIZE 20

int FirstCome();
int ShortestSeek();
int Look();
int CLook();
int Compare(const void* num1, const void* num2);
int placements[BUFFERSIZE] = {221, 16, 103, 101, 4, 99, 84, 23, 72, 245, 231, 61, 247, 233, 212, 85, 193, 115, 29, 35};
int main(int argc, char* argv[]){
	FirstCome();
	ShortestSeek();
	Look();
	CLook();
}

int FirstCome(){
	int totalCylinders = 0;
	int currentPosition = placements[0];
	int nextPosition = placements[1];
	int i = 0;
	while(i != BUFFERSIZE - 1){
		if(currentPosition - nextPosition > 0){
			totalCylinders += currentPosition - nextPosition;
			i++;
			currentPosition = placements[i];
			if(i + 1 > BUFFERSIZE);
			else
				nextPosition = placements[i + 1];
		}else if(currentPosition - nextPosition < 0){
			totalCylinders += nextPosition - currentPosition;
			i++;
			currentPosition = placements[i];
			if(i + 1 > BUFFERSIZE);
			else
				nextPosition = placements[i + 1];
		}
	}
	printf("FCFS Total Seek: %d\n", totalCylinders);
	return 0;
}

int ShortestSeek(){
	int totalCylinders = 0;
	int start = placements[0];
	int currentPosition = 0;
	int prevPosition = 0;
	int nextPosition = 0;
	int copy[BUFFERSIZE];
	for(int i = 0; i < BUFFERSIZE; i++){
		copy[i] = placements[i];
	}
	qsort(copy, sizeof(copy)/sizeof(*copy), sizeof(*copy), Compare);
	for(int i = 0; i < BUFFERSIZE; i++){
		if(copy[i] == start){
			currentPosition = i;
			nextPosition = i + 1;
			prevPosition = i - 1;
			i = BUFFERSIZE;
		}
	}
	while(1){
		if(nextPosition == BUFFERSIZE){
			if(prevPosition == -1){
				printf("SSTF Total Seek: %d\n", totalCylinders);
				return 0;
			}else{
				totalCylinders += (copy[currentPosition] - copy[prevPosition]);
				currentPosition = prevPosition;
				prevPosition--;
			}
		}else if(prevPosition == -1){
			totalCylinders += copy[nextPosition] - copy[currentPosition];
			currentPosition = nextPosition;
			nextPosition++;
		}else{
			if(copy[currentPosition] - copy[prevPosition] < copy[nextPosition] - copy[currentPosition]){
				totalCylinders += copy[currentPosition] - copy[prevPosition];
				currentPosition = prevPosition;
				prevPosition--;
			}else if(copy[currentPosition] - copy[prevPosition] >= copy[nextPosition] - copy[currentPosition]){
				totalCylinders += copy[nextPosition] - copy[currentPosition];
				currentPosition = nextPosition;
				nextPosition++;
			}
		}
	}
}

int Look(){
	int totalCylinders = 0;
	int currentPosition = 0;
	int nextPosition = 0;
	int prevPosition = 0;
	int start = placements[0];
	int copy[BUFFERSIZE];
	for(int i = 0; i < BUFFERSIZE; i++){
		copy[i] = placements[i];
	}
	qsort(copy, sizeof(copy)/sizeof(*copy), sizeof(*copy), Compare);
	for(int i = 0; i < BUFFERSIZE; i++){
		if(copy[i] == start){
			currentPosition = i;
			nextPosition = i + 1;
			prevPosition = i - 1;
			i = BUFFERSIZE;
		}
	}
	while(nextPosition != BUFFERSIZE){
		totalCylinders += copy[nextPosition] - copy[currentPosition];
		currentPosition = nextPosition;
		nextPosition++;
	}
	while(prevPosition != -1){
		totalCylinders += copy[currentPosition] - copy[prevPosition];
		currentPosition = prevPosition;
		prevPosition--;
	}
	printf("LOOK Total Seek: %d\n", totalCylinders);
}

int CLook(){
	int totalCylinders = 0;
	int currentPosition = 0;
	int nextPosition = 0;
	int prevPosition = 0;
	int start = placements[0];
	int copy[BUFFERSIZE];
	for(int i = 0; i < BUFFERSIZE; i++){
		copy[i] = placements[i];
	}
	qsort(copy, sizeof(copy)/sizeof(*copy), sizeof(*copy), Compare);
	for(int i = 0; i < BUFFERSIZE; i++){
		if(copy[i] == start){
			currentPosition = i;
			nextPosition = i + 1;
			prevPosition = i - 1;
			i = BUFFERSIZE;
		}
	}
	while(nextPosition != BUFFERSIZE){
		totalCylinders += copy[nextPosition] - copy[currentPosition];
		currentPosition = nextPosition;
		nextPosition++;
	}
	totalCylinders += copy[currentPosition] - copy[0];
	currentPosition = 0;
	while(currentPosition != prevPosition){
		totalCylinders += copy[currentPosition + 1] - copy[currentPosition];
		currentPosition++;
	}
	printf("C-LOOK Total Seek: %d\n", totalCylinders);
}

int Compare(const void* num1, const void* num2){
	int numb1 = *((int*)num1);
	int numb2 = *((int*)num2);
	if(numb1 > numb2)
		return 1;
	if(numb1 < numb2)
		return -1;
	return 0; 
}
