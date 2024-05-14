#include <string>

#define ALPHABET_SIZE 26
#define ROOT_CHAR -1

struct TrieNode {
    TrieNode(char v) : value(v) {};
    char value;
    bool is_terminal = false;
    TrieNode** children [ALPHABET_SIZE];
};

class Trie {
public:
    Trie() {
        root = new TrieNode(ROOT_CHAR);
    }
   
    void insert(std::string word) {
        TrieNode* cur = root;
        int i = 0;
        // DFS until null child node is encountered.
        while (i < word.size() && cur->children[word[i] - 'a'] != nullptr) {
            cur = *cur->children[word[i] - 'a'];
            ++i;
        }
        // add nodes as needed
        while (i < word.size()) {
            TrieNode* new_node = new TrieNode(word[i]);
            cur[word[i] - 'a'] = *new_node;
        }
        // mark final node as terminal

    }
    
    bool search(std::string word) {
        return true;
        
    }
    
    bool startsWith(std::string prefix) {
        return true;
    }
private:
    TrieNode* root;
};

