#include <iostream>

template <typename T>
struct Node
{
    T data;
    int priority = 0;
};

template <typename T>
class PriorityQueueA
{
private:
    Node<T> **queue;
    int front = -1, back = -1, size = 0;

public:
    PriorityQueueA(int size)
    {
        this->size = size;
        this->queue = new Node<T> *[size];
    }
    ~PriorityQueueA()
    {
        delete queue;
    }

    void enqueue(T value, int priority);
    T dequeue();
    std::string display();
    bool isFull();
    bool isEmpty();
    int indexOfMin();
};

template <class T>
void PriorityQueueA<T>::enqueue(T value, int priority)
{
    Node<T> *node = new Node<T>;
    node->data = value;
    node->priority = priority;
    if (isFull())
    {
        std::cout << "queue is full";
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        back = 0;
        queue[back] = node;
    }
    else
    {

        // queue[++back] = node;

        for (int i = back + 1; i > 0; i--)
        {
            if (node->priority > queue[i - 1]->priority)
            {
                queue[i] = queue[i - 1];
            }
            else
            {
                queue[i] = node;
            }
        }

        back++;
    }
}

template <class T>
T PriorityQueueA<T>::dequeue()
{
    int val;
    if (isEmpty())
    {
        std::cout << "queue is empty";
        return -1;
    }
    else
    {
        int index = indexOfMin();
        val = queue[index]->data;
        for (int i = index; i < back; i++)
        {
            queue[i] = queue[i + 1];
        }
    }

    if (front == back)
    {
        front = -1;
        back = -1;
    }
    else
    {
        back--;
    }

    return val;
}

template <class T>
int PriorityQueueA<T>::indexOfMin()
{
    int index = 0;
    for (int i = 0; i != back + 1; i++)
    {
        if (queue[i]->priority < queue[index]->priority)
        {
            index = i;
        }
    }

    return index;
}

template <class T>
std::string PriorityQueueA<T>::display()
{
    std::string output = "";
    if (front == -1)
        return "";
    int temp = front;
    while (temp != back + 1)
    {
        output += std::to_string(queue[temp++]->data) + " ";
    }

    return output;
}

template <class T>
bool PriorityQueueA<T>::isFull()
{
    return back == size;
    ;
}

template <class T>
bool PriorityQueueA<T>::isEmpty()
{
    return front == -1;
}