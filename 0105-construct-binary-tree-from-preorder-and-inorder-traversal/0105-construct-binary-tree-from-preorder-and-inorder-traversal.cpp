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
    
    int rootVal;
    unordered_map<int,int> mp;
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int low, int high, int& idx) {
        if (idx == preorder.size())
            return nullptr;
        int nodeVal = preorder[idx];
        int nodeIdx = idx;
        TreeNode* node = new TreeNode(nodeVal);
        
        idx++;
        if (idx == preorder.size())
            return node;
        int nextNodeVal = preorder[idx];
        
        if (low < mp[nextNodeVal] && mp[nextNodeVal] < mp[nodeVal]) { // Left child
            node->left = solve(preorder, inorder, low, mp[nodeVal], idx);
        }
        
        if (idx == preorder.size())
            return node;
        nextNodeVal = preorder[idx];
        if (mp[nodeVal] < mp[nextNodeVal] && mp[nextNodeVal] < high) { // right child
            node->right = solve(preorder, inorder, mp[nodeVal], high, idx);
        }
        
        return node;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        rootVal = preorder[0];
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int idx = 0;
        return solve(preorder, inorder, -1, 1e9, idx);
    }
};