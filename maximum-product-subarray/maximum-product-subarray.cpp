class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int mi = nums[0];
        int ma = nums[0];
        int n=nums.size();
        for(int i=1; i<n; ++i){
            if(nums[i]<0){
                swap(mi, ma);
                
            }
            mi = min(nums[i], nums[i]*mi);
                ma = max(nums[i], nums[i]*ma);
                res = max(res, ma);
        }
        return res;
    }
};