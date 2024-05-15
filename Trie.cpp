#include "Trie.h"

void Trie::insert(std::string word) {
    TrieNode* curNode = m_root;
    for (auto c : word) {
        if (curNode->children[c - 'a'] == nullptr) {
            TrieNode* newNode = new TrieNode;
            curNode->children[c - 'a'] = newNode;
        }
        curNode = curNode->children[c - 'a'];
    }
    curNode->terminal = true;
}

bool Trie::search(std::string word) {
    TrieNode* curNode = m_root;
    for (auto c : word) {
        if (curNode->children[c - 'a'] == nullptr) {
            return false;
        }
        curNode = curNode->children[c - 'a'];
    }
    if (!curNode->terminal) {
        return false;
    }
    return true;
}

bool Trie::startsWith(std::string prefix) {
    TrieNode* curNode = m_root;
    for (auto c : prefix) {
        if (curNode->children[c - 'a'] == nullptr) {
            return false;
        }
        curNode = curNode->children[c - 'a'];
    }
    return true;
}
