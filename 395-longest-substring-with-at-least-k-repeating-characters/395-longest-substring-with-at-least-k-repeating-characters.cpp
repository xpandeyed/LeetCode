class Solution {
public:
    int rec(string s, int k, int start, int end){
        // cout << start << " " << end << endl;
        if(end<start){
            return 0;
        }
        vector<int> f(26, 0);
        int n=s.size(), i;
        for(i=start; i<=end; ++i){
            f[s[i]-'a']++;
        }
        for(i=start; i<=end; ++i){
            if(f[s[i]-'a']>0 and f[s[i]-'a']<k){
                return max(rec(s, k, start, i-1), rec(s, k, i+1, end));
            }
        }
        return end-start+1;
    }
    
    int longestSubstring(string s, int k) {
        return rec(s, k, 0, s.size()-1);
    }
};