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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        stack<TreeNode*> s;
        vector<int> res;
        if(curr==NULL){
            return res;
        }
        do{
            while(curr){
                if(curr->right){
                    s.push(curr->right);
                }
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if(!s.empty() && curr->right==s.top()){
                s.pop();
                s.push(curr);
                curr=curr->right;
            }else{
                res.push_back(curr->val);
                curr=NULL;
            }
        }while(!s.empty());
        return res;
    }
};