#include <iostream>
#include "QueueA.h"
int main(int argc, char const *argv[])
{
    QueueA<int> queue(20);

    queue.enqueue(30);
    queue.enqueue(30);
    queue.enqueue(30);
    queue.enqueue(30);
    queue.enqueue(30);
    queue.enqueue(30);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.display();
    return 0;
}
