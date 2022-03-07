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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int l = height(root->left);
        
        int r = height(root->right);
        
        // cout << root->val << "  left: " << l << "  right: " << r << endl;
        
        if((l==-1 or r==-1) or abs(l-r)>1){
            return -1;
        }
        return 1+max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        return (height(root)!=-1);
    }
};