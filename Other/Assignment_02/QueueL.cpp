#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

#include <iostream>
template <typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr;
};
template <typename T>
class Queue
{
private:
    Node<T> *head = nullptr;

public:
    Queue();
    ~Queue();
    void enqueue(T value);
    T dequeue();
    T front();
    bool isEmpty();
    void reverse();
    void display();
    T secondFront();
};

template <class T>
Queue<T>::Queue()
{
}

template <class T>
Queue<T>::~Queue()
{
}

template <class T>
void Queue<T>::enqueue(T value)
{
    Node<T> *node = new Node<T>;
    node->data = value;

    if (head == nullptr)
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
T Queue<T>::dequeue()
{
    if (head == nullptr)
    {
        std::cout << "Empty!!";
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        T data = temp->data;
        delete temp;
        return data;
    }
}

template <class T>
T Queue<T>::front()
{
    if (head == nullptr)
    {
        std::cout << "Empty!!";
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        return temp->data;
    }
}

template <class T>
bool Queue<T>::isEmpty()
{
    return head == nullptr;
}

template <class T>
void Queue<T>::display()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <class T>
void Queue<T>::reverse()
{
    Node<T> *current = head, *previous = nullptr, *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

template <class T>
T Queue<T>::secondFront()
{
    if (head == nullptr)
    {
        std::cout << "Empty!!";
    }
    if (head->next == nullptr)
    {
        std::cout << "No Second Element!";
    }
    else
    {
        Node<T> *temp = head, *prev = nullptr;
        while ((temp->next)->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        return temp->data;
    }
}

int main(int argc, char const *argv[])
{
    Queue<int> queue;

    queue.enqueue(3);
    queue.enqueue(1);
    queue.enqueue(2);

    std::cout << "\nQueue: ";
    queue.display();

    std::cout << "\nReversed Queue: ";
    queue.reverse();
    queue.display();
    std::cout << "\nSecond Element from Front is " << queue.secondFront() << std::endl;
    return 0;
}
#pragma GCC diagnostic pop
