class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size(), i, j, res=0;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(i=1;i<=n1;++i){
            for(j=1;j<=n2;++j){
                if(nums1[i-1]==nums2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                res=max(res, dp[i][j]);
            }
        }
        return res;
    }
};