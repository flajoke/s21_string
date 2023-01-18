#include <check.h>

#define TESTS_COUNT 1



static const TTest *test[TESTS_COUNT] = {
};

Suite *setup_suite(void) {
    Suite *suite = suite_create("s21_string");
    TCase *core  = tcase_create("Core");

    for (int i = 0; i < TESTS_COUNT; ++i) {
        tcase_add_test(core, test[i]);
    }

    suite_add_tcase(suite, core);

    return suite;
}

int main(void) {
    Suite *suite = setup_suite();
    SRunner *runner = srunner_create(suite); 

    // NOTE(pottluci): "-" outputs to stdout.
    //                  "filename" outputs to 
    //                  a file
    //                       v
    srunner_set_tap(runner, "-"); 

    srunner_run_all(runner, CK_MINIMAL);

    srunner_free(runner);

    return 0;
}
