class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(), l=-1;
        for(int i=0; i<n; ++i){
            if(nums[i]!=0){
                l++;
                swap(nums[l], nums[i]);
            }
        }
    }
};