class Solution {
public:
    bool isPal(int s, int e, string t){
        while(s<e){
            if(t[s]!=t[e]){
                return false;
            }
            s++;
            e--;
        }
            return true;
    }
    
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return (isPal(l, r-1, s) or isPal(l+1, r, s));
            }else{
                l++;
                r--;
            }
        }
        return true;
    }
};