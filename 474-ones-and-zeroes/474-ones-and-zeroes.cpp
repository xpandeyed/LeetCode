class Solution {
public:
    int dynamic(vector<string>& strs, int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto s: strs){
            int ones = count(s.begin(), s.end(), '1');
            int zeroes = s.size()-ones;
            for(int i=m; i>=zeroes; --i){
                for(int j=n; j>=ones; --j){
                    dp[i][j]=max(dp[i][j], 1+dp[i-zeroes][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        return dynamic(strs, m, n);
    }
};