class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n=s.size(), i, n1, j;
        vector<string> res;
        res.push_back(s);
        for(i=0; i<n; ++i){
            if(s[i]>=48 && s[i]<=57){
                continue;
            }
            n1=res.size();
            for(j=0; j<n1; ++j){
                if(s[i]>=97 && s[i]<=122){
                    string temp = res[j];
                    temp[i]-=32;
                    res.push_back(temp);
                }else{
                    string temp = res[j];
                    temp[i]+=32;
                    res.push_back(temp);
                }
            }
            
        }
        
        return res;
    }
};