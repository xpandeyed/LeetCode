class Solution {
public:
    bool isMatch(char a, char b){
        if(a=='(' && b==')'){
            return true;
        }
        if(a=='{' && b=='}'){
            return true;
        }
        if(a=='[' && b==']'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0; i<n; ++i){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                continue;
            }
            if(st.empty()){
                return false;
            }
            if(isMatch(st.top(), s[i])){
                st.pop();

            }else{
                return false;
            }
            
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};