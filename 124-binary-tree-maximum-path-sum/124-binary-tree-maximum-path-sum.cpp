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
    int singleMax(TreeNode* root, int &res){
        if(root==NULL){
            return 0;
        }
        int l=singleMax(root->left, res);
        int r=singleMax(root->right, res);
        
        int maxSingle = max(root->val , max(l, r)+root->val);
        int maxTop = max(maxSingle, root->val+l+r);
        res=max(res, maxTop);
        return maxSingle;
        
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int res=INT_MIN;
        singleMax(root, res);
        return res;
    }
};