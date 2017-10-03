#pragma once
#include <elem.h>

typedef struct Nodo
{
    Elem dato;
    struct Nodo* izq;
    struct Nodo* der;
} *Arbin;

Arbin Vacio();

Arbin Cons(Elem, Arbin, Arbin);

int EsVacio(Arbin);

Elem Raiz(Arbin);

Arbin Izq(Arbin);

Arbin Der(Arbin);

int NumElem(Arbin);

void ImpInOrd(Arbin);

int Max(int, int);

int Altura(Arbin);