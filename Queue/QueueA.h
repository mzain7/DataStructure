#include <iostream>
template <class T>
class QueueA
{
private:
    int front;
    int back;
    int size;
    T *queuePtr;

public:
    QueueA(int size)
    {
        this->size = size;
        front = -1;
        back = -1;
        queuePtr = (T *)calloc(size, sizeof(T));
    }

    bool enqueue(int T)
    {
        if (isFull())
        {
            std::cout << "queue is full";
            return false;
        }
        else if (isEmpty())
        {
            front = 0;
            back = 0;
        }
        else
        {
            back++;
        }
        *(queuePtr + back) = val;
        return true;
    }

    int dequeue()
    {
        int val;
        if (isEmpty())
        {
            std::cout << "queue is empty";
            return -1;
        }
        else
        {
            val = *(queuePtr + front);
            *(queuePtr + front) = 0;
        }

        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else
        {
            front = front + 1;
        }
        return val;
    }

    bool isFull()
    {
        return back == size;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        int temp = front;
        std::cout << std::endl;
        while (true)
        {
            std::cout << *(queuePtr + temp) << " ";
            if (temp == back)
            {
                break;
            }
            temp = (temp + 1) % size;
        }
    }
};