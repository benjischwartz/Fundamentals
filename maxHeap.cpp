#include <cassert>
#include <vector>
#include <iostream>

class MaxHeap {
public:
    void insert(int val);
    bool isEmpty() { return _size == 0; };
    int getMax();
    int extractMax();
    size_t size() { return _size; };
    void printHeap();

private:
    std::vector<int> vec{-1};
    size_t _size{};
    int p(int i) { return i >> 1; };
    int l(int i) { return i << 1; };
    int r(int i) { return (i << 1) + 1; };
    void shiftDown(int i);
    void shiftUp(int i);
};

void MaxHeap::insert(int val) {
    if (_size + 1 >= vec.size()) {
        vec.push_back(0);
    }
    vec[++_size] = val;
    shiftUp(_size);
    return;
}

int MaxHeap::getMax() {
    return isEmpty() ? 0 : vec[1];
}

int MaxHeap::extractMax() {
    int max = 0;
    if (!isEmpty()) {
        max = vec[1];
        std::swap(vec[1], vec[_size]);
        --_size;
        shiftDown(1);
    }
    return max;
}

void MaxHeap::shiftUp(int i) {
    if (i > _size || i == 1) { return; }
    if (vec[p(i)] < vec[i]) {
        std::swap(vec[p(i)], vec[i]);
        shiftUp(p(i));
    }
    return;
};


void MaxHeap::shiftDown(int i) {
    if (i > _size) { return; }
    int swapId;
    if (l(i) <= _size && vec[l(i) > vec[i]]) {
        swapId = l(i);
    }
    if (r(i) <= _size && vec[r(i)] > vec[swapId]) {
        swapId = r(i);
    }
    if (swapId != i) {
        std::swap(vec[i], vec[swapId]);
        shiftDown(swapId);
    }
    return;
};

void MaxHeap::printHeap() {
    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    MaxHeap* priorityQueue = new MaxHeap{};
    assert(priorityQueue->isEmpty());
    priorityQueue->insert(5);
    priorityQueue->insert(20);
    priorityQueue->insert(10);
    priorityQueue->insert(15);
    priorityQueue->insert(35);
    priorityQueue->insert(24);
    priorityQueue->insert(7);
    priorityQueue->insert(29);
    priorityQueue->printHeap();
    assert(!priorityQueue->isEmpty());
    assert(priorityQueue->size() == 8);
    int max = priorityQueue->extractMax();
    assert(priorityQueue->size() == 7);
    std::cout << max << std::endl;
    assert(max == 35);
    assert(priorityQueue->getMax() == 29);
    max = priorityQueue->extractMax();
    assert(max == 29);
    assert(priorityQueue->size() == 6);
    assert(priorityQueue->getMax() == 24);
}



















