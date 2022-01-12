class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=nums[0], n=nums.size(), i=1;
        for(i=1; i<n; ++i){
            res=res^nums[i];
        }
        return res;
    }
};