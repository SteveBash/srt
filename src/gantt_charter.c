
#include <stdio.h>
#include <stdlib.h>
#include "execution_instant.c"

void construct_gantt_chart(ExecutionInstants *einstants){
	printf("Diagrama Gantt:\n");	
    ExecutionInstant *einstant = einstants->first;
    ExecutionInstant *itemp = einstant;
	while(itemp!=NULL){
		printf("|%2d ", itemp->time);
        itemp = itemp->next;
	}
	itemp = einstant;
	printf("|\n");
	while(itemp!=NULL){
		printf("| %c ", itemp->pid);
        itemp = itemp->next;
	}
	printf("|\n");
}

