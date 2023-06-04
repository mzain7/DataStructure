
#include <iostream>
template <class T>
class Stack
{
private:
    int size, top = 0;
    T *stack;

public:
    Stack(int size = 10)
    {
        this->size = size;
        this->top = -1;
        this->stack = new T[size];
    }
    ~Stack()
    {
        delete stack;
    }

    bool push(T val)
    {
        if (isFull())
        {
            std::cout << "Full!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            return false;
        }
        else
        {
            stack[++top] = val;
            return true;
        }
    }

    T pop()
    {
        if (isEmpty())
        {
            std::cout << "Empty!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            return 0;
        }
        else
        {
            return stack[top--];
        }
    }

    T peek()
    {
        if (isEmpty())
        {
            std::cout << "Empty!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            return 0;
        }
        else
        {
            return stack[top];
        }
    }

    std::string display()
    {
        int temp = top;
        std::string toString = "{";
        while (temp != -1)
        {
            toString += stack[temp] + " ,";
            temp--;
        }

        toString += "}";
        return toString;
    }


    bool isFull()
    {
        return top + 1 == size;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};
