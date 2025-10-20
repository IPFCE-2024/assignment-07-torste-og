#include "stack.h"
#include <assert.h>

int main(void)
{
    stack s;
    initialize(&s);
    assert(empty(&s));

    push(10, &s);
    int y = pop(&s);
    assert(empty(&s));
    assert(y == 10);

    push(5, &s);
    push(7, &s);
    int y0 = pop(&s);
    int y1 = pop(&s);
    assert(empty(&s));
    assert(y0 == 7 && y1 == 5);

    printf("All stack tests passed.\n");
    return 0;
}