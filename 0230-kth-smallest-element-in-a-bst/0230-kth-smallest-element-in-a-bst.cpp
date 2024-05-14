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
    int ans;
    int target;
    void solve(TreeNode* root, int& curr) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            solve(root->left, curr);
        }
        curr++;
        if (curr == target) {
            ans = root->val;
            
        }
        if (root->right != nullptr) {
            solve(root->right, curr);
        }
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        target = k;
        int temp = 0;
        solve(root, temp);
        return ans;
    }
};