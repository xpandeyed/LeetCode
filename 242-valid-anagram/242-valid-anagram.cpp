class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.size(), n2=t.size(), i;
        if(n1!=n2){
            return false;
        }
        vector<int> res(256, 0);
        for(i=0; i<n1; ++i){
            res[s[i]]++;
            res[t[i]]--;
        }
        for(i=0; i<256; ++i){
            if(res[i]!=0){
                return false;
            }
        }
        return true;
    }
};