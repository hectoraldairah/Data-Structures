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

Lista pegaListas(Lista l1, Lista l2)
{
    return esVacia(l1) ? l2 : cons(cabeza(l1), pegaListas(resto(l1), l2));

}

Lista invierteLista(Lista l)
{
    if(esVacia(l))
        return l;
    else
        return pegaListas(invierteLista(resto(l)), cons(cabeza(l), vacia()));    
}

Lista insOrden(Elem e, Lista l)
{
    if (esVacia(l))
        return cons(e, l);
    else if (esMenor(e , cabeza(l)))
        return cons(e, l);
    else
        return  cons(cabeza(l), insOrden(e, resto(l))); 
}

Lista ordenaLista(Lista l)
{
    if(esVacia(l))
        return l;
    else 
        return insOrden(cabeza(l), ordenaLista(resto(l)));    
}

int estaEn(Elem e, Lista l)
{
    if(esVacia(l))
        return 0;
    else if(sonIguales(e , cabeza(l)))
        return 1;
    else
        return estaEn(e , resto(l));        
}

Lista duplicaLista(Lista l)
{
    if(esVacia(l))
        return l;
    else
        return cons(cabeza(l) * 2, duplicaLista(resto(l)));        
}
