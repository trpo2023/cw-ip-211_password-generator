#include <stdio.h>

#define CTEST_MAIN

#include "../test_header/ctest.h"

int main(int argc, const char* argv[])
{
    int result = ctest_main(argc, argv);

    return result;
}