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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int n, i;
        vector<int> temp;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        TreeNode *curr;
        q.push(root);
        while(!q.empty()){
            n=q.size();
            for(i=0; i<n; ++i){
                curr = q.front();
                temp.push_back(curr->val);
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};