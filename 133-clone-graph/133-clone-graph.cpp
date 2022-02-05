/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *helper(Node* node, vector<Node*> &nodePointers){
        if(node==NULL){
            return NULL;
        }
        if(nodePointers[node->val]==NULL){
            Node * res = new Node(node->val);
            nodePointers[node->val] = res;
            for(auto nei: node->neighbors){
                res->neighbors.push_back(helper(nei, nodePointers));
            }
            return res;
        }else{
            return nodePointers[node->val];
        }
    }
    
    
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        vector<Node*> nodePointers(101, NULL);
        return helper(node, nodePointers);
        
    }
};