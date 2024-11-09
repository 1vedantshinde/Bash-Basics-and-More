#include<stdio.h>

struct Process{
	int id;
	int burstTime;
	int waitingTime;
	int remainingTime;
	int turnAroundTime;
};

void findWaitingTime(struct Process processes[], int n, int quantum){
	int time = 0;
	
	while(1){
		int done = 1;
		for(int i = 0; i < n; i++){
			if(processes[i].remainingTime > 0){
				done = 0;
				
				if(processes[i].remainingTime > quantum){
					time += quantum;
					processes[i].remainingTime -= quantum;
				}else{
					time += processes[i].remainingTime;
					processes[i].waitingTime = time - processes[i].burstTime;
					processes[i].remainingTime = 0;
					}
			}
		}
	
	
		if(done == 1)
			break;
	}
}

void findTurnAroundTime(struct Process processes[], int n){
	for(int i = 0; i < n; i++){
	processes[i].turnAroundTime = processes[i].burstTime + processes[i].waitingTime;
	}
}


void findAvgTime(struct Process processes[], int n, int quantum){
	int totalWaitingTime = 0, totalTurnAroundTime = 0;

	findWaitingTime(processes, n, quantum);
	findTurnAroundTime(processes, n);

	printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

	for(int i = 0; i < n; i++){
		totalWaitingTime += processes[i].waitingTime;
		totalTurnAroundTime += processes[i].turnAroundTime;
		printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime,
			processes[i].waitingTime, processes[i].turnAroundTime);
	}
	printf("\nAverage Waiting Time = %.2f\n",  (float)totalWaitingTime /n);
	printf("Average Turnaround Time = %.2f\n", (float)totalTurnAroundTime /n);

}


int main(){
	int n, quantum;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	
	struct Process processes[n];
	for(int i = 0; i < n; i++){
		processes[i].id = i + 1;
		printf("Enter the burst time for process %d: ", i + 1);
		scanf("%d", &processes[i].burstTime);
		processes[i].remainingTime = processes[i].burstTime;
	}
	printf("Enter the time quantum: ");
	scanf("%d", &quantum);
	
	printf("\nRound Robin Scheduling Algorithm: \n");
	findAvgTime(processes, n, quantum);
	return 0;
}	
