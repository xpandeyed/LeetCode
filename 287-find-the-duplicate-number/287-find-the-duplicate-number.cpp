class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(), i, curr;
        for(i=0; i<n; ++i){
            curr = nums[i]>0?nums[i]:(-nums[i]);
            if(nums[curr]<0){
                return curr;
            }else{
                nums[curr]*=(-1);
            }
        }
        return -1;
    }
};