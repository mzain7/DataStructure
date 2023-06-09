#include <iostream>
#include "AVL_Tree.h"

int main(int argc, char const *argv[])
{
    int arr[] = {3,4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    // std::cout << size << std::endl;
    AVL_Tree tree(arr, sizeof(arr) / sizeof(arr[0]));
    tree.print(tree.root);
    /*tree.insert(55);
    tree.insert(33);
    tree.insert(66);
    // tree.insert(20);
    
    tree.insert(44);
    tree.insert(60);
    tree.insert(80);
    tree.insert(15);
    tree.insert(40);
    tree.insert(50);
    tree.insert(88);
    tree.insert(38);
    tree.insert(42);
    tree.insert(52);
    tree.insert(35);
    tree.insert(5);

    tree.insert(13);
    tree.insert(10);
    tree.insert(15);
    tree.insert(5);
    tree.insert(11);
    tree.insert(16);
    tree.insert(4);
    tree.insert(8);
    tree.insert(3);

    std::cout << tree.preorder(tree.root);

    std::cout << std::endl
              << tree.contain(55) << std::endl;

    tree.print(tree.root);
    return 0;*/
}
