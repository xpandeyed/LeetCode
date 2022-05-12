class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size(), i, m, res=0;
        sort(nums.begin(), nums.end());
        m=nums[0];
        for(i=1;i<n; ++i){
            res+=(nums[i]-m);
        }
        return res;
    }
};