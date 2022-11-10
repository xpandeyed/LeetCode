class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        int i=0, n=s.size();
        st.push(s[0]);
        i++;
        while(i<n){
            if(!st.empty() and st.top()==s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
            i++;
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};