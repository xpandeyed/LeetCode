class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0, n=words.size(), i, j;
        vector<unordered_set<int>> ws(n);
        for(i=0;i<n;++i){
            for(char c: words[i]){
                ws[i].insert(c);
            }
        }
        for(i=0;i<n;++i){
            for(j=i+1;j<n;++j){
                bool isP = false;
                for(char c: ws[i]){
                    if(ws[j].find(c)!=ws[j].end()){
                        isP=true;
                        break;
                    }
                }
                if(!isP){
                    int t =  words[i].size()*words[j].size();
                    res = max(res, t);
                }
            }
        }
        return res;
    }
};