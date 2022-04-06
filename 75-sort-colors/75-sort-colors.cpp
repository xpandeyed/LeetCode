class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i, l=0, n=nums.size(), h=n-1;
        while(i<=h){
            if(nums[i]==0){
                swap(nums[i], nums[l]);
                l++;
                i++;
            }else if(nums[i]==1){
                i++;
            }else{
                swap(nums[i], nums[h]);
                h--;
            }
        }
    }
};