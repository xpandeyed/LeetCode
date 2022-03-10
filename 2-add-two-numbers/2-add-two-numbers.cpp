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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        ListNode* head = NULL;
        ListNode* curr = head;
        while(l1!=NULL && l2!=NULL){
            int a = l1->val;
            int b = l2->val;
            ListNode* temp = new ListNode((a+b+carry)%10);
            carry=(a+b+carry)/10;
            l1=l1->next;
            l2=l2->next;
            if(head==NULL){
                head=temp;
                curr=head;
                continue;
            }
            curr->next = temp;
            curr=curr->next;
        }
        while(l1!=NULL){
            int a = l1->val;
            ListNode* temp = new ListNode((a+carry)%10);
            carry=(a+carry)/10;
            l1=l1->next;
            if(head==NULL){
                head=temp;
                curr=head;
                continue;
            }
            curr->next = temp;
            curr=curr->next;
        }
        while(l2!=NULL){
            int a = l2->val;
            ListNode* temp = new ListNode((a+carry)%10);
            carry=(a+carry)/10;
            l2=l2->next;
            if(head==NULL){
                head=temp;
                curr=head;
                continue;
            }
            curr->next = temp;
            curr=curr->next;
        }
        if(carry==0){
            return head;
        }
        ListNode* temp = new ListNode(carry);
        curr->next = temp;
        return head;
        
    }
};