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
    node *new = (node*)malloc(sizeof(node));
    new->data = x;
    new->next = s->head;
    s->head = new;
}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
    /* pre-condition: stack must not be empty */
    assert(s->head != NULL);

    /* post-condition: top item is removed and returned */
    int val = s->head->data; // Saves the top value (to return)
    node *p = s->head; // Saves the top address (to free)
    s->head = s->head->next;// Head points to the new top node
    free(p); // Frees the old top node

    return val;
}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    /* pre-condition: true */
    /* post-condition: Returns true if stack is full, false otherwise */
    
    // This is a linked list stack. 
    // There is no limit on the number of nodes there can be. 
    // The stack can't be full so alwasy retursn false
    return false;
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    /* pre-condition: true */
    /* post-condition: returns true if stack is empty, false otherwise */

    return (s->head == NULL);
    
/*     
    if (s->head == NULL)
        return true;
    else
        return false; 
*/
}

/* Print the contents of the stack */
void print(stack *s)
{
    /* pre-condition: true */
    /* post-condition: prints all items in the stack */

    for (node *p = s->head; p != NULL; p = p->next) {
        printf("%d\n", p->data);
    }
}
