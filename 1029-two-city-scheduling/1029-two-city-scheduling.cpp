class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size(), cost=0, i, refund=0;
        for(i=0; i<n; ++i){
            cost+=costs[i][0];
        }
        vector<int> refunds(n, 0);
        for(i=0; i<n; ++i){
            refunds[i]=costs[i][0]-costs[i][1];
        }
        
        sort(refunds.begin(), refunds.end(), greater<int>());
        
        for(i=0; i<n/2; ++i){
            refund+=refunds[i];
        }
        
        return cost-refund;
    }
};