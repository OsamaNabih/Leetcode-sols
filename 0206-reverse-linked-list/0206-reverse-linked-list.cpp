/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int N;
    int curr;
    ListNode* solve(ListNode* ptr, ListNode* oldRoot) {
        if (ptr == nullptr) return nullptr;
        N++;
        curr++;
        if (ptr->next != nullptr) {
            ListNode* nextNode = solve(ptr->next, oldRoot);
            oldRoot = nextNode;
        }
        if (curr == ((N+1) / 2)) {
            return oldRoot->next;
        }
        int temp = ptr->val;
        ptr->val = oldRoot->val;
        oldRoot->val = temp;
        curr--;
        return oldRoot->next;
    }
    ListNode* reverseList(ListNode* head) {
        solve(head, head);
        return head;
    }
};