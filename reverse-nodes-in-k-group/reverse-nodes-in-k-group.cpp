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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head){
            return NULL;
        }
        int n = 0;
        ListNode *curr = head;
        while(curr){
            n++;
            curr=curr->next;
        }
        if(n<k){
            return head;
        }
        curr=head;
        
        
        ListNode *prev = NULL;
        ListNode *next = NULL;
        int count = 0;
        while(count<k && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
            count++;
        }
        if(!curr){
            return prev;
        }
        head->next=reverseKGroup(curr, k);
        return prev;
        
        
    }
};