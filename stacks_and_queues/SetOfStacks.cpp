#include <iostream>
#include <vector>

#define MAX_STACK_SIZE 10

class SetOfStacks {
public:
    void push(int val);
    int pop();
    bool empty() { return stack_vec.empty(); };
    int peek() { return empty() ? -1 : stack_vec.back()[idx - 1]; };
    void displayStacks();

private:
    std::vector<std::vector<int>> stack_vec;
    int idx;
};

void SetOfStacks::push(int val) {
    if (stack_vec.empty() || idx == MAX_STACK_SIZE) 
    {
        idx = 0;
        std::vector<int> new_stack(MAX_STACK_SIZE);
        new_stack[idx] = val;
        stack_vec.push_back(new_stack);
    }
    else 
    {
        stack_vec.back()[idx] = val;
    }
    ++idx;
}

int SetOfStacks::pop() {
    if (stack_vec.empty()) { return -1; }
    if (idx == 0) 
    {
        stack_vec.pop_back();
        if (stack_vec.empty()) {
            return -1;
        }
        idx = MAX_STACK_SIZE - 1;
        return stack_vec.back()[idx];
    }
    else 
    {
        --idx;
        return stack_vec.back()[idx];
    }
}

void SetOfStacks::displayStacks() {
    int i = 0;
    while (i < stack_vec.size()) {
        std::cout << "STACK " << i << ":\n{ ";
        if (i == stack_vec.size() - 1) {
            for (int j = 0; j < idx; ++j) {
                std::cout << stack_vec[i][j] << " ";
            }
        }
        else {
            for (int j = 0; j < MAX_STACK_SIZE; ++j) {
                std::cout << stack_vec[i][j] << " ";
            }
        }
        std::cout << "}\n";
        ++i;
    }
}

int main() {
    auto test_stack = SetOfStacks();
    std::cout << "Testing...\n";
    std::cout << "Pushing to stack...\n";
    for (int i = 0; i < 40; ++i) {
        test_stack.push(rand() % 10);
    }
    test_stack.displayStacks();
    std::cout << "Popping from stack...\n";
    for (int i = 0; i < 35; ++i) {
        test_stack.pop();
    }
    test_stack.displayStacks();
}
