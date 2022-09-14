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
    
    int res = 0;
    
    void checker(vector<int> &m){
            int odd = 0;
            for(int i=1;i<=9;++i){
                if(m[i]%2) odd++;
            }
            if(odd<2) res++;
    }
    
    void rec(TreeNode* root, vector<int> m){
        if(!root) return;
        m[root->val]++;
        if(!root->left and !root->right){
            checker(m);
            return;
        }
        rec(root->left, m);
        rec(root->right, m);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> m(10, 0);
        rec(root, m);        
        return res;
    }
};