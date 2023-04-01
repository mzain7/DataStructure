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
class BinaryTree
{
private:
    int size = 0;

public:
    Node<T> *root = nullptr;
    BinaryTree(/* args */);
    ~BinaryTree();
    void insert(T value);
    std::string inorderToString(Node<T> *node);
    Node<T> *search(T value);
    void deleteRoot();
    void deleteNode(T value);
    void deleteNode(Node<T> *node);
    void bfs_iterative();
    void dfs_iterative();
    Node<T> **successor(Node<T> *);
    // void rearrange();
};
template <typename T>
BinaryTree<T>::BinaryTree(/* args */)
{
}
template <typename T>
BinaryTree<T>::~BinaryTree()
{
}

template <class T>
void BinaryTree<T>::insert(T value)
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
std::string BinaryTree<T>::inorderToString(Node<T> *node)
{
    if (node == nullptr)
    {
        return "";
    }
    else
    {
        return inorderToString(node->left) + ", " + std::to_string(node->data) + ", " + inorderToString(node->right);
    }
}

template <class T>
Node<T> *BinaryTree<T>::search(T value)
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
void BinaryTree<T>::deleteRoot()
{
    // Node<T> *current = root;
    // if (current->left == nullptr && current->right == nullptr)
    // {
    //     delete current;
    // }
    // else if (current->left == nullptr)
    // {
    //     root = current->right;
    //     delete current;
    // }
    // else if (current->right == nullptr)
    // {
    //     root = current->left;
    //     delete current;
    // }
    // else
    // {
    //     current = current->left;

    //     while (current->right != nullptr)
    //     {
    //         current = current->right;
    //     }
    //     current->right = root->right;

    //     current = root;

    //     root = root->left;

    //     delete current;
    // }

    Node<T> *temp = root;
}

template <class T>
void BinaryTree<T>::deleteNode(T value)
{
    // if (root->data == value)
    // {
    //     deleteRoot();
    // }
    // else
    // {
    //     Node<T> *current = root, *previous = nullptr;
    //     bool found = false;
    //     while (current->left != nullptr || current->right != nullptr)
    //     {
    //         if (current->data == value)
    //         {
    //             found = true;
    //             break;
    //         }
    //         else if (value > current->data)
    //         {
    //             previous = current;
    //             current = current->right;
    //         }
    //         else if (value < current->data)
    //         {
    //             previous = current;
    //             current = current->left;
    //         }
    //     }

    //     if (!found)
    //     {
    //         return;
    //     }

    //     Node<T> *node = current;
    //     if (node->left == nullptr && node->right == nullptr)
    //     {
    //         if (current->data > previous->data)
    //         {
    //             previous->right = nullptr;
    //         }
    //         else
    //         {
    //             previous->left = nullptr;
    //         }
    //         delete current;
    //     }
    //     else if (node->left == nullptr)
    //     {
    //         if (current->data > previous->data)
    //         {
    //             previous->right = current->right;
    //             delete current;
    //         }
    //         else
    //         {
    //             previous->left = current->right;
    //             delete current;
    //         }
    //     }
    //     else if (node->right == nullptr)
    //     {
    //         if (current->data > previous->data)
    //         {
    //             previous->right = current->left;
    //             delete current;
    //         }
    //         else
    //         {
    //             previous->left = current->left;
    //             delete current;
    //         }
    //     }
    //     else
    //     {
    //         node = node->left;

    //         while (node->right != nullptr)
    //         {
    //             node = node->right;
    //         }
    //         node->right = current->right;

    //         if (current->data > previous->data)
    //         {
    //             previous->right = current->left;
    //             delete current;
    //         }
    //         else
    //         {
    //             previous->left = current->left;
    //             delete current;
    //         }
    //     }
    // }

    Node<T> *node = root, *parentNode = nullptr;
    while (node != nullptr)
    {
        if (node->data == value)
        {
            break;
        }
        else if (value > node->data)
        {
            parentNode = node;
            node = node->right;
        }
        else if (value < node->data)
        {
            parentNode = node;
            node = node->left;
        }
    }

    if(node == nullptr)
    {
        return;
    }

    if(node->left == nullptr && node->right == nullptr)
    {
        if(node->data <= parentNode->data){
            parentNode->left = nullptr;
        }else{
            parentNode->right = nullptr;
        }
        delete (node);

    }else if(node->left == nullptr){
        if(node->data <= parentNode->data){
            parentNode->left = node->right;
        }else{
            parentNode->right = node->right;
        }
        delete (node);

    }else if(node->right == nullptr){
        if(node->data <= parentNode->data){
            parentNode->left = node->left;
        }else{
            parentNode->right = node->left;
        }
        delete (node);

    }else{
        deleteNode(node);
    }









    // Node<T> *node = search(value);
    // deleteNode(node);


}
template <class T>
void BinaryTree<T>::deleteNode(Node<T> *node)
{
    std::cout<<"RUNNING SUCCESSOR";
    Node<T> **successor_arr = successor(node);
    node->data = successor_arr[0]->data;
    if (successor_arr[0]->right == nullptr)
    {
        if (successor_arr[0]->data < successor_arr[1]->data)
        {
            successor_arr[1]->left = nullptr;
        }
        else
        {
            successor_arr[1]->right = nullptr;
        }

        delete (successor_arr[0]);
    }
    else
    {
        deleteNode(successor_arr[0]);
    }
}

template <typename T>
void BinaryTree<T>::bfs_iterative()
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
void BinaryTree<T>::dfs_iterative()
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
template <class T>
Node<T> **BinaryTree<T>::successor(Node<T> *node)
{
    Node<T> **arr = new Node<T> *[2];
    arr[0] = node;
    arr[1] = nullptr;
    if (arr[0]->right == nullptr)
    {
        return nullptr;
    }
    else
    {
        arr[1] = arr[0];
        arr[0] = arr[0]->right;
    }
    while (arr[0]->left != nullptr)
    {
        arr[1] = arr[0];
        arr[0] = arr[0]->left;
    }

    return arr;
}

// template <class T>
// void BinaryTree<T>::rearrange()
// {
//     int * arr = inorderNode(root);

//     for (size_t i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
//         std::cout << arr[i] << ' ';
//     }

// }
// template <class T>
// int* inorderNode(Node<T> *node){
//     if (node == nullptr)
//     {
//         return nullptr;
//     }
//     else
//     {
//         int *left =inorderNode(node->left);
//         int *current = &node->data;
//         int *right = inorderNode(node-> right);

//         int size1 = sizeof(left)/sizeof(*left);
//         int size2 = sizeof(current)/sizeof(*current);
//         int size3 = sizeof(right)/sizeof(*right);

//         int result[size1+size2+size3];

//         std::copy(left,left+size1,result);
//         std::copy(current,current+size2,result+size1);
//         std::copy(right,right+size3,result+size1+size2);

//         return result;
//     }

// }