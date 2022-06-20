class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n=words.size(), i=0;
        for(i=0;i<n;++i){
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(), words.end());
        int res = 0;
        for(i=0;i<n-1;++i){
            if(words[i+1].find(words[i])!=0){
                res+=(words[i].size()+1);
            }
        }
        res+=(words[i].size()+1);
        return res;
    }
};

//em emit lleb