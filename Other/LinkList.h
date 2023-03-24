#include <iostream>

struct node
{
    int data;
    node *next = nullptr;
};

class LinkList
{
private:
    node *head = nullptr;
    int size = 0;

public:
    bool addAtEnd(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        node *tmp = head;
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }

        size++;
    }

    bool addAtStart(int value)
    {
        node *newNode = new node;
        (*newNode).data = value;
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
        return true;
    }

    void insertion(int value, int index)
    {
        node *newNode = new node;
        newNode->data = value;
        node *curr = head;
        int nodeCount = 1;

        while (nodeCount != index)
        {
            curr = curr->next;
            nodeCount++;
        }
        newNode->next = curr->next;
        curr->next = newNode;

        size++;
    }

    void deleteAtStart()
    {
        head = head->next;
    }

    void deleteAtEnd()
    {
        int nodeCount = 1;
        node *curr = head;

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
        node *curr = head;
        node *prev = nullptr;

        while (nodeCount != index)
        {
            prev = curr;
            curr = curr->next;
            nodeCount++;
        }
        prev->next = curr->next;
        delete(curr);
    }

    int removeNode()
    {
        int ret = head->data;
        if (head->next != NULL)
        {
            head = head->next;
        }
        else
        {
            head = nullptr;
        }

        size--;
        return ret;
    }

    void display()
    {
        node *tmp = head;

        while (tmp != nullptr)
        {
            std::cout << tmp->data << std::endl;
            tmp = tmp->next;
        }
    }

    node search(int value)
    {
        node *tmp = head;

        while (tmp != nullptr)
        {
            if (tmp->data == value)
            {
                return *tmp;
            }

            tmp = tmp->next;
        }

        return *tmp;
    }
};
int main(int argc, char const *argv[])
{
    LinkList list{};
    // list.addAtStart(10);
    // list.display();
    return 0;
}
