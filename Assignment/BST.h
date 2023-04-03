#include <iostream>
#include <queue>
#include <stack>

template <typename T>
struct Node
{
    T data;
    Node *left = nullptr, *right = nullptr;
};

template <typename T>
class BST
{
private:
    int size = 0;

public:
    Node<T> *root = nullptr;
    BST(/* args */);
    ~BST();
    void insert(T value);
    std::string inorder(Node<T> *node);
    std::string preorder(Node<T> *node);
    std::string postorder(Node<T> *node);
    Node<T> *search(T value);
    Node<T> *left(Node<T> *node);
    Node<T> *right(Node<T> *node);
    bool hasLeft(Node<T> *node);
    bool hasRight(Node<T> *node);
    Node<T> *parent(Node<T> *node, Node<T> *root);
    Node<T> *sibling(Node<T> *node);
    Node<T> *deletion(Node<T> *node, T value);
    Node<T> *getChild(Node<T> *node);
    Node<T> *successor(Node<T> *node);
    void copyNode(Node<T> *node, Node<T> *successor);
};
template <typename T>
BST<T>::BST(/* args */)
{
}
template <typename T>
BST<T>::~BST()
{
}

template <class T>
void BST<T>::insert(T value)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = value;
    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        Node<T> *temp = root;
        while (true)
        {
            if (value > temp->data)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
    }
}
template <class T>
std::string BST<T>::inorder(Node<T> *node)
{
    if (node == nullptr)
    {
        return "";
    }
    else
    {
        return inorder(node->left) + " " + std::to_string(node->data) + " " + inorder(node->right);
    }
}
template <class T>
std::string BST<T>::preorder(Node<T> *node)
{
    if (node == nullptr)
    {
        return "";
    }
    else
    {
        return std::to_string(node->data) + " " + preorder(node->left) + " " + preorder(node->right);
    }
}
template <class T>
std::string BST<T>::postorder(Node<T> *node)
{
    if (node == nullptr)
    {
        return "";
    }
    else
    {
        return postorder(node->left) + " " + postorder(node->right) + " " + std::to_string(node->data);
    }
}

template <class T>
Node<T> *BST<T>::search(T value)
{
    Node<T> *node = root;
    while (node != nullptr)
    {
        if (node->data == value)
        {
            break;
        }
        else if (value > node->data)
        {
            node = node->right;
        }
        else if (value < node->data)
        {
            node = node->left;
        }
    }

    return node;
}

template <class T>
Node<T> *BST<T>::left(Node<T> *node)
{
    return node->left;
}
template <class T>
Node<T> *BST<T>::right(Node<T> *node)
{
    return node->right;
}

template <class T>
bool BST<T>::hasLeft(Node<T> *node)
{
    return node->left != nullptr;
}
template <class T>
bool BST<T>::hasRight(Node<T> *node)
{
    return node->right != nullptr;
}

template <class T>
Node<T> *BST<T>::parent(Node<T> *node, Node<T> *root)
{
    if (node == root)
    {
        return nullptr;
    }
    else if (root->left == node || root->right == node)
    {
        return root;
    }
    else if (node->data > root->data)
    {
        return parent(node, root->right);
    }
    else
    {
        return parent(node, root->left);
    }
}

template <class T>
Node<T> *BST<T>::sibling(Node<T> *node)

{
    Node<T> *parentNode = parent(node, root);
    if (parentNode->left == node)
    {
        return parentNode->right;
    }
    else
    {
        return parentNode->left;
    }
}

template <class T>
Node<T> *BST<T>::deletion(Node<T> *node, T value)
{
    if (node != nullptr)
    {
        if (node->data == value)
        {
            if (hasLeft(node) && hasRight(node))
            {
                Node<T> *successorNode = successor(node);
                copyNode(node, successorNode);
                node->right = deletion(node->right, successorNode->data);
            }
            else
            {
                node = getChild(node);
            }
        }
        else if (value > node->data)
        {
            node->right = deletion(node->right, value);
        }
        else
        {
            node->left = deletion(node->left, value);
        }

        return node;
    }
    return node;
}

template <class T>
Node<T> *BST<T>::getChild(Node<T> *node)
{
    if (node->left != nullptr)
    {
        return node->left;
    }
    else
    {
        return node->right;
    }
}

template <class T>
Node<T> *BST<T>::successor(Node<T> *node)
{
    node = node->right;
    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}
template <class T>
void BST<T>::copyNode(Node<T> *node, Node<T> *successor)
{
    node->data = successor->data;
}
