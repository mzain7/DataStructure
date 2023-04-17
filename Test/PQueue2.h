#include <iostream>
template <typename T>
class Queue
{
private:
    int front = -1, back = -1, size = 0;
    T *queue;
    int *priority;

public:
    Queue(int size = 10)
    {
        this->size = size;
        this->priority = new int[size];
        this->queue = new T[size];
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
        for(int i = back; i>=0; i--)
        {
            if(priority[i]<pri)
            {
                priority[i+1]=priority[i];
                queue[i+1]= queue[i];
            }else
            {
                priority[i+1]= pri;
                queue[i+1]= value;
                back++;
                return;
            }
        }
        priority[0]= pri;
        queue[0]= value;
        back++;
        return;
        
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
        return queue[back--];
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
        return queue[back];
    }
}

template <class T>
void Queue<T>::display()
{
    int temp = 0;
    while (temp <= back)
    {
        std::cout << queue[temp];
        temp++;
    }
    std::cout << std::endl;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return back == -1;
}

template <class T>
bool Queue<T>::isFull()
{
    return back + 1 == size;
}

template <class T>
int Queue<T>::findMin()
{
    int min = priority[0], index = 0;
    for (int i = front; i <= back; i++)
    {
        if (priority[i] < min)
        {
            min = priority[i];
            index = i;
        }
    }

    return index;
}