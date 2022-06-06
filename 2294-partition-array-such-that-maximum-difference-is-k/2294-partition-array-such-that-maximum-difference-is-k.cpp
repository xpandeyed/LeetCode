class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res=1, n=nums.size(), i, x=nums[0];
        for(i=1;i<n;++i){
            if(nums[i]-x>k){
                res++;
                x=nums[i];
            }
        }
        return res;
    }
};