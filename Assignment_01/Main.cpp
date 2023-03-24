#include <iostream>
#include "LinkedList.h"
#include "CircularLinkedList.h"
template <typename T>
Node<T> *copy(Node<T> *node);

template <typename T>
LinkedList<T> copy(LinkedList<T> list);
template <typename T>
Node<T> *concat(Node<T> *list1, Node<T> *list2);

template <typename T>
LinkedList<T> concat(LinkedList<T> list1, LinkedList<T> list2);

template <typename T>
void replace(LinkedList<T> list, T before, T after);

template <typename T>
void replace(Node<T> *node, int index, T value);

int main(int argc, char const *argv[])
{

    LinkedList<int> list;
    // CircularLinkedList<int> list;

    std::cout << list.display() << std::endl;
    list.addAtStart(7);
    std::cout << list.display() << std::endl;
    list.addAtStart(3);
    std::cout << list.display() << std::endl;
    list.addAtStart(2);
    std::cout << list.display() << list.getSize() << std::endl;
    list.addAtStart(53);
    std::cout << list.display() << list.getSize() << std::endl;
    list.addAtStart(256);
    // std::cout << list.display() << list.getSize() << std::endl<< list.getSized();
    list.addAtEnd(4);
    std::cout << list.display() << list.getSize() << std::endl;
    list.insertion(40, 3);
    std::cout << list.display() << list.getSize() << std::endl;
    list.insertion(40, 3);
    std::cout << list.display() << list.getSize() << std::endl;

    // list.rotate(2);
    // std::cout << list.display() << list.getSize() << std::endl;

    // list.deleteAtStart();
    // std::cout << list.display() << list.getSize() << std::endl;
    // list.deleteAtStart();
    // std::cout << list.display() << list.getSize() << std::endl;
    // list.deleteAtEnd();
    // std::cout << list.display() << list.getSize() << std::endl;
    // list.deletion(3);
    // std::cout << list.display() << list.getSize() << std::endl;
    // list.deletion(0);
    // std::cout << list.display() << list.getSize() << std::endl;
    // list.reverse();
    // std::cout << list.display() << list.getSize() << std::endl;
    // std::cout << list.search(3).data << std::endl;
    // std::cout << list.search(9).data << std::endl;

    LinkedList<int> copyList;
    copyList.setHead(copy(list.getHead()));
    std::cout << copyList.display() << copyList.getSize() << std::endl;
    list.insertion(64, 3);
    list.insertion(24, 6);
    std::cout << list.display() << list.getSize() << std::endl;
    std::cout << copyList.display() << copyList.getSize() << std::endl;

    LinkedList<int> concatList;
    concatList.setHead(concat(list.getHead(), copyList.getHead()));
    // concatList = concat(list, concatList);
    std::cout << concatList.display() << concatList.getSize() << std::endl;
    replace(concatList.getHead(), 2, 100);
    std::cout << concatList.display() << concatList.getSize() << std::endl;
    // replace();

    std::cout << concatList.secondToLastNode()->data;
    // concatList.sort();
    // concatList.insertion(284, 25);
    // concatList.removeDuplicate();
    // std::cout << "Sorted" << concatList.display() << concatList.getSize() << std::endl;
    return 0;
}

template <typename T>
Node<T> *copy(Node<T> *node)
{
    LinkedList<T> result;
    Node<T> *temp = node;
    while (temp != nullptr)
    {
        result.addAtEnd(temp->data);
        temp = temp->next;
    }

    return result.getHead();
}

template <typename T>
Node<T> *concat(Node<T> *list1, Node<T> *list2)
{
    LinkedList<T> result;
    Node<T> *temp = list1;
    while (temp != nullptr)
    {
        result.addAtEnd(temp->data);
        temp = temp->next;
    }
    temp = list2;
    while (temp != nullptr)
    {
        result.addAtEnd(temp->data);
        temp = temp->next;
    }
    

    return result.getHead();
}
template <typename T>
void replace(Node<T> *node, int index, T value)
{
    Node<T> *temp = node;
    int counter = 1;
    while (temp != nullptr)
    {
        if (counter == index)
        {
            temp->data = value;
            break;
        }
        temp = temp->next;
        counter++;
        
    }
}

// template <typename T>
// LinkedList<T> copy(LinkedList<T> list)
// {
//     LinkedList<T> result;

//     for (int i = 1; i <= list.getSize(); i++)
//     {
//         result.addAtEnd(list.read(i));
//     }

//     return result;
// }

// template <typename T>
// LinkedList<T> concat(LinkedList<T> list1, LinkedList<T> list2)
// {
//     LinkedList<T> result;
//     for (int i = 1; i <= list1.getSize(); i++)
//     {
//         result.addAtEnd(list1.read(i));
//     }
//     for (int i = 1; i <= list2.getSize(); i++)
//     {
//         result.addAtEnd(list2.read(i));
//     }

//     return result;
// }

// template <typename T>
// void replace(LinkedList<T> list, T before, T after)
// {
//     while (list.search(before) != nullptr)
//     {
//         list.search(before)->data = after;
//     }
// }
