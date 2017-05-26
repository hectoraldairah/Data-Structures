#include <elem.h>
#include <stdio.h>

void printElem(Elem e)
{
    printf("%d \n", e);
}

int isSmaller(Elem e1, Elem e2)
{
   return e1 < e2;
}
