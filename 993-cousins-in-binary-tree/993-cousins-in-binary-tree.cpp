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
    pair<int, TreeNode*> p1;
    pair<int, TreeNode*> p2;
    void findParAndLevel(TreeNode* root, int x, int level, TreeNode* par){
        if(!root) return;
        if(root->val==x){
            if(p1.first==-1) p1 = make_pair(level+1, par);
            else p2 = make_pair(level+1, par);
        }
        findParAndLevel(root->left, x, level+1, root);
        findParAndLevel(root->right, x, level+1, root);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        p1.first = -1;
        p1.second = NULL;
        p2.first = -1;
        p2.second = NULL;
        findParAndLevel(root, x, 0, NULL);
        findParAndLevel(root, y, 0, NULL);
        // cout << p1.first << " " << p1.second->val << endl;
        // cout << p2.first << " " << p2.second->val << endl;
        if(p1.first==p2.first and p1.second!=p2.second) return true;
        return false;
    }
};