#include <iostream>
#include "Stack.h"
#include "Deque.h"
#include "QueueL.h"
int main(int argc, char const *argv[])
{

    Queue<int> queue;
    queue.enqueue(4);
    queue.display();
    queue.enqueue(1);
    queue.enqueue(8);
    queue.display();
    queue.enqueue(6);
    queue.enqueue(3);
    queue.display();



    queue.dequeue();
    queue.display();
    queue.dequeue();
    queue.display();
    queue.dequeue();
    queue.display();
    queue.dequeue();
    queue.display();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    queue.display();


    // Stack<int> stack;
    // Queue<int> queue;
    // queue.enqueue(3, 3);
    // queue.display();
    // queue.enqueue(8, 8);
    // queue.display();
    // queue.enqueue(1 , 1);
    // queue.display();
    // queue.enqueue(7, 7);
    // queue.display();
    // queue.enqueue(2, 2);

    // Dequeue<int> queue;
    // queue.enqueue_front(3);
    // queue.enqueue_front(4);
    // queue.enqueue_back(2);
    // queue.enqueue_back(6);

    // queue.display();

    // queue.dequeue_front();
    // queue.display();
    // queue.dequeue_back();
    // queue.display();
    // queue.enqueue_back(queue.dequeue_front());
    // queue.display();
    // // queue.dequeue_front();
    // // queue.display();
    // // queue.dequeue_back();
    // // queue.display();



    // queue.display();

    // // queue.dequeue();
    // queue.display();
    // queue.dequeue();
    // queue.display();
    // queue.dequeue();
    // queue.display();
    // queue.dequeue();
    // queue.display();
    // queue.dequeue();
    // queue.display();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.display();
    // queue.dequeue();
    // queue.dequeue();

    // queue.display();
    // queue.dequeue();

    return 0;
}
