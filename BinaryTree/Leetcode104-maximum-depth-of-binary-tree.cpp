#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 给定一个二叉树 root ，返回其最大深度。二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
// 通过 后序遍历, 先求子节点的最大深度, 当前节点的最大深度为 子节点最大深度 + 1

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            return getDepth(root);
        }

        int getDepth(TreeNode* node) {
            if (node == nullptr) return 0;
            int left_depth = getDepth(node->left);
            int right_depth = getDepth(node->right);
            int depth = 1 + std::max(left_depth, right_depth);
            return depth;
        }
    };