class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, set<string>> m;
        for(auto &p: products){
            string curr = "";
            int n=p.size();
            for(int i=0;i<n;++i){
                curr+=p[i];
                m[curr].insert(p);
            }
        }
        int n=searchWord.size(), i;
        vector<vector<string>> res;
        string pre="";
        for(i=0;i<n;++i){
            vector<string> curr;
            pre+=searchWord[i];
            auto it=m[pre].begin();
            int j=0;
            while(it!=m[pre].end() and j<3){
                curr.push_back(*it);
                it++;
                j++;
            }
            res.push_back(curr);
        }
        return res;
    }
};