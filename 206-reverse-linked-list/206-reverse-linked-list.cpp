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
    ListNode* reverseList(ListNode* head, ListNode *prev=NULL) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            head->next=prev;
            return head;
        }
        
        ListNode *res = reverseList(head->next, head);
        head->next = prev ;
        return res;
    }
};