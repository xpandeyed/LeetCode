/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        if(head->next==head){
            return true;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = head, *next=head->next;
        while(curr){
            if(curr->next==dummy){
                return true;
            }
            curr->next=dummy;
            curr=next;
            if(curr){
                next=curr->next;
            }
            
        }
        return false;
    }
};