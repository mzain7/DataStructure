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
    Node<T> *node = new Node<T>;
    node->data = value;

    node->next = head;
    head = node;

}

template <class T>
std::string StackLL<T>::display()
{
    std::string output = "";
    Node<T> *temp = head;
    while(temp != nullptr){
        output += std::to_string(temp->data) + ", ";
        temp = temp->next;
    }

    return output;
}

template <class T>
T StackLL<T>::peek()
{
    if(isEmpty()){
        std::cout<< "Empty!";
        return NULL;
    }
    return head->data;
}
template <class T>
T StackLL<T>::pop()
{
    if(isEmpty()){
        std::cout<< "Empty!";
        return 0;
    }
    Node<T> *temp = head;
    T value = temp->data;
    head = head->next;
    delete temp;
    return value;
}

template <class T>
bool StackLL<T>::isEmpty()
{
    return this->head == nullptr;
}