
#include <stdio.h>
#include <stdlib.h>

struct Instant{
    char pid;
    int time;
};

typedef struct Instant Instant;

void add_instant_to_clock(Instant *clock, char pid, int index){
	Instant i = { .pid = pid, .time = index};
	clock[index] = i;
}

void init_clock(Instant *clock, int size){
	Instant i = { .pid = '*', .time = -1};
	int c; for(c=0; c<size; c++)clock[c] = i;	
}

/*int main(){*/
	/*Instant clock[100];	*/
	/*init_clock(clock, 100);*/
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

