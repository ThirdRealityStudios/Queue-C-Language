#include "queue.h"

#ifndef DEFAULT_LIBS
    #define DEFAULT_LIBS
    #include <stdio.h>
    #include <stdlib.h>
#endif

#define DEBUG 1

struct queue
{
    struct node *head, *tail;
    int size;
};

struct node
{
    int value;
    struct node *next;
};

void printTest(char *functionName, int testOK)
{
    printf("[INFO]: Test for \"%s\": %s\n", functionName, testOK ? "OK" : "Failed");
}

/*
 * Tests the given function and returns 1 if everything is OK. Otherwise 0.
 * Pass 1 as an argument to print additional debug information on testing.
 */
int testEmpty()
{
    int ok = 1;

    struct queue *queue = create();

    ok &= empty(queue) == 1;

    if(DEBUG)
    {
        printTest("ok &= empty(queue) == 1", ok);
    }

    free(queue);

    queue = NULL;

    if(DEBUG)
    {
        puts("=>");
    }

    return ok;
}

/*
 * Tests the given function and returns 1 if everything is OK. Otherwise 0.
 * Pass 1 as an argument to print additional debug information on testing.
 */
int testCreate()
{
    int ok = 1;

    struct queue *test = NULL;

    test = create();

    ok &= (test != NULL);

    if(DEBUG)
    {
        printTest("ok &= (test != NULL)", ok);
    }

    free(test);
    test = NULL;

    if(DEBUG)
    {
        puts("=>");
    }

    return ok;
}

/*
 * Tests the given function and returns 1 if everything is OK. Otherwise 0.
 * Pass 1 as an argument to print additional debug information on testing.
 */
int testEnqueue()
{
    int ok = 1;

    struct queue *test = create();

    ok &= test -> size == 0;

    if(DEBUG)
    {
        printTest("ok &= test -> size == 0", ok);
    }

    enqueue(test, 0);

    ok &= test -> size == 1;

    if(DEBUG)
    {
        printTest("ok &= test -> size == 1", ok);
    }

    enqueue(test, 1);

    ok &= test -> size == 2;

    if(DEBUG)
    {
        printTest("ok &= test -> size == 2", ok);
    }

    enqueue(test, 2);

    ok &= test -> size == 3;

    if(DEBUG)
    {
        printTest("ok &= test -> size == 3", ok);
    }

    free(test);
    test = NULL;

    if(DEBUG)
    {
        puts("=>");
    }

    return ok;
}

/*
 * Tests the given function and returns 1 if everything is OK. Otherwise 0.
 * Pass 1 as an argument to print additional debug information on testing.
 */
int testDequeue()
{
    int ok = 1;

    struct queue *test = create();

    enqueue(test, 0);
    enqueue(test, 1);
    enqueue(test, 2);

    dequeue(test);
    ok &= test -> size == 2;

    if(DEBUG)
    {
        printTest("ok &= test -> size == 2", ok);
    }

    dequeue(test);
    ok &= test -> size == 1;

    if(DEBUG)
    {
        printTest("ok &= test -> size == 1", ok);
    }

    dequeue(test);
    ok &= test -> size == 0 && test -> head == NULL && test -> tail == NULL;

    if(DEBUG)
    {
        printTest("ok &= test -> size == 0 && test -> head == NULL && test -> tail == NULL", ok);
    }

    dequeue(test);
    ok &= test -> size == 0 && test -> head == NULL && test -> tail == NULL;

    if(DEBUG)
    {
        printTest("dequeue(test) again on empty queue", ok);
    }

    ok &= empty(test);

    if(DEBUG)
    {
        printTest("empty(test)", ok);
    }

    free(test);
    test = NULL;

    if(DEBUG)
    {
        puts("=>");
    }

    return ok;
}

/*
 * Tests the given function and returns 1 if everything is OK. Otherwise 0.
 * Pass 1 as an argument to print additional debug information on testing.
 */
int testPrintQueue()
{
    struct queue *test = create();

    enqueue(test, 0);
    enqueue(test, 1);
    enqueue(test, 2);

    if(DEBUG)
    {
        puts("I. Enqueing (0), (1) and (2) to an empty queue looks like this:");
    }

    printQueue(test);

    dequeue(test);
    dequeue(test);

    if(DEBUG)
    {
        puts("");
        puts("II. Dequeing two elements looks like this:");
    }

    printQueue(test);

    dequeue(test);

    if(DEBUG)
    {
        puts("");
        puts("III. Dequeing one element looks like this:");
    }

    printQueue(test);

    dequeue(test);

    if(DEBUG)
    {
        puts("");
        puts("IV. Dequeing one element looks like this:");
    }

    printQueue(test);

    free(test);
    test = NULL;

    if(DEBUG)
    {
        puts("=>");
    }

    return 1;
}
