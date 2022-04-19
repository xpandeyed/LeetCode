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
    //The main problem is to identify which two nodes are misplaced
    //This can be done by doing inorder traversal and storing in a vector
    //The two nodes which when swapped make the inorder vector swapped are the two nodeshle
    
    void help(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second){
        if(!root){
            return;
        }
        help(root->left, prev, first, second);
        if(prev){
            if(prev->val>root->val){
                if(!first){
                    first=prev;
                }
                second = root;
            }
        }
        prev = root;
        help(root->right, prev, first, second);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL, *first=NULL, *second=NULL;
        help(root, prev, first, second);
        swap(first->val, second->val);
    }
};