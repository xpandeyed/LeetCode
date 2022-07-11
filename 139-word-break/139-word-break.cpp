class Solution {
public:
    map<int, bool> m;
    bool help(string s, unordered_set<string> dic, int i, int n){
        if(i>=n){
            return m[i] = true;
        }
        if(m.find(i)!=m.end()) return m[i];
        string curr="";
        int j;
        for(j=i; j<n; ++j){
            curr+=s[j];
            // cout << curr << endl;
            if(dic.find(curr)!=dic.end() and help(s, dic, j+1, n)){
                return m[i] = true;
            }
        }
        return m[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic;
        for(auto x: wordDict){
            dic.insert(x);
        }
        return help(s, dic, 0, s.size());
    }
};