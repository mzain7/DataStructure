#include <iostream>
#include "BST.h"
#include <string>
#include <regex>

template <typename T>
void operation(int option, BST<T> tree);

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

    tree.levelOrderInsertion(tree.root,32);
    tree.levelOrderInsertion(tree.root,5);
    tree.levelOrderInsertion(tree.root,5);

    std::cout<<tree.inorder(tree.root);
    std::cout <<std::endl<< tree.parent(tree.search(12),tree.root)->data;
    std::cout<<std::endl<< tree.depth(tree.search(25),tree.root);
    std::cout << std::endl<< tree.isSameLevel(tree.search(9),  tree.search(35), tree.root);
    std::cout << std::endl << tree.totalNodes(tree.root);
    // std::cout << std::endl << tree.height(tree.root);
    std::cout << std::endl << tree.isBST(tree.root);

    std::string

    // int option;
    // tree.insert(5);
    // do
    // {
    //     std::cout << "1 - Insert " << std::endl;
    //     std::cout << "2 - Delete" << std::endl;
    //     std::cout << "3 - Inorder Display" << std::endl;
    //     std::cout << "4 - Preorder Display" << std::endl;
    //     std::cout << "5 - Postrder Display" << std::endl;
    //     std::cout << "6 - Search" << std::endl;
    //     std::cout << "7 - Find Parent" << std::endl;
    //     std::cout << "8 - Find Sibling" << std::endl;
    //     std::cout << "9 - Find Successor" << std::endl;
    //     std::cout << "Enter your Choice: ";
    //     std::cin >> option;
    //     operation(option, tree);

    // } while (option != -1);

    return 0;
}
template <typename T>
void operation(int option, BST<T> tree)
{
    std::regex r("[, ]+");
    int value;
    switch (option)
    {
    case 1:
        while (true)
        {
            std::cout << "Enter a Value:";
            std::cin >> value;
            if (value == -1)
                break;
            tree.insert(value);
        }

        break;
    case 2:
        std::cout << "Enter a Value:";
        std::cin >> value;
        tree.deletion(tree.root, value);
        break;
    case 3:
        std::cout << std::endl
                  << tree.inorder(tree.root);
        //   << std::regex_replace(tree.inorder(tree.root), r, ", ");
        break;
    case 4:
        std::cout << std::endl
                  << std::regex_replace(tree.preorder(tree.root), r, ", ");
        break;
    case 5:
        std::cout << std::endl
                  << std::regex_replace(tree.postorder(tree.root), r, ", ");
        break;
    case 6:
        std::cout << "Enter a Value:";
        std::cin >> value;
        std::cout << std::endl
                  << (tree.search(value) != nullptr);
        break;
    case 7:
        std::cout << "Enter a Value:";
        std::cin >> value;
        std::cout << std::endl
                  << tree.parent(tree.search(value), tree.root)->data;
        break;
    case 8:
        std::cout << "Enter a Value:";
        std::cin >> value;
        std::cout << std::endl
                  << tree.sibling(tree.search(value))->data;
        break;
    case 9:
        std::cout << "Enter a Value:";
        std::cin >> value;
        std::cout << std::endl
                  << tree.successor(tree.search(value))->data;
        break;

    default:
        break;
    }
}
