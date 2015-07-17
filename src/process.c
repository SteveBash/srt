#include <stdio.h>
#include <stdlib.h>

#define EMPTY_PCB { .proc = { .pid = '*', .arrival_time= -1, .burst_time = -1}, .state= TERMINATED, .turnaround_time = -1, .response_time = -1, .waiting_time = -1}
#define EMPTY_PROCESS { .pid = '*', .arrival_time= -1, .burst_time = -1}

typedef struct Process{
    char pid;
    int arrival_time;
    int burst_time;
}Process;

void init_processes(Process* processes, int size){	
	int i;
	for(i = 0; i < size; i++)processes[i] = (Process)EMPTY_PROCESS;	
}

void order_processes_by_arrival(Process* processes){
	int i, j, size=0;
	Process temp;
	while(processes[size].pid!='*'){
		size++;	
	}
	for(i = size- 1; i > 0; i--) {
		for(j=0; j < i; j++) {
			if((processes[j].arrival_time) > (processes[j+1].arrival_time)){
				temp = processes[j];
				processes[j] = processes[j+1];
				processes[j+1] = temp;
			}
		}
	}
}

void print_processes(Process* processes){
	int i=0;
	printf("\n\nNombre\tLlegada\tDuracion\n");
	while(processes[i].pid!='*'){
		printf("\n%c\t%d\t%d", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
		i++;
	}
	puts("\n");
}

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

/*
 * Process table es una tabla hash implementanda con un vector disperso sin colisiones
*/
void init_process_table(PCB *process_table, int size){	
	int i;
	PCB init_pcb = EMPTY_PCB;
	for(i = 0; i < size; i++)process_table[i] = init_pcb;	
}

int hash(char pid){		
	return pid - 65;
}

void insert_in_process_table(PCB* process_table, Process proc){
	PCB pcb = { .proc = proc, .state = READY, .turnaround_time = -1, .response_time = -1, .waiting_time = -1}; 
	int index = hash(proc.pid);
	process_table[index] = pcb;
}

PCB get_from_process_table(PCB* process_table, char pid){
	int index = hash(pid);
	return process_table[index];
}

void set_to_process_table(PCB* process_table, PCB pcb, char pid){
	int index = hash(pid);
	process_table[index] = pcb;
}

void print_process_table(PCB *process_table, int size){
	int i=0;
	printf("\nNombre\tLlegada\tDuracion\tT.Ret.\tT.Resp.\tT.Esp.\n");
	while(i<size){
        if(process_table[i].proc.pid != '*')
		printf("\n%c\t%d\t%d\t\t%d\t%d\t%d", process_table[i].proc.pid, process_table[i].proc.arrival_time, process_table[i].proc.burst_time, process_table[i].turnaround_time, process_table[i].response_time, process_table[i].waiting_time);
		i++;
	}
	puts("\n");
}

/*int main(){*/
	/*Process processes[26];*/
	/*init_processes(processes, 26);*/
	/*processes[0] = (Process){ .pid = 'A', .arrival_time = 2, .burst_time = 4};*/
	/*processes[1] = (Process){ .pid = 'B', .arrival_time = 1, .burst_time = 2};*/
	/*processes[2] = (Process){ .pid = 'C', .arrival_time = 0, .burst_time = 5};*/
	/*order_processes_by_arrival(processes);*/
	/*print_processes(processes);*/
	/*return 0;*/
/*}*/

/*int main(){*/
    /*PCB process_table[26];*/
    /*init_process_table(process_table, 26);*/
    /*Process p1 = { .pid = 'A', .arrival_time = 0, .burst_time = 4};*/
    /*Process p2 = { .pid = 'B', .arrival_time = 1, .burst_time = 2};*/
    /*Process p3 = { .pid = 'C', .arrival_time = 2, .burst_time = 5};*/
    /*insert_in_process_table(process_table, p1);*/
    /*insert_in_process_table(process_table, p2);*/
    /*insert_in_process_table(process_table, p3);*/
    /*printf("%d\n", get_from_process_table(process_table, 'A').proc.burst_time);*/
    /*printf("%d\n", get_from_process_table(process_table, 'B').proc.burst_time);*/
    /*printf("%d\n", get_from_process_table(process_table, 'C').proc.burst_time);*/
    /*print_process_table(process_table, 3);*/
    /*return 0;*/
/*}*/

