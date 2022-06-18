class WordFilter {
public:
    unordered_map<string, int> m;
    WordFilter(vector<string>& words) {
        int n=words.size(), i, j, k;
        for(i=0;i<n;++i){
            string w = words[i];
            int s = words[i].size();
            for(j=1;j<=s;++j){
                string pre = w.substr(0, j);
                for(k=0;k<s;++k){
                    string suf = w.substr(k, s-k);
                    m[pre+"|"+suf]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return m[prefix+"|"+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */