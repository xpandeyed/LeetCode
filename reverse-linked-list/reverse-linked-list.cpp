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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode *prev = head, *curr=head->next, *next = curr->next;
        prev->next = NULL;
        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }
        curr->next = prev;
        return curr;
        

    }
};