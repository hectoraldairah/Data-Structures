#pragma once
#include <arbin.h>
#include <lista.h>

typedef Arbin Heap;

int esCompleto(Arbin);
int esLleno(Arbin);
Arbin hazCompleto(Elem, Arbin);
Heap hazHeap(Elem, Heap, Heap);
Heap consHeap(Arbin);
Arbin insElems(Lista, Arbin);
int esHoja(Arbin);
Elem masDerecho(Arbin);
Arbin eliminaDerecho(Arbin);
Lista heapSort(Lista, Heap);
