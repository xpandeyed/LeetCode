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
        int t=0;
        ListNode *curr = head;
        while(curr){
            t++;
            curr=curr->next;
        }
        int x = t-n+1;
        curr=head;
        for(int i=2; i<x; ++i){
            curr=curr->next;
        }
        if(n==t){
            return head->next;
        }
        curr->next = curr->next->next;
        return head;
        
    }
};