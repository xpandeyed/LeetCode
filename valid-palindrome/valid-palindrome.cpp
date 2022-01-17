class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        int n=s.size();
        if(n==1){
            return true;
        }
        for(int i=0; i<n; ++i){
            if(s[i]<=90 && s[i]>=65){
                s[i]+=32;
                temp+=s[i];
                continue;
            }
            if((s[i]<=122 && s[i]>=97) || (s[i]>=48 && s[i]<=57)){
                temp+=s[i];
            }
        }
        n=temp.size();
        int l=0, r=n-1;
        while(l<=r){
            if(temp[l]!=temp[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};