/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    bool isLast(int n) {
        return int(log2(n+1)) != int(log2(n));
    }
    void solve(Node* root) {
        queue<Node*> q;
        q.push(root);
        int count = 0;
        Node* prev = nullptr;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr == nullptr) continue;
            count++;
            q.push(curr->left);
            q.push(curr->right);
            
            if (prev) prev->next = curr;
            if (isLast(count)) {
                curr->next = nullptr;
                prev = nullptr;
                continue;
            }
            prev = curr;
        }
    }
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};