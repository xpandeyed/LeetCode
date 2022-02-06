class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), i, count=1, j=0;
        for(i=1; i<n; ++i){
            if(nums[i]==nums[j]){
                count++;
            }
            else{
                count=1;
            }
            if(count>=3){
                continue;
            }else{
                j++;
                swap(nums[i], nums[j]);
            }
        }
        return j+1;
    }
};