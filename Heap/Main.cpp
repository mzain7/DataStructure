#include <iostream>
#include "Heap.h"
int main(int argc, char const *argv[])
{
    Heap<int> heap;
    heap.insert(3);
    heap.insert(5);
    heap.insert(8);
    heap.insert(1);
    heap.print();

    heap.extractMax();
    heap.print();
    heap.extractMax();
    heap.print();
    heap.extractMax();
    heap.print();
    return 0;
}
