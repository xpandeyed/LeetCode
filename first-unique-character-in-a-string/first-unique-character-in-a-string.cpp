class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(256, -1);
        int n=s.size(), i, res=INT_MAX;
        for(i=0; i<n; ++i){
            if(freq[s[i]]==-1){
                freq[s[i]]=i;
            }
            else{
                freq[s[i]]=-2;
            }
        }
        for(i=0;i<256; ++i){
            if(freq[i]!=-1 && freq[i]!=-2){
                res=min(res, freq[i]);
            }
        }
        if(res==INT_MAX){
            return -1;
        }
        return res;
    }
};