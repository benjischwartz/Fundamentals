#include <iostream>
#include <unordered_set>

struct TreeNode {
    int val;    
    TreeNode* left;
    TreeNode* right;
};

enum Traversal {
    InOrder, /* left -> current -> right */
    PreOrder, /* current -> left -> right */
    PostOrder, /* left -> right -> current */
};

class Tree {
public:
    Tree(TreeNode* root) : root(root) {};
    void printTree(Traversal);
    void insert(int val);
    TreeNode* getRoot() { return root; };
private:
    TreeNode* root;
    void inOrderHelper(std::unordered_set<TreeNode*>&, TreeNode*);
    void preOrderHelper(std::unordered_set<TreeNode*>&, TreeNode*);
    void postOrderHelper(std::unordered_set<TreeNode*>&, TreeNode*);
};

void Tree::printTree(Traversal t) {
    std::unordered_set<TreeNode*> visited;
    switch (t)
    {
        case Traversal::InOrder:
          inOrderHelper(visited, root);
          
        case Traversal::PreOrder:
            preOrderHelper(visited, root);
            
        case Traversal::PostOrder:
            postOrderHelper(visited, root);
            
    }
    std::cout << "END \n";
}

void Tree::inOrderHelper(std::unordered_set<TreeNode*>& visited, TreeNode* node) {
    if (node->left != nullptr && !visited.count(node->left)) {
        inOrderHelper(visited, node->left);
    }
    if (!visited.count(node)) {
        std::cout << node->val << " -> ";
        visited.insert(node);
    }
    if (node->right != nullptr && !visited.count(node->right)) {
        inOrderHelper(visited, node->right);
    }
}

void Tree::preOrderHelper(std::unordered_set<TreeNode*>& visited, TreeNode* node) {
    if (!visited.count(node)) {
        std::cout << node->val << " -> ";
        visited.insert(node);
    }
    if (node->left != nullptr && !visited.count(node->left)) {
        preOrderHelper(visited, node->left);
    }
    if (node->right != nullptr && !visited.count(node->right)) {
        preOrderHelper(visited, node->right);
    }
}

void Tree::postOrderHelper(std::unordered_set<TreeNode*>& visited, TreeNode* node) {
    if (node->left != nullptr && !visited.count(node->left)) {
        postOrderHelper(visited, node->left);
    }
    if (node->right != nullptr && !visited.count(node->right)) {
        postOrderHelper(visited, node->right);
    }
    if (!visited.count(node)) {
        std::cout << node->val << " -> ";
        visited.insert(node);
    }
}

Tree createTree();

int main2() {
    Tree testTree = createTree();
    testTree.printTree(Traversal::PreOrder);
    testTree.printTree(Traversal::InOrder);
    testTree.printTree(Traversal::PostOrder);
    return 0;
}


Tree createTree() {
    TreeNode* root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->right = new TreeNode{3};
    root->left->left = new TreeNode{4};
    root->left->right = new TreeNode{5};
    root->right->right = new TreeNode{6};
    root->right->right->left = new TreeNode{7};
    root->right->right->left->right = new TreeNode{8};
    return Tree{root};
}
