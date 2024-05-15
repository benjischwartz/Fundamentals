#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class MedianHeap {

public:
    void insert(int);
    
    int getMedian() const;

private:
    std::vector<int> m_topHeap; /* Is a Min-Heap */
    
    std::vector<int> m_bottomHeap; /* Is a Max-Heap */

    void balance();
};

void MedianHeap::insert(int val) {
    if (m_topHeap.empty()) {
        m_topHeap.push_back(val);
    }
    else if (m_bottomHeap.empty()) {
        m_bottomHeap.push_back(val);
    }
    else if (val >= m_topHeap.front()) {
        m_topHeap.push_back(val);
        std::push_heap(m_topHeap.begin(), m_topHeap.end(), std::greater<>{});
    }
    else {
        m_bottomHeap.push_back(val);
        std::push_heap(m_bottomHeap.begin(), m_bottomHeap.end());
    }
    balance();
}

int MedianHeap::getMedian() const {
    if (m_topHeap.size() > m_bottomHeap.size()) {
        return m_topHeap.front();
    }
    else if (m_bottomHeap.size() > m_topHeap.size()) {
        return m_bottomHeap.front();
    }
    else {
        return (m_topHeap.front() + m_bottomHeap.front()) / 2;
    }
}


void MedianHeap::balance() {
    while (static_cast<int>(m_topHeap.size() - m_bottomHeap.size()) > 1) {
        std::pop_heap(m_topHeap.begin(), m_topHeap.end(), std::greater<>{});
        auto top = m_topHeap.back();
        m_bottomHeap.push_back(top);
        std::push_heap(m_bottomHeap.begin(), m_bottomHeap.end());
        m_topHeap.pop_back();
    }
    while (static_cast<int>(m_bottomHeap.size() - m_topHeap.size()) > 1) {
        std::pop_heap(m_bottomHeap.begin(), m_bottomHeap.end());
        auto top = m_bottomHeap.back();
        m_topHeap.push_back(top);
        std::push_heap(m_topHeap.begin(), m_topHeap.end(), std::greater<>{});
        m_bottomHeap.pop_back();
    }
}

/* For testing only */
int get_median(std::vector<int>& v) {
    if (v.empty()) {
        return 0;
    }
    std::sort(v.begin(), v.end());
    size_t mid = v.size() / 2 - 1;
    if (v.size() % 2 == 0) {
        return ((v[mid] + v[mid + 1])) / 2;
    }
    return v[mid];
}

void run_test(int seed) {
    MedianHeap medianHeap{};
    std::vector<int> testVec;
    srand(seed);
    for (int i = 0; i < 1000; ++i) {
        int r = rand() % 1000;
        medianHeap.insert(r);
        testVec.push_back(r);
    }
    std::cout << "Median: " << medianHeap.getMedian() << std::endl;
    std::cout << "Sample: " << get_median(testVec) << std::endl;
}

int main() {
    std::cout << "Runing tests...\n";
    run_test(10);
    run_test(42);
    run_test(7);
    run_test(4);
    run_test(81);
}
