#include "Tree.cpp"
#include <cstdlib>
#include <queue>
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

/* Create a binary tree with minimal height, given a sorted, increasing array */
TreeNode* createMinHeightTree(std::vector<int>& vals) 
{
    if (vals.empty()) { return nullptr; };

    std::queue<TreeNode*> to_visit;
    TreeNode* root = new TreeNode{vals[0]};
    to_visit.push(root);

    for (int i = 1; i < vals.size(); ++i) 
    {
        TreeNode* curNode = to_visit.front();
        TreeNode* newNode = new TreeNode{vals[i]};
        if (curNode->left == nullptr) 
        {
            curNode->left = newNode;
        }
        else 
        {
            curNode->right = newNode;
            to_visit.pop();
        }
        to_visit.push(newNode);
    }
    return root;
}

int main()
{
    Tree test_tree = createTree();
    assert(!isBalanced(test_tree.getRoot()));
    test_tree.getRoot()->right->right->right = new TreeNode{9};
    test_tree.getRoot()->left->right->right = new TreeNode{8};
    test_tree.getRoot()->left->right->left = new TreeNode{7};
    test_tree.getRoot()->left->left->right = new TreeNode{6};
    test_tree.getRoot()->left->left->left = new TreeNode{5};
    test_tree.printTree(Traversal::InOrder);
    assert(isBalanced(test_tree.getRoot()));
    std::cout << "Pretty printing...\n";
    test_tree.prettyPrint();
    
    std::cout << "Testing min height tree...\n";
    std::vector<int> test_vec {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode* res = createMinHeightTree(test_vec);
    test_tree = Tree{res};
    test_tree.prettyPrint();
};
