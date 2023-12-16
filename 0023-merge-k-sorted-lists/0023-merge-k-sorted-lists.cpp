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
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* sortedHead = nullptr;
        ListNode* sortedPtr = nullptr;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        while(ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->val < ptr2->val) {
                if (sortedPtr == nullptr) {
                    sortedPtr = ptr1;
                    sortedHead = sortedPtr;
                } else {
                    sortedPtr->next = ptr1;
                    sortedPtr = sortedPtr->next;
                }
                
                ptr1 = ptr1->next;
                sortedPtr->next = nullptr;
            } else {
                if (sortedPtr == nullptr) {
                    sortedPtr = ptr2;
                    sortedHead = sortedPtr;
                } else {
                    sortedPtr->next = ptr2;
                    sortedPtr = sortedPtr->next;
                }
                ptr2 = ptr2->next;
                sortedPtr->next = nullptr;

            }
        }
        
        if(ptr1 != nullptr) {
            sortedPtr->next = ptr1;
        }
        
        if(ptr2 != nullptr) {
            sortedPtr->next = ptr2;
        }
        return sortedHead;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return nullptr;
        ListNode* ans;
        int phases = ceil(log2(k));
        int j, partner, iterationStep, partnerStep;
        for(int phase = 1; phase <= phases; phase++) {
            j = 0;
            partnerStep = (1 << (phase-1));
            iterationStep = (1 << phase);
            while (j < k) {
                partner = j + partnerStep;
                if (partner < k) {
                    lists[j] = mergeTwoLists(lists[j], lists[partner]);
                }
                j += iterationStep;
            }
            
        }
        return lists[0];
    }
};