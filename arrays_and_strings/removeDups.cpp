#include <iostream>

void removeDuplicates(char* str) {
    char* cur = str + 1;
    int tail = 1;
    while (*cur != '\0') {
        bool already_found = false;
        for (int i = 0; i < tail; ++i) {
            if (str[i] == *cur) {
                already_found = true;
                break;
            }
        }
        if (!already_found) {
            *(str + tail) = *cur;
            ++tail;
        }
        ++cur;
    }
    *(str + tail) = '\0';
}

int main() {
    std::cout << "Testing..." << std::endl;
    char test_string1[] = "aabbccdd";
    std::cout << "Before: " << test_string1 << std::endl;
    removeDuplicates(test_string1);
    std::cout << "After: " << test_string1 << std::endl;
    char test_string2[] = "hello, world!";
    std::cout << "Before: " << test_string2 << std::endl;
    removeDuplicates(test_string2);
    std::cout << "After: " << test_string2 << std::endl;
    char test_string3[] = "removingduplicates...abcdabcdabcdabcdabcd!";
    std::cout << "Before: " << test_string3 << std::endl;
    removeDuplicates(test_string3);
    std::cout << "After: " << test_string3 << std::endl;
    return 0;
}
