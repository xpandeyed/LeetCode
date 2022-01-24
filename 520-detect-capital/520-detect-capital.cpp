class Solution {
public:
    bool allCapital(string word){
        int n=word.size(), i; 
        for(i=0 ;i<n; ++i){
            if(word[i]<65 || word[i]>90){
                return false;
            }
        }
        return true;
    }
    
    bool noCapital(string word){
        int n=word.size(), i; 
        for(i=0 ;i<n; ++i){
            if(word[i]>=65 && word[i]<=90){
                return false;
            }
        }
        return true;
    }
    
    bool firstCapital(string word){
        if(word[0]>90){
            return false;
        }
        return noCapital(word.substr(1));
    }
    
    
    bool detectCapitalUse(string word) {
        return allCapital(word) || (noCapital(word) || firstCapital(word));
    }
};