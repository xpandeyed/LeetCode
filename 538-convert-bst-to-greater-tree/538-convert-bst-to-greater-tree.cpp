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
    int rec(TreeNode *root, int prev){
        if(!root){
            return prev;
        }
        int right = rec(root->right, prev);
        root->val+=right;
        return rec(root->left, root->val);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        rec(root, 0);
        return root;
    }
};