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
int isNewQueue(Queue);
Queue enQueue(Queue, Elem);
Elem Front(Queue);
void unQueue(Queue);
void printQueue(Queue);