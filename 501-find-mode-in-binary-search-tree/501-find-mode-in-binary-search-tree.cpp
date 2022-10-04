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
    map<int, int> m;
    map<int, vector<int>> m2;
    void rec(TreeNode* root){
        if(!root) return ;
        m[root->val]++;
        rec(root->left);
        rec(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        rec(root);
        for(auto &[x, y]: m){
            m2[y].push_back(x);
        }
        
        return (*m2.rbegin()).second;
    }
};