#include <iostream>
#include "HeapTree.h"
int main(int argc, char const *argv[])
{
    HeapTree heap;
    heap.insert(3);
    heap.insert(5);
    heap.insert(8);
    heap.insert(1);
    heap.insert(2);
    heap.insert(4);
    heap.insert(6);
    heap.insert(7);
    heap.insert(9);
    heap.insert(10);
    heap.insert(11);
    heap.print(heap.root);
    heap.deletion();
    heap.print(heap.root);
    heap.deletion();
    heap.print(heap.root);
    heap.deletion();
    heap.print(heap.root);
    heap.deletion();
    heap.print(heap.root);
    heap.deletion();



    return 0;
}
