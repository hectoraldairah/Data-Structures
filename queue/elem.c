#include <elem.h>
#include <stdio.h>


void printElem(Elem e)
{
    printf("%d", e);
}

int isSmaller(Elem e1, Elem e2)
{
    if (e1 < e2)
        return e1;
}