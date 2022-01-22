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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        ListNode *curr1 = head, *curr2 = head->next, *head1 = head, *head2 = head->next;
        
        while(curr1 && curr2){
            curr1->next = curr2->next;
            if(curr1->next){
                curr2->next = curr1->next->next;
            }
            else{
                break;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
            
        }
        curr1->next = head2;
        return head1;
    }
};