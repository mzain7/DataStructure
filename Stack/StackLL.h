#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr;
};

template <typename T>
class StackLL
{
private:
    Node<T> *head = nullptr;
    T *stack;

public:
    int size;
    StackLL(int size = 10)
    {
        this->size = size;
        this->stack = new T[size];
    }
    ~StackLL()
    {
        delete stack;
    }

    void push(T value);
    T pop();
    T peek();
    std::string display();
    bool isEmpty();
};

template <class T>
void StackLL<T>::push(T value)
{
    Node<T> node = new Node<T>;
    node.data = value;

    node.next = head;
    head = node;

}

template <class T>
std::string StackLL<T>::display()
{
    
}

template <class T>
T StackLL<T>::peek()
{
}
template <class T>
T StackLL<T>::pop()
{
}

template <class T>
bool StackLL<T>::isEmpty()
{
    return this->head == nullptr;
}