#include <iostream>
template <typename T>
class Dequeue
{
private:
    int front = -1, back = -1, size = 0;
    T *queue;

public:
    Dequeue(int size = 5)
    {
        this->size = size;
        this->queue = new T[size];
    }
    void enqueue_front(T data)
    {
        if (isFull())
        {
            std::cout << "FULL!";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
                back = 0;
            }
            else if (front == 0)
            {
                front = size - 1;
            }
            else
            {
                front--;
            }
            queue[front] = data;
        }
    }
    void enqueue_back(T data)
    {
        if (isFull())
        {
            std::cout << "FULL!";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
                back = 0;
            }
            else if (back == size - 1)
            {
                back = 0;
            }
            else
            {
                back++;
            }
            queue[back] = data;
        }
    }
    T dequeue_front()
    {
        if (isEmpty())
        {
            std::cout << "EMPTY!";
        }
        else
        {
            T data = queue[front];
            if (front == back)
            {
                front = -1;
                back = -1;
            }
            else if (front == size - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
            return data;
        }
    }
    T dequeue_back()
    {
        if (isEmpty())
        {
            std::cout << "EMPTY!";
        }
        else
        {
            T data = queue[back];
            if (front == back)
            {
                front = -1;
                back = -1;
            }
            else if (back == 0)
            {
                back = size - 1;
            }
            else
            {
                back--;
            }
            return data;
        }
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return front == (back + 1) % size;
    }

    void display()
    {
        if (!isEmpty())
        {
            int temp = front;
            while (temp != (back+1)%size)
            {
                std::cout << queue[temp];
                temp = (temp + 1) % size;
            }
            std::cout<<std::endl;
        }
    }
};
