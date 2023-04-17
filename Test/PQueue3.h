#include <iostream>
template <typename T>
struct Node
{
    T data;
    int priority;
};

template <typename T>
class Queue
{
private:
    int front = -1, back = -1, size = 0;
    Node<T> *queue;

public:
    Queue(int size = 10)
    {
        this->size = size;
        this->queue = new Node<T>[size];
    }
    ~Queue() {}
    void enqueue(T value, int priority);
    T dequeue();
    T peek();
    bool isEmpty();
    bool isFull();
    void display();
    int findMin();
};
template <class T>
void Queue<T>::enqueue(T value, int pri)
{
    if (isFull())
    {
        std::cout << "Queue is Full!";
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
        }
        Node<T> node;
        node.data = value;
        node.priority = pri;
        queue[++back] = node;
    }
}
template <class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "EMPTY!";
    }
    else
    {
        int index = findMin();
        T data = queue[index].data;
        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else
        {
            for (int i = index; i < back; i++)
            {
                queue[i] = queue[i + 1];
            }
            back--;
        }
        return data;
    }
}

template <class T>
T Queue<T>::peek()
{
    if (isEmpty)
    {
        std::cout << "EMPTY!";
    }
    else
    {
        int index = findMin();
        return queue[index].data;
    }
}

template <class T>
void Queue<T>::display()
{
    int temp = front;
    while (temp <= back)
    {
        std::cout << queue[temp].data;
        temp++;
    }
    std::cout << std::endl;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return front == -1;
}

template <class T>
bool Queue<T>::isFull()
{
    return back + 1 == size;
}

template <class T>
int Queue<T>::findMin()
{
    int min = queue[0].priority, index = 0;
    for (int i = front; i <= back; i++)
    {
        if (queue[i].priority < min)
        {
            min = queue[i].priority;
            index = i;
        }
    }

    return index;
}