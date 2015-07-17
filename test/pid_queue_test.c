#include "../lib/minunit.h"
#include "../src/pid_queue.c"

char *test_empty(){
    PidQueue *q= create_queue();
    mu_assert(queue_empty(q), "La cola esta vacia");
    return NULL;
}

char *test_copy_works(){
    PidQueue *q= create_queue();
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    PidQueue *copy_q = copy(q);
    mu_assert(dequeue(copy_q) == 'A', "La cola copiada tiene al pid A");
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_empty);
    mu_run_test(test_copy_works);
    return NULL;
}

RUN_TESTS(all_tests);
