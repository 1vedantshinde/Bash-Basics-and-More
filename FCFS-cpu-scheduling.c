#include<stdio.h>

struct Process{
	int id;
int burstTime;
int waitingTime;
int turnAroundTime;
};

void findWaitingTime(struct Process processes[], int n){
	processes[0].waitingTime = 0;

	for(int i = 1; i < n; i++){
		processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
	}
}

void findTurnAroundTime(struct Process processes[], int n){
	for(int i = 0; i < n; i++){
	processes[i].turnAroundTime = processes[i].burstTime + processes[i].waitingTime;
	}
}

void findAvgTime(struct Process processes[], int n){
	int totalWaitingTime = 0, totalTurnAroundTime = 0;

	findWaitingTime(processes, n);
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
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);

	struct Process processes[n];
	for(int i = 0; i < n; i++){
		processes[i].id = i + 1;
		printf("Enter the burst time for process %d: ", i + 1);
		scanf("%d", &processes[i].burstTime);
	}

	printf("\nFirst-Come, First-Served (FCFS) Scheduling Algorithm: \n");
	findAvgTime(processes, n);


	return 0;

}
