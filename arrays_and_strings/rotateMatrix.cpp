#include <iomanip>
#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>>& matrix, int n) {
    for (auto row : matrix) {
        for (auto cell : row) {
            std::cout << "[" << std::setw(2) << cell << "] ";
        }
        std::cout << std::endl;
    }
}

// Rotate an N x N matrix by 90 degrees
void rotateMatrix(std::vector<std::vector<int>>& matrix, int n) {
    // Go layer by layer
    for (int layer = 0; layer < n / 2; ++layer) {
        int start = layer;
        int end = n - 1 - layer;
        for (int i = start; i < end; ++i) {
            int offset = i - start;
            // Save top
            int top = matrix[layer][start];

            // Rotate left to top
            matrix[layer][start] = matrix[end - start][layer];

            // Rotate bottom to left
            matrix[end - start][layer] = matrix[end][end - start];

            // Rotate right to bottom
            matrix[end][end - start] = matrix[start][end];

            // Rotate top to right
            matrix[start][end] = top;

            ++start;
        }
    }
}

std::vector<std::vector<int>> generate_matrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int val = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = val;
            ++val;
        }
    }
    return matrix;
}

int main() {
    int n = 4;
    auto test_matrix = generate_matrix(n);

    std::cout << "Testing...\n";

    std::cout << "Before:\n";
    printMatrix(test_matrix, n);
    rotateMatrix(test_matrix, n);
    std::cout << "After:\n";
    printMatrix(test_matrix, n);

    n = 8;
    test_matrix = generate_matrix(n);
    std::cout << "Before:\n";
    printMatrix(test_matrix, n);
    rotateMatrix(test_matrix, n);
    std::cout << "After:\n";
    printMatrix(test_matrix, n);
}
