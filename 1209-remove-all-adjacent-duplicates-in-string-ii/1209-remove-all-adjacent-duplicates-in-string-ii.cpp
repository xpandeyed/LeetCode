class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size(), i;
        stack<pair<char, int>> st;
        for(i=0; i<n; ++i){
            if(!st.empty() and s[i]==st.top().first){
                st.push(make_pair(s[i], st.top().second+1));
            }else{
                st.push(make_pair(s[i], 1));
            }
            
            if(st.top().second==k){
                int j=k;
                while(j>0){
                    st.pop();
                    j--;
                }
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top().first;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};