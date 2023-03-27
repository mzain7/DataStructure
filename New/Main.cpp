#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> tree;


    tree.bfs_iterative();
    tree.dfs_iterative();
    tree.preOrder(tree.getRoot());
    cout << endl;
    tree.postOrder(tree.getRoot());
    cout << endl;
    tree.inOrder(tree.getRoot());
    cout << endl;

    return 0;
}