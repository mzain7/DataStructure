#include <iostream>
template <typename T>
class Queue
{
private:
    int front = -1, back = -1, size = 0;
    T *queue;

public:
    Queue(int size = 10)
    {
        this->size = size;
        this->queue = new T[size];
    }
    ~Queue() {}
    void enqueue(T data);
    T dequeue();
    T peek();
    bool isEmpty();
    bool isFull();
    void display();
};
template <class T>
void Queue<T>::enqueue(T data)
{
    if (isFull())
    {
        std::cout << "Queue is Full!";
    }
    else
    {
        queue[++back] = data;
        if (front == -1)
        {
            front = 0;
        }
    }
}

template <class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue is Empty!";
    }
    else
    {
        T data = queue[front];
        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else
        {
            front++;
        }
        return data;
    }
}

template <class T>
void Queue<T>::display()
{
    if (!isEmpty())
    {
        int temp = front;
        while (temp <= back)
        {
            std::cout << queue[temp];
            temp++;
        }
    }
}
template <class T>
T Queue<T>::peek()
{
    if (isEmpty())
    {
        std::cout << "Queue id Empty!";
    }
    else
    {
        return queue[front];
    }
}
template <class T>
bool Queue<T>::isEmpty()
{
    return front == -1;
}

template <class T>
bool Queue<T>::isFull()
{
    return back == size - 1;
}