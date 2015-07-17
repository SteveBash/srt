#include "../lib/minunit.h"
#include "../src/dispatcher.c"

void _init_test_processes(Process *processes){
    init_processes(processes, 26);
    processes[0] = (Process){ .pid = 'A', .arrival_time = 0, .burst_time = 4};
    processes[1] = (Process){ .pid = 'B', .arrival_time = 0, .burst_time = 2};
    processes[2] = (Process){ .pid = 'C', .arrival_time = 2, .burst_time = 5};
}

char *test_two_processes_arrived(){
    Process processes[26];
     _init_test_processes(processes);
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

void _init_test_process_table( Process *processes, PCB *process_table){
    init_processes(processes, 26);
    processes[0] = (Process){ .pid = 'A', .arrival_time = 0, .burst_time = 4};
    processes[1] = (Process){ .pid = 'B', .arrival_time = 0, .burst_time = 2};
    processes[2] = (Process){ .pid = 'C', .arrival_time = 2, .burst_time = 1};
    processes[3] = (Process){ .pid = 'D', .arrival_time = 3, .burst_time = 5};

    init_process_table(process_table, 26);
    insert_in_process_table(process_table, processes[0]);
    insert_in_process_table(process_table, processes[1]);
    insert_in_process_table(process_table, processes[2]);
    insert_in_process_table(process_table, processes[3]);
}

char *test_srt(){
    PCB process_table[26];
    Process processes[26];
    _init_test_process_table( processes,  process_table);
    Queue *q = create_queue();
    enqueue(q, processes[0].pid);
    enqueue(q, processes[1].pid);
    enqueue(q, processes[2].pid);
    enqueue(q, processes[3].pid);
    mu_assert(srt(process_table, q)=='C', "El menor tiempo restante es C");
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_two_processes_arrived);
    mu_run_test(test_srt);
    return NULL;
}

RUN_TESTS(all_tests);
