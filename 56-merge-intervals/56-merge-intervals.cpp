class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n=intervals.size(), i=1;
        vector<vector<int>> res;
        vector<int> currInterval(2);
        currInterval[0]=intervals[0][0];
        currInterval[1]=intervals[0][1];
        for(i=1; i<n; ++i){
            if(intervals[i][0]<=currInterval[1]){
                currInterval[0]=min(currInterval[0], intervals[i][0]);
                currInterval[1]=max(currInterval[1], intervals[i][1]);
                continue;
            }
            res.push_back(currInterval);
            currInterval[0]=intervals[i][0];
            currInterval[1]=intervals[i][1];
        }
        res.push_back(currInterval);
        return res;
        
    }
};