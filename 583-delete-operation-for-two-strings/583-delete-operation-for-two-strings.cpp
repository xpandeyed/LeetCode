class Solution {
public:
    int dynamic(string w1, string w2){
        int n1=w1.size(), n2=w2.size(), i1, i2;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        //i1 for rows
        //i2 for cols
        for(i1=0;i1<=n1;++i1){
            for(i2=0;i2<=n2;++i2){
                // cout << i1 << " " << i2 << endl;
                if(i1==0){
                    dp[i1][i2]=i2;
                    continue;
                }
                if(i2==0){
                    dp[i1][i2]=i1;
                    continue;
                }
                if(w1[i1-1]!=w2[i2-1]){
                    dp[i1][i2]=1+min(dp[i1-1][i2], dp[i1][i2-1]);
                }else{
                    dp[i1][i2]=dp[i1-1][i2-1];
                }
            }
        }
        return dp[n1][n2];
    }
    
    int minDistance(string word1, string word2) {
        return dynamic(word1, word2);
    }
};