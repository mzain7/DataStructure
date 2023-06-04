#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

#include <iostream>
template <typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr;
};
template <typename T>
class Queue
{
private:
    Node<T> *head = nullptr;

public:
    Queue();
    ~Queue();
    void enqueue(T value);
    T dequeue();
    T front();
    bool isEmpty();
    void reverse();
    void display();
    T secondFront();
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
    if (head == nullptr)
    {
        std::cout << "Empty!!";
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        T data = temp->data;
        return data;
    }
}

template <class T>
T Queue<T>::front()
{
    if (head == nullptr)
    {
        std::cout << "Empty!!";
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        return temp->data;
    }
}

template <class T>
bool Queue<T>::isEmpty()
{
    return head == nullptr;
}

template <class T>
void Queue<T>::display()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

template <class T>
void Queue<T>::reverse()
{
    Node<T> *current = head, *previous = nullptr, *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}


template <class T>
T Queue<T>::secondFront()
{
    if (head == nullptr)
    {
        std::cout << "Empty!!";
    }
    else
    {
        Node<T> *temp = head;
        while ((temp->next)->next != nullptr)
        {
            temp = temp->next;
        }

        return temp->data;
    }
}

#pragma GCC diagnostic pop
