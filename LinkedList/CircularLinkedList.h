#include <iostream>

template <typename T>
class CircularLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next = nullptr;
    };

    Node *head;
    Node *tail;
    int size;

public:
    CircularLinkedList(/* args */) {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~CircularLinkedList() {}

    void addAtStart(T value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (this->head == nullptr)
        {
            head = newNode;
            head->next = head;
            tail = head;
        }
        else
        {

            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            // tail->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    int getSize()
    {
        int counter = 0;
        Node *temp = head;
        do
        {
            counter++;
            temp = temp->next;
        } while (temp != head);

        return counter;
    }

    int getSized()
    {
        return size;
    }

    std::string display()
    {
        Node *temp = head;
        std::string listToString = "{";

        do
        {
            listToString += std::to_string(temp->data) + ", ";
            temp = temp->next;
        } while (temp != head);


        // listToString += std::to_string(temp->data) + ", ";
        listToString += "}";

        return listToString;
    }
};