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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        
        ListNode *dummy = new ListNode(200);
        dummy->next = head;
        ListNode *prev = dummy, *curr=head;
        
        while(curr && curr->next){
            if(curr->val==curr->next->val){
                while(curr && curr->val==prev->next->val){
                    curr=curr->next;
                }
                prev->next = curr;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        
        return dummy->next;
        
    }
};