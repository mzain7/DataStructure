#include <iostream>

template <typename T>
class DoubleLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next = nullptr;
        Node *previous = nullptr;
    };

    Node *head;
    int size;

public:
    DoubleLinkedList()
    {
        head = nullptr;
    }
    ~DoubleLinkedList() {}

    void addAtStart(T value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }

    std::string display()
    {
        std::string listToString = "{";
        Node *temp = head;
        while (temp != nullptr)
        {
            listToString += std::to_string(temp->data) + ", ";
            temp = temp->next;
        }

        listToString += "}";

        return listToString;
    }

    void addAtEnd(T value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        Node *temp = head;

        while (temp->next != nullptr && head != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->previous = temp;
    }

    Node search(T value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return *temp;
            }
            temp = temp->next;
        }
        return *temp;
    }

    void insertion(T value, int index)
    {
        Node *newNode = new Node;
        newNode->data = value;
        Node *temp = head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        newNode->previous = temp;
        newNode->next = temp->next;
        (temp->next)->previous = newNode;
        temp->next = newNode;
    }

    void deleteAtStart()
    {
        head = head->next;
        delete (head->previous);
        head->previous = nullptr;
    }

    void deleteAtEnd()
    {
        Node *temp = head;
        while (temp->next != nullptr && head != nullptr)
        {
            temp = temp->next;
        }

        (temp->previous)->next = nullptr;
        delete temp;
    }

    void deletion(int index)
    {
        if (index == 0)
        {
            deleteAtStart();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }

            (temp->previous)->next = temp->next;
            (temp->next)->previous = temp->previous;
            delete temp;
        }
    }

    void reverse()
    {
        Node *temp = head;
        Node *temp2 = nullptr;
        while (temp != nullptr && head != nullptr)
        {
            temp2 = temp->next;
            temp->next = temp->previous;
            temp->previous = temp2;
            if (temp->previous == nullptr)
            {
                head = temp;
            }

            temp = temp->previous;
        }
    }
};