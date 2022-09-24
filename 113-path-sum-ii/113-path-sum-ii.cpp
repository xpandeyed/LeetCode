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
    vector<vector<int>> res;
    
    void rec(TreeNode* root, int t, vector<int> path, int sum){
        if(!root){
            return;
        }
        path.push_back(root->val);
        sum+=root->val;
        if(!root->left and !root->right and sum==t){
            res.push_back(path);
            return ;
        }
        rec(root->left, t, path, sum);
        rec(root->right, t, path, sum);
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        rec(root, targetSum, path, 0);
        return res;
    }
};