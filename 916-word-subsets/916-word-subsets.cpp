class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1 = words1.size(), n2 = words2.size(), i,j, n;
        vector<string> res;
        map<string, vector<int>> m, m2;
        for(i=0;i<n1;++i){
            vector<int> freq(26, 0);
            n=words1[i].size();
            for(j=0;j<n;++j){
                freq[words1[i][j]-'a']++;
            }
            m[words1[i]]=freq;
        }
        vector<int> maxFreq(26, 0);
        for(i=0;i<n2;++i){
            string w = words2[i];
            for(j='a'; j<='z'; ++j){
                int c = count(w.begin(), w.end(), char(j));
                maxFreq[j-'a'] = max(maxFreq[j-'a'], c);
            }
        }
        
        auto it = m.begin();
        for(it = m.begin(); it!=m.end(); ++it){
            auto freq = (*it).second;
            for(i=0;i<26;++i){
                if(freq[i]<maxFreq[i]) break;
            }
            if(i==26) res.push_back((*it).first);
        }
        
        
        return res;
        
    }
};