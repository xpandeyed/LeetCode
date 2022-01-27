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
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int& i){
        if(start>end){
            return NULL;
        }
        TreeNode * root = new TreeNode(preorder[i]);
        i++;
        if(start==end){
            return root;
        }
        int inIndex = find(inorder.begin(), inorder.end(), root->val)-inorder.begin();
        root->left = helper(preorder, inorder, start , inIndex-1, i);
        root->right = helper(preorder, inorder, inIndex+1, end, i);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size(), i=0;
        return helper(preorder, inorder, 0, n-1, i);
    }
};