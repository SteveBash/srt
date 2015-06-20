
#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "instant.c"
#include "process.c"

#define MAX_TIME 30

int time = -1;

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
int* get_arrived_processes(Process* processes, int time){
	int i=0, j=0, k;
	int* indexes=malloc(26*sizeof(int));
	for(k=0; k<26;k++) indexes[k]=-1;	
	while(processes[i].pid!='*'){
		if(processes[i].arrival_time==time){
			indexes[j] = i;
			j++;
		}
		i++;
	}
	return indexes;
}

int has_a_process_arrived(int* indexes){
	if(indexes[0] != -1)
		return 1;
	else
		return 0;
}

int has_process_terminated(PCB* process_table, char pid){
	PCB pcb = get_from_process_table(process_table, pid);
	return pcb.state == TERMINATED? 1:0;
}

int is_process_executing(PCB* process_table, char pid){
	PCB pcb = get_from_process_table(process_table, pid);
	return pcb.state == RUNNING? 1:0;
}

void execute(PCB* process_table, char pid){
	PCB pcb = get_from_process_table(process_table, pid);
	pcb.proc.burst_time--;
	if(pcb.proc.burst_time == 0)
		pcb.state = TERMINATED;
}

char srt(PCB* process_table, Queue *q){
    Queue *copy_q = copy(q);
	int min = 1000, proc_burst;
    char pid;
	while(!queue_empty(copy_q)){
		pid = dequeue(copy_q);
		proc_burst = get_from_process_table(process_table, pid).proc.burst_time;
		if(proc_burst < min){
			min = proc_burst;
		}
	}
	return pid;
}

/*void scheduling(){*/
    /*time++;*/
    /*while(time<=MAX_TIME){*/
        /*int *indexes = get_arrived_processes(processes, time);*/
        /*char pid;*/
        /*if(has_a_process_arrived(indexes)){*/
            /*insert_in_process_table(process_table, processes[indexes]);*/
            /*enqueue(queue, processes[indexes].pid);*/
            /*pid = srt(queue);*/
            /*execute(process_table, pid);*/
            /*add_instant(instants, pid, time);*/
        /*}else if(has_process_terminated(pid)){*/
            /*pid = srt(queue);*/
            /*execute(process_table, pid);*/
            /*add_instant(instants, pid, time);*/
        /*}else if(is_process_executing(pid)){*/
            /*execute(process_table, pid);	*/
            /*add_instant(instants, pid, time);*/
        /*}else{No hay proceso por ejecutar*/
            /*execute(process_table, pid);	*/
            /*add_instant(instants, ' ', time);*/
        /*}*/
    /*}*/
/*}*/

/*int main(){*/
    /*puts("\nSimulacion del algoritmo SRT(Shortest remaining time)\n");*/
    /*Instant instants[100];*/
    /*Process processes[26];*/
    /*init_processes(processes, 26);*/
    /*get_processes_from_input(processes);*/
    /*order_processes_by_arrival(processes);*/
    /*print_processes(processes);*/
    /*int *asdf = get_arrived_processes(processes, 0);*/
    /*int c;*/
    /*for(c=0; c<26; c++)*/
        /*printf("%d\n", asdf[c]);*/
/*}*/

int main(){
    puts("\nSimulacion del algoritmo SRT(Shortest remaining time)\n");
    int i;
    Instant instants[100];
    Process processes[26];
    PCB process_table[26];
    init_processes(processes, 26);
    init_process_table(process_table, 26);
    Queue *queue = create_queue();

    get_processes_from_input(processes);
    order_processes_by_arrival(processes);
    print_processes(processes);
    for(i=0; i<4; i++){
        insert_in_process_table(process_table, processes[i]); 
        enqueue(queue, processes[i].pid);;
    }
    /*int *asdf = get_arrived_processes(processes, 0);*/
    /*int c;*/
    /*for(c=0; c<26; c++)*/
        /*printf("%d\n", asdf[c]);*/
}

