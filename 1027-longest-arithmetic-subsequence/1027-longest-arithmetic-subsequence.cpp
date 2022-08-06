class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(), i, j;
        if(n<3)
            return n;
        vector<map<int, int>> dp(n);
        int res = 0;
        for(i=0;i<n;++i){
            for(j=1+i;j<n;++j){
                int diff = nums[j]-nums[i];
                if(dp[i].find(diff)!=dp[i].end())
                    dp[j][diff] = dp[i][diff]+1;
                else
                    dp[j][diff] = 2;
                res=max(res, dp[j][diff]);
                
            }
        }
        return res;
    }
};