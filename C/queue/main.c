#include <stdio.h>
#include <queue.h>

int main()
{
    Queue a = newQueue();
    a = enQueue(enQueue(enQueue(enQueue(a,1),2),3),4);
    printQueue(a);
    return 0;
}