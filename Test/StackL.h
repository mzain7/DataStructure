#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next = nullptr;
};

template <typename T>
class Stack
{
private:
    Node<T> *head;

public:
    Stack()
    {
        this->head = nullptr;
    }
    ~Stack() {}
    void push(T data);
    T pop();
    T peek();
    void display();
    bool isEmpty();
};

template <class T>
bool Stack<T>::isEmpty()
{
    return head == nullptr;
}

template <class T>
void Stack<T>::push(T data)
{
    Node<T> *node = new Node<T>;
    node->data = data;

    if (isEmpty())
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
T Stack<T>::pop()
{
    Node<T> *temp = head;
    head = head->next;
    T data = temp->data;
    delete temp;
    return data;
}

template <class T>
T Stack<T>::peek()
{
    return head->data;
}

template <class T>
void Stack<T>::display()
{
    Node<T> *temp = head;
    while(temp != nullptr)
    {
        std::cout<< temp->data <<std::endl;
        temp = temp->next;
    }
}