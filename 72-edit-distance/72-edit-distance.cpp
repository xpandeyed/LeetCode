class Solution {
public:
    int helper(string s1, string s2, int i1, int i2, vector<vector<int>> &res){
        if(i1==-1){
            return res[i1+1][i2+1] = i2+1;
        }
        if(i2==-1){
            return res[i1+1][i2+1] = i1+1;
        }
        if(res[i1+1][i2+1]!=-2){
            return res[i1+1][i2+1];
        }
        if(s1[i1]==s2[i2]){
            return res[i1+1][i2+1] = helper(s1, s2, i1-1, i2-1, res);
        }else{
            int replace = helper(s1, s2, i1-1, i2-1, res);
            int del = helper(s1, s2, i1-1, i2, res);
            int insert = helper(s1, s2, i1, i2-1, res);
            return res[i1+1][i2+1] = 1+min(replace, min(del, insert));
        }
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> res(word1.size()+1, vector<int>(word2.size()+1, -2));
        return helper(word1, word2, word1.size()-1, word2.size()-1, res);
    }
};