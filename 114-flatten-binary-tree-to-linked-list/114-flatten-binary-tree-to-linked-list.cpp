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
    void flatten(TreeNode* root) {
        TreeNode *curr=root, *temp;
        while(curr){
            if(curr->left){
                temp = curr->left;
                while(temp->right){
                    temp=temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            
            curr = curr->right;
        }
    }
};