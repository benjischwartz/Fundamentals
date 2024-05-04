#include <algorithm>
#include <cstddef>
#include <regex>
#include <vector>
#include <iostream>

/*
 * Sorts in-place, constant amount of extra space.
 * Affects run-time complexity.
 */

void print_vector(std::vector<int>& v);
std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
    std::cout << "in merge...\n";
    std::cout << " a is ";
    print_vector(a);
    std::cout << " b is ";
    print_vector(b);
    std::vector<int> res;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res.push_back(a[i]);
            ++i;
        }
        else {
            res.push_back(a[j]);
            ++j;
        }
    }
    while (i < a.size()) {
        res.push_back(a[i]);
        ++i;
    }
    while (j < b.size()) {
        res.push_back(b[j]);
        ++j;
    }
    return res;
}

std::vector<int> mergesort(std::vector<int>& v, size_t start, size_t end) {
    if (v.size() == 1) {
        return v;
    }
    std::vector<int> left = mergesort(v, start, end / 2);
    std::vector<int> right = mergesort(v, end / 2 + 1, end);
    return merge(left, right);
}

void print_vector(std::vector<int>& v) {
    std::cout << "{";
    for (auto x : v) {
        std::cout << x << ", ";
    }
    std::cout << "\b\b}\n";
}


int main() {
    std::vector<int> v1{1, 4, 2, 7, 4, 6, 4, 2, 1, 4, 22, 43, 3, 3, 22, 12, 10, 24, 2, 2, 34, 10};
    std::cout << "Before sorting...\n";
    print_vector(v1);
    v1 = mergesort(v1, 0, v1.size() - 1);
    std::cout << "After sorting...\n";
    print_vector(v1);
}



