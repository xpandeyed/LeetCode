class Solution {
public:
    int removePalindromeSub(string s) {
        bool isPal = true;
        int l=0, h=s.size()-1;
        while(l<h){
            if(s[l]!=s[h]){
                return 2;
            }
            l++;
            h--;
        }
        return 1;
    }
};