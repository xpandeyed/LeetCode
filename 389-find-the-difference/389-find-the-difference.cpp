class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> fre(256, 0);
        int n1 =s.size(), n2 = t.size(), i;
        for(i=0; i<n1; ++i){
            fre[s[i]]++;
        }
        for(i=0; i<n2; ++i){
            fre[t[i]]--;
        }
        for(i=0; i<256; ++i){
            if(fre[i]!=0){
                return i;
            }
        }
        return 'a';
    }
};