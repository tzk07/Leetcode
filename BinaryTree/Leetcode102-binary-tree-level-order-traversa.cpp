#include <algorithm>
#include <cstddef>
#include<vector>
#include<queue>
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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> result;
            queue<TreeNode*> q;
            if (root != nullptr) {
                q.push(root);
            }
            while (!q.empty()) {
                size_t size = q.size();
                vector<int> vec;
                for (size_t i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    vec.push_back(node->val);
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                result.push_back(vec);
            }
            return result;
        }

        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> result;
            queue<TreeNode*> q;
            if (root != nullptr) {
                q.push(root);
            }
            while (!q.empty()) {
                size_t size = q.size();
                vector<int> vec;
                for (size_t i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    vec.push_back(node->val);
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                result.push_back(vec);
            }
            reverse(result.begin(), result.end());
            return result;
        }
    };