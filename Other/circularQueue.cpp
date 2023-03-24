#include <iostream>

class CircularQueue
{
public:
    CircularQueue(int size)
    {
        this->size = size;
        front = -1;
        back = -1;
        queuePtr = (int *)calloc(size, sizeof(int));
    }

    bool enqueue(int val)
    {
        if (isFull())
        {
            std::cout << "queue is full";
            return false;
        }
        else
        {
            back = (back + 1) % size;
            *(queuePtr + back) = val;
            if (isEmpty())
            {
                front = 0;
            }
            return true;
        }
    }

    int dequeue()
    {
        int val;
        if (isEmpty())
        {
            std::cout << "queue is empty";
            return NULL;
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
            front = (front + 1) % size;
        }
        return val;
    }

    bool isFull()
    {
        return (back + 1) % size == front;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    int getSize()
    {
        return (size - front + back) % size + 1;
    }

    void display()
    {
    }

private:
    int front;
    int back;
    int size;
    int *queuePtr;
};

int main()
{

    return 0;
}