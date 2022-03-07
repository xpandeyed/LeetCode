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
    
    int minHeight(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        if(root->left and !root->right){
            return 1+minHeight(root->left);
        }
        
        if(!root->left and root->right){
            return 1+minHeight(root->right);
        }
        
        if(root->left and root->right){
            return 1+min(minHeight(root->left), minHeight(root->right));
        }
        
        return 1;
        
        
    }
    
    int minDepth(TreeNode* root) {
        return minHeight(root);
    }
};