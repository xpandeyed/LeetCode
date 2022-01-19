class Solution {
public:
    int profit(vector<int>& nums, int index, vector<int> &results){
        if(index<0){
            return 0;
        }
        if(results[index]!=-1){
            return results[index];
        }
        return results[index] = max(profit(nums, index-1, results), nums[index]+profit(nums, index-2, results));
    }
    
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> results(n, -1);
        return profit(nums, nums.size()-1, results);
    }
};