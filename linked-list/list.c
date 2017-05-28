#include <list.h>
#include <stdlib.h>

List empty()
{
    return NULL;
}

List cons(Elem e, List l)
{
    List t = (List)malloc(sizeof(struct node));
    t->dato = e;
    t->next = l;
    return t;
}

int isEmpty(List l)
{
    return l == NULL;
}

Elem head(List l)
{
    return l->dato;
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

List unionLists(List l1, List l2)
{
    return isEmpty(l1) ? l2 : cons(head(l1), unionLists(rest(l1), l2));
}

List reverseList(List l)
{
    if (isEmpty(l))
        return l;
    else
        return unionLists(reverseList(rest(l)), cons(head(l), empty()));
}

List insOrd(Elem e, List l)
{
    if (isEmpty(l))
        return cons(e, l);
    else if (isSmaller(e, head(l)))
        return cons(e, l);
    else
        return cons(head(l), insOrd(e, rest(l)));
}

List sortList(List l)
{
    if (isEmpty(l))
        return l;
    else
        return insOrd(head(l), sortList(rest(l)));
}
