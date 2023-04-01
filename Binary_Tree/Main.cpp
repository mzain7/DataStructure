#include <iostream>
#include "BinaryTree.h"
#include <string>
#include <regex>

int main(int argc, char const *argv[])
{
    BinaryTree<int> tree;
    tree.insert(4);
    tree.insert(24);
    tree.insert(26);
    tree.insert(9);
    tree.insert(0);
    tree.insert(2);
    tree.insert(8);
    tree.insert(8);
    tree.insert(8);
    tree.insert(42);
    tree.insert(5);
    tree.insert(8);
    tree.insert(4);
    tree.insert(4);
    tree.insert(4);
    tree.insert(25);

    std::regex r ("[, ]+");
    // std::cout << std::regex_replace(tree.inorderToString(tree.root),r,", ");
    // std::cout << tree.search(4)->data;
    // tree.deleteRoot();
    std::cout <<std::endl<< std::regex_replace(tree.inorderToString(tree.root),r,", ");
    std::cout << tree.successor(tree.search(24))[0]->data << " and " << tree.successor(tree.search(24))[1]->data;
    tree.deleteNode(24);
    std::cout <<std::endl<< std::regex_replace(tree.inorderToString(tree.root),r,", ");
    // tree.rearrange();

    // tree.bfs_iterative();

    return 0;
}
