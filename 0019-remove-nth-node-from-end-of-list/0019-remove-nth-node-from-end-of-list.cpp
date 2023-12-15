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
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* ptr = head;
        ListNode* prevPtr = head;
        int L = 0;
        int R = 0;
        int count = 0;
        while(ptr != nullptr) {
            ptr = ptr->next;
            R++;
            if (R - L > n + 1) {
                prevPtr = prevPtr->next;
                L++;
            }
            count++;
        }
        if (count == n) return head->next;
        if (prevPtr == nullptr || prevPtr->next == nullptr) return head;
        prevPtr->next = prevPtr->next->next;
        return head;
    }
};