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
    int postIndex ;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int iS, int iE)
    {
        if(iS>iE){
            return NULL;
        }
        
        TreeNode *root = new TreeNode(postorder[postIndex]);
        postIndex--;
        
        if(iS==iE){
            return root;
        }
        int inIndex = find(inorder.begin(), inorder.end(), root->val)-inorder.begin();
        root->right = helper(inorder, postorder, inIndex+1, iE);
        root->left = helper(inorder, postorder, iS, inIndex-1);
        return root;
    }
    
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size()-1;
        return helper(inorder, postorder, 0, inorder.size()-1);
    }
};