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
    Node<T> *search(T value);
    Node<T> *parent(Node<T> *node, Node<T> *root);
    int depth(Node<T> *node, Node<T> *root);
    bool isSameLevel(Node<T> *node1, Node<T> *node2, Node<T> *root);
    int totalNodes(Node<T> *node);
    int height(Node<T> *node);
    bool isBST(Node<T> *root);
    void levelOrderInsertion(Node<T> *root, T data);
    void deletion(Node<T> *node);
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
int BST<T>::depth(Node<T> *node, Node<T> *root)
{
    int count = 0;
    while (root != node)
    {
        if (root->data < node->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
        count++;
    }
    return count;
}

template <class T>
bool BST<T>::isSameLevel(Node<T> *node1, Node<T> *node2, Node<T> *root)
{
    return depth(node1, root) == depth(node2, root);
}

template <class T>
int BST<T>::totalNodes(Node<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return totalNodes(node->left) + 1 + totalNodes(node->right);
    }
}

template <class T>
int BST<T>::height(Node<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else if (node->left == nullptr && node->right == nullptr)
    {
        return depth(node, this->root);
    }
    else
    {
        int left = height(node->left);
        int right = height(node->right);
        if (left > right)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

template <class T>
bool BST<T>::isBST(Node<T> *root)
{
    std::queue<Node<T> *> queue;
    queue.push(root);
    Node<T> *temp = nullptr;
    while (!queue.empty())
    {
        temp = queue.front();
        queue.pop();
        if (temp->left != nullptr)
        {
            if (temp->data < temp->left->data)
            {
                return false;
            }
            queue.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            if (temp->data > temp->right->data)
            {
                return false;
            }
            queue.push(temp->right);
        }
    }

    return true;
}

template <class T>
void BST<T>::levelOrderInsertion(Node<T> *root, T data)
{
    Node<T> *node = new Node<T>;
    node->data = data;

    std::queue<Node<T> *> q;
    q.push(root);

    Node<T> *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->left != nullptr)
            q.push(temp->left);
        else
        {
            temp->left = node;
            return;
        }

        if (temp->right != nullptr)
            q.push(temp->right);
        else
        {
            temp->right = node;
            return;
        }
    }
}

template <class T>
void BST<T>::deletion(Node<T> *node)
{
    Node<T> *prev = nullptr;
    while (node->right != nullptr)
    {
        node->data = node->right->data;
        prev = node;
        node = node->right;
    }
    if (node->left == nullptr)
    {
        prev->right = nullptr;
    }
    else
    {
        prev->right = node->left;
    }
    delete node;
}

int main(int argc, char const *argv[])
{
    BST<int> tree;
    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    tree.insert(12);
    tree.insert(35);
    tree.insert(55);
    tree.insert(90);
    tree.insert(9);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(44);

    std::cout << "\n\nInorder Display: " << tree.inorder(tree.root);

    std::cout << "\n\nParent of 12 is " << tree.parent(tree.search(12), tree.root)->data;

    std::cout << "\n\nDepth of 25 is " << tree.depth(tree.search(25), tree.root);

    std::cout << "\n\nIs 9 and 35 at same level : " << tree.isSameLevel(tree.search(9), tree.search(35), tree.root);

    std::cout << "\n\nTotal Nodes are " << tree.totalNodes(tree.root);

    std::cout << "\n\nHeight of tree is " << tree.height(tree.root);

    std::cout << "\n\nIs tree a BST? " << tree.isBST(tree.root);

    tree.deletion(tree.search(25));

    std::cout << "\n\nInorder Display: " << tree.inorder(tree.root);

    std::cout << "\n\nIs tree a BST? " << tree.isBST(tree.root);
    return 0;
}