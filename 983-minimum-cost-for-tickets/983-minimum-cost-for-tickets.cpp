class Solution {
public:
    int helper(vector<int>& days, vector<int>& costs, int validity, int i,vector<vector<int>> &res){
        if(i==days.size()){
            return res[i][validity] = 0;
        }
        if(res[i][validity]!=-1){
            return res[i][validity];
        }
        if(validity>=days[i]){
            return res[i][validity] =helper(days, costs, validity, i+1, res);
        }
        int one = costs[0] + helper(days, costs, days[i], i+1, res);
        int two = costs[1] + helper(days, costs, days[i]+6, i+1, res);
        int three = costs[2] + helper(days, costs, days[i]+29, i+1, res);
        return res[i][validity] = min(one, min(two, three));
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> res(days.size()+1, vector<int>(395, -1));
        return helper(days, costs, days[0]-1, 0, res);
    }
};