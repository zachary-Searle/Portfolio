#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 20

int arrival_time[BUFFERSIZE] = {5, 11, 238, 254, 330, 637, 1042, 1163, 1364, 1404, 1737, 1885, 2149, 2230, 2273, 2327, 2441, 2498, 2875, 2954};
int burst_time[BUFFERSIZE]  = {100, 20, 80, 20, 140, 220, 360, 120, 170, 170, 180, 40, 190, 330, 360, 200, 190, 110, 250, 200};
void FirstCome();
void ShortestJobFirst();

int main(){
	FirstCome();
	ShortestJobFirst();
	return 0;
}

void FirstCome(){
	printf("First come, first serve\n");
	int tat[BUFFERSIZE];
	int wt[BUFFERSIZE];
	int rt[BUFFERSIZE];
	int queue[BUFFERSIZE];
	int queueCount = 0;
	int totalWait = 0;
	int totalRT = 0;
	int totalTAT = 0;
	int pCount = 0;
	int i = 1;
	int collectBurst = burst_time[0] + arrival_time[0];
	int currentProcess = 0;
	for(i; i < BUFFERSIZE; i++){
		wt[i] = 0;
		rt[i] = 0;
		tat[i] = 0;
		queue[i] = 0;
	}
	i = 1;
	wt[0] = 0;
	rt[0] = 0;
	tat[0] = wt[0] + burst_time[0];
	while(pCount != BUFFERSIZE - 1){
		for(i;i < BUFFERSIZE; i++){
				queue[queueCount] =  i;
				queueCount++;
		}
		currentProcess = queue[pCount];
		queue[pCount] = -1;
		pCount = (pCount + 1) % BUFFERSIZE;
		if(arrival_time[currentProcess] >= collectBurst){
		wt[currentProcess] = 0;
		rt[currentProcess] = 0;
		tat[currentProcess] = burst_time[currentProcess];
		collectBurst = burst_time[currentProcess] + arrival_time[currentProcess];
		}else{
		wt[currentProcess] = collectBurst - arrival_time[currentProcess];
		rt[currentProcess] = wt[currentProcess];
		collectBurst += burst_time[currentProcess];
		tat[currentProcess] = collectBurst - arrival_time[currentProcess];
		}
	}
	for(int j = 0; j < BUFFERSIZE; j++){
		totalWait += wt[j];
		totalRT += rt[j];
		totalTAT += tat[j];
	}
	printf("The average response time is: %.2f\n", (double)totalRT/BUFFERSIZE);
	printf("The average turnaround time is: %.2f\n", (double)totalTAT/BUFFERSIZE);
	printf("The average waiting time is: %.2f\n", (double)totalWait/BUFFERSIZE);
}
void ShortestJobFirst(){
	printf("Shortest job first\n");
	int bt[BUFFERSIZE];
	int endTime[BUFFERSIZE];
	int tat[BUFFERSIZE];
	int rt[BUFFERSIZE];
	int wt[BUFFERSIZE];
	int queue[BUFFERSIZE];
	int queueCount = 0;
	int totalWait = 0;
	int totalRT = 0;
	int totalTAT = 0;
	int pCount = 0;
	int i = 0;
	int collectBurst = arrival_time[0];
	int currentProcess = -1;
	for(i; i < BUFFERSIZE; i++){
		bt[i] = burst_time[i];
		wt[i] = 0;
		tat[i] = 0;
		rt[i] = 0;
		queue[i] = 0;
	}
	i = 0;
	while(pCount != BUFFERSIZE){
		for(i; i < BUFFERSIZE; i++){
			queue[queueCount] = i;
			queueCount = (queueCount + 1) % BUFFERSIZE;
		}
		for(int j = 0; j < BUFFERSIZE; j++){
			if(queue[j] != -1){
				int temp = queue[j];
				if (currentProcess == -1){
					currentProcess = queue[j];
				}else if(arrival_time[temp] <= collectBurst && bt[temp] < bt[currentProcess]){
					currentProcess = temp;
				}
			}else
				continue;
		}
		if(bt[currentProcess] == 9999){
			collectBurst = arrival_time[pCount];
			currentProcess = -1;
		}else{
			collectBurst += bt[currentProcess];
			endTime[currentProcess] = collectBurst;
			bt[currentProcess] = 9999;
			currentProcess = -1;
			pCount++;
		}
	}
	for(int j = 0; j < BUFFERSIZE; j++){
		tat[j] = endTime[j] - arrival_time[j];
		wt[j] = tat[j] - burst_time[j];
		rt[j] = wt[j];
		totalTAT += tat[j];
		totalWait += wt[j];
		totalRT += rt[j];
	}
	printf("The average wait time is: %.2f\n", (double)totalWait/BUFFERSIZE);
	printf("The average response time is: %.2f\n", (double)totalRT/BUFFERSIZE);
	printf("The average turnaround time is: %.2f\n", (double)totalTAT/BUFFERSIZE);
}
