#include <iostream>

class HeapTree
{
private:
    class Node
    {
    public:
        int key = 0;
        Node *left = nullptr, *right = nullptr;
        Node(int data) { this->key = data; }
        ~Node() {}
    };

    Node *root = nullptr, *lastNode = nullptr;

public:
    HeapTree() {}
    ~HeapTree() {}
    Node *insert(int value);
    Node *getParent(Node *root, Node *node);
    bool isLeft(Node *parent, Node *node);
    bool isRight(Node *parent, Node *node);
};

HeapTree::Node *HeapTree::insert(int value)
{
    Node *parent = getParent(this->root, lastNode);
    if (isLeft(parent, lastNode))
    {
        parent->right = new Node(value);
    }
    else
    {
        
    }
}

HeapTree::Node *HeapTree::getParent(HeapTree::Node *root, HeapTree::Node *node)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (root->left == node || root->right == node)
    {
        return root;
    }
    Node *left = getParent(root->left, node);
    Node *right = getParent(root->right, node);

    if (left == nullptr && right == nullptr)
    {
        return nullptr;
    }
    else if (left == nullptr)
    {
        return right;
    }
    else
    {
        return left;
    }
}

bool HeapTree::isLeft(HeapTree::Node *parent, HeapTree::Node *node)
{
    return parent->left == node;
}

bool HeapTree::isRight(HeapTree::Node *parent, HeapTree::Node *node)
{
    return parent->right == node;
}