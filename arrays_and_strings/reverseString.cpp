#include <iostream>

// reverse a C-style string e.g. abcd\0
void reverse(char* str) {
    if (str != nullptr) {
        char* end = str;
        char* start = str;
        while (*end != '\0') {
            ++end;
        }
        --end;
        while (start < end) {
            char temp = *end;
            *end = *start;
            *start = temp;
            ++start;
            --end;
        }
    }
}

int main() {
    char c_string[] = "abcd";
    std::cout << "Reversing..." << std::endl;
    std::cout << "Before: " << c_string << std::endl;
    reverse(c_string);
    std::cout << "After: " << c_string << std::endl;
}
