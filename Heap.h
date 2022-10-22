//
// Created by Johnathan Hwang on 10/14/22.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include <iostream>
#include <cassert>
#include <vector>

template<class T>
class Heap {
private:
    std::vector<T> data;
    int getParent(int child);
    int getLeftChild(int parent);
    int getRightChild(int parent);
    void reHeapifyUp(int child);
    void reHeapifyDown(int parent);
    void swap(int parent, int child);

public:
    void push(const T& item);
    T pop();
    T& top();
    int size();
    bool empty();
    T& search(const T& item);
};


#include "Heap.cpp"
#endif //HEAP_HEAP_H
