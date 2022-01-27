class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size(), n2 = t.size(), i, j=0;
        if(n1==0){
            return true;
        }
        if(n2==0 || n2<n1){
            return false;
        }
        for(i=0; i<n1; ++i){
            if(j>=n2){
                break;
            }
            while(j<n2 && s[i]!=t[j] ){
                j++;
                
            }
            j++;
        }
        if(i==n1 && t[j-1]==s[i-1]){
            return true;
        }
        return false;
    }
};