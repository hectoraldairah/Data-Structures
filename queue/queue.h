#include <elem.h>

typedef struct Node
{
    Elem value;
    struct Node *next;
} * ApNode;

typedef struct qNode
{
    ApNode first;
    ApNode last;
}* Queue;

Queue newQueue();
int isNewQueue(Queue q);
Queue enQueue(Queue q, Elem e);
Elem Front(Queue);
void unQueue(Queue q);
void printQueue(Queue q);