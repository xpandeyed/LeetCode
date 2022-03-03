class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(), i, low, high, start=0, len=0;
        
        for(i=0; i<n; ++i){
            low = i-1;
            high = i+1;
            
            while(low>=0 && s[low]==s[i]){
                low--;
            }
            
            while(high<n && s[high]==s[i]){
                high++;
            }
            
            while((low>=0 and high<n) && (s[low]==s[high])){
                low--;
                high++;
            }
            
            if(len<(high-low-1)){
                len=(high-low-1);
                start=low+1;
            }
        }
        
        return s.substr(start, len);
    }
};