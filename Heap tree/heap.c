#include <heap.h>

typedef Arbin Heap;

int esCompleto(Arbin a)
{
    if (0 <= (Altura(Izq(a)) - Altura(Der(a)) <= 1) && esCompleto(Izq(a)) && esCompleto(Der(a)))
        return 1;
}

int esLleno(Arbin a)
{
    if ((Altura(Izq(a)) == Altura(Der(a))) && esLleno(Der(a)) && esLleno(Der(a)))
        return 1;
}

Arbin hazCompleto(Elem e, Arbin a)
{
    if ((Altura(Izq(a)) == (Altura(Der(a)) + 1)) && esLleno(Izq(a)) || ((Altura(Izq(a)) == Altura(Der(a))) && !esLleno(Der(a))))
        return Cons(Raiz(a), Izq(a), hazCompleto(e, Der(a)));
}

Heap hazHeap(Elem e, Heap i, Heap d)
{
    if (EsVacio(d))
    {
        if (e >= Raiz(i))
            return Cons(e, i, d);
        else
            return Cons(Raiz(i), Cons(e, Vacio(), Vacio()), Vacio());
    }
    if (e > Raiz(i) && e > Raiz(d))
        return Cons(e, i, d);
    else if (Raiz(i) >= Raiz(d))
        return Cons(Raiz(i), hazHeap(e, Izq(i), Der(i)), d);
    else
        return Cons(Raiz(d), i, hazHeap(e, Izq(d), Der(d)));
}

Heap consHeap(Arbin a)
{
    if (EsVacio(a))
        return a;
    else if ((Altura(Izq(a)) - Altura(Der(a))) <= 1)
        return hazHeap(Raiz(a), consHeap(Izq(a)), consHeap(Der(a)));
}

Arbin insElems(Lista l, Arbin a)
{
    if (esVacia(l))
        return a;
    else
        return InsElems(resto(l), hazCompleto(cabeza(l), a));
}

int esHoja(Arbin a)
{
    if (EsVacio(Izq(a)) && EsVacio(Der(a)))
        return 1;
}

Elem masDerecho(Arbin a)
{

    if (esHoja(a))
        return Raiz(a);
    if (esLleno(a))
        return masDerecho(Der(a));
    if ((Altura(Izq(a))) == (Altura(Der(a)) + 1))
        return masDerecho(Izq(a));

    else if ((Altura(Izq(a))) == (Altura(Der(a))))
        return masDerecho(Der(a));
}

Arbin eliminaDerecho(Arbin a)
{
    if (EsVacio(a))
        return a;
    if (esHoja(a))
        return a = Vacio();

    if ((Altura(Izq(a))) == (Altura(Der(a)) + 1))
        return eliminaDerecho(Izq(a));

    else if ((Altura(Izq(a))) == (Altura(Der(a))))
        return eliminaDerecho(Der(a));
}

Lista heapSort(Lista l, Heap h)
{
    if (!EsVacio(h))
    {

        if (esHoja(h))
        {
            l = cons(Raiz(h), l);
            h = Vacio();
            return l;
        }
        else
        {
            l = cons(Raiz(h), l);
            h = eliminaDerecho(hazHeap((masDerecho(h)), Izq(h), Der(h)));
            return l;
        }
    }
}