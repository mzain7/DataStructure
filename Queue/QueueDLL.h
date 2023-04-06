#include <iostream>
template <typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
};
template <typename T>
class Queue
{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

public:
    Queue();
    ~Queue();
    void enqueue(T value);
    T dequeue();
    T front();
    bool isEmpty();
};

template <class T>
Queue<T>::Queue()
{
}

template <class T>
Queue<T>::~Queue()
{
}

template <class T>
void Queue<T>::enqueue(T value)
{
    Node<T> *node = new Node<T>;
    node->data = value;

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}

template <class T>
T Queue<T>::dequeue()
{
    if (tail == nullptr)
    {
        return NULL;
    }
    else
    {
        Node<T> *node = tail;
        T data = node->data;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;

            tail->next = nullptr;
        }

        delete node;

        return data;
    }
}

template <class T>
T Queue<T>::front()
{
    if (tail == nullptr)
    {
        return NULL;
    }
    else
    {
        return tail->data;
    }
}

template <class T>
bool Queue<T>::isEmpty()
{
    return head == nullptr;
}