#include <elem.h>

typedef struct node
{
    Elem value;
    struct node *next;
} * Stack;

Stack empty();
void push(Stack *, Elem);
int isEmpty(Stack);
int top(Stack);
Stack pop(Stack);