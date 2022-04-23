class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size(), i, res=0;
        if(n<3){
            return true;
        }
        for(i=1; i<n; ++i){
            if(nums[i]>nums[i-1]){
                if(res==-1) return false;
                else res = 1;
            }
            if(nums[i]<nums[i-1]){
                if(res==1) return false;
                else res = -1;
            }
        }
        return true;
    }
};