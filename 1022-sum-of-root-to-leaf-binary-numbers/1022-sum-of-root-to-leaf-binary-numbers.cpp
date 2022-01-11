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
    vector<int> path;
    int res=0;
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(!root->left && !root->right){
            path.push_back(root->val);
            int twos=1;
            int n=path.size();
            int curr =0;
            for(int i=n-1; i>=0; --i){
                curr+=(path[i]*twos);
                twos*=2;
            }
            res+=curr;
            cout << curr <<  " " ;
            return curr;
        }
        path.push_back(root->val);
        if(root->left){
            sumRootToLeaf(root->left);
            path.pop_back();
        }
        if(root->right){
            sumRootToLeaf(root->right);
            path.pop_back();
        }
        return res;
    }
};
