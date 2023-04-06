#include <iostream>
// #include "QueueA.h"
// #include "PriorityQueueA.h"
#include "QueueL.h"
int main(int argc, char const *argv[])
{
    // QueueA<int> queue(20);
    Queue<int> queue;

    queue.enqueue(3);
    queue.enqueue(1);
    queue.enqueue(2);

    queue.display();

    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    queue.reverse();
    queue.display();
    return 0;
}
