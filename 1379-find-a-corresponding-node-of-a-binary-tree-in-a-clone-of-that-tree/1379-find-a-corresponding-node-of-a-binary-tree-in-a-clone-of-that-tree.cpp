/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!target or (!original or !cloned)){
            return NULL;
        }
        if(original==target){
            return cloned;
        }
        TreeNode *res = getTargetCopy(original->left, cloned->left, target);
        if(res){
            return res;
        }
        res = getTargetCopy(original->right, cloned->right, target);
        return res;
        
    }
};