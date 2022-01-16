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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr1 = headA, *curr2 = headB;
        while(curr1){
            ListNode *dummy = new ListNode(-1);
            dummy->next=curr1->next;
            curr1->next=dummy;
            curr1=dummy->next;
        }
        ListNode *res = NULL;
        while(curr2->next){
            if(curr2->next->val==-1){
                res=curr2;
                break;
            }
            curr2=curr2->next;
        }
        curr1=headA;
        while(curr1){
            curr1->next = curr1->next->next;
            curr1=curr1->next;
        }
        return res;
        
    }
};