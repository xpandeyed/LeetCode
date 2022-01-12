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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head , *fast = head;
        while(slow && fast){
            
            slow=slow->next;
            if(!fast->next){
                return NULL;
            }
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        slow = head;
        while(slow!=fast){
            if(!fast){
                return NULL;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};