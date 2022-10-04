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
    bool isCompleteTree(TreeNode* root) {
        bool inc = false;
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;++i){
                auto curr = q.front();
                q.pop();
                if(inc and curr->left) return false;
                if(curr->left) q.push(curr->left);
                else inc = true;
                if(inc and curr->right) return false;
                if(curr->right) q.push(curr->right);
                else inc = true;
            }
        }
        return true;
    }
};