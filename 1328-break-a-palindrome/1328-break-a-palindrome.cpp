class Solution {
public:
    string breakPalindrome(string pal) {
        int n=pal.size(), i;
        if(n==1) return "";
        for(i=0;i<n/2;++i){
           if(pal[i]!='a'){
               pal[i]='a';
               return pal;
           } 
        }
        pal[n-1]='b';
        return pal;
    }
};
//if pal[i] is a no need to replace
//abcba//5
//abba