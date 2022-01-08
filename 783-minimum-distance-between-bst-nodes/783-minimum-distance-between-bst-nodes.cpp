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
    vector<int> arr;
    void fillArr(TreeNode *root){
        if(root==NULL){
            return ;
        }
        fillArr(root->left);
        arr.push_back(root->val);
        fillArr(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        fillArr(root);
        if(arr.size()<2){
            return 0;
        }
        int res = arr[1]-arr[0];
        for(int i=2; i<arr.size(); ++i){
            res=min(res, arr[i]-arr[i-1]);
        }
        return res;
    }
};