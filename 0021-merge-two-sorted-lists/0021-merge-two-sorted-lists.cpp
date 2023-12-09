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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == list2) return list1;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* ptr1, *ptr2, *ptr3, *sortedHead;
        ptr1 = list1;
        ptr2 = list2;
        
        if (ptr1->val < ptr2->val) {
            sortedHead = ptr1;
            ptr1 = ptr1->next;
        } else {
            sortedHead = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = sortedHead;
        while(ptr1 != nullptr || ptr2 != nullptr) {
            cout << ptr3->val << endl;
            if (ptr1 == nullptr) {
                ptr3->next = ptr2;
                ptr3 = ptr2;
                ptr2 = ptr2->next;
            } else if (ptr2 == nullptr) {
                ptr3->next = ptr1;
                ptr3 = ptr1;
                ptr1 = ptr1->next;
            } else {
                if (ptr1->val < ptr2->val) {
                    ptr3->next = ptr1;
                    ptr3 = ptr1;
                    ptr1 = ptr1->next;
                } else {
                    ptr3->next = ptr2;
                    ptr3 = ptr2;
                    ptr2 = ptr2->next;
                }
            }
        }
        return sortedHead;
    }
};