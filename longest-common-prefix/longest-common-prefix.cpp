class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for(int i=0 ; i<strs[0].size(); ++i){
            bool flag = true;
            for(int j=1; j<strs.size(); ++j){
                if(j>=strs.size()){
                    return res;
                }
                if(strs[j][i]!=strs[0][i]){
                    return res;
                }
            }
            if(flag==true){
                res+=strs[0][i];
            }
        }
        return res;
    }
};