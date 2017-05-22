#include <lista.h>
#include <stdlib.h>

Lista vacia()
{
    return NULL;
}

Lista cons(Elem e, Lista l)
{
    Lista t = (Lista)malloc(sizeof(struct nodo));
    t->dato = e;
    t->sig = l;
    return t;
}

int esVacia(Lista l)
{
    return l == NULL;
}

Elem cabeza(Lista l)
{
    return l->dato;
}

Lista resto(Lista l)
{
    return l->sig;
}

void impLista(Lista l)
{
    if (!esVacia(l))
    {
        do
        {
            impElem(cabeza(l));
            impLista(resto(l));
        } while (esVacia(l));
    }
}