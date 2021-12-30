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
    ListNode *mergeTwo(ListNode* list1, ListNode* list2){
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        if(list1->val<=list2->val){
            list1->next = mergeTwo(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwo(list1, list2->next);
            return list2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        queue<ListNode*> q;
        for(int i=0; i<lists.size(); ++i){
            q.push(lists[i]);
        }
        while(q.size()>1){
            ListNode *head1 = q.front();
            q.pop();
            ListNode *head2 = q.front();
            q.pop();
            q.push(mergeTwo(head1, head2));
        }
        return q.front();
    }
};