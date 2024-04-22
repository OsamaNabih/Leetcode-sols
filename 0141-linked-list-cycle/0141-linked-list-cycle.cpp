/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while(slowPtr != nullptr) {
            slowPtr = slowPtr->next;
            if (fastPtr != nullptr) fastPtr = fastPtr->next;
            if (fastPtr != nullptr) fastPtr = fastPtr->next;
            if (slowPtr == fastPtr && fastPtr != nullptr) return true;
        }
        return false;
    }
};