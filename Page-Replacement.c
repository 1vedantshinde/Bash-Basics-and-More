#include<stdio.h>
#include<limits.h>

#define MAX 100

//Function to check if a page is present in memory
int isPageInMemory(int page, int memory[], int frames){
	for(int i = 0; i < frames; i++){
		if(memory[i] == page){
			return 1;
		}
	}
	return 0;
}

//Function to find the position of the page to be replaced in FIFO
int fifo(int memory[], int front, int frames){
	return front;
}


int LRU(int memory[], int frames, int referenceString[], int n, int index){
	int least_recent[MAX];

	for(int i = 0; i < frames; i++){
		least_recent[i] = -1;
		for(int j = index - 1; j >=0; j--){
			if(referenceString[j] == memory[i]){
				least_recent[i] = j;
				break;
			}
		}
	}

	int min = least_recent[0], pos = 0;
	for(int i = 1; i < frames; i++){
		if(least_recent[i] < min){
			min = least_recent[i];
			pos = i;
		}
	}
	return pos;
}


int optimal(int memory[], int frames, int referenceString[], int n, int index){
	int future[MAX];

	for(int i = 0; i < frames; i++){
		future[i] = INT_MAX;
		for(int j = index + 1; j < n; j++){
			if(referenceString[j] == memory[i]){
				future[i] = j;
				break;
			}
		}
	}

	int max = future[0], pos= 0;
	for(int i = 1; i < frames; i++){
		if(future[i] > max){
			max = future[i];
			pos = i;
		}
	}
	return pos;
}

void simulate(int referenceString[], int n, int frames, const char *algo){
	int memory[MAX];
	int pageFaults = 0;
	int pos = 0;
	int front = 0;

	for(int i = 0; i < frames; i++){
		memory[i] = -1;
	}

	for(int i = 0; i < n; i++){
		if(!isPageInMemory(referenceString[i], memory, frames)){
			pageFaults++;
			if(algo == "FIFO"){
				pos = fifo(memory, front, frames);
				front = (front + 1) % frames;
			} else if(algo == "LRU"){
				pos = LRU(memory, frames, referenceString, n, i);
			} else if(algo == "Optimal"){
				pos = optimal(memory, frames, referenceString, n, i);
			}
			memory[pos] = referenceString[i];
		}
		printf("Memory after inserting %d: ", referenceString[i]);
		for(int j = 0; j < frames; j++){
			if(memory[j] == -1){
				printf(" - ");
			} else {
				printf(" %d ", memory[j]);
			}
		}
		printf("\n");
	}
	printf("Total page faults using %s: %d", algo, pageFaults);
}

int main(){
	int referenceString[MAX], n, frames;
	printf("Enter the number of pages in the reference string: ");
	scanf("%d", &n);

	printf("Enter the reference string: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &referenceString[i]);
	}

	printf("Enter the number of frames: ");
	scanf("%d", &frames);

	printf("\n----- FIFO -----\n");
	simulate(referenceString, n, frames, "FIFO");

	printf("\n----- LRU -----\n");
	simulate(referenceString, n, frames, "LRU");

	printf("\n----- Optimal -----\n");
	simulate(referenceString, n, frames, "Optimal");

	return 0;
}
