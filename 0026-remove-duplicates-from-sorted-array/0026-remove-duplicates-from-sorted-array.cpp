class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int initial=0, n=nums.size(), i=1;
        for(i=1; i<n; ++i){
            if(nums[i]!=nums[initial]){
                swap(nums[i], nums[++initial]);
            }
        }
        return (initial+1);
    }
};