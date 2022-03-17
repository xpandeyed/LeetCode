class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0, prev = '(', depth=0;
        
        for(auto x: s){
            if(x=='('){
                depth++;
            }else{
                depth--;
                if(prev=='('){
                    res+=(pow(2, depth));
                }
                
            }
            prev=x;
        }
        
        return res;
        
    }
};