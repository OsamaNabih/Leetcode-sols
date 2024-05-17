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
    bool solve(TreeNode* root, int target) {
        if (root == nullptr) return true;
        // cout << root->val << endl;
        bool left = solve(root->left, target);
        if (left) {
            delete root->left;
            root->left = nullptr;
        }
        bool right = solve(root->right, target);
        if (right) {
            delete root->right;
            root->right = nullptr;
        }
        // cout << (root->left == nullptr) << " " << (root->right == nullptr) << endl;
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            // cout << "Deleting self\n";
            return true;
        }
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, target) ? nullptr : root;
    }
};