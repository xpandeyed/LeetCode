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
    int goodNodes(TreeNode* root, int greatest=INT_MIN) {
        if(!root) return 0;
        greatest = max(greatest, root->val);
        int left = goodNodes(root->left, greatest);
        int right = goodNodes(root->right, greatest);
        if(root->val==greatest) return 1+left+right;
        return left+right;
    }
};