class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0, curr;
        for(auto x: accounts){
            curr = 0;
            for(auto y: x){
                curr+=y;
            }
            res= max(res, curr);
        }
        return res;
    }
};