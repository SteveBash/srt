#include "../lib/minunit.h"
#include "../src/execution_instant.c"

char *test_empty(){
    ExecutionInstants *eis = create_execution_instants();
    mu_assert(execution_instants_empty(eis), "La lista de instantes esta vacia");
    return NULL;
}

char *test_has_instant_with_time_1_and_pid_A(){
    ExecutionInstants *eis = create_execution_instants();
    execution_instant_add(eis, 'A', 1);
    mu_assert(eis->first->time  == 1, "La lista de instantes tiene primer elemento con time 1");
    mu_assert(eis->first->pid == 'A', "La lista de instantes tiene primer elemento con pid A");
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_empty);
    mu_run_test(test_has_instant_with_time_1_and_pid_A);
    return NULL;
}

RUN_TESTS(all_tests);
