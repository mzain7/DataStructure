#include <iostream>
#include "LinkedList.h"
#include "DoubleLinkedList.h"

int main(int argc, char const *argv[])
{
    // LinkedList<int> list;
    // std::cout << list.display() << std::endl;

    // list.addAtStart(7);
    // std::cout << list.display() << std::endl;
    // list.addAtStart(3);
    // std::cout << list.display() << std::endl;
    // list.addAtStart(2);
    // std::cout << list.display() << std::endl;
    // list.addAtStart(53);
    // std::cout << list.display() << std::endl;
    // list.addAtStart(256);
    // std::cout << list.display() << std::endl;
    // list.addAtEnd(4);
    // std::cout << list.display() << std::endl;
    // list.insertion(40,3);
    // std::cout << list.display() << std::endl;
    // list.reverse();
    // std::cout << list.display() << std::endl;
    // std::cout << list.search(3).data << std::endl;
    // std::cout << list.search(9).data << std::endl;

    DoubleLinkedList<int> list;
    list.addAtStart(5);
    std::cout << list.display() << std::endl;
    list.addAtStart(9);
    std::cout << list.display() << std::endl;
    list.addAtEnd(429);
    std::cout << list.display() << std::endl;
    list.insertion(53,1);
    std::cout << list.display() << std::endl;
    // list.deleteAtStart();
    // std::cout << list.display() << std::endl;
    // list.deleteAtEnd();
    // std::cout << list.display() << std::endl;
    list.deletion(3);
    std::cout << list.display() << std::endl;
    list.reverse();
    // std::cout << list.display() << std::endl;


    return 0;
}
