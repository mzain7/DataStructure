#include <iostream>
// #include "QueueA.h"
#include "PriorityQueueA.h"
int main(int argc, char const *argv[])
{
    // QueueA<int> queue(20);
    PriorityQueueA<int> queue(20);

    queue.enqueue(1,1);
    queue.enqueue(3,3);
    queue.enqueue(0,0);

    std::cout<<queue.display()<<std::endl;

    queue.dequeue();
    queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();

    std::cout<<queue.display();
    return 0;
}
