class Solution {
public:
    int count, n;
    void extend(string s, int l, int r){
        while((l>-1 and r<n) and s[l]==s[r]){
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        count=0;
        n=s.size();
        int i;
        for(i=0;i<n;++i){
            extend(s, i, i);
            extend(s, i, i+1);
        }
        return count;
    }
};