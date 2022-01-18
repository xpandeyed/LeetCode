class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int currSum = nums[0];
        int n=nums.size();
        for(int i=1; i<n; i++){
            currSum=max(currSum+nums[i], nums[i]);
            res=max(res, currSum);
        }
        return res;
    }
};