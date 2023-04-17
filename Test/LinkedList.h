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
    Node<T> *head = nullptr;
    LinkedList() {}
    ~LinkedList() {}
    void insert(T data, int loc)
    {
        Node<T> *node = new Node<T>;
        node->data = data;

        if (head == nullptr)
        {
            head = node;
        }
        else if (loc == 0)
        {
            node->next = head;
            head = node;
        }
        else
        {
            Node<T> *temp = head;
            int count = 0;
            while (temp->next != nullptr)
            {
                count++;
                if (count == loc)
                {
                    break;
                }
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data + " ";
        }

        std::cout << std::endl;
    }

    Node<T> *search(T key)
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }

    void update(Node<T> *node, T key)
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (temp == node)
            {
                temp->data = key;
                return;
            }
            temp = temp->next;
        }
    }

    void deletion(T key)
    {
        Node<T> *temp = head, *pre = nullptr;

        if (head->data == key)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            while (temp != nullptr)
            {
                if (temp->data == key)
                {
                    pre->next = temp->next;
                    delete temp;
                    return;
                }

                pre = temp;
                temp = temp->next;
            }
        }
    }

    void deletion2(int index)
    {
        if (head != nullptr)
        {
            Node<T> *temp = head;
            if (index == 0)
            {
                head = head->next;
                delete temp;
            }
            else if (index >= getSize())
            {
                return;
            }
            else
            {
                int count = 0;
                Node<T> *pre = nullptr;
                while (temp != nullptr)
                {
                    if (count == index)
                    {
                        pre->next = temp->next;
                        delete temp;
                        return;
                    }

                    per = temp;
                    temp = temp->next;
                }
            }
        }
    }

    int getSize()
    {
        Node<T> *temp = head;
        int size = 0;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    void insertion(T data, T key)
    {
        Node<T> *temp = head;
        Node<T> *node = new Node<T>;
        node->data = data;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                node->next = temp->next;
                temp->next = node;
                return;
            }

            temp = temp->next;
        }
    }

    void insertSorted(T data)
    {
        Node<T> *temp = head;
        Node<T> *node = new Node<T>;
        node->data = data;

        while (temp != nullptr)
        {
            if (data < temp->next->data)
            {
                node->next = temp->next;
                temp->next = node;
                return;
            }
        }
    }

    void sortSeletion()
    {
        Node<T> *temp = head, *max = head;
        int size = getSize();
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                if (temp->data > max->data)
                {
                    max = temp;
                }
            }
        }
    }

    void sort()
    {
        Node<T> *temp1 = head, *temp2 = head, *pre = nullptr;
        while (temp1 != nullptr)
        {
            while (temp2 != nullptr)
            {
                if (temp2->data > temp2->next->data)
                {
                    swap(pre, temp2, temp2->next);
                }
                pre = temp2;
                temp2 = temp2->next;
            }
            temp2 = head;
            temp1 = temp1->next;
        }
    }
    void swap(Node<T> *pre, Node<T> *node1, Node<T> *node2)
    {
        node1->next = node2->next;
        node2->next = node1;
        pre->next = node2;
    }

    void mergeList(LinkedList<T> list)
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = list.head;
    }

    void reverse()
    {
        Node<T> *curr = head, *pre = nullptr, *next = head->next;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
    }

    void removeDuplicate()
    {
        Node<T> *temp1 = head, *temp2 = nullptr, *pre = nullptr;
        while (temp1 != nullptr)
        {
            temp2 = temp1->next;
            pre = temp1;
            while (temp2 != nullptr)
            {
                if (temp1->data == temp2->data)
                {
                    pre->next = temp2->next;
                    delete temp2;
                    temp2 = pre->next;
                    continue;
                }
                pre = temp2;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }

    void reorder()
    {
        Node<T> *even = head, *odd = head->next;

        while(odd != nullptr && odd->next != nullptr)
        {
            even->next = even->next->next;
            odd->next = odd->next->next;

            even = even->next;
            odd = odd->next;
        }
        even->next = head->next;

    }
};