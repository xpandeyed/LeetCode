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
    int dynamic(string s1, string s2){
        int n1=s1.size(), n2 = s2.size(), i, j;
        vector<vector<int>> res(n1+1, vector<int>(n2+1, 0));
        for(i=0; i<n1+1; ++i){
            for(j=0; j<n2+1; ++j){
                if(j==0){
                    res[i][j] = i;
                    continue;
                }
                if(i==0){
                    res[i][j]= j;
                    continue;
                }
                if(s1[i-1]==s2[j-1]){
                    res[i][j] = res[i-1][j-1];
                }else{
                    res[i][j] = min(1+res[i-1][j], min(1+res[i][j-1], 1+res[i-1][j-1]));
                    
                }
            }
        }
        return res[n1][n2];
        
    }
    int minDistance(string word1, string word2) {
        return dynamic(word1, word2);
    }
};