#include <iostream>

class AVLTree
{
private:
    AVLTree(){
        right = this;
        left = this;
        height = -1;
    }
    int key, height=0;
    AVLTree *left = nullptr, *right = nullptr;

    AVLTree(int key, AVLTree *left, AVLTree *right)
    {
        this->key = key;
        this->left = left;
        this->right = right;
        height = 1 + std::max(left->height, right->height);
    }

    void rebalance()
    {
        if (right->height > left->height + 1)
        {
            if (right->left->height > right->right->height)
            {
                right->rotateRight();
            }
            rotateLeft();
        }
        else if (left->height > right->height+1)
        {
            if (left->right->height > left->left->height)
            {
                left->rotateLeft();
            }
            rotateRight();
        }
    }

    void rotateLeft()
    {
        left = new AVLTree(key, left, right->left);
        key = right->key;
        right = right->right;
    }

    void rotateRight()
    {
        right = new AVLTree(key, left->right, right);
        key = left->key;
        left = left->left;
    }

public:
    AVLTree *NIL = new AVLTree;

    AVLTree(int key)
    {
        this->key = key;
        left = right = NIL;
    }

    bool add(int key)
    {
        int oldSize = size();
        grow(key);
        return size() > oldSize;
    }

    AVLTree *grow(int key)
    {
        if (this == NIL)
            return new AVLTree(key);
        if (key == this->key)
            return this;
        if (key < this->key)
            left = left->grow(key);
        else
            right = right->grow(key);
        rebalance();
        height = 1 + std::max(left->height, right->height);
        return this;
    }

    int size()
    {
        if (this == NIL)
        {
            return 0;
        }

        return 1 + left->size() + right->size();
    }

    std::string toString()
    {
        if (this == NIL)
            return "";
        return left->toString() + " " + std::to_string(key) + " " + right->toString();
    }
};

int main(int argc, char const *argv[])
{
    AVLTree tree(20);
    tree.add((10));
    tree.add((30));
    tree.add((80));
    tree.add((1));

    std::cout << tree.toString();
    return 0;
}
