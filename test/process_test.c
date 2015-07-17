#include "../lib/minunit.h"
#include "../src/process.c"

char *test_process_table_has_element(){
    PCB process_table[26];
    init_process_table(process_table, 26);
    Process p1 = { .pid = 'A', .arrival_time = 0, .burst_time = 4};
    Process p2 = { .pid = 'B', .arrival_time = 1, .burst_time = 2};
    Process p3 = { .pid = 'C', .arrival_time = 2, .burst_time = 5};
    insert_in_process_table(process_table, p1);
    insert_in_process_table(process_table, p2);
    insert_in_process_table(process_table, p3);
    mu_assert( get_from_process_table(process_table, 'A').proc.burst_time == 4,"El pid A de la tabla de procesos tiene una duracion de 4");
    mu_assert( get_from_process_table(process_table, 'B').proc.burst_time == 2,"El pid B de la tabla de procesos tiene una duracion de 2");
    mu_assert( get_from_process_table(process_table, 'C').proc.burst_time == 5,"El pid C de la tabla de procesos tiene una duracion de 5");
    return NULL;
}


char *all_tests() {
    mu_suite_start();
    mu_run_test(test_process_table_has_element);
    return NULL;
}

RUN_TESTS(all_tests);
