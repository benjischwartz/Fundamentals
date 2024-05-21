#include <iomanip>
#include <iostream>
#include <ostream>
#include <set>
#include <vector>

void printMatrix(std::vector<std::vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto cell : row) {
            std::cout << "[" << std::setw(2) << cell << "] ";
        }
        std::cout << std::endl;
    }
}

void setMatrixZero(std::vector<std::vector<int>>& matrix, int m, int n) {
    std::set<int> zeroRows;
    std::set<int> zeroCols;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                zeroRows.insert(i);
                zeroCols.insert(j);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (zeroRows.count(i)) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
        else {
            for (int j = 0; j < n; ++j) {
                if (zeroCols.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

std::vector<std::vector<int>> generate_random_matrix(int m, int n, int max) {
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % max;
        }
    }
    return matrix;
}

void run_test(int m, int n, int max) {

    auto test_matrix = generate_random_matrix(m, n, max);
    std::cout << "Before:\n";
    printMatrix(test_matrix);
    setMatrixZero(test_matrix, m, n);
    std::cout << "After:\n";
    printMatrix(test_matrix);
}

int main() {
    std::cout << "Testing...\n";
    run_test(5, 4, 3);
    run_test(10, 8, 20);
}
