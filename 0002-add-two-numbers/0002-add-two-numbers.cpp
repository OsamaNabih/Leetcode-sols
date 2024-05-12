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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int a, b, s;
        int c = 0;
        ListNode* ans, *temp;
        ans = new ListNode(-1);
        temp = ans;
        while(p1 != nullptr && p2 != nullptr) {
            a = p1->val;
            b = p2->val;
            s = a + b + c;
            if (s > 9) {
                s -= 10;
                c = 1;
            } else {
                c = 0;
            }
            temp->next = new ListNode(s);
            temp = temp->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1 != nullptr) {
            s = p1->val + c;
            if (s > 9) {
                s -=10;
                c = 1;
            } else {
                c = 0;
            }
            temp->next = new ListNode(s);
            temp = temp->next;
            p1 = p1->next;
        }
        
        while(p2 != nullptr) {
            s = p2->val + c;
            if (s > 9) {
                s -= 10;
                c = 1;
            } else {
                c = 0;
            }
            temp->next = new ListNode(s);
            temp = temp->next;
            p2 = p2->next;
        }
        if (c == 1) {
                temp->next = new ListNode(1);    
        }
        temp = ans;
        ans = ans->next;
        delete temp;
        return ans;
    }
};