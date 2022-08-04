class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2){
            if(v1[0]!=v2[0])
                return v1[0]<v2[0];
            return v1[1]<v2[1];
        });
        int res = 0, n=intervals.size(), i, j;
        vector<int> dp(n, 1);
        for(i=1;i<n;++i){
            for(j=i-1;j>-1;--j){
                if(intervals[j][1]<=intervals[i][0])
                    break;
            }
            if(j!=-1){
                dp[i]=dp[j]+1;
                continue;
            }
        }
        int noi = 0;
        for(i=0;i<n;++i){
            // cout << dp[i] << " ";
            noi=max(noi, dp[i]);
        }
        // cout << endl;
        return n-noi;
    }
};