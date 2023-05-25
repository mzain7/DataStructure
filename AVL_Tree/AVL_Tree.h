#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
class AVL_Tree
{
private:
    struct Node
    {
        int key = 0;
        Node *left = nullptr;
        Node *right = nullptr;
        int height = 0;
    };

public:
    AVL_Tree(int a[]);
    Node *root = nullptr;
    void insert(int data);
    Node *grow(Node *node, int key);
    int height(Node *node);
    void balance(Node *node);
    Node *newNode(int key, Node *left, Node *right);
    void rotateLeft(Node *node);
    void rotateRight(Node *node);
    std::string preorder(Node *node);
    void print(Node *node);
    bool contain(int data);
};
std::string AVL_Tree::preorder(Node *node)
{
    if (node == nullptr)
    {
        return "";
    }
    else
    {
        return std::to_string(node->key) + " " + preorder(node->left) + " " + preorder(node->right);
    }
}
void AVL_Tree::insert(int data)
{
    this->root = grow(root, data);
}

AVL_Tree::Node *AVL_Tree::grow(AVL_Tree::Node *node, int key)
{
    if (node == nullptr)
    {
        Node *newNode = new Node;
        newNode->key = key;
        return newNode;
    }
    else if (key < node->key)
    {
        node->left = grow(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = grow(node->right, key);
    }
    else
    {
        return node;
    }

    balance(node);
    node->height = 1 + std::max(height(node->left), height(node->right));
    return node;
}

void AVL_Tree::balance(AVL_Tree::Node *node)
{
    if (height(node->right) > height(node->left) + 1)
    {
        if (height(node->right->left) > height(node->right->right))
        {
            rotateRight(node->right);
        }
        rotateLeft(node);
    }
    else if (height(node->left) > height(node->right) + 1)
    {
        if (height(node->left->right) > height(node->left->left))
        {
            rotateLeft(node->left);
        }
        rotateRight(node);
    }
}

void AVL_Tree::rotateLeft(AVL_Tree::Node *node)
{
    node->left = newNode(node->key, node->left, node->right->left);
    node->key = node->right->key;
    Node *temp = node->right;
    node->right = node->right->right;
    delete temp;
}
void AVL_Tree::rotateRight(AVL_Tree::Node *node)
{
    node->right = newNode(node->key, node->left->right, node->right);
    node->key = node->left->key;
    Node *temp = node->left;
    node->left = node->left->left;
    delete temp;
}
AVL_Tree::Node *AVL_Tree::newNode(int key, AVL_Tree::Node *left, AVL_Tree::Node *right)
{
    Node *node = new Node;
    node->key = key;
    node->left = left;
    node->right = right;
    node->height = 1 + std::max(height(node->left), height(node->right));
    return node;
}

int AVL_Tree::height(AVL_Tree::Node *node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

void AVL_Tree::print(AVL_Tree::Node *node)
{
    std::queue<Node *> q, queue;
    q.push(root);
    int count = 0, counter = 0;
    while (!q.empty())
    {
        count++;
        Node *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            std::cout << "   ";
        }
        else
        {
            std::cout << temp->key << " ";
            q.push(temp->left);
            q.push(temp->right);
        }
        if (count == pow(2, counter))
        {
            count = 0;
            std::cout << std::endl;
            counter++;
        }
    }
}

bool AVL_Tree::contain(int value)
{
    Node *node = root;
    while (node != nullptr)
    {
        if (node->key == value)
        {
            break;
        }
        else if (value > node->key)
        {
            node = node->right;
        }
        else if (value < node->key)
        {
            node = node->left;
        }
    }

    return node;
}


AVL_Tree::AVL_Tree(int *a)
{
    int size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size; i++)
    {
        this->insert(a[i]);
    }
}