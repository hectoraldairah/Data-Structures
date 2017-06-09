#pragma once
#include <elem.h>

typedef struct Nodo
{
    struct parElementos;
    struct Nodo* next;

} * List;

List empty()
{
    return NULL;
}

List cons(Campos e, List t)
{
List l = (List)malloc(sizeof(struct Nodo));
   l->elem = e;
   l->next = t;
   return t;
}

int isEmpty(List l)
{
    return l == NULL;
}

Campos head(List l)
{
    return l->elem
}

List rest(List l)
{
    return l->next;
}

void impList(List l)
{
    if (!isEmpty(l))
    {
        do
        {
            impElem(head(l));
            impList(rest(l));
        } while (isEmpty(l));
    }
}