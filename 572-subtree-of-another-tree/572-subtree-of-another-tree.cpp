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
    bool fullCheck(TreeNode *r1, TreeNode *r2){
        if(!r1 and !r2){
            return true;
        }
        if(!r1 and r2){
            return false;
        }
        if(r1 and !r2){
            return false;
        }
        if(r1->val!=r2->val) return false;
        
        return fullCheck(r1->left, r2->left) and fullCheck(r1->right, r2->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and subRoot){
            return false;
        }
        if(!subRoot and root){
            return false;
        }
        if(!root and !subRoot){
            return true;
        }
        if(root->val==subRoot->val and fullCheck(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};