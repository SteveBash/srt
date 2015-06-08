
#include <stdio.h>
#include <stdlib.h>
#include "instant.c"

void construct_gantt_chart(Instant *clock, int size){
	printf("Diagrama Gantt:\n");	
	int i=0;
	while(clock[i].time!=-1){
		printf("|%2d ", clock[i].time);
		i++;
	}
	i = 0;
	printf("|\n");
	while(clock[i].time!=-1){
		printf("| %c ", clock[i].pid);
		i++;
	}
	printf("|\n");
}

/*int main(){*/
	/*Instant clock[100];	*/
	/*init_clock(clock, 100);*/
	/*add_instant(clock, 'A', 0);*/
	/*add_instant(clock, 'B', 1);*/
	/*add_instant(clock, 'C', 2);*/
	/*construct_gantt_chart(clock, 100);*/
/*}*/


