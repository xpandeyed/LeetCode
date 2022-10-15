class Solution {
public:
    int calLen(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n<10) return 2;
        if(n<100) return 3;
        return 4;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        long long int n=s.size();
        vector<vector<long long int>> dp(n+1, vector<long long int>(k+1, 0));
        for(int i=1;i<=n;++i){
            for(int j=0;j<=k;++j)
                dp[i][j]=INT_MAX;
        }
        
        
        for(int i=1;i<=n;++i){
            for(int j=0;j<=k; ++j){
                if(j>0) dp[i][j] = dp[i-1][j-1];
                int removed = 0, count = 0, p;
                for(p=i; p>0; p--){
                    if(s[p-1]==s[i-1]) count++;
                    else if(++removed>j) break;
                    dp[i][j] = min(dp[i][j], dp[p-1][j-removed]+calLen(count));
                }
            }
        }
        return dp[n][k];
    }
};