class Solution {
public:
    int longestPalindrome(string s) {
        int res=0, n=s.size(), maxOdds=0, evens=0, currOdds;
        
        vector<int> freq(256, 0);
        
        for(char x: s){
            freq[x]++;
        }
        
        for(int x: freq){
            if(x%2){
                
                if(x>maxOdds){
                    if(maxOdds>0){
                        res+=(maxOdds-1);
                    }
                    
                    maxOdds=x;
                }else{
                    res+=(x-1);
                }
                
                
            }
            else{
                res+=x;
            }
        }
        
        if(maxOdds){
            res+=maxOdds;
        }
        
        return res;
        
    }
};