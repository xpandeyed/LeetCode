class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid, n;
        n=r+1;
        if(n<2){
            return 0;
        }
        while(l<=r){
            mid=(l+r)/2;
            if(mid==0 && nums[mid]>nums[1]){
                return mid;
            }
            
            if(mid==n-1 && nums[mid]>nums[mid-1]){
                return mid;
            }
            
            if(nums[mid]>nums[mid+1]  and nums[mid]>nums[mid-1]){
                return mid;
            }
            
            if(nums[mid+1]>nums[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        
        return mid;
    }
};