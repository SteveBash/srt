
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "instant.c"
#include "process.c"

int timer = 0;
int processes_total;

Instant instants[100];
Process processes[20];

void order_processes_by_arrival(){
	int i, j;
	Process temp;

	for(i = processes_total - 1; i > 0; i--) {
		for(j=0; j < i; j++) {
			if((processes[j].arrival_time) > (processes[j+1].arrival_time)){
				temp = processes[j];
				processes[j] = processes[j+1];
				processes[j+1] = temp;
			}
		}
	}
}

void get_processes_from_input(){
	int i;
	puts("\nSimulacion del algoritmo SRT(Shortest remaining time)\n");
	puts("Ingrese numero de procesos: ");
	scanf("%d", &processes_total);
	for(i=0; i<processes_total; i++) {
		printf("Nombre de proceso(Max 1 caracter): ");
		scanf("%c", &processes[i].pid);
		printf("Tiempo de llegada de %c: ", processes[i].pid);
		scanf("%d", &processes[i].arrival_time);
		printf("Nro de rafagas de cpu de %c: ", processes[i].pid);
		scanf("%d", &processes[i].burst_time);

	}
}

void print_processes(){
	int i=0;
	printf("\n\nNombre\tLlegada\tRafagas\n");
	for(i=0; i< processes_total; i++) {
		printf("\n%c\t%d\t%d", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
	}
	order_processes_by_arrival(processes, processes_total);
	puts("\n");
}


//Queue init = aadsf
//int clock = 0;

void insert_in_ready_queue(){
   //modify Queue state 
}

void time_passes(){
    //if arrived
    //insert in ready queue
    //scheduling()
    //clock++
    //else
    //clock++
}

void scheduling(){
    //dequeue all in ready queue
    //srt(ready_queue)
    //construct_pcb()
}

char srt(Queue *q){
	while(!queue_empty(q)){
		dequeue(q);	
	}
}

