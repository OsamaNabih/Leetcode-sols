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
    int size = 0;
    ListNode* solve(ListNode* ptr, ListNode* replacerPtr, int idx) {
        if (ptr == nullptr){
            return replacerPtr;
        }
        ListNode* returnedPtr = solve(ptr->next, replacerPtr, idx + 1);
        if (idx < size/2) return nullptr;
        int temp = ptr->val;
        ptr->val = returnedPtr->val;
        returnedPtr->val = temp;
        return returnedPtr->next;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            size++;
            ptr = ptr->next;
        }
        ptr = head;
        ListNode* ptr2 = head;
        solve(ptr, ptr2, 0);
        return head;
    }
};