/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*, int> mp_p;
    unordered_map<TreeNode*, int> mp_q;
    unordered_map<int, int> mp;
    // TreeNode* solve(TreeNode* root) {
    //     bool p_left, p_right, q_left, q_right;
    //     if (mp_p[root->val] == mp_q[root->val]) {
    //         return mp_p[root->val] == 1 ? solve(root->left) : solve(root->right);
    //     }
    //     else return root;
    // }

    // void traverse(TreeNode* root, int p, int q) {
    //     traverse(root->left, p, q);
    //     traverse(root->right, p, q);
    //     if (root->val == p || root->left->val == p || root->right->val == q) mp_p[root->val] = 1;
    //     if (root->val == q || root->left->val == q || root->right->val == q) mp_q[root->val] = 2;
    // }

    void printMap(unordered_map<TreeNode*, int> &mp) {
        for(auto it = mp.cbegin(); it != mp.cend(); ++it)
        {
            if (it->first == nullptr) {
                cout << "NULLPTR" << endl;
                continue;
            }
            std::cout << it->first->val << " " << it->second << "\n";
        }
    }

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* left, *right;
        left = right = nullptr;
        if (root->left != nullptr) left = solve(root->left, p, q);
        if (root->right != nullptr) right = solve(root->right, p, q);
        if (left != nullptr) return left;
        if (right != nullptr) return right;
        if (root == p) mp_p[root] = 1;
        if (root == q) mp_q[root] = 1;
        int p_left, p_right, q_left, q_right, p_me, q_me;
        p_left = mp_p[root->left];
        p_right = mp_p[root->right];
        q_left = mp_q[root->left];
        q_right = mp_q[root->right];
        p_me = mp_p[root];
        q_me = mp_q[root];
        if (p_left + q_right > 1 || p_right + q_left > 1 || p_me + q_left + q_right > 1 || q_me + p_left + p_right > 1) return root;
        if (p_left + p_right == 1) mp_p[root] = 1;
        if (q_left + q_right == 1) mp_q[root] = 1;
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = solve(root, p, q);
        return ans;
    }
};