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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        while(fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
            if (fastPtr->next != nullptr) {
                fastPtr = fastPtr->next;
            }
        }
        return slowPtr;
    }
};