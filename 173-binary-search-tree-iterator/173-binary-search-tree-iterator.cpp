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
class BSTIterator {
public:
    int i;
    vector<int> tree;
    void filler(TreeNode* root){
        if(!root){
            return ;
        }
        filler(root->left);
        tree.push_back(root->val);
        filler(root->right);
    }
    BSTIterator(TreeNode* root) {
        filler(root);
        i=-1;
        // cout << tree.size() << endl;
    }
    
    int next() {
        return tree[++i];
    }
    
    bool hasNext() {
        if(i>=((int)tree.size()-1)){
            // cout << i << " returning false " << tree.size()<<endl;
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */