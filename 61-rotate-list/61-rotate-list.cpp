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
    
    ListNode *reverse(ListNode *head, ListNode*prev = NULL){
        if(!head){
            return prev;
        }
        
        
        ListNode *newHead = reverse(head->next, head);
        head->next = prev;
        return newHead;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k or (!head or !head->next)){
            return head;
        }
        
        int num=0;
        
        ListNode *curr=head, *prev = NULL, *head2, *tempHead=head;
        
        
        while(curr && num<k){
            // cout << num << endl;
            curr = curr->next;
            num++;
        }
        // cout << "f" <<num << endl;
        
        if(!curr){
            return rotateRight(head, k%num);
        }
        
        
        while(curr){
            // cout << tempHead->val << " " << curr->val << endl;
            prev = tempHead;
            tempHead = tempHead->next;
            curr = curr->next;
        }
        // cout << "f" << endl;
        
        prev->next = NULL;
        
        head = reverse(head);
        tempHead = reverse(tempHead);
        
        curr = head;
        // cout << "l1: " ;
        // while(curr){
        //     cout << curr->val << " ";
        //     curr =curr->next;
        // }
        // cout << endl;
        // cout << "l2: " ;
        curr = tempHead;
        // while(curr){
        //     cout << curr->val << " " ;
        //     curr = curr->next;
        // }
        
        curr = head;
        prev = NULL;
        
        // cout << "h" << endl;
        
        while(curr){
            prev=curr;
            curr=curr->next;
        }
        
        // cout << "l" << endl;
        
        prev->next = tempHead;
        
        // cout << "m" << endl;
        
        
        return reverse(head);
    }
};