#include <cstddef>
#include <iterator>
#include <functional>

template <typename K, typename V>
struct Item {
    K key;
    V value;
    Item<K, V>* next;
};

/* Key type: K, Value type: V, num_buckets: N */
template <typename K, typename V, size_t N>
class HashTable {
public:
    HashTable();
    void insert(K, V);
    void erase(K);
    bool empty() const;
    size_t size() const;
    void clear();
    V operator[](K);
    bool contains(K) const;
    void printTable() const;
private:
    Item<K, V>** m_items;
    size_t m_size;
    size_t m_count;
    size_t getHash(K key) const {
        std::hash<K> hashFunc;
        return hashFunc(key) % N;
    }
};
