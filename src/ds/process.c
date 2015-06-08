#include <stdio.h>
#include <stdlib.h>

struct Process{
    char pid;
    int arrivalTime;
    int burstTime;
};

typedef struct Process Process;

enum process_state{
   READY = 'R', 
   TERMINATED = 'T' 
};

struct PCB{
    Process proc;
    enum process_state state;
    int turnaroundTime;
    int responseTime;
    int waitingTime;
};

typedef struct PCB PCB;

struct ProcessTable{
    PCB first;
    PCB *next;
};

typedef struct ProcessTable ProcessTable;

