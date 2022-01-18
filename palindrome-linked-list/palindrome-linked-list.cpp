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
    ListNode* reverse(ListNode* head, ListNode *prev=NULL){
        if(head==NULL){
            return NULL;
        }
        if(!head->next){
            head->next=prev;
            return head;
        }
        ListNode *curr = reverse(head->next, head);
        head->next = prev;
        return curr;
        
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode *slow=head, *fast=head, *prev = NULL, *first=NULL, *second = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow ->next;
            fast = fast->next->next;
        }
        if(!fast){
            second  = reverse(slow);
        }else{
            second  = reverse(slow->next);
        }
        
        if(prev){
            prev->next = NULL;
        }
        first = head;
        while(first && second){
            if(first->val!=second->val){
                return false;
            }
            first=first->next;
            second = second->next;
        }
        if(first || second ){
            return false;
        }
        return true;
        
        
        
    }
};