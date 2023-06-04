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
    int depth(Node<T> *node, Node<T> *root);
    bool isSameLevel(Node<T> *node1, Node<T> *node2, Node<T> *root);
    int totalNodes(Node<T> *node);
    int height(Node<T> *node);
    bool isBST(Node<T> *root);
    void levelOrderInsertion(Node<T> *root, T data);
    int isAVL(Node<T> *node);
    void bfs_iterative();
    void dfs_iterative();
    bool isComplete(Node<T> *node);
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
// int isBST(struct node* node)
// {
//     if (node == NULL)
//         return 1;

//     /* false if the max of the left is > than us */
//     if (node->left != NULL
//         && maxValue(node->left) > node->data)
//         return 0;

//     /* false if the min of the right is <= than us */
//     if (node->right != NULL
//         && minValue(node->right) < node->data)
//         return 0;

//     /* false if, recursively, the left or right is not a BST
//      */
//     if (!isBST(node->left) || !isBST(node->right))
//         return 0;

//     /* passing all that, it's a BST */
//     return 1;
// }
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
int BST<T>::isAVL(Node<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int left = isAVL(node->left);
        int right = isAVL(node->right);
        if (left == -1 || right == -1)
        {
            return -1;
        }
        else if (abs(left - right) > 1)
        {
            return -1;
        }
        else
        {
            return std::max(left, right) + 1;
        }
    }
}

template <typename T>
void BST<T>::bfs_iterative()
{
    if (root != nullptr)
    {
        std::queue<Node<T> *> q;
        Node<T> *temp = root;
        q.push(temp);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            std::cout << temp->data << " ";
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
        std::cout << std::endl;
    }
}

template <typename T>
void BST<T>::dfs_iterative()
{
    if (root != nullptr)
    {
        std::stack<Node<T> *> s;
        Node<T> *temp = root;
        s.push(temp);
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            std::cout << temp->data << " ";
            if (temp->right != nullptr)
            {
                s.push(temp->right);
            }
            if (temp->left != nullptr)
            {
                s.push(temp->left);
            }
        }
        std::cout << std::endl;
    }
}


template<class T> bool BST<T>::isComplete(Node<T> *node)
{
    if (node == nullptr)
    {
        return true;
    }
    else
    {
        std::queue<Node<T> *> q;
        q.push(node);
        Node<T> *temp;
        bool flag = false;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp->left != nullptr)
            {
                if (flag)
                {
                    return false;
                }
                q.push(temp->left);
            }
            else
            {
                flag = true;
            }
            if (temp->right != nullptr)
            {
                if (flag)
                {
                    return false;
                }
                q.push(temp->right);
            }
            else
            {
                flag = true;
            }
        }
        return true;
    }
}