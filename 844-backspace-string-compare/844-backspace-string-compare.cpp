class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st, st2;
        int n=s.size(), i;
        for(i=0; i<n; ++i){
            if(s[i]!='#'){
                st.push(s[i]);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        n=t.size();
        for(i=0; i<n; ++i){
            if(t[i]!='#'){
                st2.push(t[i]);
            }else if(!st2.empty()){
                st2.pop();
            }
        }
        while(!st.empty() and !st2.empty()){
            if(st.top()!=st2.top()){
                return false;
            }
            st.pop();
            st2.pop();
        }
        
        return st.empty()==st2.empty();
    }
};