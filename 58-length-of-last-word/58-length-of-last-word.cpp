class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(), i, res=0, j;
        j=n-1;
        while(j>-1 and s[j]==' '){
            j--;
        }
        for(i=j; i>-1 and s[i]!=' '; --i){
            res++;
        }
        
        return res;
    }
};