#include <iostream>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next = nullptr;
    };

    Node *head;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }
    ~LinkedList() {}

    void addAtStart(T value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (this->head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtEnd(T value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        if (this->head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    Node search(T value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if(temp->data == value){
                return *temp;
            }
            temp = temp->next;
        }
        return *temp;

        
    }

    std::string display()
    {
        Node *temp = head;
        std::string listToString = "{";
        while (temp != nullptr)
        {
            listToString += std::to_string(temp->data) + ", ";
            temp = temp->next;
        }

        listToString += "}";

        return listToString;
    }

    void insertion(T value,int index){
        Node *newNode = new Node;
        newNode->data = value;
        Node *temp =head;
        int counter = 0;
        while (counter != index)
        {
            temp = temp->next;
            counter++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        

    }

    void deleteAtStart()
    {
        head = head->next;
    }

    void deleteAtEnd()
    {
        int nodeCount = 0;
        Node *curr = head;

        while (nodeCount != size - 1)
        {
            curr = curr->next;
            nodeCount++;
        }
        curr->next = nullptr;
        // delete(curr->next);

        // node *prev = nullptr;

        // while (curr->next != nullptr)
        // {
        //     prev = curr;
        //     curr = curr->next;
        // }

        // prev->next = nullptr;
        // delete(curr);
    }

    void deletion(int index)
    {
        int nodeCount = 0;
        Node *curr = head;
        Node *prev = nullptr;

        while (nodeCount != index)
        {
            prev = curr;
            curr = curr->next;
            nodeCount++;
        }
        prev->next = curr->next;
        delete(curr);
    }

    void reverse(){
        Node *current = head, *previous = nullptr , *next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;

        }

        head = previous;
    }
};