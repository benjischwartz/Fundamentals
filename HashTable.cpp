#include "HashTable.h"
#include <cstdlib>
#include <iostream>

template class Item <int, std::string>;
template class HashTable<int, std::string, 10>;

template <typename K, typename V, size_t N>
HashTable<K, V, N>::HashTable() {
    m_items = (Item<K, V>**) malloc(N * sizeof(Item<K, V>));
    for (size_t i = 0; i < N; ++i) {
        m_items[i] = nullptr;
    }
};

template <typename K, typename V, size_t N>
void HashTable<K, V, N>::insert(K key, V val) {
    Item<K, V>* newItem = new Item<K, V> {key, val, (Item<K, V>*) nullptr};
    auto hash = getHash(key);
    if (m_items[hash] == nullptr) {
        m_items[hash] = newItem;
    }
    else {
        auto cur = m_items[hash];
        while (cur->next != nullptr) {
            cur = cur->next;            
        }
        cur->next = newItem;
    }
}

template <typename K, typename V, size_t N>
void HashTable<K, V, N>::printTable() const {
    for (int i = 0; i < N; ++i) {
        std::cout << "Bucket " << i << ":\n";
        auto cur = m_items[i];
        while (cur != nullptr) {
            std::cout << "{Key: " << cur->key << ", Value: " << cur->value << "}\n";
            cur = cur->next;
        }
    }
}


/*
template <typename K, typename V, size_t N>
void HashTable<K, V, N>::erase(K key) {
    auto hash = getHash(key);
    auto cur = m_items[hash];
    while (cur != nullptr) {
        
    }
}
*/

/*
    void insert(K, V);
    void erase(K);
    bool empty() const;
    size_t size() const;
    void clear();
    V operator[](K);
    bool contains(K) const;
private:
    Item<K, V>** items;
    size_t m_size;
    size_t count;
    size_t getHash(K key) const {
        std::hash<K> hashFunc;
        return hashFunc(key);
    }
};
*/

