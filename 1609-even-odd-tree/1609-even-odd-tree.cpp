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
    bool isEvenOddTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = -1, n, prev, i;
        while(!q.empty()){
            
            level++;
            
            if(level%2){
                //odd
                prev=INT_MAX;
            }else{
                prev=INT_MIN;
            }
            
            n=q.size();
            
            for(i=0; i<n; ++i){
                
                TreeNode *curr = q.front();
                q.pop();
                
                if(level%2){
                    //odd
                    if(curr->val%2!=0 or curr->val>=prev){
                        return false;
                    }
                }else{
                    if(curr->val%2==0 or curr->val<=prev){
                        return false;
                    }
                }
                
                prev = curr->val;
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
            
        }
        
        return true;
    }
};