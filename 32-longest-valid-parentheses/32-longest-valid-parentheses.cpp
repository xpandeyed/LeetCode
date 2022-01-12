class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int res=0;
        int n=s.size(), i=0;
        for(i=0; i<n; ++i){
            if(s[i]=='('){
                st.push(i);
                continue;
            }
            st.pop();
            if(!st.empty()){
                res = max(res, i-st.top());
            }else{
                st.push(i);
            }
        }
        return res;
    }
};