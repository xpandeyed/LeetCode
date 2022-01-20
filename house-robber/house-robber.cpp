class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(), i;
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        vector<int> res(n, -1);
        res[0]=nums[0];
        res[1]=max(nums[0], nums[1]);
        for(i=2;i<n; ++i){
            res[i]=max(nums[i]+res[i-2], res[i-1]);
        }
        return res[n-1];
    }
};