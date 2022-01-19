class Solution {
public:
    int helper(vector<int>& nums, int target, int index, int currSum){
        if(index==0){
            if(currSum+nums[0]==target && currSum-nums[0]==target){
                return 2;
            }
            if(currSum+nums[0]==target || currSum-nums[0]==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        return helper(nums, target, index-1, currSum+nums[index]) + helper(nums, target, index-1, currSum-nums[index]);
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, nums.size()-1, 0);
    }
};