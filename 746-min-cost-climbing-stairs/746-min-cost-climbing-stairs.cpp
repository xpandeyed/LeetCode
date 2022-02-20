class Solution {
public:
    int rec(vector<int>& cost, int i, int n, vector<int> &res){
        if(i>=n){
            return res[i]= 0;
        }
        if(res[i]!=-1){
            return res[i];
        }
        
        return res[i] = cost[i]+min(rec(cost, i+1, n, res), rec(cost, i+2, n, res));
    }
    
    int dynamic(vector<int> cost){
        int n=cost.size(), i;
        for(i=n-3; i>=0; --i){
            cost[i]+=min(cost[i+1], cost[i+2]);
        }
        
        return min(cost[0], cost[1]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // int n=cost.size();
        // vector<int> res(n+4, -1);
        // return min(rec(cost, 0, n, res),rec(cost, 1, n, res));
        
        return dynamic(cost);
    }
};