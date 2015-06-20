
#include <stdio.h>
#include <stdlib.h>

#define EMPTY_INSTANT { .pid = '*', .time= -1}

struct Instant{
    char pid;
    int time;
};

typedef struct Instant Instant;

void add_instant(Instant *instants, char pid, int index){
	Instant i = { .pid = pid, .time = index};
	instants[index] = i;
}

void init_instants(Instant *instants, int size){
	Instant i = EMPTY_INSTANT;
	int c; for(c=0; c<size; c++)instants[c] = i;	
}

/*int main(){*/
	/*Instant clock[100];	*/
	/*init_instants(clock, 100);*/
	/*add_instant(clock, 'A', 0);*/
	/*add_instant(clock, 'B', 1);*/
	/*add_instant(clock, 'C', 2);*/
	/*printf("%c\n", clock[0].pid);*/
	/*printf("%c\n", clock[1].pid);*/
	/*printf("%d\n", clock[2].time);*/
	/*if(clock[2].time==-1)*/
		/*puts("asdfa");*/
	/*return 0;*/
/*}*/

