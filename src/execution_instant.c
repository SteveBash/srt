
#include <stdio.h>
#include <stdlib.h>

typedef struct ExecutionInstant{
    char pid;
    int time;
    struct ExecutionInstant *next;
}ExecutionInstant;

typedef struct ExecutionInstants{
   ExecutionInstant *first;
} ExecutionInstants;

ExecutionInstants *create_execution_instants(){
    ExecutionInstants *eis = malloc(sizeof(ExecutionInstants));
    eis->first = NULL;
    return eis;
}

int execution_instants_empty(ExecutionInstants *eis){
    return eis->first==NULL;
}

void execution_instant_add(ExecutionInstants *eis, char pid, int time){
    ExecutionInstant *ei = malloc(sizeof(ExecutionInstant)); 
    ei->pid = pid;
    ei->time = time;
    ei->next = NULL;
    if(execution_instants_empty(eis)){
        eis->first = ei;
    }
    else{
        ExecutionInstant *eitemp = eis->first;
        while(eitemp->next!=NULL)
            eitemp = eitemp ->next;
        eitemp->next = ei;
    }
}

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

