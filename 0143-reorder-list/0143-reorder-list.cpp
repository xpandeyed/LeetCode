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
    void reorderList(ListNode* head) {
        if(!head or !head->next) return ;
        vector<ListNode*> l;
        while(head){
            l.push_back(head);
            head=head->next;
        }
        int n=l.size(), lo=1, h=n-1;
        auto curr = l[0];
        while(lo<=h){
            // cout << lo<< " " << h << endl;
            curr->next = l[h];
            curr = curr->next;
            h--;
            if(lo<=h){
                curr->next = l[lo];
                curr=curr->next;
                lo++;
            }
        }
        curr->next = NULL;
        head = l[0];
    }
};