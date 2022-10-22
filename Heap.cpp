//
// Created by Johnathan Hwang on 10/14/22.
//

#ifndef HEAP_HEAP_CPP
#define HEAP_HEAP_CPP
#include "Heap.h"

template<class T>
int Heap<T>::getParent(int child) {
    int parent;
    parent = (child - 1)/2;
    return parent;
}

template<class T>
int Heap<T>::getLeftChild(int parent) {
    int leftChild;
    leftChild = (2 * parent)+ 1;
    return leftChild;
}

template<class T>
int Heap<T>::getRightChild(int parent) {
    int rightChild;
    rightChild = (2 * parent )+ 2;
    return rightChild;
}

template<class T>
void Heap<T>::reHeapifyUp(int child) {
    int parent = getParent(child);
    if (data[child] > data[parent] && parent <= data.size()-1) {
        swap(parent,child);
        reHeapifyUp(parent);
    }
    else {
        return ;
    }

}

template<class T>
void Heap<T>::reHeapifyDown(int parent) {

    int maxChild = parent;
    int leftChild = getLeftChild(parent);
    int rightChild = getRightChild(parent);

    if (data[maxChild] < data[leftChild] && data[leftChild] > data[rightChild] && maxChild <= (data.size() - 1)) {
        swap(parent, leftChild);
        reHeapifyDown(leftChild);
    }
    else if (data[maxChild] < data[rightChild] && data[rightChild] > data[leftChild] && maxChild <= (data.size() - 1)) {
        swap(parent, rightChild);
        reHeapifyDown(rightChild);
    }
    else {
        return;
    }
}

template<class T>
void Heap<T>::swap(int parent, int child) {
    int temp;
    temp = data[parent];
    data[parent] = data[child];
    data[child] = temp;
}

template<class T>
void Heap<T>::push(const T &item) {
    data.push_back(item);
    reHeapifyUp(data.size() -1);
}

template<class T>
T Heap<T>::pop() {
    T temp = data[0];
    data[0] = data[data.size()-1];
    data.pop_back();
    reHeapifyDown(0);
    return temp;
}

template<class T>
T &Heap<T>::top() {
    return data[0];
}

template<class T>
int Heap<T>::size() {
    return data.size();
}

template<class T>
bool Heap<T>::empty() {
    if (data.empty()) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
T &Heap<T>::search(const T &item) {
    return std::search(data.begin(), data.end(), item);
}

#endif