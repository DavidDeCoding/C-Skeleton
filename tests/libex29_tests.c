#include "minunit.h"

char *test_dlopen()
{
    lib = dlopen(lib_file, RTLD_NOW);
    mu_assert(lib != NULL, "Failed to open the library to test.");
    
    return NULL;
}

char *test_functions()
{
    mu_assert(check_function("print_a_message", "Hello", 0), "print_a_message failed.");
    mu_assert(check_function("uppercase", "Hello", 0), "uppercase failed.");
    mu_assert(check_function("lowercase", "Hello", 0), "lowercase failed.");
    
    return NULL;
}

char *test_failures()
{
    int rc = dlclose(lib);
    mu_assert(rc == 0, "Failed to close lib.");
    
    return NULL;
}

char *test_dlclose()
{
    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_dlopen);
    mu_run_test(test_functions);
    mu_run_test(test_failures);
    mu_run_test(test_dlclose);

    return NULL;
}

RUN_TESTS(all_tests);
