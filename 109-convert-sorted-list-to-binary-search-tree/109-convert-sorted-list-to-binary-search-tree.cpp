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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* halfSolve(ListNode* head, ListNode* tail){
        if(head==tail)
            return NULL;
        ListNode* slow=head, *fast=head;
        while(fast!=tail and fast->next!=tail){
            fast=fast->next->next;
            slow=slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = halfSolve(head, slow);
        root->right = halfSolve(slow->next, tail);
        return root;
            
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        return halfSolve(head, NULL);
    }
};