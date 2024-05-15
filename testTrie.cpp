#include "Trie.h"
#include <cassert>
#include <iostream>

int main() {
    std::cout << "Running tests...\n";
    Trie* trie = new Trie();
    trie->insert("apple");
    assert(trie->search("apple") == true);
    assert(trie->search("app") == false);
    assert(trie->startsWith("app") == true);
    trie->insert("app");
    assert(trie->search("app") == true);
    std::cout << "Tests passed!\n";
    return 0;
}
