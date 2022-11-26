class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& p) {
        
        vector<vector<int>> job;
        for(int i=0;i<p.size(); ++i){
            vector<int> temp;
            
            temp.push_back(endTime[i]);
            temp.push_back(startTime[i]);
            temp.push_back(p[i]);
            
            job.push_back(temp);
        }
        
        sort(job.begin(), job.end());
        
        
        vector<int> dp(p.size(), 0);
        
        for(int i=0;i<p.size(); ++i){
            int l=0, h=i, ri=-1, m;
            while(l<=h){
                m=(l+h)/2;
                if(job[i][1]>=job[m][0]){
                    ri = m;
                    l = m+1;
                }
                else{
                    h = m-1;
                }
            }
            
            
            int val1=0, val2=0, val3=job[i][2];
            if(i>0) val1=dp[i-1];
            if(ri>-1) val2=dp[ri]+job[i][2];
            dp[i]=max(val1, max(val2, val3));
            
        }
        
        int res = 0;
        for(auto x:dp){
            // cout <<x<< endl;
            res=max(res, x);
        }
        
        return res;
        
    }
};
//sort all jobs by endtime
//at each end time fill the dp table by max profit
//max profit = max(currJob+profitAtStartOfJob, profit at end of previous job)