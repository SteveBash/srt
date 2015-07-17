#include "../lib/minunit.h"
#include "../src/gantt_charter.c"

char *test_chart(){
    ExecutionInstants *eis = create_execution_instants();
    execution_instant_add(eis, 'A', 0);
    execution_instant_add(eis, 'B', 1);
    execution_instant_add(eis, 'C', 2);
    construct_gantt_chart(eis);
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_chart);
    return NULL;
}

RUN_TESTS(all_tests);
