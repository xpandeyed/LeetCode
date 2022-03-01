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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        
        if((!root->left && !root->right) && targetSum==root->val){
            return true;
        }
        bool a = false, b = false;
        if(root->left){
            a = hasPathSum(root->left, targetSum-root->val) ;
        }
        
        if(root->right){
            b = hasPathSum(root->right, targetSum-root->val);
        }
        
        
        return a || b;
        
    }
    
};