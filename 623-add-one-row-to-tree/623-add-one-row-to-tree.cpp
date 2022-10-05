class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {        
        if(depth==1){
            TreeNode* res = new TreeNode(val);
            res->left = root;
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int d=1, n, i;
        while(!q.empty() and d<depth){
            n=q.size();
            for(i=0;i<n;++i){
                auto curr = q.front();
                q.pop();
                
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
                
                if(d==depth-1){
                    TreeNode* l = new TreeNode(val);
                    l->left = curr->left;
                    curr->left = l;
                    TreeNode* r = new TreeNode(val);
                    r->right = curr->right;
                    curr->right = r;
                }
            }
            
            d++;
        }
        
        return root;
    }
};