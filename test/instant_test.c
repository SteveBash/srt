#include "../lib/minunit.h"
#include "../src/instant.c"

char *test_asdf(){
    Instant clock[100];	
    init_instants(clock, 100);
    add_instant(clock, 'A', 0);
    add_instant(clock, 'B', 1);
    add_instant(clock, 'C', 2);
    mu_assert(clock[0].pid=='B', "ctm");
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_asdf);
    return NULL;
}

RUN_TESTS(all_tests);
