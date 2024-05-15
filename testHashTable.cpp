#include "HashTable.cpp"
#include <string>

int main() {
    HashTable<int, std::string, 10> hashTable{};
    hashTable.insert(101, "Benji");
    hashTable.insert(201, "Tom");
    hashTable.insert(301, "Albert");
    hashTable.insert(401, "Sachin");
    hashTable.insert(501, "Oli");
    hashTable.insert(601, "Antho");
    hashTable.insert(272, "Seb");
    hashTable.insert(349, "James");
    hashTable.insert(111, "Ethan");
    hashTable.insert(595, "Paras");
    hashTable.insert(108, "Jacob");
    hashTable.printTable();
}
