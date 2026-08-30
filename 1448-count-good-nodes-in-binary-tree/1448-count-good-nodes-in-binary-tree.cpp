/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 1;
        return ans + traverse(root->left, root->val) +
               traverse(root->right, root->val);
    }

    int traverse(TreeNode* node, int max) {
        if (!node)
            return 0;

        if (max > node->val) {
            return traverse(node->left, max) + traverse(node->right, max);
        } else {
            return 1 + traverse(node->left, node->val) +
                   traverse(node->right, node->val);
        }
    }
};