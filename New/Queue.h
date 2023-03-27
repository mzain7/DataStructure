#include <iostream>
#include "LinkedList.h"
template <typename T>
class Queue
{
private:
    LinkedList<T> list;

public:
    Queue(/* args */);
    ~Queue();
    void enqueue(T value);
    T dequeue();
    bool isEmpty();
    // Node* is();
};
template <typename T>

Queue<T>::Queue(/* args */)
{
}
template <typename T>

Queue<T>::~Queue()
{
}

template <class T>
void Queue<T>::enqueue(T value)
{
    list.addAtStart(value);
}
template <class T>
T Queue<T>::dequeue()
{
    return list.deleteAtEnd();
}

template <class T>
bool Queue<T>::isEmpty()
{
    return list.size ==0;
}