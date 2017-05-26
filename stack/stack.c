#include <stack.h>
#include <stdlib.h>

Stack empty()
{
    return NULL;
}

void push(Stack *s, Elem e)
{
    Stack t = (Stack)malloc(sizeof(struct node));
    t->dato = e;
    t->next = *s;
    *s = t;
}

int isEmpty(Stack s)
{
    return s == NULL;
}

int top(Stack s)
{
    return s->dato;
}

Stack pop(Stack s)
{
    return s->next;
}