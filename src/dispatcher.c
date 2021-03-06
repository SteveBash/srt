
#include <stdio.h>
#include <stdlib.h>
#include "pid_queue.c"

#include "execution_instant.c"
#include "process.c"
#include "int_list.c"

#define MAX_PROCESSES 26
#define MAX_TIME 40
#define MAX_BURST_TIME 10000

void get_processes_from_input(Process* processes){
	int i, processes_total;
	puts("Ingrese numero de procesos: ");
	scanf("%d", &processes_total);
	for(i=0; i<processes_total; i++) {
		puts("\nNombre de proceso(Solo letras en mayusculas): ");
		scanf("\n%c", &processes[i].pid);
		printf("\nTiempo de llegada de %c: ", processes[i].pid);
		scanf("%d", &processes[i].arrival_time);
		printf("\nNro de rafagas de cpu de %c: ", processes[i].pid);
		scanf("%d", &processes[i].burst_time);
	}
}

//Llamar a free luego de usar la funcion
IntList* get_arrived_processes(Process* processes, int time){
    IntList *il = create_int_list();
    int i=0;
	while( i < MAX_PROCESSES ){
		if(processes[i].arrival_time==time){
            int_list_add(il, i);
		}
        i++;
	}
	return il;
}

char srt(PCB* process_table, PidQueue *q){
    PidQueue *copy_q = copy(q);
	int min = MAX_BURST_TIME, proc_burst;
    char pid, lowest_pid='-';
	while(!queue_empty(copy_q)){
		pid = dequeue(copy_q);
		PCB pcb = get_from_process_table(process_table, pid);
		proc_burst = pcb.proc.burst_time;
		if(proc_burst < min && pcb.state != TERMINATED){
			min = proc_burst;
            lowest_pid = pid;
		}
	}
	return lowest_pid;
}

int has_a_process_arrived(IntList *index_list){
    return !int_list_empty(index_list);
}

int is_process_terminated(PCB* process_table, char pid){
	PCB pcb = get_from_process_table(process_table, pid);
	return pcb.proc.burst_time == 0;
}

void execute(PCB* process_table, char pid){
	PCB pcb = get_from_process_table(process_table, pid);
	pcb.proc.burst_time--;
	if(pcb.proc.burst_time == 0)
		pcb.state = TERMINATED;
    set_to_process_table(process_table, pcb, pid);
}

void calculate_turnaround_time(PCB* process_table, char pid, int time){
	PCB pcb = get_from_process_table(process_table, pid);
    pcb.turnaround_time = time - pcb.proc.arrival_time; 
    set_to_process_table(process_table, pcb, pid);
}

void calculate_response_time(PCB* process_table, char pid, int time){
	PCB pcb = get_from_process_table(process_table, pid);
    if(pcb.response_time==-1){
        pcb.response_time = time - pcb.proc.arrival_time; 
        set_to_process_table(process_table, pcb, pid);
    }
}

void calculate_waiting_time(PCB* process_table, char executing_pid, PidQueue *copy_q){
    int i=0;
    char pid;
	while(!queue_empty(copy_q)){
		pid = dequeue(copy_q);
		PCB pcb = get_from_process_table(process_table, pid);
        if(pcb.state!=TERMINATED && pcb.proc.pid != executing_pid){
            pcb.waiting_time++;
            set_to_process_table(process_table, pcb, pid);
        }
	}
}

void print_calculate_averages(PCB* process_table, PidQueue *copy_q){
    float average_response_time = 0;
    float average_turnaround_time = 0;
    float average_waiting_time = 0;
    int total_proc = 0;
    char pid;
	while(!queue_empty(copy_q)){
		pid = dequeue(copy_q);
        total_proc++;
		PCB pcb = get_from_process_table(process_table, pid);
        average_response_time += pcb.response_time;
        average_waiting_time += pcb.waiting_time;
        average_turnaround_time  += pcb.turnaround_time;
	}
    average_turnaround_time/= total_proc; 
    average_waiting_time/= total_proc; 
    average_response_time/= total_proc; 
    printf("\nPromedio de tiempo de retorno: %.2f", average_turnaround_time);
    printf("\nPromedio de tiempo de respuesta: %.2f", average_response_time);
    printf("\nPromedio de tiempo de espera: %.2f\n\n", average_waiting_time);
}

void scheduling(Process *processes, PCB *process_table, PidQueue *queue, ExecutionInstants *einstants){
    int time=0;
    char pid='-';
    while(time<MAX_TIME){
        IntList *il = get_arrived_processes(processes, time);
        IntNode *in = il->first;
        if(has_a_process_arrived(il)){
            while(in!=NULL){
                insert_in_process_table(process_table, processes[in->i]);
                enqueue(queue, processes[in->i].pid);
                in = in->next; 
            }
            pid = srt(process_table, queue);
        }else if(is_process_terminated(process_table, pid)){
            calculate_turnaround_time(process_table, pid, time);
            pid = srt(process_table, queue);
        }
        if(pid!='-'){
            execute(process_table, pid);
            calculate_response_time(process_table, pid, time);
        }
        calculate_waiting_time(process_table, pid, copy(queue));
        execution_instant_add(einstants, pid, time);
        time++;
    }
}

int main(){
    puts("\nSimulacion del algoritmo SRT(Shortest remaining time)\n");
    ExecutionInstants *eis = create_execution_instants();
    Process processes[26];
    PCB process_table[26];
    PidQueue *queue = create_queue();
    init_processes(processes, 26);
    init_process_table(process_table, 26);
    get_processes_from_input(processes);
    order_processes_by_arrival(processes);
    print_processes(processes);
    scheduling(processes, process_table, queue, eis);
    print_process_table(process_table, 26);
    print_calculate_averages(process_table, copy(queue));
    construct_gantt_chart(eis);
}

