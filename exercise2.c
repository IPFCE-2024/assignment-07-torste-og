/*
 * Exercise 2: Stack Implementation using Linked List
 * Assignment 7 - IPFCE 2025
 * 
 * Implement all the stack functions declared in include/stack.h
 * The stack should be implemented using a linked list structure.
 * 
 * Functions to implement:
 * - initialize: Create an empty stack
 * - push: Insert an item at the top of the stack
 * - pop: Remove and return the top item
 * - full: Check if stack is full (always false for linked list)
 * - empty: Check if stack is empty
 * - print: Print all items in the stack
 */

#include "stack.h"

/* Create an empty stack */
void initialize(stack *s)
{
    /* pre-condition: true */
    /* post-condition: stack is empty */

    s->head = NULL;
}

/* Insert item x at the top of stack s */
void push(int x, stack *s)
{
    /* pre-condition: true (linked list can always accept more items) */
    /* post-condition: x is added to top of stack */

    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Couldn't allocate memory in push()\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = x;
    new_node->next = s->head;
    s->head = new_node;
}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
  /* pre-condition: stack must not be empty */
  /* post-condition: top item is removed and returned */

  if (empty(s)) {
        fprintf(stderr, "Can't pop from an empty stack\n");
        exit(EXIT_FAILURE);
    }

    node *temp = s->head;
    int value = temp->data;
    s->head = temp->next;
    free(temp);
    return value;
}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    /* pre-condition: true */
    /* post-condition: Returns true if stack is full, false otherwise */
    
    node *test = malloc(sizeof(node));
    if (test == NULL)
        return true;

    free(test);
    return false;
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    /* pre-condition: true */
    /* post-condition: returns true if stack is empty, false otherwise */

    return s->head == NULL;
}

/* Print the contents of the stack */
void print(stack *s)
{
    /* pre-condition: true */
    /* post-condition: prints all items in the stack */

    node *current = s->head;
    printf("Stack contents (top to bottom): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
