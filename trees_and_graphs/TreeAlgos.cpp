#include "Tree.cpp"
#include <cstdlib>
#include <unordered_set>

void dfsHeight(int& maxHeight, int& minHeight, TreeNode* node, int height);
    
/* no two leaf nodes differ in distance fro mthe root by > 1*/
bool isBalanced(TreeNode* root) { 
    std::unordered_set<int> leaf_heights;
    int minHeight = INT_MAX;    
    int maxHeight = 0;    
    dfsHeight(maxHeight, minHeight, root, 0);
    std::cout << "min height: " << minHeight << std::endl;
    std::cout << "max height: " << maxHeight << std::endl;
    return std::abs(maxHeight - minHeight) > 1 ? false : true;
}

void dfsHeight(int& maxHeight, int& minHeight, TreeNode* node, int height) {
    if (node->left != nullptr) {
        dfsHeight(maxHeight, minHeight, node->left, height + 1);
    }   
    if (node->right != nullptr) {
        dfsHeight(maxHeight, minHeight, node->right, height + 1);
    }   
    if (node->left == nullptr && node->right == nullptr) {
        minHeight = std::min(height, minHeight);
        maxHeight = std::max(height, maxHeight);
    }
}

int main()
{
    Tree test_tree = createTree();
    assert(!isBalanced(test_tree.getRoot()));
    test_tree.getRoot()->right->right->right = new TreeNode{9};
    test_tree.getRoot()->left->right->right = new TreeNode{10};
    test_tree.getRoot()->left->right->left = new TreeNode{11};
    test_tree.getRoot()->left->left->right = new TreeNode{12};
    test_tree.getRoot()->left->left->left = new TreeNode{13};
    test_tree.printTree(Traversal::InOrder);
    assert(isBalanced(test_tree.getRoot()));
};
