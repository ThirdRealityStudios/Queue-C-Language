#include "test.h"

#ifndef DEFAULT_LIBS
    #define DEFAULT_LIBS
    #include <stdio.h>
    #include <stdlib.h>
#endif

int main(int args, char **argv)
{
    puts("");
    puts("");
    puts("Testing implementation:");
    puts("-----------------------");
    puts("");
    puts("");

    printTest("create", testCreate());
    puts("");
    puts("");

    printTest("empty", testEmpty());
    puts("");
    puts("");

    printTest("enqueue", testEnqueue());
    puts("");
    puts("");

    printTest("dequeue", testDequeue());
    puts("");
    puts("");

    printTest("printQueue", testPrintQueue());
    puts("");
    puts("");

    return 1;
}
