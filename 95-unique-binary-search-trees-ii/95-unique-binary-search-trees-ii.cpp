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
    vector<TreeNode*> sol(int s, int e){
        if(s==e){
            vector<TreeNode*> temp;
            temp.push_back(new TreeNode(s));
            return temp;
        }
        
        if(s>e){
            return vector<TreeNode*>(1, NULL);
        }
        
        int i;
        vector<TreeNode*> res;
        for(i=s; i<=e; ++i){
            vector<TreeNode*> l = sol(s, i-1);
            vector<TreeNode*> r = sol(i+1, e);
            for(auto x: l){
                for(auto y: r){
                    res.push_back(new TreeNode(i, x, y));
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return sol(1, n);
    }
};