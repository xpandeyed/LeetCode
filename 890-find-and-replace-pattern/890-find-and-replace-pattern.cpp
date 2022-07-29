class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n=words.size(), i, j, wsize;
        vector<string> res;
        for(auto &w: words){
            wsize = w.size();
            if(wsize!=pattern.size()) continue;
            map<int, int> m;
            set<int> s;
            for(j=0;j<wsize;++j){
                if(m.find(w[j])==m.end() and s.find(pattern[j])==s.end()) {
                    m[w[j]]=pattern[j];
                    s.insert(pattern[j]);
                }
                else if(m[w[j]]!=pattern[j] or s.find(pattern[j])==s.end()) break;
            }
            if(j==wsize){
                res.push_back(w);
            }
        }
        return res;
    }
};