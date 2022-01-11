class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1]){
            return nums[0];
        }
        int l=0, h=n-1;
        while(l<=h){
            if(l==h){
                return nums[h];
            }
            int m=(l+h)/2;
            if(m>0 && nums[m-1]>nums[m]){
                return nums[m];
            }
            if(nums[m]<nums[h]){
                h=m-1;
                continue;
            }
            if(nums[m]>nums[h]){
                l=m+1;
            }
            
        }
        return 0;
    }
};