class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size(), i, count=0;
        sort(nums.begin(), nums.end());
        for(i=1; i<n ; ++i){
            if(nums[i]<=nums[i-1]){
                count+=(nums[i-1]-nums[i] +1);
                nums[i]+=(nums[i-1]-nums[i] +1);
            }
        }
        return count;
    }
};