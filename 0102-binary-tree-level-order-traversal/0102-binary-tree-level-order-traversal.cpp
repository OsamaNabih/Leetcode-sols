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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int currLevel = 0;
        vector<int> currVec;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int level = p.second;
            if (level != currLevel) {
                currLevel = level;
                ans.push_back(currVec);
                currVec.clear();
                
            }
            currVec.push_back(node->val);
            if (node->left != nullptr) q.push(make_pair(node->left, level + 1));
            if (node->right != nullptr) q.push(make_pair(node->right, level + 1));
        }
        if (!currVec.empty()) ans.push_back(currVec);
        return ans;
    }
};