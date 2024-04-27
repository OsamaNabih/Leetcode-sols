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
    ListNode* last;
    int N;
    int curr;
    ListNode* solve(ListNode* ptr, ListNode* oldRoot) {
        if (ptr == nullptr) return nullptr;
        N++;
        curr++;
        cout << ptr->val << " " << oldRoot->val << endl;
        if (ptr->next != nullptr) {
            ListNode* nextNode = solve(ptr->next, oldRoot);
            oldRoot = nextNode;
        }
        cout << ptr->val << " counts: " << curr << " " << N << endl;
        if (curr == ((N+1) / 2)) {
            return oldRoot->next;
        }
        cout << "Swapping " << ptr->val << " " << oldRoot->val;
        int temp = ptr->val;
        ptr->val = oldRoot->val;
        oldRoot->val = temp;
        curr--;
        return oldRoot->next;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        solve(head, head);
        return head;
    }
};