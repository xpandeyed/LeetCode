class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int res = INT_MAX;
        int n  = nums.size();
        int count = 0;
        for(int i=0; i<n; ++i){
            if(nums[i]==1){
                count++;
            }
            nums.push_back(nums[i]);
        }
        int currSwaps = 0;
        for(int i=0; i<count; ++i){
            if(nums[i]!=1){
                currSwaps++;
            }
        }
        res=currSwaps;
        for(int i=count; i<2*n; ++i){
            if(nums[i-count]==nums[i]){
                continue;
            }
            else if(nums[i-count]==0 && nums[i]==1){
                currSwaps--;
            }
            else{
                currSwaps++;
            }
            res=min(res, currSwaps);
        }
        return res;
    }
};