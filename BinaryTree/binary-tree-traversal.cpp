#include<vector>
#include<stack>
#include<string>
using namespace std;

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
    // 使用pair标记是否访问过：{节点, 是否已处理}
    vector<int> unifiedTraversal(TreeNode* root, string order) {
        vector<int> result;
        if (!root) return result;
        
        stack<pair<TreeNode*, bool>> stk;
        stk.push({root, false});
        
        while (!stk.empty()) {
            auto [node, visited] = stk.top(); stk.pop();
            
            if (!node) continue;
            
            if (visited) {
                // 已处理过子树，直接访问
                result.push_back(node->val);
            } else {
                // 未处理，按遍历顺序的逆序入栈（右中左、右左中、中右左）
                if (order == "preorder") {      // 根左右 → 右左根
                    stk.push({node->right, false});
                    stk.push({node->left, false});
                    stk.push({node, true});
                } else if (order == "inorder") { // 左根右 → 右根左
                    stk.push({node->right, false});
                    stk.push({node, true});
                    stk.push({node->left, false});
                } else {                         // 左右根 → 根右左
                    stk.push({node, true});
                    stk.push({node->right, false});
                    stk.push({node->left, false});
                }
            }
        }   
        return result;
    }
    // 递归遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalHelper(root, result);
        return result;
    }

    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            result.push_back(current->val);
            current = current->right;
        }
        return result;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversalHelper(root, result);
        return result;
    }

    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            result.push_back(current->val);
            if (current->right != nullptr) {
                s.push(current->right);
            }
            if (current->left != nullptr) {
                s.push(current->left);
            }
        }
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversalHelper(root, result);
        return result;
    }

    vector<int> postorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode*> s;
        TreeNode* current = root;
        TreeNode* prev = nullptr;

        while (current != nullptr || !s.empty()) {
            // 遍历左子树
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            TreeNode* top = s.top();
            if (top->right == nullptr || top->right == prev) {
                result.push_back(top->val);
                prev = top;
                s.pop();
            } else {
                current = top->right;
            }
        }
        return result;
    }

    void inorderTraversalHelper(TreeNode* current, vector<int>& result) {
        if (current == nullptr) {
            return;
        }
        inorderTraversalHelper(current->left, result);
        result.push_back(current->val);
        inorderTraversalHelper(current->right, result);
    }

    void preorderTraversalHelper(TreeNode* current, vector<int>& result) {
        if (current == nullptr) {
            return;
        }
        result.push_back(current->val);
        preorderTraversalHelper(current->left, result);
        preorderTraversalHelper(current->right, result);
    }

    void postorderTraversalHelper(TreeNode* current, vector<int>& result) {
        if (current == nullptr) {
            return;
        }
        postorderTraversalHelper(current->left, result);
        postorderTraversalHelper(current->right, result);
        result.push_back(current->val);
    }
};