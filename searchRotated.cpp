#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        // in left sorted subarray
        if (nums[mid] >= nums[lo]) {
            // Search left
            if (nums[mid] > target && nums[lo] <= target) {
                hi = mid - 1;
            }
            // Search right
            else {
                lo = mid + 1;
            }
        }
        // in right sorted subarray
        else {
            // Search right
            if (nums[mid] < target && nums[hi] >= target) {
                lo = mid + 1;
            }
            // Search left
            else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

void test_search(std::vector<int>& nums, int target) {
    std::cout << "Searching for " << target << std::endl;
    std::cout << "Result: index = " << search(nums, target) << std::endl;
}

int main() {
    std::vector<int> v1 {4, 5, 6, 7, 0, 1, 2, 3};
    std::cout << "Running test...\n";
    std::cout << "Test vector: {";
    for (auto x : v1) {
        std::cout << x << ", ";
    }
    std::cout << "\b\b}\n";
    for (int i = 0; i < 9; ++i) {
        test_search(v1, i);
    }
}
