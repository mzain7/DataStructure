#include <iostream>
template <typename T>
class Heap
{
private:
    int size = 0, capatity = 0;
    T *heap;

public:
    Heap(int capacity = 10)
    {
        this->capatity = capacity;
        heap = new T[capacity];
    }
    ~Heap() {}
    void heapifyUp(int index);
    void heapifydown(int index);
    void insert(T key);
    T extractMax();
    bool isFull();
    bool isEmpty();
    T getMax();
    void print();
};

template <class T>
void Heap<T>::heapifyUp(int index)
{
    if (index == 0)
    {
        return;
    }

    int parent_index = (index - 1) / 2;

    if (this->heap[parent_index] < this->heap[index])
    {
        std::swap(this->heap[parent_index], this->heap[index]);
        heapifyUp(parent_index);
    }
}

template<class T> void Heap<T>::heapifydown(int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && this->heap[left] > this->heap[largest])
    {
        largest = left;
    }

    if (right < size && this->heap[right] > this->heap[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        std::swap(this->heap[index], this->heap[largest]);
        heapifydown(largest);
    }
}

template <class T>
void Heap<T>::insert(T key)
{
    if (isFull())
    {
        throw std::runtime_error("Heap is Full!");
    }

    heap[size] = key;
    heapifyUp(size);
    size++;
}

template <class T>
bool Heap<T>::isFull()
{
    return size == capatity;
}

template <class T>
T Heap<T>::extractMax()
{
    if (isEmpty())
    {
        throw std::runtime_error("Heap is Empty!");
    }

    T data = this->heap[0];
    std::swap(this->heap[0], this->heap[--size]);
    heapifydown(0);

    return data;
}

template <class T>
bool Heap<T>::isEmpty()
{
    return size == 0;
}

template <class T>
T Heap<T>::getMax()
{
    return this->heap[0];
}

template <class T>
void Heap<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << this->heap[i] << " ";
    }

    std::cout << std::endl;
}