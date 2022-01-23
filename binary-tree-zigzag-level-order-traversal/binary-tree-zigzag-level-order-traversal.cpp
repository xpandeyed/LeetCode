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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> temp;
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        q.push(root);
        TreeNode *curr;
        int n, level=1, j;
        while(!q.empty()){
            temp.clear();
            n=q.size();
            for(j=0; j<n; ++j){
                curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                temp.push_back(curr->val);
            }
            
            if(level%2==0){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            level++;
        }
        return res;
    }
};