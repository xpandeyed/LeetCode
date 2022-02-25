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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy, *curr = head;
        prev->next = curr;
        while(curr){
            while(curr && curr->val==val){
                curr=curr->next;
            }
            prev->next=curr;
            prev = curr;
            if(curr) curr=curr->next;
        }
    return dummy->next;
    }
    
};