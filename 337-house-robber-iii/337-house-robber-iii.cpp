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
    map<pair<TreeNode*, bool>, int> m;
    //the bool stores if the house has been robbed or not
    int robRec(TreeNode* root, bool canRob){
        if(!root)return 0;
        
        if(canRob){
            //If robber robs
            auto p1 = make_pair(root, true);
            int m1 ;
            if(m.find(p1)!=m.end()){
                m1 = m[p1];
            }else{
                int l1 = robRec(root->left, false);
                int r1 = robRec(root->right, false);
                m1 = root->val + l1 + r1;
                m[p1] = m1;
            }
            
            
            //If robber does not rob
            auto p2 = make_pair(root, false);
            int m2 ;
            if(m.find(p2)!=m.end()){
                m2 = m[p2];
            }else{
                int l2 = robRec(root->left, true);
                int r2 = robRec(root->right, true);
                m2 = l2 + r2;
                m[p2] = m2;
            }
            
            return max(m1, m2);
        }

        auto p = make_pair(root, false);
        if(m.find(p)==m.end()){
            int l = robRec(root->left, true);
            int r = robRec(root->right, true);
            
            return m[p] = l+r;
        }
        return m[p];
    }
    int rob(TreeNode* root) {
        return robRec(root, true);
    }
};