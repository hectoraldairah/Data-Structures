#pragma once
#include <elem.h>

typedef struct nodo
{
    Elem dato;
    struct nodo *sig;
} * Lista;

Lista vacia();
Lista cons(Elem, Lista);
int esVacia(Lista);
Elem cabeza(Lista);
Lista resto(Lista);
void impLista(Lista);
Lista pegaListas(Lista, Lista);
Lista invierteLista(Lista);
Lista insOrden(Elem, Lista);
Lista ordenaLista(Lista);