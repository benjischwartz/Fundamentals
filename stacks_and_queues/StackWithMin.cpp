#include <climits>
#include <iostream>
#include <vector>

struct StackNode {
    int val;
    int local_min;
};

class StackWithMin {
public:
    int min();
    void push(int val);
    int pop();
    StackNode peek();
private:
    std::vector<StackNode> elems;
};

int StackWithMin::min() {
    return elems.empty() ? INT_MAX : peek().local_min;
}

void StackWithMin::push(int val) {
    elems.push_back(StackNode{val, std::min(min(), val)});
}

int StackWithMin::pop() {
    if (elems.empty()) { return -1; };
    int val = elems.back().val;
    elems.pop_back();
    return val;
} 

StackNode StackWithMin::peek() {
    return elems.back();
}

int main() {
    StackWithMin test_stack;
    for (int i = 0; i < 10; ++i) {
        int val = rand() % 10;
        std::cout << "Pushing " << val << std::endl;
        test_stack.push(val);
        std::cout << "Min: " << test_stack.min();
        std::cout << std::endl;
    }
    for (int i = 0; i < 10; ++i) {
        int val = test_stack.pop();
        std::cout << "Popping " << val << std::endl;
        std::cout << "Min: " << test_stack.min();
        std::cout << std::endl;
    }
}
