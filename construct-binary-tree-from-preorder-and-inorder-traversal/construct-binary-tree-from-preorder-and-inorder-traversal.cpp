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
    //traverse one by one preorder array
    int preindex = 0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int iS, int iE){
        if(iS>iE){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preindex]);
        preindex++;
        if(iS==iE){
            return root;
        }
        int inIndex = find(inorder.begin(), inorder.end(), root->val)-inorder.begin();
        
        root->left = helper(preorder, inorder, iS, inIndex-1);
        root->right = helper(preorder, inorder, inIndex+1, iE);
        return root;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size()-1);
    }
};