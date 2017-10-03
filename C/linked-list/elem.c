#include <elem.h>
#include <stdio.h>

void impElem(Elem e)
{
    printf("%d \n", e);
}

int isSmaller(Elem e1, Elem e2)
{
    if (e1 < e2)
        return e1;
}

int areEqual(Elem e1, Elem e2)
{
    if (e1 == e2)
        return 1;
}
