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