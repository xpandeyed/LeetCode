/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //Find root to node path and store parent to node distance
    //Find all descendents at distance k
    
    map<TreeNode*, int> anc;
    vector<int> res;
    
    int ancestors(TreeNode* root, TreeNode* target){
        if(!root) return -1;
        if(root==target){
            anc[root] = 0;
            return 0;
        }
        int l = ancestors(root->left, target);
        if(l!=-1){
            anc[root] = l+1;
            return l+1;
        }
        int r = ancestors(root->right, target);
        if(r!=-1){
            anc[root] = r+1;
            return r+1;
        }
        return -1;
        
    }
    
    //Finds required nodes
    void findReq(TreeNode* root, int dis, int k){
        if(!root) return;
        if(dis>k) return;
        if(dis==k){
            res.push_back(root->val);
            return ;
        }
        if(anc.find(root->left)==anc.end()){
            findReq(root->left, dis+1, k);
        }
        if(anc.find(root->right)==anc.end()){
            findReq(root->right, dis+1, k);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ancestors(root, target);
        for(auto &[x, y]: anc){
            findReq(x, y, k);
            // cout << x->val << " " << y << endl;
        }
        return res;
    }
};