#include <stack.h>
#include <stdlib.h>

Stack empty()
{
    return NULL;
}

Stack push(Stack *s, Elem e)
{
    Stack t = (Stack)malloc(sizeof(struct node));
    t->dato = e;
    t->sig = *s;
    *s = t;
}

int isEmpty(Stack s)
{
    return s == NULL;
}

Stack top(Stack s)
{
    return s->dato;
}

Stack pop(Stack s)
{
    return s->sig;
}