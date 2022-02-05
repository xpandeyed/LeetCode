class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), i, res=0;
        for(i=n-1; i>=2; --i){
            if(nums[i-2]+nums[i-1]>nums[i]){
                res=max(res, nums[i]+nums[i-1]+nums[i-2]);
            }
            if(res>0){
                break;
            }
        }
        
        
        return res;
    }
};