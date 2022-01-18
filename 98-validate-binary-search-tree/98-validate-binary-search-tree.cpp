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
    void fill(TreeNode* root, vector<int> &res){
        if(root==NULL){
            return ;
        }
        fill(root->left, res);
        res.push_back(root->val);
        fill(root->right, res);
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        vector<int> res;
        fill(root, res);
        for(int i=1; i<res.size(); ++i){
            if(res[i-1]>=res[i]){
                return false;
            }
        }
        return true;
    }
};