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
    int maxDepth(TreeNode* root, int count=0) {
        if(root==NULL){
            return count;
        }
        int r1, r2;
        r1 = maxDepth(root->left, count+1);
        r2 = maxDepth(root->right, count+1);
        return max(r1, r2);
    }
};