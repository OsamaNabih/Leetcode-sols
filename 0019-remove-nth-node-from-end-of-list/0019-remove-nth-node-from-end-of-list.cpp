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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* ptr = head;
        ListNode* ptrs[30];
        while (ptr) {
            ptrs[length] = ptr;
            length++;
            ptr = ptr->next;
        }
        int target_idx = length - n;
        if (target_idx != 0) {
            ptrs[target_idx-1]->next = ptrs[target_idx]->next;
        }
        else {
            head = head->next;
        }
        return head;
    }
};