#include <iostream>

// Replaces spaces with "%20"
void replaceSpaces(char* str) {
    char* cur = str;
    int space_count = 0;
    while (*cur != '\0') {
        if (*cur == ' ') {
            ++space_count;
        }
        ++cur;
    }
    std::cout << "space count: " << space_count << std::endl;
    int extra_chars = 2 * space_count;

    char* new_cur = cur + extra_chars;
    *new_cur = '\0';
    --cur; // cur is at last letter
    --new_cur;

    while (cur >= str) {
        if (*cur == ' ') {
            *new_cur = '0';
            --new_cur;
            *new_cur = '2';
            --new_cur;
            *new_cur = '%';
        }
        else {
            *new_cur = *cur;
        }
        --new_cur;
        --cur;
    }
}

int main() {
    std::cout << "Testing...\n";
    char test_string1[] = "hello world!  ";
    std::cout << "Before: " << test_string1 << std::endl;
    replaceSpaces(test_string1);
    std::cout << "After: " << test_string1 << std::endl;
}
