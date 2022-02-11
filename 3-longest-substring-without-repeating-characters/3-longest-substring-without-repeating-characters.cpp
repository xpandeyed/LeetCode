class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), start=0, res=0, i, curr;
        if(n<2){
            return n;
        }
        map<int, int> m;
        m[s[0]]=0;
        for(i=1; i<n; ++i){
            if(m.find(s[i])==m.end()){
                m[s[i]]=i;
                curr = i-start+1;
                res = max(curr, res);
                continue;
            }
            
            int ind = m[s[i]];
            m[s[i]]=i;
            if(ind>=start){
                start=ind+1;
            }
            curr = i-start+1;
            res = max(curr, res);
            
            
            
            
        }
        
        return res;
    }
};