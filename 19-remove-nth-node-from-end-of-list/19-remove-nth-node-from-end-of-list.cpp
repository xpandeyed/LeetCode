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
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fast = dummy;
        for(int i=1; i<=n+1; ++i){
            fast=fast->next;
        }
        if(!fast){
            return dummy->next->next;
        }
        ListNode *curr = dummy;
        while(fast){
            fast=fast->next;
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return dummy->next;
    }
};