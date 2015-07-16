#include "../lib/minunit.h"
#include "../src/int_list.c"

char *test_empty(){
    IntList *il = create_int_list();
    mu_assert(int_list_empty(il), "La lista de enteros esta vacia");
    return NULL;
}

char *test_has_int_1(){
    IntList *il = create_int_list();
    int_list_add(il, 1);
    mu_assert(il->first->i == 1, "La lista de enteros tiene al elemento 1");
    return NULL;
}

char *all_tests() {
    mu_suite_start();
    mu_run_test(test_empty);
    mu_run_test(test_has_int_1);
    return NULL;
}

RUN_TESTS(all_tests);
