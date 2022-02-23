/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root, Node *pair=NULL) {
        if(root==NULL){
            return NULL;
        }
        root->next = pair ;
        connect(root->left, root->right);
        if(pair){
            connect(root->right, pair->left);
        }else{
            connect(root->right);
        }
        return root;
    }
};