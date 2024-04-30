#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

/*
 * Select a pivot element randomly.
 * Seperate remaining into two piles (one smaller, one larger)
 * Sort piles by same process of dividing each of the two piles
 * until each pile only has one element left.
 * Combine sorted piles: when all sub piles are sorted put them together
 * in order such that smalelst is on the left and largest on the right.
 *
 * Divide and conquer like merge sort but not extra space for sorting.
 *
 * Use median-of-three to choose pivot
 */

#define TEST_MAX 100000

void print_vector(std::vector<int>& v);

int get_pivot_idx(std::vector<int>& v, size_t begin, size_t end) {
    int middle_idx = begin + (end - begin) / 2;
    int first = v[begin];
    int middle = v[middle_idx];
    int last = v[end];
    int res;
    if (first >= middle && first <= last || first >= last && first <= middle) {
        res = begin;
    }
    else if (middle >= first && middle <= last || middle >= last && middle <= first) {
        res = middle_idx;
    }
    else {
        res = end;
    }
    return res;
}

void quicksort(std::vector<int>& v, size_t begin, size_t end) {

    if (begin >= end) {
        return;
    }

    if (end - begin == 1) {
        if(v[begin] > v[end]) {
            int temp = v[end];
            v[end] = v[begin];
            v[begin] = temp;
        }
        return;
    }
    int pivot = get_pivot_idx(v, begin, end);
    
    // swap pivot and last elem
    int temp = v[end];
    v[end] = v[pivot];
    v[pivot] = temp;

    int item_from_left;

    int item_from_right;

    while (true) 
    {
        for (int i = begin; i < end; ++i) {
            if (v[i] > v[end]) {
                item_from_left = i;
                break;
            }
        }
        for (int i = end - 1; i >= begin; --i) {
            if (v[i] < v[end]) {
                item_from_right = i;
                break;
            }
        }
        if (item_from_right < item_from_left) {
            break;
        }

        // Swap
        int temp = v[item_from_right];
        v[item_from_right] = v[item_from_left];
        v[item_from_left] = temp;

    }

    // Swap pivot and item_from_left
    temp = v[item_from_left];
    v[item_from_left] = v[end];
    v[end] = temp;

    // Recursively sort left and right subarrays
    quicksort(v, begin, item_from_left - 1);
    quicksort(v, item_from_left + 1, end);
}

void print_vector(std::vector<int>& v) {
    std::cout << "{";
    for (auto x : v) {
        std::cout << x << ", ";
    }
    std::cout << "\b\b}\n";
}


int main() {
    std::cout << "Running Quicksort...\n" << std::endl;

    std::cout << "TEST 1: \n";
    std::vector<int> test_input {2, 6, 5, 0, 8, 7, 1, 3};
    std::cout << "Before sorting:\n";
    print_vector(test_input);
    quicksort(test_input, 0, test_input.size() - 1);
    std::cout << "After sorting:\n";
    print_vector(test_input);

    std::cout << "TEST 2: \n";
    test_input.clear();
    for (int i = 0; i < TEST_MAX; ++i) {
        test_input.push_back(std::rand());
    }
    std::vector<int> result = test_input;

    auto t1 = std::chrono::high_resolution_clock::now();
    std::sort(result.begin(), result.end());
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_std_sort = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

    t1 = std::chrono::high_resolution_clock::now();
    quicksort(test_input, 0, test_input.size() - 1);
    t2 = std::chrono::high_resolution_clock::now();
    auto ms_quicksort = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

    if (result == test_input) {
        std::cout << "Test passed...\n";
        std::cout << "Your runtime: " << ms_quicksort.count() << "ms.\n";
        std::cout << "std::sort runtime: " << ms_std_sort.count() << "ms.\n";
    }
    else {
        std::cout << "Test failed...\n";
    }
}

