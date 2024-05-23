#include <cstddef>
#include <iostream>
#include <vector>

#define DEFAULT_SIZE 64

/* Implement a queue using two stacks */
template <typename T>
class MyQueue 
{
public:
    void enqeue(T val);
    T dequeue();
    T peek();
    size_t size() { return stack1.size() + stack2.size(); };
    void displayQueue();
private:
    std::vector<T> stack1; /* Stores elements with newest on top */
    std::vector<T> stack2; /* Stores elements with oldest on top */
    
};

template<typename T>
void MyQueue<T>::enqeue(T val) 
{
    while (!stack2.empty()) 
    {
        stack1.push_back(stack2.back());
        stack2.pop_back();
    }
    stack1.push_back(val);
}


template<typename T>
T MyQueue<T>::dequeue() 
{
    while (!stack1.empty()) 
    {
        stack2.push_back(stack1.back());
        stack1.pop_back();
    }
    if (stack2.empty()) 
    {
        return -1;
    }
    T val = stack2.back();
    stack2.pop_back();
    return val;
}

template<typename T>
T MyQueue<T>::peek() 
{
    while (!stack1.empty()) 
    {
        stack2.push_back(stack1.back());
        stack1.pop_back();
    }
    if (stack2.empty()) 
    {
        return -1;
    }
    return stack2.back();
}

template<typename T>
void MyQueue<T>::displayQueue() {
    std::cout << "STACK 1:\n";
    for (auto x : stack1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "STACK 2:\n";
    for (auto x : stack2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    MyQueue<int> test_queue;
    for (int i = 0; i < 10; ++i) {
        test_queue.enqeue(i);
    }
    test_queue.displayQueue();
    assert(test_queue.size() == 10);
    assert(test_queue.peek() == 0);
    assert(test_queue.dequeue() == 0);
    assert(test_queue.size() == 9);
    test_queue.displayQueue();
    test_queue.enqeue(15);
    test_queue.displayQueue();
}
