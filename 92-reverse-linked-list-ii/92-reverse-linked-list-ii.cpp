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
    ListNode* reverse(ListNode* head, ListNode* prev){
        if(!head) return prev;
        auto next = head->next;
        head->next = prev;
        return reverse(next, head);
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        int i=1;
        ListNode *curr = head, *prev = NULL, *next = NULL, *tempHead;
        while(curr and i<left){
            i++;
            prev = curr;
            curr = curr->next;
        }
        tempHead = curr;
        while(curr and i<right){
            i++;
            curr=curr->next;
        }
        next = curr->next;
        curr->next = NULL;
        tempHead = reverse(tempHead, next);
        if(prev){
            prev->next = tempHead;
            return head;
        }
        return tempHead;
        
    }
};