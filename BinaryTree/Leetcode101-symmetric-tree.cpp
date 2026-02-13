struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (root == nullptr) return true;
            return compare(root->left, root->right);
        }

        bool compare(TreeNode* left, TreeNode* right) {
            if (left == nullptr && right == nullptr) {
                return true;
            } else if (left == nullptr && right != nullptr) {
                return false;
            } else if (left != nullptr && right == nullptr) {
                return false;
            } else if (left->val != right->val) {
                return false;
            } else {
                // 此时, 左右子节点均不为空且值相等, 递归判断下一层
                bool outside = compare(left->left, right->right);
                bool inside = compare(left->right, right->left);
                bool same = outside && inside;
                return same;
            }
        }
    };