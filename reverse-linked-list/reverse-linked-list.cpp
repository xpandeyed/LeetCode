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
    ListNode *newHead = NULL;
    ListNode* reverseList(ListNode* head, ListNode* prev=NULL) {
        if(!head){
            return NULL;
        }
        if(!head->next){
            head->next = prev ;
            newHead = head;
            return head;
        }
        reverseList(head->next, head);
        head->next = prev;
        return newHead;
        
    }
};