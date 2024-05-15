#include <string>

#define ALPHABET_SIZE 26
#define ROOT_CHAR -1

struct TrieNode {
    TrieNode* children [ALPHABET_SIZE];
    bool terminal = false;
    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        m_root = new TrieNode();
    }
   
    void insert(std::string word);
    
    bool search(std::string word);     
    
    bool startsWith(std::string prefix);

private:
    TrieNode* m_root;
};

