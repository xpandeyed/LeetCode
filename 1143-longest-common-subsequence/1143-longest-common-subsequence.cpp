class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size(), i, j;
        vector<vector<int>> res(text1.size()+1, vector<int>(text2.size()+1, -1));
        for(i=0; i<n1+1; ++i){
            for(j=0; j<n2+1; ++j){
                if(i==0 || j==0){
                    res[i][j]=0;
                    continue;
                }
                if(text1[i-1]==text2[j-1]){
                    res[i][j] = res[i-1][j-1];
                    res[i][j]++;
                    continue;
                }
                res[i][j] = max(res[i-1][j-1], max(res[i-1][j], res[i][j-1]));

            }
        }
        return res[n1][n2];
    }
};