#include <arbin.h>
#include <stdio.h>
#include <stdlib.h>

Arbin Vacio(){ return NULL;}

Arbin Cons(Elem e, Arbin i, Arbin d)
{
    Arbin t = (Arbin)malloc(sizeof(struct Nodo));
    t->dato = e;
    t->izq = i, t->der = d;
    return t;
}

int EsVacio(Arbin a)
{
    return a == NULL;
}

Elem Raiz(Arbin a)
{
    return a->dato;
}

Arbin Izq(Arbin a)
{
    return a->izq;
}

Arbin Der(Arbin a)
{
    return a->der;
}

int NumElem(Arbin a)
{
    if(EsVacio(a))
        return 0;
    else
        1 + NumElem(Izq(a) + NumElem(Der(a)));    
}

void ImpInOrd(Arbin a)
{
    if(!EsVacio(a))
    {
        ImpInOrd(Izq(a));
        impElem(Raiz(a));
        ImpInOrd(Der(a));
    }

}

int Max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;    
}

int Altura(Arbin a)
{
    if(EsVacio(a))
        return 0;
    else
        return 1 + Max(Altura(Izq(a)), Altura(Der(a)));    
}