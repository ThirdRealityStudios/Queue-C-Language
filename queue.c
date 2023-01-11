#ifndef NO_ELEMENT
    #define NO_ELEMENT -1
#endif

#ifndef ELEMENT_PRINT_WIDTH
    #define ELEMENT_PRINT_WIDTH 4
#endif

#ifndef DEFAULT_LIBS
    #define DEFAULT_LIBS
    #include <stdio.h>
    #include <stdlib.h>
#endif

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

/*
 * Creates an empty queue.
 */
struct queue* create()
{
    struct queue *new = calloc(1, sizeof(struct queue));

    return new;
}

/*
 * Returns 1 if the queue is simply empty, otherwise 0.
 */
int empty(struct queue *queue)
{
    return queue -> size == 0;
}

/*
 * Enqueues a value to the queue.
 */
void enqueue(struct queue *queue, int value)
{
    struct node *node = calloc(1, sizeof(struct node));
    node -> value = value;

    if(queue -> size == 0)
    {
        queue -> head = node;
        queue -> tail = node;
        queue -> size++; // = 1
    }
    else
    {
        node -> next = queue -> tail;
        queue -> tail = node;
        queue -> size++;
    }
}

/*
 * Dequeues a node from the queue.
 * Does not perform any action if the queue is empty (no error).
 */
void dequeue(struct queue *queue)
{
    struct node *current = NULL;

    if(queue -> size > 1)
    {
        current = queue -> tail;

        // Look for the new head element.
        while(current -> next != queue -> head)
        {
            current = current -> next;
        }

        free(current -> next); // so the head is meant..
        current -> next = NULL;

        queue -> head = current; // aquire a new head.

        queue -> size--;
    }
    else // if queue only has 1 element.
    {
        free(queue -> tail);

        queue -> tail = NULL;
        queue -> head = NULL;

        queue -> size = 0;
    }
}

/*
 * Prints the given queue graphically
 */
void printQueue(struct queue *queue)
{
    struct node *current = queue -> tail;

    if(queue -> size == 0)
    {
        puts("Simply empty. Nothing to show.");
    }
    else
    {
        for(int index = 0; index < queue -> size; index++)
        {
            printf("(%d.)[ %*d ] -> ", index + 1, ELEMENT_PRINT_WIDTH, current -> value);

            current = current -> next;
        }

        puts("");
    }
}
