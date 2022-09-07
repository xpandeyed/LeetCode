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
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string l = tree2str(root->left);
        string r = tree2str(root->right);
        if(r!="" or l!=""){
            l.insert(0, "(");
            l+=")";
        }
        if(r!=""){
            r.insert(0, "(");
            r+=")";
        }
        return to_string(root->val)+l+r;
    }
};