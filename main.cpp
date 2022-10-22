#include <iostream>
#include "Heap.h"

int main() {
    Heap<int> heap;
    heap.push(0);
    heap.push(1);
    heap.push(2);
    heap.push(3);
    heap.push(4);
    heap.push(5);
    heap.push(6);
    heap.push(7);
    heap.push(8);
    heap.pop();
    std::cout <<heap.top();

    return 0;

}

