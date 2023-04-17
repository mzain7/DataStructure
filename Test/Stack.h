#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#include <iostream>

template <typename T>
class Stack
{
private:
    int top = -1;
    int size = 0;
    T *stack;

public:
    Stack(int size = 10)
    {
        this->size = size;
        stack = new T[size];
    }
    ~Stack() {}

    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    void display();
};
template <class T>
void Stack<T>::push(T data)
{
    if (isFull())
    {
        std::cout << "\n Stack is Full!";
    }
    else
    {
        stack[++top] = data;
    }
}

template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "\n Stack is Empty!";
    }
    else
    {
        return stack[top--];
    }
}

template <class T>
T Stack<T>::peek()
{
    if (isEmpty())
    {
        std::cout << "\n Stack is Empty!";
    }
    else
    {
        return stack[top];
    }
}

template <class T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}

template <class T>
bool Stack<T>::isFull()
{
    return top == size - 1;
}

#pragma GCC diagnostic pop
