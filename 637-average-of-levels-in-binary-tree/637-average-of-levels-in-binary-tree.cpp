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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root){
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size(), i;
            double avg = 0.0;
            for(i=0; i<n; ++i){
                TreeNode *curr = q.front();
                q.pop();
                avg+=((double)curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            avg/=(double)n;
            res.push_back(avg);
        }
        
        return res;
    }
};