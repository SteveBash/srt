#include "../lib/minunit.h"
#include "../src/dispatcher.c"

Process processes[26];

void _init_test(){
    init_processes(processes, 26);
    processes[0] = (Process){ .pid = 'A', .arrival_time = 0, .burst_time = 4};
    processes[1] = (Process){ .pid = 'B', .arrival_time = 0, .burst_time = 2};
    processes[2] = (Process){ .pid = 'C', .arrival_time = 2, .burst_time = 5};
}

char *test_arrived_processes(){
    _init_test();
    IntList *il = get_arrived_processes(processes, 0);
    IntNode *in = il->first;
    int counter=0;
    while(in!=NULL){
        in=in->next;
        counter++;
    }
    mu_assert(counter==2, "Dos procesos llegaron en el segundo 0");
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_arrived_processes);
    return NULL;
}

RUN_TESTS(all_tests);
