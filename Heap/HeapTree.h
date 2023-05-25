#include <iostream>

template <typename T>
class HeapTree
{
private:
    class Node
    {
    public:
        T data;
        Node *left, *right;
        Node(T data) : data(data), left(nullptr), right(nullptr) {}

    }

    Node *root = nullptr;
    Node *last = nullptr;

    void heapifyUp(Node *node);
    void heapifyDown(Node *node);

public:
    HeapTree() {}
    ~HeapTree() {}

    Node *insert(T data); 
    Node *remove();

    Node *sibling(Node *node);

};

template<class T> <error-type> *HeapTree<T>::insert(T data)
{
    Node *node = new Node(data);
    if (root == nullptr)
    {
        root = node;
        last = node;
    }
    else
    {
        Node *temp = last;
        while (temp != nullptr)
        {
            if (temp->left == nullptr)
            {
                temp->left = node;
                break;
            }
            else if (temp->right == nullptr)
            {
                temp->right = node;
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
        last = node;
    }
    heapifyUp(node);
    return node;
}