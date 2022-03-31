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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> s;
        queue<TreeNode*> q;
        vector<vector<int>> res;
        
        if(!root){
            return res;
        }
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n=q.size(), i;
            for(i=0; i<n; ++i){
                TreeNode *curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            s.push(level);
        }
        
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};