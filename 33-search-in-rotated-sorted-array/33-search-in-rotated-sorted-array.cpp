class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(), start=0, end, mid;
        end=n-1;
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<nums[end]){
                if(target>=nums[mid] && target<=nums[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }else{
                if(target>=nums[start] && target <=nums[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }
        }
        
        return -1;
    }
};
