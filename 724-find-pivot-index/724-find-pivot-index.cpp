class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, n=nums.size(), lSum=0, rSum=0;
        for(i=0;i<n;++i){
            rSum+=nums[i];
        }
        for(i=0;i<n;++i){
            rSum-=nums[i];
            if(lSum==rSum){
                return i;
            }
            lSum+=nums[i];
        }
        return -1;
    }
};