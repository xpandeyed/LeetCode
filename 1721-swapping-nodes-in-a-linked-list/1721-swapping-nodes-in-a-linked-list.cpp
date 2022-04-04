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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *kFromBegin, *kFromEnd;
        ListNode *curr = head;
        for(int i=1; i<k; ++i){
            curr=curr->next;
        }
        kFromBegin=curr;
        curr=curr->next;
        kFromEnd=head;
        while(curr){
            curr=curr->next;
            kFromEnd=kFromEnd->next;
        }
        int temp = kFromBegin->val;
        kFromBegin->val = kFromEnd->val;
        kFromEnd->val = temp;
        return head;
    }
};