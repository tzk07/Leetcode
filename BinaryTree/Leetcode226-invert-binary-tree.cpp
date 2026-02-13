#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
// 采用 先序遍历 的顺序, 交换节点的左右子节点
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if (!root) return nullptr;
            std::swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
    };