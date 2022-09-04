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
    map<pair<int, int>, vector<int>> m;
    map<int, vector<int>> m2;
    void store(TreeNode* root, int dis, int r){
        if(!root) return ;
        m[make_pair(dis, r)].push_back(root->val);
        store(root->left, dis-1, r+1);
        store(root->right, dis+1, r+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        store(root, 0, 0);
        for(auto [x, y]: m){
            sort(y.begin(), y.end());
            for(auto t: y){
                m2[x.first].push_back(t);
            }
        }
        for(auto [x, y]: m2){
            res.push_back(y);
        }
        return res;
    }
};