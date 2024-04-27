/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool validate(TreeNode* root, long mx, long mn) {
        if (root == nullptr) return true;
        long val = 1L*root->val;
        if (val <= mn || val >= mx) return false;
        return validate(root->left, min(mx, val),  mn) && validate(root->right, mx, max(mn, val));
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MAX, LONG_MIN);
    }
};