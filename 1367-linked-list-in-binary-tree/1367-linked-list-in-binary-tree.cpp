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
    bool dfs(ListNode* head, TreeNode* root){
        if(!head){
            return true;
        }
        if(!root){
            return false;
        }
        return head->val==root->val and (dfs(head->next, root->left) or dfs(head->next, root->right));
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q;
        if(!root){
            return false;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size(), i;
            for(i=0; i<n; ++i){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                if(curr->val==head->val and dfs(head, curr)){
                    return true;
                }
            }
        }
        return false;
    }
};