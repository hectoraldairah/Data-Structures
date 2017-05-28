#pragma once
#include <elem.h>

typedef struct node
{
    Elem dato;
    struct node *next;
} * List;

List empty();
List cons(Elem, List);
int isEmpty(List);
Elem head(List);
List rest(List);
void impList(List);
List unionLists(List, List);
List reverseList(List);
List insOrd(Elem, List);
List sortList(List);