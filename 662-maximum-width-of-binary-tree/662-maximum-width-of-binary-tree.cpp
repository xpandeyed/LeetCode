/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * 
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*, long long int>> q;
        
        q.push(pair<TreeNode*, int>(root, 0));
        
        long long int left, right, currNodeNumber, n, res=0, i;
        
        TreeNode* currNode;
        
        while(!q.empty()){
            
            left = q.front().second;
            right = INT_MIN;
            int n=q.size();
            
            for(i=0; i<n; ++i){
                
                currNode = q.front().first;
                currNodeNumber = q.front().second;
                
                q.pop();
                
                right=max(right, currNodeNumber);
                
                if(currNode->left){
                    q.push(pair<TreeNode*, int>(currNode->left, currNodeNumber*2+1));
                }
                if(currNode->right){
                    q.push(pair<TreeNode*, int>(currNode->right, currNodeNumber*2+2));
                }
                
                // cout << left << "  " << right << endl;
                
            }
            res=max(res, right-left+1);
        }
        
        return res;
    }
};