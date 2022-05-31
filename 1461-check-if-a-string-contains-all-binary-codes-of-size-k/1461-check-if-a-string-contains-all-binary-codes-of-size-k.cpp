class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int i=0, n=s.size();
        unordered_set<string> st;
        for(i=0;i<=n-k;++i){
            st.insert(s.substr(i, k));
        }
        return st.size()==pow(2,k);
    }
};