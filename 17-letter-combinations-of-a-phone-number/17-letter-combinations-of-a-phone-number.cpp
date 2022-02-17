class Solution {
public:
    
    void help(string digits, map<int, vector<string>> m, int index, vector<string> &res, int n, string curr){
        if(index>=n){
            res.push_back(curr);
            return ;
        }
        int currDigit = digits[index]-'0', s, i;
        s = m[currDigit].size();
        for(i=0; i<s; ++i){
            help(digits, m, index+1, res, n, curr+m[currDigit][i]);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string> res;
        if(n==0){
            return res;
        }
        map<int, vector<string>> m;
        m[2]={"a", "b", "c"};
        m[3]={"d", "e", "f"};
        m[4]={"g", "h", "i"};
        m[5]={"j", "k", "l"};
        m[6]={"m", "n", "o"};
        m[7]={"p", "q", "r", "s"};
        m[8]={"t", "u", "v"};
        m[9]={"w", "x", "y", "z"};
        help(digits, m, 0, res, n, "");
        return res;
        
    }
        
};