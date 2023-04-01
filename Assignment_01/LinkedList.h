#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr;
};
template <typename T>
class LinkedList
{
public:
private:
    Node<T> *head;
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
        Node<T> *newNode = new Node<T>;
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
        size++;
    }

    void addAtEnd(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        if (this->head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    Node<T> *search(T value)
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return temp;
            }
            temp = temp->next;
        }
        return temp;
    }

    std::string display()
    {
        Node<T> *temp = head;
        std::string listToString = "{";
        while (temp != nullptr)
        {

            listToString += std::to_string(temp->data) + " ";

            temp = temp->next;
        }

        listToString += "}";
        return listToString;
    }

    void insertion(T value, int index)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        Node<T> *temp = head;
        int counter = 1;
        while (counter != index)
        {
            temp = temp->next;
            counter++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void deleteAtStart()
    {
        head = head->next;
        size--;
    }

    void deleteAtEnd()
    {
        Node<T> *curr = head;
        Node<T> *prev = nullptr;

        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        delete (curr);
        size--;
    }

    void deletion(int index)
    {
        if (index == 1)
        {
            deleteAtStart();
        }
        else
        {
            int nodeCount = 1;
            Node<T> *curr = head;
            Node<T> *prev = nullptr;

            while (nodeCount != index)
            {
                prev = curr;
                curr = curr->next;
                nodeCount++;
            }
            prev->next = curr->next;
            delete (curr);
            size--;
        }
    }

    void reverse()
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

    int getSize()
    {
        int sizee = 0;
        Node<T> *temp = head;

        while (temp != nullptr)
        {
            sizee++;
            temp = temp->next;
        }
        this->size = sizee;
        return sizee;
    }

    T read(int index)
    {
        Node<T> *temp = head;
        for (int i = 2; i <= index && i <= size; i++)
        {
            temp = temp->next;
        }

        return temp->data;
    }

    Node<T> *secondToLastNode()
    {
        Node<T> *curr = head;

        while ((curr->next)->next != nullptr)
        {
            curr = curr->next;
        }

        return curr;
    }

    void rotate(int index)
    {
        Node<T> *temp = head, *temp2 = nullptr;
        int counter = 1;
        while (counter != index)
        {
            temp = temp->next;
            counter++;
        }
        temp2 = temp->next;
        temp->next = nullptr;

        temp = temp2;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = head;
        head = temp2;
    }

    Node<T> *getHead()
    {
        return head;
    }

    void setHead(Node<T> *head)
    {
        this->head = head;
    }

    // void sort()
    // {
    //    Node<T>*temp = head, *temp2 = head;
    //     while (temp2->next != nullptr)
    //     {
    //         while (temp->next != nullptr)
    //         {
    //             if (temp->data > (temp->next)->data)
    //             {
    //                 swap(temp, temp->next);
    //             }
    //             temp = temp->next;
    //         }
    //         temp = head;
    //         temp2 = temp2->next;
    //     }
    // }

    // void swap(Node *firstNode,Node<T>*secondNode)
    // {
    //     T temp = firstNode->data;
    //     firstNode->data = secondNode->data;
    //     secondNode->data = temp;
    // }

    // void removeDuplicate()
    // {
    //    Node<T>*temp = head, *temp2, *previous;
    //     while (temp != nullptr)
    //     {
    //         previous = temp;
    //         temp2 = temp->next;
    //         while (temp2 != nullptr)
    //         {
    //             if (temp->data == temp2->data)
    //             {
    //                 previous->next = temp2->next;
    //                 delete temp2;
    //                 temp2 = previous->next;
    //                 size--;
    //             }
    //             else
    //             {
    //                 previous = temp2;
    //                 temp2 = temp2->next;
    //             }
    //         }
    //         std::cout << display() << std::endl;

    //         temp = temp->next;
    //     }
    // }
};