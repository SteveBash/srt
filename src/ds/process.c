#include <stdio.h>
#include <stdlib.h>

#define EMPTY_PCB { .proc = { .pid = '*', .arrival_time= -1, .burst_time = -1}, .state= TERMINATED, .turnaround_time = -1, .response_time = -1, .waiting_time = -1}

typedef struct Process{
    char pid;
    int arrival_time;
    int burst_time;
}Process;

typedef enum process_state{
   READY = 'Y', 
   RUNNING= 'R', 
   TERMINATED = 'T' 
}process_state;

typedef struct PCB{
    Process proc;
    enum process_state state;
    int turnaround_time;
    int response_time;
    int waiting_time;
}PCB;

void init_process_table(PCB *process_table, int size){	
	int i;
	PCB init_pcb = EMPTY_PCB;
	for(i = 0; i < size; i++)process_table[i] = init_pcb;	
}

void process_table_add_PCB(PCB *process_table, Process proc, process_state state, int turnaround_time, int response_time, int waiting_time, int index){
	PCB pcb = { .proc = proc, .state = state, .turnaround_time = turnaround_time, .response_time = response_time, .waiting_time = waiting_time}; 
	process_table[index] = pcb;
}

PCB process_table_get_PCB(PCB *process_table, int size, char pid){
	int i;
	PCB pcb, empty_pcb=EMPTY_PCB;
	for(i=0; i < size; i++) if(process_table[i].proc.pid==pid)pcb = process_table[i];
	return pcb;
}

/*int main(){*/
	/*PCB pt[100];*/
	/*init_process_table(pt, 100);*/
	/*Process p1 = { .pid = 'A', .arrival_time = 0, .burst_time = 4};*/
	/*Process p2 = { .pid = 'B', .arrival_time = 1, .burst_time = 2};*/
	/*Process p3 = { .pid = 'C', .arrival_time = 2, .burst_time = 5};*/
	/*process_table_add_PCB(pt, p1, READY, 0, 0, 0, 0);*/
	/*process_table_add_PCB(pt, p2, READY, 0, 0, 0, 1);*/
	/*process_table_add_PCB(pt, p3, READY, 0, 0, 0, 2);*/
	/*printf("%d\n", process_table_get_PCB(pt, 100, 'A').proc.burst_time);*/
	/*printf("%d\n", process_table_get_PCB(pt, 100, 'B').proc.burst_time);*/
	/*printf("%d\n", process_table_get_PCB(pt, 100, 'C').proc.burst_time);*/
	/*return 0;*/
/*}*/

