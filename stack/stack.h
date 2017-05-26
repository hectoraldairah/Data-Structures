#include <elem.h>

typedef struct node
{
    Elem dato;
    struct node *sig;
} * Stack;