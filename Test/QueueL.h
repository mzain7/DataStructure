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
    bool isEmpty()
    {
        return head == nullptr;
    }

    void enqueue(T data)
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

    T dequeue()
    {
        T data;
        if (head->next == nullptr)
        {

            data = head->data;
            head = nullptr;
            return data;
        }
        else
        {
            Node<T> *temp = head;
            while ((temp->next)->next != nullptr)
            {
                temp = temp->next;
            }
            data = (temp->next)->data;
            delete temp->next;
            temp->next = nullptr;
            return data;
        }
    }

    T peek()
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data;
            temp = temp->next;
        }

        std::cout<<std::endl;
    }
};