/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size(), i;
            vector<int> temp;
            for(i=0; i<n; ++i){
                auto curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                auto children = curr->children;
                for(auto child: children){
                    if(child){
                        q.push(child);
                    }
                }
            }
            res.push_back(temp);
            
        }
        return res;
    }
};