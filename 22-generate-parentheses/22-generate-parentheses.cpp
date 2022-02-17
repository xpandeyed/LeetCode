class Solution {
public:
    void help(int open, int close, vector<string> &res, string temp){
        if(open==0 && close==0){
            res.push_back(temp);
            return ;
        }
        
        if(open>0){
            help(open-1, close, res, temp+'(');
        }
        if(close>open){
            help(open, close-1, res, temp+')');
        }
        
    }
    
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        help(n, n, res, "");
        return res;
    }
};