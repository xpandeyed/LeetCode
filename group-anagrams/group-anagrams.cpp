class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> res;
        string temp ;
        int n=strs.size(), i;
        for(i=0; i<n; ++i){
            temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        
        for(auto x: m){
            res.push_back(x.second);
        }
        
        return res;
    }
};