#include <queue.h>
#include <elem.h>
#include <stdlib.h>

Queue newQueue()
{
    Queue newq = (Queue)malloc(sizeof(struct qNode));
    newq->first = newq->last = NULL;
    return newq;
}

int isNewQueue(Queue q)
{
    return q->first == NULL;
}

Queue enQueue(Queue q, Elem e)
{
	ApNode nodo = (ApNode)malloc(sizeof(struct Node));
	nodo->value = e;
	nodo->next = NULL;
	if (isNewQueue(q))
	{
		q->first = nodo;
		q->last = nodo;
	}
	else
	{
		q->last->next = nodo;
		q->last = nodo;
	}
	return q;
}

Elem Front(Queue q)
{
	return q->first->value;
}

void unQueue(Queue q)
{
	if (isNewQueue(q))
	{
		return;
	}
	ApNode temp = q->first;
	if (q->first == q->last)
	{
		q->first = q->last = NULL;
		return;
	}

	q->first = q->last->next;

	free(temp);
}

void printQueue(Queue q)
{
	ApNode frt = q->first;
	while( frt != NULL)
	{
		printElem(frt->value);
		frt = frt->next;
	}
}